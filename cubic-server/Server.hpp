#ifndef F43D56DD_C750_470F_A7C9_27CE21D37FC3
#define F43D56DD_C750_470F_A7C9_27CE21D37FC3

#include <cstdint>
#include <string>
#include <vector>
#include <arpa/inet.h>
#include <memory>

#include "Client.hpp"
#include "ServerPackets.hpp"

#include "ConfigHandler.hpp"
#include "Logger.hpp"





class Server
{
public:
    Server();
    ~Server();

    void launch();

private:
    void _acceptLoop();

    [[noreturn]] void _networkLoop();
//    void _handleClientPacket(std::shared_ptr<Client> cli);
//    void _handleParsedClientPacket(std::shared_ptr<Client> cli,
//                                   const std::shared_ptr<protocol::BaseServerPacket>& packet,
//                                   protocol::ServerPacketsID packetID);

    std::string _host;
    uint16_t _port;
    logging::Logger *_log;

    // Looks like it is thread-safe, if something breaks it is here
    std::vector<std::shared_ptr<Client>> _clients;

    int _sockfd;
    struct sockaddr_in _addr;

    // Packet handling (This will be moved somewhere else later)


    Configuration::ConfigHandler _config;
};

#endif /* F43D56DD_C750_470F_A7C9_27CE21D37FC3 */
