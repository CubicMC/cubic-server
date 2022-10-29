#include <iostream>
#include <unistd.h>
#include <poll.h>
#include <cstring>
#include <memory>

#include "Client.hpp"
#include "ServerPackets.hpp"
#include "nlohmann/json.hpp"
#include "ClientPackets.hpp"
#include "Server.hpp"

Client::Client(int sockfd, struct sockaddr_in addr)
    : _sockfd(sockfd), _addr(addr), _status(protocol::ClientStatus::Initial)
{
    _is_running = true;
    _log = logging::Logger::get_instance();
}

Client::~Client()
{
}

void Client::networkLoop()
{
    struct pollfd poll_set[1];
    uint8_t in_buffer[2048];

    poll_set[0].fd = _sockfd;
    while (1)
    {
        poll_set[0].events = POLLIN;
        if (!_send_buffer.empty())
            poll_set[0].events |= POLLOUT;
        poll(poll_set, 1, 50); // TODO: Check how this can be changed
        if (poll_set[0].revents & POLLIN)
        {
            int read_size = read(_sockfd, in_buffer, 2048);
            if (read_size == -1)
                std::cerr << "Read error: " << strerror(errno) << std::endl;
            else if (read_size == 0)
                break;
            else
            {
                // This is extremely inefficient but it will do for now
                for (int i = 0; i < read_size; i++)
                    _recv_buffer.push_back(in_buffer[i]);
                _handlePacket();
            }
        }
        if (poll_set[0].revents & POLLOUT)
        {
            _flushSendData();
        }
    }
    _is_running = false;
}

std::thread *Client::getRunningThread()
{
    return _current_thread;
}

void Client::setRunningThread(std::thread *thread)
{
    _current_thread = thread;
}

bool Client::isDisconnected() const
{
    return !_is_running;
}

void Client::_sendData(const std::vector<uint8_t> &data)
{
    // This is extremely inefficient but it will do for now
    for (const auto i : data)
        _send_buffer.push_back(i);
}

void Client::_flushSendData()
{
    char send_buffer[2048];
    size_t to_send = std::min(_send_buffer.size(), (size_t)2048);
    std::copy(_send_buffer.begin(), _send_buffer.begin() + to_send, send_buffer);

    ssize_t write_return = write(_sockfd, send_buffer, to_send);
    if (write_return == -1)
        std::cerr << "Write error: " << strerror(errno) << std::endl;

    if (write_return <= 0)
        return;

    _send_buffer.erase(_send_buffer.begin(), _send_buffer.begin() + write_return);
}

std::vector<uint8_t> &Client::get_recv_buffer()
{
    return _recv_buffer;
}

void Client::switchToPlayState()
{
    this->setStatus(protocol::ClientStatus::Play);
    this->_player = new Player(this);
}

void Client::handleParsedClientPacket(const std::shared_ptr<protocol::BaseServerPacket> &packet,
                                      protocol::ServerPacketsID packetID)
{
    using namespace protocol;

    switch (_status) {
    case ClientStatus::Initial:
        switch (packetID) {
        case ServerPacketsID::Handshake:
            PCK_CALLBACK(Handshake);
        default:
            break;
        }
        break;
    case ClientStatus::Status:
        switch (packetID) {
        case ServerPacketsID::StatusRequest:
            PCK_CALLBACK(StatusRequest);
        case ServerPacketsID::PingRequest:
            PCK_CALLBACK(PingRequest);
        default:
            break;
        }
        break;
    case ClientStatus::Login:
        switch (packetID) {
        case ServerPacketsID::LoginStart:
            PCK_CALLBACK(LoginStart);
        case ServerPacketsID::EncryptionResponse:
            PCK_CALLBACK(EncryptionResponse);
        default:
            break;
        }
        break;
    case ClientStatus::Play:
        switch (packetID) {
            PCK_CALLBACK_PLAY(ConfirmTeleportation);
            PCK_CALLBACK_PLAY(QueryBlockEntityTag);
            PCK_CALLBACK_PLAY(ChangeDifficulty);
            PCK_CALLBACK_PLAY(ClientCommand);
            PCK_CALLBACK_PLAY(ClientInformation);
            PCK_CALLBACK_PLAY(CommandSuggestionRequest);
            PCK_CALLBACK_PLAY(ClickContainerButton);
            PCK_CALLBACK_PLAY(CloseContainerRequest);
            PCK_CALLBACK_PLAY(EditBook);
            PCK_CALLBACK_PLAY(QueryEntityTag);
            PCK_CALLBACK_PLAY(Interact);
            PCK_CALLBACK_PLAY(JigsawGenerate);
            PCK_CALLBACK_PLAY(KeepAliveResponse);
            PCK_CALLBACK_PLAY(LockDifficulty);
            PCK_CALLBACK_PLAY(SetPlayerPosition);
            PCK_CALLBACK_PLAY(SetPlayerPositionAndRotation);
            PCK_CALLBACK_PLAY(SetPlayerRotation);
            PCK_CALLBACK_PLAY(SetPlayerOnGround);
            PCK_CALLBACK_PLAY(MoveVehicle);
            PCK_CALLBACK_PLAY(PaddleBoat);
            PCK_CALLBACK_PLAY(PickItem);
            PCK_CALLBACK_PLAY(PlaceRecipe);
            PCK_CALLBACK_PLAY(PlayerAbilities);
            PCK_CALLBACK_PLAY(PlayerAction);
            PCK_CALLBACK_PLAY(PlayerCommand);
            PCK_CALLBACK_PLAY(PlayerInput);
            PCK_CALLBACK_PLAY(Pong);
            PCK_CALLBACK_PLAY(ChangeRecipeBookSettings);
            PCK_CALLBACK_PLAY(SetSeenRecipe);
            PCK_CALLBACK_PLAY(RenameItem);
            PCK_CALLBACK_PLAY(ResourcePack);
            PCK_CALLBACK_PLAY(SeenAdvancements);
            PCK_CALLBACK_PLAY(SelectTrade);
            PCK_CALLBACK_PLAY(SetBeaconEffect);
            PCK_CALLBACK_PLAY(SetHeldItem);
            PCK_CALLBACK_PLAY(ProgramCommandBlock);
            PCK_CALLBACK_PLAY(ProgramCommandBlockMinecart);
            PCK_CALLBACK_PLAY(ProgramJigsawBlock);
            PCK_CALLBACK_PLAY(ProgramStructureBlock);
            PCK_CALLBACK_PLAY(UpdateSign);
            PCK_CALLBACK_PLAY(SwingArm);
            PCK_CALLBACK_PLAY(TeleportToEntity);
            PCK_CALLBACK_PLAY(UseItemOn);
            PCK_CALLBACK_PLAY(UseItem);
        default:
            break;
        }
        break;
    }
    _log->error("Unhandled packet: " + std::to_string(static_cast<int>(packetID)) +
                " in status " + std::to_string(static_cast<int>(_status))); // TODO: Properly handle the unknown packet
}

