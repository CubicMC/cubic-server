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

#include "typeSerialization.hpp"
#include "ServerPackets.hpp"
#include "ClientPackets.hpp"

#include "Logger.hpp"

Server::Server()
    : _config("config.yml")
{
    _host = _config.getNode("ip").as<std::string>();
    _port = _config.getNode("port").as<uint16_t>();
    _log = logging::Logger::get_instance();
    _log->debug("Server created with host: " + _host + " and port: " + std::to_string(_port));
}

Server::~Server()
{
    _log->debug("Server destroyed");
}

void Server::launch()
{
    // Get the socket for the server
    _sockfd = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto);

    // Create the addr for the server
    if (!inet_pton(AF_INET, _host.c_str(), &(_addr.sin_addr)))
    {
        throw std::runtime_error("Invalid host ip address");
    }
    _addr.sin_family = AF_INET;
    _addr.sin_port = htons(_port);

    // Bind server socket
    int optval = 1;
    setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    if (bind(_sockfd, reinterpret_cast<struct sockaddr *>(&_addr), sizeof(_addr)))
    {
        throw std::runtime_error(strerror(errno));
    }

    // Listen
    listen(_sockfd, SOMAXCONN);

//    auto acceptThread = std::thread(&Server::_acceptLoop, this);
    _acceptLoop();

//    _networkLoop();
}

//[[noreturn]] void Server::_networkLoop()
//{
//    while (true)
//    {
//        // This is only for test purposes
//        // TODO: Remove all that
////        using namespace std::chrono_literals;
////        std::this_thread::sleep_for(50ms); // TODO: Change it to proper ticking
//        for (const auto& i : _clients)
//            _handleClientPacket(i);
////        std::cout << "Server ticked" << std::endl;
//    }
//}

//void Server::_handleClientPacket(std::shared_ptr<Client> cli)
//{
//    auto &data = cli->get_recv_buffer();
//    while (true) {
//        // Get the length of the packet stored
//        auto buffer_length = data.size();
//        if (buffer_length == 0)
//            break;
//        uint8_t *at = data.data();
//        uint8_t *eof = at + buffer_length;
//        int32_t length = 0;
//        try {
//            length = protocol::popVarInt(at, eof);
//            if (length > eof - at + 1)
//                break; // Not enough data in buffer to parse the packet
//            if (length == 0) {
//                data.erase(data.begin());
//                continue;
//            }
//        } catch (const protocol::PacketEOF &_) {
//            break; // Not enough data in buffer to parse the length of the packet
//        }
//        const uint8_t *start_payload = at;
//        // Handle the packet if the length is there
//        const auto packet_id = static_cast<protocol::ServerPacketsID>(protocol::popVarInt(at, eof));
//        auto status = cli->getStatus();
//        std::function<std::shared_ptr<protocol::BaseServerPacket>(std::vector<uint8_t> &)> parser;
//        PARSER_IT_DECLARE(Initial);
//        PARSER_IT_DECLARE(Login);
//        PARSER_IT_DECLARE(Status);
//        PARSER_IT_DECLARE(Play);
//        switch (status) {
//        case protocol::ClientStatus::Initial:
//            GET_PARSER(Initial);
//        case protocol::ClientStatus::Login:
//            GET_PARSER(Login);
//        case protocol::ClientStatus::Status:
//            GET_PARSER(Status);
//        case protocol::ClientStatus::Play:
//            GET_PARSER(Play);
//        }
//        std::vector<uint8_t> to_parse(data.begin() + (at - data.data()), data.end());
//        auto packet = parser(to_parse);
//        // Callback to handle the packet
//        cli->handleParsedClientPacket(packet, packet_id);
//        data.erase(data.begin(), data.begin() + (start_payload - data.data()) + length);
//    }
//}

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
            struct sockaddr_in client_addr{};
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
