#ifndef CUBICSERVER_CLIENT_HPP
#define CUBICSERVER_CLIENT_HPP

#include <arpa/inet.h>
#include <memory>
#include <netinet/in.h>
#include <thread>
#include <vector>

#include "chat/Message.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/ServerPackets.hpp"
#include "protocol/common.hpp"

#define __PCK_CALLBACK_PRIM(type, object) return object->_on##type(std::static_pointer_cast<type>(packet))

#define PCK_CALLBACK(type) __PCK_CALLBACK_PRIM(type, this)

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
    "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEAAAABABAMAAABYR2ztAAAABGdBTUEAALGPC/"
    "xhBQAAAAFzUkdCAK7OHOkAAAAJcEhZcwAAAAEAAAABAE8lxNYAAAAYUExURaWmv5CMnJyZrDgtJiUhEbO21JhwbGxSSjIKCl4AAAROSURBVEjHVZXNaus6FEZlge44WwecqSRoz7jI1A9gQ6ei4HmTA844dbFe/"
    "64tpz33qiVpraVv/8vGmOLcspSUkjHGWpFgTIgi3sbEn7rYP4DFWRO9OzgfbArhG3H6Tyk8i8EtxQCgxLc9AGuSSU9FHwtSwVhsnEwpur/ww3nDaUki/XpFxagTnON3KUiiBRBjEL+udU3Slk9NoKiPmDXBJO/"
    "7baz12rax4Ra10AD+MvgQ120bxz2pRgpl+T9ArPFW8zbumPPeHMqHBTXBSulWWSMAPurRR5qWI9QUn/eVVX3CheAO4Nh3JWgye4DrWkWaE64pt/"
    "1AkgnD9jvE8400ItG8MAdl9IOEPJOFdd2piHjcCAeAvnloPa83gLvpxHvrMVKOXCwKqNba1odpUURNRYuOnQMwKwpXANOhICHF734wrn25528FS8N408XUMkw9ygEQBgo8jJoIzRdHW7a+41Unr7QReSDZBgVVT+"
    "pmeIKwakHbTHszhg4LizVPhnitsa6UuJKoS9sX2iidNEOWSFWB5rGiiaItG0BxaBm3PABDLaKoCe14D+BCiVH76Gl5X5akPSnPq0bhtZ/o6qcSvcoE9+60lCF6zcN120UrYQA6HMYVeqENTr9GAL/lemlz8eRQwP1oaAbvU7/"
    "tsd4u3ZbziEggLDwpyUTMWx/7Le9SV/9P1rUDGAoK4MzJJi/nLQ97T7f9ynnKebhTqc5HoJI8KvKHh+NeLwkLSrxGOcWmkqI/MRI8n4a91r7tT3mUKM0MRZFQ3gGGIdf9fMuHwui1YPS657YIiwIQte6Vb35y/"
    "tDO9kbUPpmQbRimqfYKtP185SSOekY9+"
    "mIJcsLwpaqSmsifqfnAMDAlTMQ2TdM89rsGMeDlcFWgzZx03Ec9AjjZNwVd050LpQGd9i8AQczjrX5pEFOe5xecBwih85psBYbM7aEeztMwT2SKVjP09olkAcz4hgICGuk8jSIuKRBPckqd+jAPb1UBxmeY5+"
    "FVnHUKBDlZgJkwJnyc3uhLgOmN587QOxTLJoBZcw2QAb70v/vpPbQGx4l4BpgPYADY2B/"
    "exB6AcSn9HlCdMYGdcV+1+Hm+6M2uwJLSWfdxnaNTboCWgypRqqAX4Jno51zrNk+Ar63oWacjai0Zot+bdgOJ1P153LRc+YNcMeE0fUn0Q13rbVRfmzEFPnU6HiY8V/Ct3urwAOb6F/"
    "A6Ntq0esv+APPDhL4Z2tyeFdjGv8A83a0cAIOTfLxRy68GvOnHul/"
    "00jftzuSFFDFCF4ztqAJXpikeQCep6Gz3PN9+DFwxG5sPTA7TT89IxbMfBwCooqDtQ3JOX3UKbD9p+IwKRO47z+w0hf7PfPhwAEmXKECqyGTohOP1AdAMaoLpTnpfURI59doS27fA8IKHzK95vCPlIv8FkHjRbY7K+"
    "az7fd8LLTE1gIIO0+txkH6584qq9/2+4+OhkJV5u7T1L0fvcTIRPlN2AAAAAElFTkSuQmCC";

class Player;

class Client {
    friend class Player;

public:
    Client(int sockfd, struct sockaddr_in6 addr);
    ~Client();

    void networkLoop();

    [[nodiscard]] bool isDisconnected() const;

    [[nodiscard]] protocol::ClientStatus getStatus() const { return _status; }

    void setStatus(protocol::ClientStatus status) { _status = status; }

    void switchToPlayState(u128 playerUuid, const std::string &username);

    void handleParsedClientPacket(const std::shared_ptr<protocol::BaseServerPacket> &packet, protocol::ServerPacketsID packetID);

    // All the send packets go here
    void sendStatusResponse(const std::string &json);
    void sendPingResponse(int64_t payload);
    void sendLoginSuccess(const protocol::LoginSuccess &packet);
    void sendLoginPlay(void);

    // Disconnect the client
    void disconnect(const chat::Message &reason = "Disconnected");

    // Stop the client (called by the server on shutdown)
    void stop(const chat::Message &reason = "Disconnected");

    std::shared_ptr<Player> getPlayer();
    const std::shared_ptr<Player> getPlayer() const;

private:
    void _handlePacket();
    void _flushSendData();
    void _tryFlushAllSendData();
    void _sendData(const std::vector<uint8_t> &data);
    void _onHandshake(const std::shared_ptr<protocol::Handshake> &pck);
    void _onStatusRequest(const std::shared_ptr<protocol::StatusRequest> &pck);
    void _onLoginStart(const std::shared_ptr<protocol::LoginStart> &pck);
    void _onPingRequest(const std::shared_ptr<protocol::PingRequest> &pck);
    void _onEncryptionResponse(const std::shared_ptr<protocol::EncryptionResponse> &pck);
    void _loginSequence(const protocol::LoginSuccess &packet);

    const int _sockfd;
    const struct sockaddr_in6 _addr;
    std::atomic<bool> _isRunning;
    protocol::ClientStatus _status;
    std::vector<uint8_t> _recvBuffer;
    std::vector<uint8_t> _sendBuffer;
    std::thread _networkThread;
    std::shared_ptr<Player> _player;
    std::mutex _writeMutex;
};

#endif // CUBICSERVER_CLIENT_HPP
