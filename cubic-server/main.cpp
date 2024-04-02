#include <array>
#include <cstdint>
#include <iostream>
#include <netdb.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

#define TIMEOUT 5

class Client {
public:
    int fd;
    bool isRunning;
    std::vector<uint8_t> inBuffer;
    // TODO: Out buffer

    Client(int fd, bool is_running)
    {
        this->fd = fd;
        this->isRunning = is_running;
    }
};

namespace {
auto init_fd_list(std::vector<pollfd> &fds, std::vector<Client> &clients, int server_fd) -> void
{
    fds.push_back({ .fd = server_fd, .events = POLLIN });

    for (auto &cli : clients) {
        if (cli.isRunning) {
            fds.push_back({ .fd = cli.fd, .events = POLLIN });
        }
    }
}
} // namespace

auto main() -> int
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto);

    if (socket_fd == -1) {
        perror("socket");
        return 1;
    }

    const uint16_t port = 25565;
    sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr = {
            .s_addr = htonl(INADDR_ANY),
        },
    };
    int some_l_value = 1;
    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &some_l_value, sizeof(int));
    if (bind(socket_fd, (struct sockaddr *) &addr, sizeof addr) == -1) {
        perror("bind");
        return 1;
    }
    listen(socket_fd, 0);

    std::vector<Client> clients;
    std::array<uint8_t, 1024> in_buffer;

    for (;;) {
        std::vector<pollfd> fds;
        init_fd_list(fds, clients, socket_fd);

        if (poll(fds.data(), fds.size(), -1) == -1) {
            perror("poll");
            break;
        }
        if ((fds[0].revents & POLLIN) != 0) {
            int cli_fd = accept(socket_fd, nullptr, nullptr);
            if (cli_fd != -1)
                clients.emplace_back(cli_fd, true);
            else
                perror("accept");
        }

        for (size_t i = 1; i < fds.size(); i++) {
            if ((fds[i].revents & POLLIN) != 0) {
                // TODO: Read properly from client
                int ret = read(fds[i].fd, in_buffer.data(), 1024);
                if (ret == 0) {
                    for (auto &cli : clients) {
                        if (cli.fd == fds[i].fd)
                            cli.isRunning = false;
                    }
                }
            }
            if ((fds[i].revents & POLLHUP) != 0) {
                // TODO: Handle client close
            }
        }
    }
    return 0;
}
