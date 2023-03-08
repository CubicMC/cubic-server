#include <iostream>
#include <netdb.h>
#include <cerrno>
#include <sys/socket.h>
#include <poll.h>
#include <chrono>
#include <exception>
#include <cstring>
#include <algorithm>

#include <curl/curl.h>

#include <nlohmann/json.hpp>

#include "Server.hpp"

#include "protocol/typeSerialization.hpp"
#include "protocol/ServerPackets.hpp"
#include "protocol/ClientPackets.hpp"

#include "logging/Logger.hpp"
#include "WorldGroup.hpp"
#include "default/DefaultWorldGroup.hpp"

Server::Server():
    _sockfd(-1),
    _config(),
    _running(true)
{
    _config.parse("./config.yml");
    _host = _config.getIP();
    _port = _config.getPort();
    _maxPlayer = _config.getMaxPlayers();
    _motd = _config.getMotd();
    _enforceWhitelist = _config.getEnforceWhitelist();

    LINFO("Server created with host: ", _host, " and port: ", _port);
}

Server::~Server()
{

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
        throw std::runtime_error(strerror(errno));

    // Listen
    listen(_sockfd, SOMAXCONN);

    _downloadFile(std::string("https://cdn.cubic-mc.com/") + MC_VERSION + "/blocks.json", "blocks.json");
    _downloadFile(std::string("https://cdn.cubic-mc.com/") + MC_VERSION + "/registries.json", "registries.json");

    // Initialize the global palette
    _globalPalette.initialize();
    LINFO("GlobalPalette initialized");

    // Initialize default world group
    auto defaultChat = std::make_shared<Chat>();
    _worldGroups.emplace("default", new DefaultWorldGroup(defaultChat));
    _worldGroups.at("default")->initialize();

    _acceptLoop();

    this->_stop();
}

void Server::stop()
{
    this->_running = false;
}

void Server::_acceptLoop()
{
    struct pollfd poll_set[1];

    poll_set[0].fd = _sockfd;
    poll_set[0].events = POLLIN;
    while (this->_running) {
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
            // auto cli = std::make_shared<Client>(client_fd, client_addr);
            // _clients.push_back(cli);
            _clients.push_back(std::make_shared<Client>(client_fd, client_addr));

            // Emplace_back is not working, I don't know why
            // _clients.emplace_back(client_fd, client_addr);

            // That line is kinda borked, but I'll check one day how to fix it
            // auto *cli_thread = new std::thread(&Client::networkLoop, &(*cli));
            // That is 99.99% a data race, but aight, it will probably
            // never happen
            // cli->setRunningThread(cli_thread);
        }

        _clients.erase(
            std::remove_if(
                _clients.begin(),
                _clients.end(),
                [](const std::shared_ptr<Client> &cli){ return cli->isDisconnected(); }
            ),
            _clients.end()
        );
    }
}

void Server::_stop()
{
    //Disconect all clients
    for (auto &client : _clients)
        client->stop("Server Closed");

    // Needed because the client will not be destroyed if a reference still exists
    this->_clients.clear();

    for (auto &[name, worldGroup] : _worldGroups) {
        worldGroup->stop();
        delete worldGroup;
    }
    if (this->_sockfd != -1)
        close(this->_sockfd);
    for (auto &command : _commands)
        delete command;
    LINFO("Server stopped");
}

void Server::_downloadFile(const std::string &url, const std::string &path)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(path.c_str(),"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        // curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}
