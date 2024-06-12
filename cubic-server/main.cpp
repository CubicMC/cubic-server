#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <memory>
#include <mutex>
#include <netdb.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

#include "cubic-protocol/c2s/handshake.hpp"
#include "cubic-protocol/c2s/status.hpp"
#include "cubic-protocol/primitives/varint.hpp"

#include "client.hpp"

using namespace cubic::server;

struct ServerContext {
    int socket_fd;
    std::vector<std::unique_ptr<client::Client>> clients;
};

namespace {
// TODO: Check that this is good values
constexpr size_t CUBIC_MAX_NETWORK_READ_SIZE = 65536;
constexpr size_t CUBIC_MAX_NETWORK_WRITE_SIZE = 65536;
constexpr int32_t CUBIC_MAX_PACKET_SIZE = 2 << 21;

auto init_fd_list(
    std::vector<pollfd> &fds, std::vector<std::unique_ptr<client::Client>> &clients, int server_fd
) -> void
{
    // Clear the previous fds as we don't really know
    fds.clear();
    // Set the server fd all the time to accept new connections
    fds.push_back({ .fd = server_fd, .events = POLLIN });

    // Add all running clients to the read list
    for (auto &cli : clients) {
        if (cli->isRunning) {
            if (!cli->outBuffer.empty())
                fds.push_back({ .fd = cli->fd, .events = POLLIN | POLLOUT });
            else
                fds.push_back({ .fd = cli->fd, .events = POLLIN });
        }
    }
}

auto cleanup_client_list(std::vector<std::unique_ptr<client::Client>> &clients) -> void
{
    // Remove all the clients that are currently not running
    clients.erase(
        std::remove_if(
            clients.begin(), clients.end(),
            [](std::unique_ptr<client::Client> &cli) { return !cli->isRunning; }
        ),
        clients.end()
    );
}

auto get_client_from_fd(int fd, std::vector<std::unique_ptr<client::Client>> &clients)
    -> client::Client *
{
    for (auto &cli : clients)
        if (cli->fd == fd)
            return cli.get();
    return nullptr;
}

auto disconnect_client(client::Client &cli) -> bool
{
    const bool was_running = cli.isRunning;
    cli.isRunning = false;
    if (was_running)
        close(cli.fd);
    return !was_running;
}

auto disconnect_client_from_fd(int fd, std::vector<std::unique_ptr<client::Client>> &clients)
    -> bool
{
    auto *cli = get_client_from_fd(fd, clients);
    return cli == nullptr ? true : disconnect_client(*cli);
}

auto setup_and_launch_socket(int socket_fd) -> bool
{
    constexpr uint16_t port = 25565;
    // TODO: Support ipv6 - Shouldn't be hard at all, but I don't want to test it rn :)
    sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr = {
            .s_addr = htonl(INADDR_ANY),
        },
    };
    // TODO: Check if there are more socket options we would want to enable here
    const int sock_enable_value = 1;
    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &sock_enable_value, sizeof sock_enable_value);
    if (bind(socket_fd, (struct sockaddr *) &addr, sizeof addr) == -1) {
        perror("bind");
        return true;
    }
    listen(socket_fd, 0);
    return false;
}

auto try_accept_new_client(ServerContext &ctx, std::vector<pollfd> &fds) -> void
{
    if ((fds[0].revents & POLLIN) != 0) {
        const int cli_fd = accept(ctx.socket_fd, nullptr, nullptr);
        if (cli_fd != -1)
            ctx.clients.emplace_back(std::make_unique<client::Client>(cli_fd));
        else
            perror("accept");
    }
}

auto add_to_client_buffer(
    client::Client &cli, std::array<uint8_t, CUBIC_MAX_NETWORK_READ_SIZE> &read_buffer,
    ssize_t num_bytes
)
{
    cli.inBuffer.insert(cli.inBuffer.end(), read_buffer.data(), read_buffer.data() + num_bytes);
    // TODO: Remove that when proper logging is implemented
    printf("Got %lu bytes from client %p on fd %d\n", num_bytes, &cli, cli.fd);
}

