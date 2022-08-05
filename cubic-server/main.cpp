#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <netdb.h>
#include <stdexcept>
#include "Packet.hpp"

typedef struct client_s
{
    struct sockaddr_in addr;
    void *write_buffer;
    void *read_buffer;
    size_t write_buffer_size;
    size_t read_buffer_size;
    int sockfd;
    bool to_remove;
} client_t;

typedef struct client_list_s
{
    client_t cli;
    struct client_list_s *next;
} client_list_t;

typedef struct server_s
{
    struct sockaddr_in addr;
    client_list_t *cli_list;
    int sockfd;
    uint16_t port;
} server_t;

void add_to_client_read_buffer(client_t *cli, void *data, size_t size)
{
    if (!size)
        return;
    cli->read_buffer = realloc(cli->read_buffer, cli->read_buffer_size + size);
    assert(cli->read_buffer);
    memmove((char *)cli->read_buffer + cli->read_buffer_size, data, size);
    cli->read_buffer_size += size;
}

void remove_client(server_t *srv, client_list_t *old_cli)
{
    client_list_t *tmp = srv->cli_list;
    client_list_t *list = srv->cli_list;

    close(old_cli->cli.sockfd);
    free(old_cli->cli.read_buffer);
    if (srv->cli_list == old_cli)
    {
        tmp = old_cli->next;
        free(old_cli);
        srv->cli_list = tmp;
        return;
    }
    for (; list != old_cli; tmp = list, list = list->next)
        ;
    tmp->next = list->next;
    free(list);
}

static void handle_reading(server_t *srv,
                           client_list_t *list, const fd_set *rd_set)
{
    char buffer[1024] = {0};
    client_list_t *tmp = NULL;
    ssize_t size_read = 0;

    while (list)
    {
        if (FD_ISSET(list->cli.sockfd, rd_set))
        {
            size_read = read(list->cli.sockfd, buffer, 1024);
            if (!size_read || size_read == -1)
            {
                printf("Disconnection\n");
                tmp = list->next;
                remove_client(srv, list);
                list = tmp;
                continue;
            }
            add_to_client_read_buffer(&list->cli, buffer, (size_t)size_read);
        }
        list = list->next;
    }
}

void add_new_client(server_t *srv, client_t *new_cli)
{
    client_list_t *list = srv->cli_list;
    client_list_t *new_node = reinterpret_cast<client_list_t *>(calloc(sizeof(client_list_t), 1));

    assert(new_node);
    memmove(&new_node->cli, new_cli, sizeof(*new_cli));
    if (!list)
    {
        srv->cli_list = new_node;
        return;
    }
    for (; list->next; list = list->next)
        ;
    list->next = new_node;
}

void smart_write(int fd, void *data, size_t size)
{
    ssize_t written_size = 0;

    while (size)
    {
        written_size = write(fd, data, size);
        if (written_size == -1)
            continue;
        size -= (size_t)written_size;
        data = (char *)data + written_size;
    }
}

void send_data_to_client(client_t *cli)
{
    smart_write(cli->sockfd, cli->write_buffer, cli->write_buffer_size);
    free(cli->write_buffer);
    cli->write_buffer = NULL;
    cli->write_buffer_size = 0;
}

static void handle_writing(client_list_t *list, const fd_set *wr_set)
{
    for (; list; list = list->next)
        if (FD_ISSET(list->cli.sockfd, wr_set))
            send_data_to_client(&list->cli);
}

char *get_client_string(const client_t *client)
{
    static char buffer[50];

    memset(buffer, 0, 50);
    snprintf(buffer, 49, "%s:%hu", inet_ntoa(client->addr.sin_addr),
             ntohs(client->addr.sin_port));
    return buffer;
}

static void accept_new_client(server_t *srv)
{
    client_t cli = {0};
    socklen_t addr_size = sizeof(cli.addr);

    cli.sockfd = accept(srv->sockfd, (struct sockaddr *)&cli.addr, &addr_size);
    if (cli.sockfd == -1)
    {
        printf("Could not accept new client:\n%s\n", strerror(errno));
        return;
    }
    add_new_client(srv, &cli);
    printf("%s - Client connected\n", get_client_string(&cli));
}

static void handle_input(server_t *srv, const fd_set *wr_set,
                         const fd_set *rd_set)
{
    handle_writing(srv->cli_list, wr_set);
    handle_reading(srv, srv->cli_list, rd_set);
    if (FD_ISSET(srv->sockfd, rd_set))
        accept_new_client(srv);
}

void bind_server_socket(server_t *srv)
{
    setsockopt(srv->sockfd, SOL_SOCKET, SO_REUSEADDR, (int[1]){1}, sizeof(int));
    if (bind(srv->sockfd, (struct sockaddr *)&srv->addr, sizeof(srv->addr)) == -1)
    {
        printf("Could not bind server to port %hu, Error:\n"
               "%s\n",
               srv->port, strerror(errno));
    }
}

