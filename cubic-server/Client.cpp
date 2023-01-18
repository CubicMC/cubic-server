#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <poll.h>
#include <cstring>
#include <string>
#include <memory>

#include "Client.hpp"
#include "protocol/ServerPackets.hpp"
#include "nlohmann/json.hpp"
#include "protocol/ClientPackets.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "whitelist/Whitelist.hpp"

Client::Client(int sockfd, struct sockaddr_in6 addr)
    : _sockfd(sockfd), _addr(addr), _status(protocol::ClientStatus::Initial)
{
    _is_running = true;
    _log = logging::Logger::get_instance();
    _player = nullptr;
}

Client::~Client()
{
    // Stop the thread
    if (_is_running)
        _is_running = false;
    if (_current_thread->joinable())
        _current_thread->join();
    delete _current_thread;

    // Close the socket
    int error_code;
    uint32_t error_code_size = sizeof(error_code);
    getsockopt(_sockfd, SOL_SOCKET, SO_ERROR, &error_code, &error_code_size);
    if (error_code == 0) {
        //_flushSendData();
        close(_sockfd);
    }

    // Remove the player from the world
    if (!_player)
        return;

    chat::Message disconnectMsg = chat::Message("", {
        .color = "yellow",
        .translate = "multiplayer.player.left",
        .with = std::vector<chat::Message>({
            chat::Message(
                _player->getUsername(),
                {
                    .insertion = _player->getUsername(),
                },
                chat::message::ClickEvent(
                    chat::message::ClickEvent::Action::SuggestCommand,
                    "/tell " + _player->getUsername() + " "
                ),
                chat::message::HoverEvent(
                    chat::message::HoverEvent::Action::ShowEntity,
                    "{\"type\": \"minecraft:player\", \"id\": \"" + _player->getUuidString() + "\", \"name\": \"" + _player->getUsername() + "\"}"
                )
            )
        })
    });
    //std::cout << "Player disconnected was with id : " << uuidstr << std::endl;
    this->_player->getDimension()->getWorld()->sendPlayerInfoRemovePlayer(this->_player);
    _player->_dim->removeEntity(_player);

    // Send a disconnect message
    _player->_dim->getWorld()->getChat()->sendSystemMessage(
        disconnectMsg,
        false,
        _player->_dim->getWorld()->getWorldGroup()
    );
    // _player->_dim->getWorld()->getChat()->sendPlayerMessage(
    //     disconnectMsg,
    //     _player
    // );

    delete _player;
}

void Client::networkLoop()
{
    struct pollfd poll_set[1];
    uint8_t in_buffer[2048];

    poll_set[0].fd = _sockfd;
    while (_is_running)
    {
        poll_set[0].events = POLLIN;
        if (!_send_buffer.empty())
            poll_set[0].events |= POLLOUT;
        poll(poll_set, 1, 50); // TODO: Check how this can be changed
        if (poll_set[0].revents & POLLIN)
        {
            int read_size = read(_sockfd, in_buffer, 2048);
            if (read_size == -1)
                LERROR("Read error" + std::string(strerror(errno)));
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
    _write_mutex.lock();
    for (const auto i : data)
        _send_buffer.push_back(i);
    _write_mutex.unlock();
}

void Client::_flushSendData()
{
    _write_mutex.lock();
    char send_buffer[2048];
    size_t to_send = std::min(_send_buffer.size(), (size_t)2048);
    std::copy(_send_buffer.begin(), _send_buffer.begin() + to_send, send_buffer);

    ssize_t write_return = write(_sockfd, send_buffer, to_send);
    if (write_return == -1)
        LERROR("Write error" + std::string(strerror(errno)));

    if (write_return <= 0) {
        _write_mutex.unlock();
        return;
    }

    _send_buffer.erase(_send_buffer.begin(), _send_buffer.begin() + write_return);
    _write_mutex.unlock();
}

void Client::switchToPlayState(u128 playerUuid, const std::string &username)
{
    this->setStatus(protocol::ClientStatus::Play);
    // TODO: get the player dimension from the world by his uuid
    this->_player = new Player(
        this,
        Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimension("overworld"),
        playerUuid,
        username
    );
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
            PCK_CALLBACK_PLAY(ChatMessage);
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
            PCK_CALLBACK_PLAY(PluginMessage);
        default:
            break;
        }
        break;
    }
    LERROR("Unhandled packet: " + std::to_string(static_cast<int>(packetID)) +
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
        bool error = false;
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
        data.erase(data.begin(), data.begin() + (start_payload - data.data()) + length);
        if (error) {
            LWARN("Unhandled packet: " + std::to_string(static_cast<int>(packet_id)) + " in status " + std::to_string(static_cast<int>(_status)));
            return;
        }
        std::shared_ptr<protocol::BaseServerPacket> packet;
        try {
            packet = parser(to_parse);
        }
        catch (std::runtime_error &error) {
            LERROR("Error during packet parsing :");
            LERROR(error.what());
            return;
        }
        // Callback to handle the packet
        handleParsedClientPacket(packet, packet_id);
    }
}