#define CUBIC_HP_CALLBACK(pck_state, packet, packet_ns, packet_cb)                  \
    case (int32_t) client::Client::state::pck_state                                 \
        | (int32_t) cubic::protocol::c2s::packet_ns::packet_id::packet: {           \
        const auto *h = (const cubic::protocol::c2s::packet_ns::packet *) p.second; \
        client::hpcb::packet_cb(cli, *h);                                           \
        delete h;                                                                   \
        break;                                                                      \
    }

auto handle_high_priority_packet(client::Client &cli, std::pair<int, void *> p) -> void
{
    printf(
        "Handling high priority packet with id %d (%d | %d)\n", p.first, p.first >> 8 & 0xff,
        p.first & 0xff
    );
    switch (p.first) {
        // Handshake
        CUBIC_HP_CALLBACK(Handshaking, Handshake, handshake, handshake);
        // Status
        CUBIC_HP_CALLBACK(Status, StatusRequest, status, status_request);
        CUBIC_HP_CALLBACK(Status, PingRequest, status, ping_request);
    default:
        break;
    }
}

auto handle_high_priority_clients(std::vector<std::unique_ptr<client::Client>> &clients) -> void
{
    for (auto &cli : clients) {
        if (cli->inHighPriorityPackets.empty())
            continue;
        for (const auto &p : cli->inHighPriorityPackets)
            handle_high_priority_packet(*cli, p);
        cli->inHighPriorityPackets.clear();
    }
}

auto handle_clients_callbacks(ServerContext &ctx, std::vector<pollfd> &fds) -> void
{
    // No need to recreate that whole buffer everytime so I just put it in static
    static std::array<uint8_t, CUBIC_MAX_NETWORK_READ_SIZE> in_buffer;
    static std::array<uint8_t, CUBIC_MAX_NETWORK_WRITE_SIZE> out_buffer;

    for (size_t i = 1; i < fds.size(); i++) {
        if ((fds[i].revents & POLLIN) != 0) {
            const ssize_t num_bytes_read = read(
                fds[i].fd, in_buffer.data(), CUBIC_MAX_NETWORK_READ_SIZE
            );
            if (num_bytes_read == 0) {
                disconnect_client_from_fd(fds[i].fd, ctx.clients);
                continue;
            }
            auto *cli = get_client_from_fd(fds[i].fd, ctx.clients);
            assert(cli);
            add_to_client_buffer(*cli, in_buffer, num_bytes_read);
        }
        if ((fds[i].revents & POLLOUT) != 0) {
            auto *cli = get_client_from_fd(fds[i].fd, ctx.clients);
            ssize_t num_bytes_written = 0;
            assert(cli);
            size_t nb_bytes_to_write = std::min(
                cli->outBuffer.size(), CUBIC_MAX_NETWORK_WRITE_SIZE
            );
            {
                const std::unique_lock<std::mutex> _(cli->outBufferMutex);
                memcpy(out_buffer.data(), cli->outBuffer.data(), nb_bytes_to_write);
            }
            num_bytes_written = write(fds[i].fd, out_buffer.data(), nb_bytes_to_write);
            {
                const std::unique_lock<std::mutex> _(cli->outBufferMutex);
                cli->outBuffer.erase(
                    cli->outBuffer.begin(), cli->outBuffer.begin() + num_bytes_written
                );
            }
            // TODO: Remove that when proper logging is implemented
            printf("Sent %ld bytes to client %p on fd %d\n", num_bytes_written, cli, cli->fd);
        }
        if ((fds[i].revents & POLLHUP) != 0)
            disconnect_client_from_fd(fds[i].fd, ctx.clients);
    }
}

#define CUBIC_HP_PARSE(type)                                                            \
    case packet_id::type: {                                                             \
        auto *p = new (type);                                                           \
        assert(p);                                                                      \
        parsed = type::parse(current_data, bytes_left, p);                              \
        if (parsed == 0) {                                                              \
            cli.isRunning = false;                                                      \
            delete p;                                                                   \
            return false;                                                               \
        }                                                                               \
        cli.inHighPriorityPackets.emplace_back(p_id | (int32_t) cli.state, (void *) p); \
        break;                                                                          \
    }

