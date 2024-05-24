#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <memory>
#include <mutex>
#include <netdb.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

class Client {
public:
    int fd;
    bool isRunning = true;
    std::vector<uint8_t> inBuffer;
    std::vector<uint8_t> outBuffer;
    mutable std::mutex inBufferMutex{};
    mutable std::mutex outBufferMutex{};

    Client(int client_fd):
        fd(client_fd)
    {
    }
};

struct ServerContext {
    int socket_fd;
    std::vector<std::unique_ptr<Client>> clients;
};

namespace {
// TODO: Check that this is good values
constexpr size_t CSMC_MAX_NETWORK_READ_SIZE = 2048;
constexpr size_t CSMC_MAX_NETWORK_WRITE_SIZE = 2048;

auto init_fd_list(
    std::vector<pollfd> &fds, std::vector<std::unique_ptr<Client>> &clients, int server_fd
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

auto cleanup_client_list(std::vector<std::unique_ptr<Client>> &clients) -> void
{
    // Remove all the clients that are currently not running
    clients.erase(
        std::remove_if(
            clients.begin(), clients.end(),
            [](std::unique_ptr<Client> &cli) { return !cli->isRunning; }
        ),
        clients.end()
    );
}

auto get_client_from_fd(int fd, std::vector<std::unique_ptr<Client>> &clients) -> Client *
{
    for (auto &cli : clients)
        if (cli->fd == fd)
            return cli.get();
    return nullptr;
}

auto disconnect_client(Client &cli) -> bool
{
    const bool was_running = cli.isRunning;
    cli.isRunning = false;
    if (was_running)
        close(cli.fd);
    return !was_running;
}

auto disconnect_client_from_fd(int fd, std::vector<std::unique_ptr<Client>> &clients) -> bool
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
            ctx.clients.emplace_back(std::make_unique<Client>(cli_fd));
        else
            perror("accept");
    }
}

auto add_to_client_buffer(
    Client &cli, std::array<uint8_t, CSMC_MAX_NETWORK_READ_SIZE> &read_buffer, ssize_t num_bytes
)
{
    {
        const std::unique_lock<std::mutex> _(cli.inBufferMutex);

        cli.inBuffer.insert(cli.inBuffer.end(), read_buffer.data(), read_buffer.data() + num_bytes);
    }
    // TODO: Remove that when proper logging is implemented
    printf("Got %lu bytes from client %p on fd %d\n", num_bytes, &cli, cli.fd);
}

auto handle_high_priority_clients(std::vector<std::unique_ptr<Client>> &clients) -> void
{
    // For now all the clients are high priority
    // TODO: Change that :3

    for (auto &cli : clients) {
        if (cli->inBuffer.empty())
            continue;
        {
            std::unique_lock<std::mutex> a(cli->inBufferMutex, std::defer_lock);
            std::unique_lock<std::mutex> b(cli->outBufferMutex, std::defer_lock);
            std::lock(a, b);

            // TODO: Obviously change that later :3
            cli->outBuffer.insert(cli->outBuffer.end(), cli->inBuffer.begin(), cli->inBuffer.end());
            cli->inBuffer.clear();
        }
    }
}

auto handle_clients_callbacks(ServerContext &ctx, std::vector<pollfd> &fds) -> void
{
    // No need to recreate that whole buffer everytime so you I just make it static
    static std::array<uint8_t, CSMC_MAX_NETWORK_READ_SIZE> in_buffer;

    for (size_t i = 1; i < fds.size(); i++) {
        if ((fds[i].revents & POLLIN) != 0) {
            const ssize_t num_bytes_read = read(fds[i].fd, in_buffer.data(), 1024);
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
            {
                const std::unique_lock<std::mutex> _(cli->outBufferMutex);

                num_bytes_written = write(
                    fds[i].fd, cli->outBuffer.data(),
                    std::min(cli->outBuffer.size(), CSMC_MAX_NETWORK_WRITE_SIZE)
                );
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
        handle_high_priority_clients(ctx.clients);
        // Now we need to remove all the clients that disconnected or errored
        cleanup_client_list(ctx.clients);
    }
}
} // namespace

auto main() -> int
{
    const int socket_fd = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto);
    if (socket_fd == -1) {
        perror("socket");
        return 1;
    }
    if (setup_and_launch_socket(socket_fd))
        return 1;

    ServerContext ctx = {
        .socket_fd = socket_fd,
        .clients = {},
    };
    launch_network_loop(ctx);

    return 0;
}
