#ifndef D23DD5CC_1F28_49BB_B77D_E244C60CC705
#define D23DD5CC_1F28_49BB_B77D_E244C60CC705

#include <arpa/inet.h>
#include <thread>
#include <deque>
#include <vector>

#include "Player.hpp"
#include "protocol/ClientPackets.hpp"
#include "Chat.hpp"
#include "protocol/common.hpp"
#include "protocol/ServerPackets.hpp"
#include "logging/Logger.hpp"

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

#define DEFAULT_FAVICON "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEAAAABABAMAAABYR2ztAAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAK7OHOkAAAAJcEhZcwAAAAEAAAABAE8lxNYAAAAYUExURaWmv5CMnJyZrDgtJiUhEbO21JhwbGxSSjIKCl4AAAROSURBVEjHVZXNaus6FEZlge44WwecqSRoz7jI1A9gQ6ei4HmTA844dbFe/64tpz33qiVpraVv/8vGmOLcspSUkjHGWpFgTIgi3sbEn7rYP4DFWRO9OzgfbArhG3H6Tyk8i8EtxQCgxLc9AGuSSU9FHwtSwVhsnEwpur/ww3nDaUki/XpFxagTnON3KUiiBRBjEL+udU3Slk9NoKiPmDXBJO/7baz12rax4Ra10AD+MvgQ120bxz2pRgpl+T9ArPFW8zbumPPeHMqHBTXBSulWWSMAPurRR5qWI9QUn/eVVX3CheAO4Nh3JWgye4DrWkWaE64pt/1AkgnD9jvE8400ItG8MAdl9IOEPJOFdd2piHjcCAeAvnloPa83gLvpxHvrMVKOXCwKqNba1odpUURNRYuOnQMwKwpXANOhICHF734wrn25528FS8N408XUMkw9ygEQBgo8jJoIzRdHW7a+41Unr7QReSDZBgVVT+pmeIKwakHbTHszhg4LizVPhnitsa6UuJKoS9sX2iidNEOWSFWB5rGiiaItG0BxaBm3PABDLaKoCe14D+BCiVH76Gl5X5akPSnPq0bhtZ/o6qcSvcoE9+60lCF6zcN120UrYQA6HMYVeqENTr9GAL/lemlz8eRQwP1oaAbvU7/tsd4u3ZbziEggLDwpyUTMWx/7Le9SV/9P1rUDGAoK4MzJJi/nLQ97T7f9ynnKebhTqc5HoJI8KvKHh+NeLwkLSrxGOcWmkqI/MRI8n4a91r7tT3mUKM0MRZFQ3gGGIdf9fMuHwui1YPS657YIiwIQte6Vb35y/tDO9kbUPpmQbRimqfYKtP185SSOekY9+mIJcsLwpaqSmsifqfnAMDAlTMQ2TdM89rsGMeDlcFWgzZx03Ec9AjjZNwVd050LpQGd9i8AQczjrX5pEFOe5xecBwih85psBYbM7aEeztMwT2SKVjP09olkAcz4hgICGuk8jSIuKRBPckqd+jAPb1UBxmeY5+FVnHUKBDlZgJkwJnyc3uhLgOmN587QOxTLJoBZcw2QAb70v/vpPbQGx4l4BpgPYADY2B/exB6AcSn9HlCdMYGdcV+1+Hm+6M2uwJLSWfdxnaNTboCWgypRqqAX4Jno51zrNk+Ar63oWacjai0Zot+bdgOJ1P153LRc+YNcMeE0fUn0Q13rbVRfmzEFPnU6HiY8V/Ct3urwAOb6F/A6Ntq0esv+APPDhL4Z2tyeFdjGv8A83a0cAIOTfLxRy68GvOnHul/00jftzuSFFDFCF4ztqAJXpikeQCep6Gz3PN9+DFwxG5sPTA7TT89IxbMfBwCooqDtQ3JOX3UKbD9p+IwKRO47z+w0hf7PfPhwAEmXKECqyGTohOP1AdAMaoLpTnpfURI59doS27fA8IKHzK95vCPlIv8FkHjRbY7K+az7fd8LLTE1gIIO0+txkH6584qq9/2+4+OhkJV5u7T1L0fvcTIRPlN2AAAAAElFTkSuQmCC"

class Player;

class Client
{
public:
    Client(int sockfd, struct sockaddr_in6 addr);
    ~Client();

    void networkLoop();

    void setRunningThread(std::thread *thread);
    std::thread *getRunningThread();

    [[nodiscard]] bool isDisconnected() const;

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
    // Should I just pass the packet directly?
    void sendChatMessageResponse(const protocol::PlayerChatMessage &packet);
    void sendDisconnectPlayerReason(const std::string &reason);

private:
    void _handlePacket();
    void _flushSendData();
    void _sendData(const std::vector<uint8_t> &data);
    void _onHandshake(const std::shared_ptr<protocol::Handshake>& pck);
    void _onStatusRequest(const std::shared_ptr<protocol::StatusRequest>& pck);
    void _onLoginStart(const std::shared_ptr<protocol::LoginStart> &pck);
    void _onPingRequest(const std::shared_ptr<protocol::PingRequest>& pck);
    void _onEncryptionResponse(const std::shared_ptr<protocol::EncryptionResponse> &pck);
    void _onDisconnectRequest(const std::shared_ptr<protocol::DisconnectReason> &pck, chat::Message &message);

    const int _sockfd;
    const struct sockaddr_in6 _addr;
    bool _is_running;
    std::thread *_current_thread{};
    std::vector<uint8_t> _recv_buffer;
    std::vector<uint8_t> _send_buffer;
    protocol::ClientStatus _status;
    Player *_player;
    logging::Logger *_log;
};

#endif /* D23DD5CC_1F28_49BB_B77D_E244C60CC705 */