#define CUBIC_HP_NO_PARSE(type)                                                         \
    case packet_id::type: {                                                             \
        auto *p = new (type);                                                           \
        assert(p);                                                                      \
        cli.inHighPriorityPackets.emplace_back(p_id | (int32_t) cli.state, (void *) p); \
        break;                                                                          \
    }

auto parse_client_packet(client::Client &cli, uint32_t bytes_read, int32_t p_id) -> bool
{
    const uint8_t *current_data = cli.inBuffer.data() + bytes_read;
    const uint32_t bytes_left = (uint32_t) cli.inBuffer.size() - bytes_read;
    uint32_t parsed = 0;

    switch (cli.state) {
    case client::Client::state::Handshaking: {
        using namespace cubic::protocol::c2s::handshake;
        switch ((packet_id) p_id) {
            CUBIC_HP_PARSE(Handshake);
        default:
            cli.isRunning = false;
            return false;
        }
        break;
    }
    case client::Client::state::Status: {
        using namespace cubic::protocol::c2s::status;
        switch ((packet_id) p_id) {
            CUBIC_HP_NO_PARSE(StatusRequest);
            CUBIC_HP_PARSE(PingRequest);
        default:
            cli.isRunning = false;
            return false;
        }
        break;
    }
    default:
        cli.isRunning = false;
        return false;
    }
    cli.inBuffer.erase(cli.inBuffer.begin(), cli.inBuffer.begin() + parsed + bytes_read);

    return true;
}

auto parse_client_packets(client::Client &cli) -> void
{
    while (true) {
        using namespace cubic::protocol::primitives;

        int32_t size;
        uint32_t parsed_size = varint::parse(
            cli.inBuffer.data(), (uint32_t) cli.inBuffer.size(), &size
        );
        if (parsed_size == 0) // Couldn't parse packet length
            return;
        if (size < 0 || size > CUBIC_MAX_PACKET_SIZE) {
            printf("Bad packet length %d from client %p on fd %d\n", size, &cli, cli.fd);
            cli.isRunning = false;
            return;
        }
        if ((uint32_t) size > (uint32_t) cli.inBuffer.size() - parsed_size) {
            printf(
                "aaaaa | size %d | parsed_size %d | inBuffer.size() %d\n", size, parsed_size,
                (int32_t) cli.inBuffer.size()
            );
            return;
        }
        int32_t packet_id;
        uint32_t parsed_id = varint::parse(
            cli.inBuffer.data() + parsed_size, (uint32_t) cli.inBuffer.size() - parsed_size,
            &packet_id
        );
        if (parsed_id == 0) {
            printf("bbbbb\n");
            return;
        }
        if (!parse_client_packet(cli, parsed_id + parsed_size, packet_id))
            return;
    }
}

auto parse_clients_packets(std::vector<std::unique_ptr<client::Client>> &clients) -> void
{
    for (auto &cli : clients)
        parse_client_packets(*cli);
}

auto launch_network_loop(ServerContext &ctx) -> void
{
    std::vector<pollfd> fds;

    for (;;) {
        init_fd_list(fds, ctx.clients, ctx.socket_fd);

        if (poll(fds.data(), fds.size(), -1) == -1) {
            perror("poll");
            break;
        }
        // Handle everything that poll gave us
        handle_clients_callbacks(ctx, fds);
        try_accept_new_client(ctx, fds);
        parse_clients_packets(ctx.clients);
        handle_high_priority_clients(ctx.clients);
        // Now we need to remove all the clients that disconnected or errored
        cleanup_client_list(ctx.clients);
    }
}
} // namespace

#ifdef UNIT_TESTS
#define MAIN definitely_not_main
#else
#define MAIN main
#endif

auto MAIN() -> int
{
    const int socket_fd = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto);
    if (socket_fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }
    if (setup_and_launch_socket(socket_fd))
        return EXIT_FAILURE;

    ServerContext ctx = {
        .socket_fd = socket_fd,
        .clients = {},
    };
    launch_network_loop(ctx);

    return EXIT_SUCCESS;
}
