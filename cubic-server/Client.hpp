#ifndef CUBICSERVER_CLIENT_HPP
#define CUBICSERVER_CLIENT_HPP

#include <arpa/inet.h>
#include <boost/asio.hpp>
#include <memory>
#include <netinet/in.h>
#include <thread>
#include <vector>

#include "EASEncryptionHandler.hpp"
#include "chat/Message.hpp"
#include "options.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/ServerPackets.hpp"
#include "protocol/common.hpp"
#include "types.hpp"
#include <boost/circular_buffer.hpp>
#include <boost/container/deque.hpp>

#define __PCK_CALLBACK_PRIM(type, object) return object->_on##type(*(type *) packet.get())

#define PCK_CALLBACK(type) __PCK_CALLBACK_PRIM(type, this)

#define __PCK_CALLBACK_EMPTY_PRIM(type, object) return object->_on##type()

#define PCK_CALLBACK_EMPTY(type) __PCK_CALLBACK_EMPTY_PRIM(type, this)

#define __PCK_CALLBACK_PLAY(type) __PCK_CALLBACK_PRIM(type, _player)

#define PCK_CALLBACK_PLAY(type) \
    case ServerPacketsID::type: \
        __PCK_CALLBACK_PLAY(type)

#define PARSER_IT_DECLARE(state) \
    std::unordered_map<protocol::ServerPacketsID, std::function<std::unique_ptr<protocol::BaseServerPacket>(std::vector<uint8_t> &)>>::const_iterator __##state

#define GET_PARSER(state)                                        \
    __##state = protocol::packetIDToParse##state.find(packetId); \
    if (__##state == protocol::packetIDToParse##state.end()) {   \
        error = true;                                            \
        break;                                                   \
    }                                                            \
    parser = __##state->second;                                  \
    break

constexpr const char DEFAULT_FAVICON[] =
    "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEAAAABABAMAAABYR2ztAAAAGFBMVEUStBFePiFHcEyPYTlEaCGolm4XIwsoemIehfltAAAABnRSTlP9/QD7c/"
    "h561WQAAACPUlEQVRIx32VTXPbIBCGtx0XX02pdU5T/QG6Vs4J8aTXto4mVzTKoKsPjf33u4s+EEiY0chj3od3dwEB3Mft17ekA+K/ZeHMLYD0S2fyAOnUGpMDyhfWhXs3GeCJdde5y/"
    "s6MOrCun+rwMuFZQoRWcwB17fOugwgBsLZ2w5CZENMFlkHGmxtNofSTc2sT9SRCqRHuGNuLYY0N9m1AJqEwlnIrEUJFrqPtx0ArOZQAgjxpa5/Q0QEgGQQWw98go1ZAI88EOzHm/+FTQo8WlKtFVuAmIBx/"
    "M7uIGqbOXBHw9mBn6l9DkDpw/fd10CYCbjrE7S0VldqZ6BntJiALVy77hraErhG7RwB32n+Y4J04b7OACaS8S4GYsLrzc8A8DcJgfD6AggEcAIR8MMDbkj03Out+psCPTHoDeIS4GJH/"
    "YRqEcITvU4GOslBToTXpUyrkHIohd9S6bhM6sNCsonlAEoznYRQsuBeBlrt4yUhtNKKPBhQulgBpEKpsWgY6ItKclCKDFBzInooOl5NSRqiVjocAsk8SA4iR4DCtPFUo3eQsgfaunDNEtCo8Y8H9qeHxTxon6QHGqz0csMo7+"
    "FDVPWpWAK0AVSfJCJyhwxllk+eYA/Ubl97XR3Cp3df4uhB61RXD/ynMvPPv/TVSQpC/trDJj5ASr8duNJYD0fQsfdQiT47xJ79JlDo369r5+Qzj235tT+sn7Ts0RAgD7mjmAgC1CF/"
    "sdLO1W1lblzNWmFlbl7uiDcvd1r516TjPwaZkJJGXel5AAAAAElFTkSuQmCC";

constexpr auto _readBufferSize = 2048;

class Player;

class Client : public std::enable_shared_from_this<Client> {
    friend class Player;

public:
    Client(boost::asio::ip::tcp::socket &&socket, size_t clientID);
    ~Client();

    void run();
    void doRead();
    void doWrite(std::unique_ptr<std::vector<uint8_t>> &&data);
    NODISCARD inline std::thread &getThread() { return _thread; };

    NODISCARD bool isDisconnected() const;
    NODISCARD protocol::ClientStatus getStatus() const { return _status; }

    void setStatus(protocol::ClientStatus status) { _status = status; }
    void switchToPlayState(u128 playerUuid, const std::string &username);
    void handleParsedClientPacket(std::unique_ptr<protocol::BaseServerPacket> &&packet, protocol::ServerPacketsID packetID);

    // All the send packets go here
    void sendStatusResponse(const std::string &json);
    void sendPingResponse(int64_t payload);
    void sendLoginSuccess(const protocol::LoginSuccess &packet);
    void sendLoginPlay(void);
    void sendEncryptionRequest(void);
    void sendSetCompression();

    // Disconnect the client
    void disconnect(const chat::Message &reason = "Disconnected");

    std::shared_ptr<Player> getPlayer();
    std::shared_ptr<const Player> getPlayer() const;
    inline size_t getID() const { return _clientID; };
    inline boost::asio::ip::tcp::socket &getSocket() { return _socket; }

private:
    void _handlePacket();
    void _flushSendData();
    void _tryFlushAllSendData();
    // void _sendData(std::vector<uint8_t> &data);
    void _onHandshake(protocol::Handshake &pck);
    void _onStatusRequest();
    void _onLoginStart(protocol::LoginStart &pck);
    void _onPingRequest(protocol::PingRequest &pck);
    void _onEncryptionResponse(protocol::EncryptionResponse &pck);
    void _loginSequence(const protocol::LoginSuccess &packet);
    bool _handleOnline(const std::array<uint8_t, 16> &key);
    NODISCARD inline const std::vector<protocol::PlayerProperty> &getProperties() const { return _resPck.properties; }
    NODISCARD inline bool isCompressed() const { return _isCompressed; }

private:
    std::atomic<bool> _isRunning;
    protocol::ClientStatus _status;
    std::vector<uint8_t> _recvBuffer;
    char _readBuffer[_readBufferSize];
    // boost::circular_buffer_space_optimized<uint8_t> _sendBuffer;
    boost::circular_buffer<uint8_t> _sendBuffer;
    std::shared_ptr<Player> _player;
    std::mutex _writeMutex;
    boost::asio::ip::tcp::socket _socket;
    // boost::lockfree::queue<uint8_t> _toSend;
    boost::container::deque<std::unique_ptr<uint8_t>> _toSend;
    const size_t _clientID;
    std::thread _thread;
    bool _isEncrypted;
    EASEncryptionHandler _encryption;
    protocol::LoginSuccess _resPck;
    bool _isCompressed;
};

#endif // CUBICSERVER_CLIENT_HPP