server_t create_server(uint16_t port)
{
    server_t srv = {
        .port = port,
        .sockfd = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto),
        .addr = {
            .sin_addr.s_addr = htonl(INADDR_ANY),
            .sin_family = AF_INET,
            .sin_port = htons(port)},
        .cli_list = NULL};

    printf("Launching the server...\n");
    bind_server_socket(&srv);
    listen(srv.sockfd, SOMAXCONN);
    return srv;
}

fd_set create_writing_fdset(const client_list_t *list)
{
    fd_set my_set;

    FD_ZERO(&my_set);
    for (; list; list = list->next)
        if (list->cli.write_buffer_size)
            FD_SET(list->cli.sockfd, &my_set);
    return my_set;
}

fd_set create_reading_fdset(const client_list_t *list)
{
    fd_set my_set;

    FD_ZERO(&my_set);
    for (; list; list = list->next)
        if (!list->cli.write_buffer_size)
            FD_SET(list->cli.sockfd, &my_set);
    return my_set;
}

static bool is_client_buffer_containing_pck(const client_t *cli)
{
    return cli->read_buffer_size > 10; // TODO: Yes this is garbage
}

static void handle_incoming_pck(Protocol::Packet *pck)
{
    printf("GOT A PACKET!!!!!\n");
    printf("Packet ID: %d\n", pck->getPacketID());
    printf("Protocol version: %d\n", pck->popVarInt());
    printf("Server address: %s\n", pck->popString().c_str());
    printf("Server port: %d\n", pck->popUnsignedShort());
    printf("Next state: %d\n", pck->popVarInt());
    printf("NO CRASH??????\n");
}

// Maybe this works... Idk ¯\_(ツ)_/¯
static void handle_read_buffer(client_t *cli)
{
    if (!is_client_buffer_containing_pck(cli))
        return;

    uint32_t value = 0;
    {
        int position = 0;
        uint8_t currentByte = 0;
        constexpr uint8_t CONTINUE_BIT = 0x80;
        constexpr uint8_t SEGMENT_BITS = 0x7f;

        while (true)
        {
            if (cli->read_buffer_size == 0)
                throw std::runtime_error("Not enough data to parse VarInt 1");
            currentByte = ((char *)cli->read_buffer)[0];
            cli->read_buffer = (char *)cli->read_buffer + 1; // TODO: Yes this leaks, and ?
            cli->read_buffer_size--;
            value |= (currentByte & SEGMENT_BITS) << position;

            if ((currentByte & CONTINUE_BIT) == 0)
                break;

            position += 7;

            if (position >= 32)
                throw std::runtime_error("VarInt is too big");
        }
    }
    uint32_t size = value;
    value = 0;
    {
        int position = 0;
        uint8_t currentByte = 0;
        constexpr uint8_t CONTINUE_BIT = 0x80;
        constexpr uint8_t SEGMENT_BITS = 0x7f;

        while (true)
        {
            if (cli->read_buffer_size == 0)
                throw std::runtime_error("Not enough data to parse VarInt 2");
            currentByte = ((char *)cli->read_buffer)[0];
            cli->read_buffer = (char *)cli->read_buffer + 1; // TODO: Yes this leaks, and ?
            cli->read_buffer_size--;
            value |= (currentByte & SEGMENT_BITS) << position;

            if ((currentByte & CONTINUE_BIT) == 0)
                break;

            position += 7;

            if (position >= 32)
                throw std::runtime_error("VarInt is too big");
        }
    }
    uint32_t payload_id = value;
    Protocol::Packet pck;
    pck.setPacketID(payload_id);
    auto bruh = pck.getPayload();
    for (int i = 0; i < size - 1; i++)
        bruh->push_back(((char *)cli->read_buffer)[i]);
    handle_incoming_pck(&pck);
    throw std::runtime_error("Parsed the handshake status packet, ALL GOOD !");
}

void check_clients_read_buffers(client_list_t *list)
{
    for (; list; list = list->next)
        if (list->cli.read_buffer_size)
            handle_read_buffer(&list->cli);
}

void check_to_disconnect(server_t *srv)
{
    client_list_t *list = srv->cli_list;

    for (; list; list = list->next)
    {
        if (list->cli.to_remove)
        {
            remove_client(srv, list);
            return;
        }
    }
}

int launch_server_loop(server_t *srv)
{
    fd_set wr_set;
    fd_set rd_set;

    while (1)
    {
        wr_set = create_writing_fdset(srv->cli_list);
        rd_set = create_reading_fdset(srv->cli_list);
        FD_SET(srv->sockfd, &rd_set);
        if (select(FD_SETSIZE + 1, &rd_set, &wr_set, NULL, NULL) == -1)
            return 84;
        handle_input(srv, &wr_set, &rd_set);
        check_to_disconnect(srv);
        check_clients_read_buffers(srv->cli_list);
    }
}

int main()
{
    server_t srv = create_server(25565);

    printf("Server launched and listening on %s:%hu\n",
           inet_ntoa(srv.addr.sin_addr), srv.port);
    launch_server_loop(&srv);
    return 0;
}