void Client::_onHandshake(const std::shared_ptr<protocol::Handshake>& pck)
{
    LDEBUG("Got an handshake");
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
    auto cli = srv->getClients();

    // TODO: Fix this
    nlohmann::json json;
    json["version"]["name"] = MC_VERSION;
    json["version"]["protocol"] = MC_PROTOCOL;
    json["players"]["max"] = conf.getMaxPlayers();
    json["players"]["online"] = std::count_if(
            cli.begin(),
            cli.end(),
            [](std::shared_ptr<Client> &each) {
                return each->getStatus() == protocol::ClientStatus::Play;
            }
    );
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
    protocol::LoginSuccess resPck;
    WhitelistHandling::Whitelist whitelist;
    nlohmann::json whitelistData = whitelist.parseWhitelist(whitelist.getFilename());

    resPck.uuid = pck->has_player_uuid ? pck->player_uuid : u128{std::hash<std::string>{}("OfflinePlayer:"), std::hash<std::string>{}(pck->name)};
    resPck.username = pck->name;
    resPck.numberOfProperties = 0;
    resPck.name = ""; // TODO: figure out what to put there
    resPck.value = ""; // TODO: figure out what to put there
    resPck.isSigned = false;

    if (Server::getInstance()->getEnforceWhitelist() == false || whitelist.isPlayer(resPck.uuid, resPck.username, whitelistData).first == true)
        sendLoginSuccess(resPck);
    else
        this->disconnect("You are not whitelisted on this server.");
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

void Client::sendLoginSuccess(const protocol::LoginSuccess &packet)
{
    auto pck = protocol::createLoginSuccess(packet);
    _sendData(*pck);
    LDEBUG("Sent a login success");

    switchToPlayState(packet.uuid, packet.username);
    LDEBUG("Switched to play state");
    this->_player->setGamemode(1);

    protocol::LoginPlay resPck = {
            .entityID = _player->getId(), // TODO: figure out what is this
            .isHardcore = false, // TODO: something like this this->_player->_dim->getWorld()->getDifficulty();
            .gamemode = this->_player->getGamemode(),
            .previousGamemode = 0, // TODO: something like this this->_player->getPreviousGamemode().has_value() ? this->_player->getPreviousGamemode() : -1;
            .dimensionNames = std::vector<std::string>({"minecraft:overworld"}), // TODO: something like this this->_player->_dim->getWorld()->getDimensions();
            .registryCodec = nbt::Compound("", {
                    new nbt::Compound("minecraft:dimension_type", {
                            new nbt::String("type", "minecraft:dimension_type"),
                            new nbt::List("value", {
                                    new nbt::Compound("", {
                                            new nbt::String("name", "minecraft:overworld"),
                                            new nbt::Int("id", 0),
                                            new nbt::Compound("element", {
                                                    new nbt::Byte("ultrawarm", 0),
                                                    new nbt::Int("logical_height", 256),
                                                    new nbt::String("infiniburn", "#minecraft:infiniburn_overworld"),
                                                    new nbt::Byte("piglin_safe", 0),
                                                    new nbt::Float("ambient_light", 0.0),
                                                    new nbt::Byte("has_skylight", 1),
                                                    new nbt::String("effects", "minecraft:overworld"),
                                                    new nbt::Byte("has_raids", 1),
                                                    new nbt::Int("monster_spawn_block_light_limit", 0),
                                                    new nbt::Byte("respawn_anchor_works", 0),
                                                    new nbt::Int("height", 384),
                                                    new nbt::Byte("has_ceiling", 0),
                                                    new nbt::Compound("monster_spawn_light_level", {
                                                            new nbt::String("type", "minecraft:uniform"),
                                                            new nbt::Compound("value", {
                                                                    new nbt::Int("max_inclusive", 7),
                                                                    new nbt::Int("min_inclusive", 0),
                                                            })
                                                    }),
                                                    new nbt::Byte("natural", 1),
                                                    new nbt::Int("min_y", -64),
                                                    new nbt::Float("coordinate_scale", 1.0),
                                                    new nbt::Byte("bed_works", 1),
                                            }),
                                    }),
                            })
                    }),
                    new nbt::Compound("minecraft:worldgen/biome", {
                            new nbt::String("type", "minecraft:worldgen/biome"),
                            new nbt::List("value", {
                                    new nbt::Compound("", {
                                            new nbt::String("name", "minecraft:plains"),
                                            new nbt::Int("id", 0),
                                            new nbt::Compound("element", {
                                                    new nbt::String("precipitation", "none"),
                                                    new nbt::Float("temperature", 0.8),
                                                    new nbt::Float("downfall", 0.4),
                                                    new nbt::Compound("effects", {
                                                            new nbt::Int("sky_color", 7907327),
                                                            new nbt::Int("water_fog_color", 329011),
                                                            new nbt::Int("fog_color", 12638463),
                                                            new nbt::Int("water_color", 4159204),
                                                    })
                                            }),
                                    })
                            })
                    }),
                    new nbt::Compound("minecraft:chat_type", {
                            new nbt::String("type", "minecraft:chat_type"),
                            new nbt::List("value", {
                                    new nbt::Compound("", {
                                            new nbt::String("name", "minecraft:chat"),
                                            new nbt::Int("id", 0),
                                            new nbt::Compound("element", {
                                                    new nbt::Compound("chat", {
                                                            new nbt::Compound("decoration", {
                                                                    new nbt::List("parameters", {
                                                                            new nbt::String("", "sender"),
                                                                            new nbt::String("", "content")
                                                                    }),
                                                                    new nbt::String("translation_key", "chat.type.text.narrate"),
                                                                    new nbt::Compound("style", {})
                                                            }),
                                                            new nbt::String("priority", "chat")
                                                    })
                                            })
                                    })
                            })
                    })
            }),
            .dimensionType = "minecraft:overworld", // TODO: something like this this->_player->_dim->getDimensionType();
            .dimensionName = "overworld", // TODO: something like this this->_player->getDimension()->name;
            .hashedSeed = 0, // TODO: something like this this->_player->_dim->getWorld()->getHashedSeed();
            .maxPlayers = 20, // TODO: something like this this->_player->_dim->getWorld()->maxPlayers;
            .viewDistance = 16, // TODO: something like this->_player->_dim->getWorld()->getViewDistance();
            .simulationDistance = 16, // TODO: something like this->_player->_dim->getWorld()->getSimulationDistance();
            .reducedDebugInfo = false, // false for developpment only
            .enableRespawnScreen = true, // TODO: implement gamerules !this->_player->_dim->getWorld()->getGamerules()["doImmediateRespawn"];
            .isDebug = false, // TODO: something like this->_player->_dim->getWorld()->isDebugModeWorld;
            .isFlat = true, // TODO: something like this->_player->_dim->isFlat;
            .hasDeathLocation = false // TODO: something like this->_player->hasDeathLocation;
    };
    if (resPck.hasDeathLocation) {
        resPck.deathDimensionName = ""; // TODO: something like this->_player->deathDimensionName;
        resPck.deathLocation = {0, 0, 0}; // TODO: something like this->_player->deathLocation;
    }
    _player->sendLoginPlay(resPck);
    resPck.registryCodec.destroy();
}

void Client::disconnect(const chat::Message &reason)
{
    if (_status == protocol::ClientStatus::Play) {
        _player->disconnect(reason);
        return;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    nlohmann::json json;

    // TODO: test this, cause I don't know if the translate key is the correct one
    json["translate"] = "chat.type.text";
    json["with"] = nlohmann::json::array({
        {"text", "PlayerName"},
        {reason.toJson()}
    });

    auto pck = protocol::createLoginDisconnect({
        json.dump()
    });
    _sendData(*pck);
    _is_running = false;
    LDEBUG("Sent a disconnect login packet");
}
