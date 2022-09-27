#ifndef F43D56DD_C750_470F_A7C9_27CE21D37FC3
#define F43D56DD_C750_470F_A7C9_27CE21D37FC3

#include <cstdint>
#include <string>
#include <vector>
#include <arpa/inet.h>
#include <memory>

#include "Client.hpp"
#include "ServerPackets.hpp"

#define PCK_CALLBACK(function, type) return this->function(cli, std::static_pointer_cast<type>(packet))

#define PARSER_IT_DECLARE(state) \
    std::unordered_map<protocol::ServerPacketsID, std::function<std::shared_ptr<protocol::BaseServerPacket>(std::vector<uint8_t> &)>>::const_iterator __##state

#define GET_PARSER(state) __##state = protocol::packetIDToParse##state.find(packet_id); \
    if (__##state == protocol::packetIDToParse##state.end()) \
        throw std::runtime_error("Unknown packet ID"); \
    parser = __##state->second;                                                                  \
    break

class Server
{
public:
    Server(const std::string &host, uint16_t port);
    ~Server();

    void launch();

private:
    void _acceptLoop();

    [[noreturn]] void _gameLoop();
    void _gameTick();
    void _handleClientPacket(std::shared_ptr<Client> cli);
    void _handleParsedClientPacket(std::shared_ptr<Client> cli,
                                   const std::shared_ptr<protocol::BaseServerPacket>& packet,
                                   protocol::ServerPacketsID packetID);

    const std::string &_host;
    const uint16_t _port;

    // Looks like it is thread-safe, if something breaks it is here
    std::vector<std::shared_ptr<Client>> _clients;

    int _sockfd;
    struct sockaddr_in _addr;

    // Packet handling (This will be moved somewhere later)

    void _onHandshake(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::Handshake>& pck);
    void _onStatusRequest(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::StatusRequest>& pck);
    void _onPingRequest(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PingRequest>& pck);
};

#endif /* F43D56DD_C750_470F_A7C9_27CE21D37FC3 */
