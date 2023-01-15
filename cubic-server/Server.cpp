#include <iostream>
#include <netdb.h>
#include <cerrno>
#include <sys/socket.h>
#include <poll.h>
#include <thread>
#include <chrono>
#include <exception>
#include <cstring>
#include <algorithm>

#include <nlohmann/json.hpp>

#include "Server.hpp"

#include "protocol/typeSerialization.hpp"
#include "protocol/ServerPackets.hpp"
#include "protocol/ClientPackets.hpp"

#include "logging/Logger.hpp"
#include "WorldGroup.hpp"
#include "default/DefaultWorldGroup.hpp"

Server::Server()
    : _config()
{
    _config.parse("./config.yml");
    _host = _config.getIP();
    _port = _config.getPort();
    _maxPlayer = _config.getMaxPlayers();
    _motd = _config.getMotd();

    _log = logging::Logger::get_instance();
    LINFO("Server created with host: " + _host + " and port: " + std::to_string(_port));
}

Server::~Server()
{
    LDEBUG("Server destroyed");
}

void Server::launch()
{
    int yes = 1;
    int no = 0;

    // Get the socket for the server
    _sockfd = socket(AF_INET6, SOCK_STREAM, getprotobyname("TCP")->p_proto);

    // Create the addr for the server
    if (!inet_pton(AF_INET, _host.c_str(), &(_addr.sin6_addr)))
    {
        throw std::runtime_error("Invalid host ip address");
    }
    _addr.sin6_family = AF_INET6;
    _addr.sin6_port = htons(_port);

    // Bind server socket
    setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
    setsockopt(_sockfd, IPPROTO_IPV6, IPV6_V6ONLY, &no, sizeof(no));
    if (bind(_sockfd, reinterpret_cast<struct sockaddr *>(&_addr), sizeof(_addr)))
    {
        throw std::runtime_error(strerror(errno));
    }

    // Listen
    listen(_sockfd, SOMAXCONN);

    // Initialize default world group
    auto defaultChat = std::make_shared<Chat>();
    _worldGroups.emplace("default", new DefaultWorldGroup(defaultChat));
    _worldGroups.at("default")->initialize();

    // Run the default world group
    auto thread = new std::thread(&DefaultWorldGroup::run, _worldGroups.at("default"));
    _worldGroupThreads.emplace("default", thread);

//    auto acceptThread = std::thread(&Server::_acceptLoop, this);
    _acceptLoop();

//    _networkLoop();
}

void Server::_acceptLoop()
{
    struct pollfd poll_set[1];

    poll_set[0].fd = _sockfd;
    poll_set[0].events = POLLIN;
    while (true)
    {
        poll(poll_set, 1, 50);
        if (poll_set[0].revents & POLLIN)
        {
            struct sockaddr_in6 client_addr{};
            socklen_t client_addr_size = sizeof(client_addr);
            int client_fd = accept(
                _sockfd,
                reinterpret_cast<struct sockaddr *>(&client_addr),
                &client_addr_size);
            if (client_fd == -1)
            {
                throw std::runtime_error(strerror(errno));
            }
            // Add accepted client to the vector of clients
            auto cli = std::make_shared<Client>(client_fd, client_addr);
            _clients.push_back(cli);
            // That line is kinda borked, but I'll check one day how to fix it
            auto *cli_thread = new std::thread(&Client::networkLoop, &(*cli));
            // That is 99.99% a data race, but aight, it will probably
            // never happen
            cli->setRunningThread(cli_thread);

//            std::cout << "Client added to the list" << std::endl;
        }

        _clients.erase(std::remove_if(
                           _clients.begin(), _clients.end(),
                           [](const std::shared_ptr<Client> &cli)
                           { return cli->isDisconnected(); }),
                       _clients.end());
    }
}
