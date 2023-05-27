#include <poll.h>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "Client.hpp"
#include "nbt.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "chat/ChatRegistry.hpp"
#include "logging/Logger.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/ServerPackets.hpp"
#include "protocol/serialization/popPrimaryType.hpp"

Client::Client(int sockfd, struct sockaddr_in6 addr):
    _sockfd(sockfd),
    _addr(addr),
    _isRunning(true),
    _status(protocol::ClientStatus::Initial),
    _recvBuffer(0),
    _sendBuffer(2048 * 64),
    _networkThread(&Client::networkLoop, this),
    _player(nullptr)
{
}

Client::~Client()
{
    LDEBUG("Destroying client");
    // Stop the thread
    _isRunning = false;
    if (this->_networkThread.joinable())
        this->_networkThread.join();

    // Close the socket
    int errorCode;
    uint32_t errorCodeSize = sizeof(errorCode);
    getsockopt(_sockfd, SOL_SOCKET, SO_ERROR, &errorCode, &errorCodeSize);
    if (errorCode == 0) {
        this->_tryFlushAllSendData();
        close(_sockfd);
    }

    if (!_player)
        return;
    // Everything that is done here is because we can't use share_from_this from the player destructor
    this->_player->_dim->removeEntity(_player->_id);
    this->_player->_dim->removePlayer(_player->_id);
    for (auto &chunkReq : this->_player->_chunks) {
        if (chunkReq.second == Player::ChunkState::Loading)
            this->_player->getDimension()->removePlayerFromLoadingChunk(chunkReq.first, this->_player);
    }
}

void Client::networkLoop()
{
    struct pollfd pollSet[1];
    uint8_t inBuffer[2048];

    pollSet[0].fd = _sockfd;
    while (_isRunning) {
        pollSet[0].events = POLLIN;
        if (!_sendBuffer.empty())
            pollSet[0].events |= POLLOUT;
        poll(pollSet, 1, 50); // TODO: Check how this can be changed
        if (pollSet[0].revents & POLLIN) {
            int readSize = read(_sockfd, inBuffer, 2048);
            if (readSize == -1)
                LERROR("Read error", strerror(errno));
            else if (readSize == 0)
                break;
            else {
                // TODO: This is extremely inefficient but it will do for now
                for (int i = 0; i < readSize; i++)
                    _recvBuffer.push_back(inBuffer[i]);
                _handlePacket();
            }
        }
        if (pollSet[0].revents & POLLOUT) {
            try {
                _flushSendData();
            } catch (const std::runtime_error &) {
                _isRunning = false;
            }
        }
    }
    _isRunning = false;
}

bool Client::isDisconnected() const { return !_isRunning; }

void Client::_sendData(const std::vector<uint8_t> &data)
{
    // This is extremely inefficient but it will do for now
    std::lock_guard<std::mutex> _(_writeMutex);
    // for (const auto &i : data)
    //     _sendBuffer.push_back(i);
    _sendBuffer.insert(_sendBuffer.end(), data.begin(), data.end());
}

#define SEND_SIZE 2048 * 64 * 128 * 100
void Client::_flushSendData()
{
    std::lock_guard<std::mutex> _(_writeMutex);
    // char sendBuffer[SEND_SIZE];
    // static char *sendBuffer = (char *) malloc(SEND_SIZE);
    size_t toSend = std::min(_sendBuffer.size(), (size_t) SEND_SIZE);
    // auto augh = _sendBuffer.begin();
    // std::advance(augh, toSend);
    // std::copy(_sendBuffer.begin(), augh, sendBuffer);

    ssize_t writeReturn = write(_sockfd, _sendBuffer.linearize(), toSend);
    if (writeReturn == -1) {
        LERROR("Write error: ", strerror(errno));
    }

    if (writeReturn <= 0) {
        _writeMutex.unlock();
        LDEBUG("error: ", writeReturn, " -> ", strerror(errno));
        if (errno == EAGAIN)
            return;
        throw std::runtime_error("Pipe error");
    }

    auto augh2 = _sendBuffer.begin();
    std::advance(augh2, writeReturn);
    _sendBuffer.erase(_sendBuffer.begin(), augh2);
    // _sendBuffer.erase_begin(writeReturn);
}