void Client::_handlePacket()
{
    auto &data = _recv_buffer;
    while (true) {
        // Get the length of the packet stored
        auto buffer_length = data.size();
        if (buffer_length == 0)
            break;
        uint8_t *at = data.data();
        uint8_t *eof = at + buffer_length;
        int32_t length = 0;
        try {
            length = protocol::popVarInt(at, eof);
            if (length > eof - at + 1)
                break; // Not enough data in buffer to parse the packet
            if (length == 0) {
                data.erase(data.begin());
                continue;
            }
        } catch (const protocol::PacketEOF &_) {
            break; // Not enough data in buffer to parse the length of the packet
        }
        const uint8_t *start_payload = at;
        // Handle the packet if the length is there
        const auto packet_id = static_cast<protocol::ServerPacketsID>(protocol::popVarInt(at, eof));
        std::function<std::shared_ptr<protocol::BaseServerPacket>(std::vector<uint8_t> &)> parser;
        PARSER_IT_DECLARE(Initial);
        PARSER_IT_DECLARE(Login);
        PARSER_IT_DECLARE(Status);
        PARSER_IT_DECLARE(Play);
        switch (_status) {
        case protocol::ClientStatus::Initial:
            GET_PARSER(Initial);
        case protocol::ClientStatus::Login:
            GET_PARSER(Login);
        case protocol::ClientStatus::Status:
            GET_PARSER(Status);
        case protocol::ClientStatus::Play:
            GET_PARSER(Play);
        }
        std::vector<uint8_t> to_parse(data.begin() + (at - data.data()), data.end());
        auto packet = parser(to_parse);
        // Callback to handle the packet
        handleParsedClientPacket(packet, packet_id);
        data.erase(data.begin(), data.begin() + (start_payload - data.data()) + length);
    }
}

void Client::_onHandshake(const std::shared_ptr<protocol::Handshake>& pck)
{
    _log->debug("Got an handshake");
    if (pck->next_state == 1)
        this->setStatus(protocol::ClientStatus::Status);
    else if (pck->next_state == 2)
        this->setStatus(protocol::ClientStatus::Login);
}

void Client::_onStatusRequest(const std::shared_ptr<protocol::StatusRequest> &pck)
{
    LDEBUG("Got a status request");

    auto srv = Server::getInstance();
    auto conf = srv->getConfig();

    // TODO: Fix this
    nlohmann::json json;
    json["version"]["name"] = MC_VERSION;
    json["version"]["protocol"] = MC_PROTOCOL;
    json["players"]["max"] = conf.getMaxPlayers();
    json["players"]["online"] = 0; // std::count_if(_clients.begin(), _clients.end(), [](std::shared_ptr<Client> &each) { return each->getStatus() == protocol::ClientStatus::Play; });
    json["description"]["text"] = conf.getMotd();
    json["favicon"] = DEFAULT_FAVICON; // TODO: Understand how this works, cause right now it is witchcraft
    json["previewsChat"] = false;
    json["enforcesSecureChat"] = false;

    sendStatusResponse(json.dump());
}

void Client::_onPingRequest(const std::shared_ptr<protocol::PingRequest> &pck)
{
    LDEBUG("Got a ping request");

    sendPingResponse(pck->payload);
}

void Client::_onLoginStart(const std::shared_ptr<protocol::LoginStart> &pck)
{
    LDEBUG("Got a Login Start");
}

void Client::_onEncryptionResponse(const std::shared_ptr<protocol::EncryptionResponse> &pck)
{
    _log->debug("Got a Encryption Response");
}

void Client::sendStatusResponse(const std::string &json)
{
    auto pck = protocol::createStatusResponse({
        json
    });
    _sendData(*pck);

    LDEBUG("Sent status response");
}

void Client::sendPingResponse(int64_t payload)
{
    auto pck = protocol::createPingResponse({
        payload
    });
    _sendData(*pck);

    LDEBUG("Sent a ping response");
}
