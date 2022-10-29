#ifndef D23DD5CC_1F28_49BB_B77D_E244C60CC705
#define D23DD5CC_1F28_49BB_B77D_E244C60CC705

#include <arpa/inet.h>
#include <thread>
#include <deque>
#include <vector>

#include "Player.hpp"
#include "common.hpp"
#include "ServerPackets.hpp"
#include "Logger.hpp"

#define __PCK_CALLBACK_PRIM(type, object) return object->_on##type(std::static_pointer_cast<type>(packet))

#define PCK_CALLBACK(type) __PCK_CALLBACK_PRIM(type, this)

#define __PCK_CALLBACK_PLAY(type) __PCK_CALLBACK_PRIM(type, _player)

#define PCK_CALLBACK_PLAY(type) case ServerPacketsID::type: __PCK_CALLBACK_PLAY(type)

#define PARSER_IT_DECLARE(state) \
    std::unordered_map<protocol::ServerPacketsID, std::function<std::shared_ptr<protocol::BaseServerPacket>(std::vector<uint8_t> &)>>::const_iterator __##state

#define GET_PARSER(state) __##state = protocol::packetIDToParse##state.find(packet_id); \
    if (__##state == protocol::packetIDToParse##state.end()) \
        throw std::runtime_error("Unhandled packet: " + std::to_string(static_cast<int>(packet_id)) + " in status " + std::to_string(static_cast<int>(_status))); \
    parser = __##state->second;                                                                  \
    break

#define DEFAULT_FAVICON "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEAAAABACAYAAACqaXHeAAABiElEQVR4Xu3ZvUoDQRTF8W0MIhLNfvQ2tnZbBBXEVhEtRBG08aMwla0gaiER7AWfQLDxBXwEH8BWK99iZS3PGYZh2Vk09xS/5sKd2fzTLElSFEVlWYIDaxQAB9YoAA6sUQAcWKMAOHBaWKqy9ZHf8hHvRZKXu3w/KBaHtOcSFKA+MHmqvHr3n7QXy8zlO92PBjtj2nNRABy4KIACKABdgBRAAYwHmHr4rtLNa69s9ZTORnm5R3to+vaD7kedBwhRf3N4Nuqfv9JeEwqgAApAZ7soAA5cFEABjAeof4GpH94n5OWkrQC98Rfdj7K1EZ3tEhQgRP2Ghg+K2grQP3uhvaYUAAdNKYACKAA9KFIABZjgANnwsJq9ePOaP3ikPZRu3dAeSjeuaK+p1gL8VwqAA2sUAAfWKAAOrFEAHMQ02L6jX25QyMtSmzoNMHfyTK+1qH7Tw72YFAAHMSmAAigAfWCkAAowwQHycv/3PzufbOWY9mLqNMBfpAA4sEYBcGCNAuDAGgXAgTU/fYHY6K4ZZygAAAAASUVORK5CYII\u003d"

class Player;

class Client
{
public:
    Client(int sockfd, struct sockaddr_in addr);
    ~Client();

    void networkLoop();

    void setRunningThread(std::thread *thread);
    std::thread *getRunningThread();

    [[nodiscard]] bool isDisconnected() const;


    std::vector<uint8_t> &get_recv_buffer();

    [[nodiscard]] protocol::ClientStatus getStatus() const {
        return _status;
    }

    void setStatus(protocol::ClientStatus status) {
        _status = status;
    }

    void switchToPlayState();

    void handleParsedClientPacket(const std::shared_ptr<protocol::BaseServerPacket>& packet,
                                  protocol::ServerPacketsID packetID);

    // All the send packets go here
    void sendStatusResponse(const std::string &json);
    void sendPingResponse(int64_t payload);

private:
    void _handlePacket();
    void _flushSendData();
    void _sendData(const std::vector<uint8_t> &data);
    void _onHandshake(const std::shared_ptr<protocol::Handshake>& pck);
    void _onStatusRequest(const std::shared_ptr<protocol::StatusRequest>& pck);
    void _onLoginStart(const std::shared_ptr<protocol::LoginStart> &pck);
    void _onPingRequest(const std::shared_ptr<protocol::PingRequest>& pck);
    void _onEncryptionResponse(const std::shared_ptr<protocol::EncryptionResponse> &pck);

    const int _sockfd;
    const struct sockaddr_in _addr;
    bool _is_running;
    std::thread *_current_thread{};
    std::vector<uint8_t> _recv_buffer;
    std::vector<uint8_t> _send_buffer;
    protocol::ClientStatus _status;
    Player *_player;
    logging::Logger *_log;
};

#endif /* D23DD5CC_1F28_49BB_B77D_E244C60CC705 */