void Client::_tryFlushAllSendData()
{
    pollfd pollSet[1];
    pollSet[0].fd = _sockfd;
    pollSet[0].events = POLLOUT;

    try {
        while (!_sendBuffer.empty()) {
            if (poll(pollSet, 1, 0) == -1)
                return;
            if (pollSet[0].revents & POLLOUT)
                _flushSendData();
            else
                return;
        }
    } catch (const std::runtime_error &) {
        return;
    }
}

void Client::switchToPlayState(u128 playerUuid, const std::string &username)
{
    this->setStatus(protocol::ClientStatus::Play);
    LDEBUG("Switched to play state");
    // TODO: get the player dimension from the world by his uuid
    this->_player =
        std::make_shared<Player>(weak_from_this(), Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimension("overworld"), playerUuid, username);
    LDEBUG("Created player");
}

void Client::handleParsedClientPacket(std::unique_ptr<protocol::BaseServerPacket> &&packet, protocol::ServerPacketsID packetID)
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
            PCK_CALLBACK_PLAY(ChatCommand);
            PCK_CALLBACK_PLAY(ClientCommand);
            PCK_CALLBACK_PLAY(ClientInformation);
            PCK_CALLBACK_PLAY(CommandSuggestionRequest);
            PCK_CALLBACK_PLAY(ClickContainerButton);
            PCK_CALLBACK_PLAY(ClickContainer);
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
            PCK_CALLBACK_PLAY(MessageAcknowledgement);
            PCK_CALLBACK_PLAY(PlayerCommand);
            PCK_CALLBACK_PLAY(PlayerInput);
            PCK_CALLBACK_PLAY(Pong);
            PCK_CALLBACK_PLAY(PlayerSession);
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
            PCK_CALLBACK_PLAY(SetCreativeModeSlot);
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
    LERROR("Unhandled packet: ", static_cast<int>(packetID), " in status ", static_cast<int>(_status)); // TODO: Properly handle the unknown packet
}

void Client::_handlePacket()
{
    auto &data = _recvBuffer;
    while (true) {
        // Get the length of the packet stored
        auto bufferLength = data.size();
        if (bufferLength == 0)
            break;
        uint8_t *at = data.data();
        uint8_t *eof = at + bufferLength;
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
        const uint8_t *startPayload = at;
        bool error = false;
        // Handle the packet if the length is there
        const auto packetId = static_cast<protocol::ServerPacketsID>(protocol::popVarInt(at, eof));
        std::function<std::unique_ptr<protocol::BaseServerPacket>(std::vector<uint8_t> &)> parser;
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
        std::vector<uint8_t> toParse(data.begin() + (at - data.data()), data.end());
        data.erase(data.begin(), data.begin() + (startPayload - data.data()) + length);
        if (error) {
            LWARN("Unhandled packet: ", static_cast<int>(packetId), " in status ", static_cast<int>(_status));
            return;
        }
        std::unique_ptr<protocol::BaseServerPacket> packet;
        try {
            packet = parser(toParse);
        } catch (std::runtime_error &error) {
            LERROR("Error during packet ", (int32_t) packetId, " parsing : ");
            LERROR(error.what());
            return;
        }
        // Callback to handle the packet
        handleParsedClientPacket(std::move(packet), packetId);
    }
}

void Client::_onHandshake(protocol::Handshake &pck)
{
    LDEBUG("Got an handshake");
    if (pck.nextState == protocol::Handshake::State::Status)
        this->setStatus(protocol::ClientStatus::Status);
    else if (pck.nextState == protocol::Handshake::State::Login)
        this->setStatus(protocol::ClientStatus::Login);
}

void Client::_onStatusRequest(UNUSED protocol::StatusRequest &pck)
{
    LDEBUG("Got a status request");

    auto srv = Server::getInstance();
    auto conf = srv->getConfig();
    auto &cli = srv->getClients();
    auto worldGroup = srv->getWorldGroup("default");

    // TODO: Fix this
    nlohmann::json json;

    json["previewsChat"] = false;
    json["favicon"] = DEFAULT_FAVICON; // TODO: Understand how this works, cause right now it is witchcraft
    json["description"]["text"] = conf["motd"].value();
    json["enforcesSecureChat"] = false;

    // Old
    if (!worldGroup->isInitialized()) {
        sendStatusResponse(json.dump());
        return;
    }

    json["version"]["name"] = MC_VERSION;
    json["version"]["protocol"] = MC_PROTOCOL;
    json["players"]["max"] = conf["max-players"].as<int32_t>();
    {
        std::lock_guard _(srv->clientsMutex);
        json["players"]["online"] = std::count_if(cli.begin(), cli.end(), [](std::shared_ptr<Client> each) {
            return each->getStatus() == protocol::ClientStatus::Play;
        });
    }

    sendStatusResponse(json.dump());
}

void Client::_onPingRequest(protocol::PingRequest &pck)
{
    LDEBUG("Got a ping request");

    sendPingResponse(pck.payload);
}

void Client::_onLoginStart(protocol::LoginStart &pck)
{
    LDEBUG("Got a Login Start");
    protocol::LoginSuccess resPck;

    resPck.uuid = pck.hasPlayerUuid ? pck.playerUuid : u128 {std::hash<std::string> {}("OfflinePlayer:"), std::hash<std::string> {}(pck.name)};
    resPck.username = pck.name;
    resPck.numberOfProperties = 0;
    resPck.properties = {}; // TODO: figure out what to put there

    if (!Server::getInstance()->getWorldGroup("default")->isInitialized()) {
        this->disconnect("Server is not initialized yet.");
        return;
    } else if (Server::getInstance()->isWhitelistEnabled() && !Server::getInstance()->getWhitelist().isPlayerWhitelisted(resPck.uuid, resPck.username).first) {
        this->disconnect("You are not whitelisted on this server.");
        return;
    }
    this->_loginSequence(resPck);
}

void Client::_onEncryptionResponse(UNUSED protocol::EncryptionResponse &pck) { LDEBUG("Got a Encryption Response"); }

void Client::sendStatusResponse(const std::string &json)
{
    auto pck = protocol::createStatusResponse({json});
    _sendData(*pck);

    LDEBUG("Sent status response");
}

void Client::sendPingResponse(int64_t payload)
{
    auto pck = protocol::createPingResponse({payload});
    _sendData(*pck);

    LDEBUG("Sent a ping response");
}

void Client::sendLoginSuccess(const protocol::LoginSuccess &packet)
{
    auto pck = protocol::createLoginSuccess(packet);
    _sendData(*pck);
    LDEBUG("Sent a login success");
}

void Client::sendLoginPlay()
{
    protocol::LoginPlay resPck = {
        .entityID = _player->getId(), // TODO: figure out what is this
        .isHardcore = false, // TODO: something like this this->_player->_dim->getWorld()->getDifficulty(); Thats not difficulty tho (peaceful, easy, normal, hard)
        .gamemode = this->_player->getGamemode(),
        .previousGamemode =
            player_attributes::Gamemode::Survival, // TODO: something like this this->_player->getPreviousGamemode().has_value() ? this->_player->getPreviousGamemode() : -1;
        .dimensionNames = std::vector<std::string>({"minecraft:overworld"}), // TODO: something like this this->_player->_dim->getWorld()->getDimensions();
        // clang-format off
        .registryCodec = std::shared_ptr<nbt::Compound>(new nbt::Compound("", {
            NBT_MAKE(nbt::Compound, "minecraft:dimension_type", {
                NBT_MAKE(nbt::String, "type", "minecraft:dimension_type"),
                NBT_MAKE(nbt::List, "value", {
                    NBT_MAKE(nbt::Compound, "", {
                        NBT_MAKE(nbt::String, "name", "minecraft:overworld"),
                        NBT_MAKE(nbt::Int, "id", 0),
                        NBT_MAKE(nbt::Compound, "element", {
                            NBT_MAKE(nbt::Byte, "ultrawarm", 0),
                            NBT_MAKE(nbt::Int, "logical_height", 256),
                            NBT_MAKE(nbt::String, "infiniburn", "#minecraft:infiniburn_overworld"),
                            NBT_MAKE(nbt::Byte, "piglin_safe", 0),
                            NBT_MAKE(nbt::Float, "ambient_light", 0.0),
                            NBT_MAKE(nbt::Byte, "has_skylight", 1),
                            NBT_MAKE(nbt::String, "effects", "minecraft:overworld"),
                            NBT_MAKE(nbt::Byte, "has_raids", 1),
                            NBT_MAKE(nbt::Int, "monster_spawn_block_light_limit", 0),
                            NBT_MAKE(nbt::Byte, "respawn_anchor_works", 0),
                            NBT_MAKE(nbt::Int, "height", 384),
                            NBT_MAKE(nbt::Byte, "has_ceiling", 0),
                            NBT_MAKE(nbt::Compound, "monster_spawn_light_level", {
                                NBT_MAKE(nbt::String, "type", "minecraft:uniform"),
                                NBT_MAKE(nbt::Compound, "value", {
                                    NBT_MAKE(nbt::Int, "max_inclusive", 7),
                                    NBT_MAKE(nbt::Int, "min_inclusive", 0)
                                })
                            }),
                            NBT_MAKE(nbt::Byte, "natural", 1),
                            NBT_MAKE(nbt::Int, "min_y", -64),
                            NBT_MAKE(nbt::Float, "coordinate_scale", 1.0),
                            NBT_MAKE(nbt::Byte, "bed_works", 1)
                        })
                    })
                })
            }),
            NBT_MAKE(nbt::Compound, "minecraft:worldgen/biome", {
                NBT_MAKE(nbt::String, "type", "minecraft:worldgen/biome"),
                NBT_MAKE(nbt::List, "value", {
                    NBT_MAKE(nbt::Compound, "", {
                        NBT_MAKE(nbt::String, "name", "minecraft:plains"),
                        NBT_MAKE(nbt::Int, "id", 0),
                        NBT_MAKE(nbt::Compound, "element", {
                            NBT_MAKE(nbt::String, "precipitation", "none"),
                            NBT_MAKE(nbt::Float, "temperature", 0.8),
                            NBT_MAKE(nbt::Float, "downfall", 0.4),
                            NBT_MAKE(nbt::Compound, "effects", {
                                NBT_MAKE(nbt::Int, "sky_color", 7907327),
                                NBT_MAKE(nbt::Int, "water_fog_color", 329011),
                                NBT_MAKE(nbt::Int, "fog_color", 12638463),
                                NBT_MAKE(nbt::Int, "water_color", 4159204),
                            })
                        }),
                    }),
                    NBT_MAKE(nbt::Compound, "", {
                        NBT_MAKE(nbt::String, "name", "minecraft:my_super_cool_biome_lol_haha"),
                        NBT_MAKE(nbt::Int, "id", 1),
                        NBT_MAKE(nbt::Compound, "element", {
                            NBT_MAKE(nbt::String, "precipitation", "none"),
                            NBT_MAKE(nbt::Float, "temperature", 0.8),
                            NBT_MAKE(nbt::Float, "downfall", 0.4),
                            NBT_MAKE(nbt::Compound, "effects", {
                                NBT_MAKE(nbt::Int, "sky_color", 7907327),
                                NBT_MAKE(nbt::Int, "water_fog_color", 329011),
                                NBT_MAKE(nbt::Int, "fog_color", 12638463),
                                NBT_MAKE(nbt::Int, "water_color", 4159204),
                            })
                        }),
                    })
                })
            }),
            NBT_MAKE(nbt::Compound, "minecraft:chat_type", {
                NBT_MAKE(nbt::String, "type", "minecraft:chat_type"),
                NBT_MAKE(nbt::List, "value", {
                    NBT_MAKE(nbt::Compound, "", {
                        NBT_MAKE(nbt::String, "name", "minecraft:chat"),
                        NBT_MAKE(nbt::Int, "id", 0),
                        NBT_MAKE(nbt::Compound, "element", {
                            NBT_MAKE(nbt::Compound, "chat", {
                                NBT_MAKE(nbt::List, "parameters", {
                                    NBT_MAKE(nbt::String, "", "sender"),
                                    NBT_MAKE(nbt::String, "", "content")
                                }),
                                NBT_MAKE(nbt::String, "translation_key", "chat.type.text"),
                            }),
                            NBT_MAKE(nbt::Compound, "narration", {
                                NBT_MAKE(nbt::List, "parameters", {
                                    NBT_MAKE(nbt::String, "", "sender"),
                                    NBT_MAKE(nbt::String, "", "content")
                                }),
                                NBT_MAKE(nbt::String, "translation_key", "chat.type.text.narrate"),
                            })
                        })
                    })
                })
            })
        })),
        // clang-format on
        .dimensionType = "minecraft:overworld", // TODO: something like this this->_player->_dim->getDimensionType();
        .dimensionName = "overworld", // TODO: something like this this->_player->getDimension()->name;
        .hashedSeed = 0, // TODO: something like this this->_player->_dim->getWorld()->getHashedSeed();
        .maxPlayers = 20, // TODO: something like this this->_player->_dim->getWorld()->maxPlayers;
        .viewDistance = 10, // TODO: something like this->_player->_dim->getWorld()->getViewDistance();
        .simulationDistance = 16, // TODO: something like this->_player->_dim->getWorld()->getSimulationDistance();
        .reducedDebugInfo = false, // false for developpment only
        .enableRespawnScreen = true, // TODO: implement gamerules !this->_player->_dim->getWorld()->getGamerules()["doImmediateRespawn"];
        .isDebug = false, // TODO: something like this->_player->_dim->getWorld()->isDebugModeWorld;
        .isFlat = false, // TODO: something like this->_player->_dim->isFlat;
        .hasDeathLocation = false, // TODO: something like this->_player->hasDeathLocation;
        .deathDimensionName = "",
        .deathLocation = {0, 0, 0},
    };
    _player->sendLoginPlay(resPck);
    // resPck.registryCodec.destroy();
}

void Client::disconnect(const chat::Message &reason)
{
    if (_status == protocol::ClientStatus::Play) {
        _player->disconnect(reason);
        return;
    }

    auto pck = protocol::createLoginDisconnect({reason.serialize()});
    _sendData(*pck);
    _isRunning = false;
    LDEBUG("Sent a disconnect login packet");
}

void Client::stop(const chat::Message &reason)
{
    this->disconnect(reason);
    if (this->_networkThread.joinable())
        this->_networkThread.join();
}

void Client::_loginSequence(const protocol::LoginSuccess &pck)
{
    // Encryption request
    // Set Compression
    this->sendLoginSuccess(pck);
    this->switchToPlayState(pck.uuid, pck.username);
    this->sendLoginPlay();
    this->_player->_continueLoginSequence();
}

std::shared_ptr<Player> Client::getPlayer() { return _player; }

const std::shared_ptr<Player> Client::getPlayer() const { return _player; }
