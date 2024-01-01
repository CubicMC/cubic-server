#include <algorithm>
#include <boost/system/detail/error_category.hpp>
#include <boost/system/detail/error_code.hpp>
#include <cstdint>
#include <cstring>
#include <curl/curl.h>
#include <mutex>
#include <netinet/in.h>
#include <poll.h>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <thread>
#include <unistd.h>
#include <zlib.h>

#include "Client.hpp"
#include "PlayerAttributes.hpp"
#include "nbt.hpp"

#include "Checksum.hpp"
#include "CompressionUtils.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "chat/ChatRegistry.hpp"
#include "logging/logging.hpp"
#include "nlohmann/json.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/ServerPackets.hpp"
#include "protocol/serialization/addPrimaryType.hpp"
#include "protocol/serialization/popPrimaryType.hpp"
#include "types.hpp"

using boost::asio::ip::tcp;

Client::Client(tcp::socket &&socket, size_t clientID):
    _isRunning(true),
    _status(protocol::ClientStatus::Initial),
    _recvBuffer(0),
    _sendBuffer(2048 * 128 * 100 * 64),
    _player(nullptr),
    _socket(std::move(socket)),
    _clientID(clientID),
    _isEncrypted(false),
    _isCompressed(false)
{
    LDEBUG("Creating client");
}

Client::~Client()
{
    LDEBUG("Destroying client");
    // Stop the thread
    _isRunning = false;

    if (!_player)
        return;
    // Everything that is done here is because we can't use share_from_this from the player destructor
    this->_player->_dim->removeEntity(_player->_id);
    this->_player->_dim->removePlayer(_player->_id);
    for (auto &chunkReq : this->_player->_chunks) {
        if (chunkReq.second == Player::ChunkState::Loading)
            this->_player->getDimension()->removePlayerFromLoadingChunk(chunkReq.first, this->_player);
    }
    chat::Message disconnectMsg = chat::Message::fromTranslationKey<chat::message::TranslationKey::MultiplayerPlayerLeft>(*_player);
    this->_player->getWorld()->getChat()->sendSystemMessage(disconnectMsg, *_player->getWorldGroup());
    // if (_thread.joinable())
    // _thread.join();
    // _thread.detach();
}

void Client::run() { _thread = std::thread(&Client::doRead, this); }

void Client::doRead()
{
    while (_isRunning) {
        boost::system::error_code ec;
        size_t length = _socket.read_some(boost::asio::buffer(_readBuffer, _readBufferSize), ec);
        if (ec) {
            // TODO(huntears): Handle error
            // LERROR(ec.what());
            _isRunning = false;
            // Server::getInstance()->triggerClientCleanup(_clientID);
            return;
        }
        if (_isEncrypted)
            _encryption.decrypt((uint8_t *) _readBuffer, length);
        _recvBuffer.insert(_recvBuffer.end(), _readBuffer, _readBuffer + length);
        _handlePacket();
    }
    // Server::getInstance()->triggerClientCleanup(_clientID);
}

static void compressPacket(std::vector<uint8_t> &in, std::vector<uint8_t> &out)
{
    // Don't compress if the packet is too small
    if (in.size() < (size_t) CONFIG["compression-threshold"].as<int32_t>()) {
        uint8_t *at = in.data();
        int32_t size = protocol::popVarInt(at, in.data() + in.size() - 1);
        protocol::addVarInt(out, size + 1);
        protocol::addVarInt(out, 0);
        out.insert(out.end(), at, in.data() + in.size());
        return;
    }
    uint8_t *at = in.data();
    int32_t size = protocol::popVarInt(at, in.data() + in.size() - 1);
    std::vector<uint8_t> compressedData;
    int compressReturn = compressVector(std::vector<uint8_t>(at, in.data() + in.size()), compressedData);
    if (compressReturn != Z_OK)
        abort(); // If we get here, we have a big problem
    protocol::addVarInt(out, compressedData.size() + (uint64_t) (at - in.data()));
    protocol::addVarInt(out, size);
    out.insert(out.end(), compressedData.begin(), compressedData.end());
}

void Client::doWrite(std::unique_ptr<std::vector<uint8_t>> &&data)
{
    if (_isCompressed) {
        auto toSend = std::make_unique<std::vector<uint8_t>>();
        compressPacket(*data, *toSend);
        if (_isEncrypted)
            _encryption.encrypt(*toSend);
        Server::getInstance()->sendData(_clientID, std::move(toSend));
        return;
    }
    if (_isEncrypted)
        _encryption.encrypt(*data);
    Server::getInstance()->sendData(_clientID, std::move(data));
}

bool Client::isDisconnected() const { return !_isRunning; }

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

    PEXP(incrementPacketRxCounter);
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
            PCK_CALLBACK_EMPTY(StatusRequest);
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
    N_LERROR("Unhandled packet: {} in status {}", packetID, _status); // TODO: Properly handle the unknown packet
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
        uint8_t *eof = at + bufferLength - 1;
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

        std::vector<uint8_t> uncompressedData;
        if (_isCompressed) {
            int32_t uncompressedLength = protocol::popVarInt(at, eof);
            if (uncompressedLength == 0)
                goto packetNotCompressed;
            if (decompressVector(std::vector<uint8_t>(at, eof + 1), uncompressedData, uncompressedLength)) {
                LERROR("Failed to decompress client packet!");
                this->disconnect("Badly formed compressed packet!");
                return;
            }
            if ((size_t) uncompressedLength != uncompressedData.size()) {
                LERROR("{} != {}", uncompressedLength, uncompressedData.size());
                this->disconnect("Bad packet compression metadata!");
                return;
            }
            at = uncompressedData.data();
            eof = uncompressedData.data() + uncompressedData.size() - 1;
        }
    packetNotCompressed:

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
        std::vector<uint8_t> toParse(at, eof + 1);
        data.erase(data.begin(), data.begin() + (startPayload - data.data()) + length);
        if (error) {
            N_LWARN("Unhandled packet: {} in status {}", packetId, _status);
            return;
        }
        std::unique_ptr<protocol::BaseServerPacket> packet;
        try {
            packet = parser(toParse);
        } catch (std::runtime_error &error) {
            N_LERROR("Error during packet {} parsing : ", packetId);
            N_LERROR("{}", error.what());
            return;
        }
        // Callback to handle the packet
        handleParsedClientPacket(std::move(packet), packetId);
    }
}

void Client::_onHandshake(protocol::Handshake &pck)
{
    N_LDEBUG("Got an handshake");
    if (pck.nextState == protocol::Handshake::State::Status)
        this->setStatus(protocol::ClientStatus::Status);
    else if (pck.nextState == protocol::Handshake::State::Login)
        this->setStatus(protocol::ClientStatus::Login);
}

void Client::_onStatusRequest()
{
    N_LDEBUG("Got a status request");

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

    json["version"]["name"] = MC_VERSION_BRANDING;
    json["version"]["protocol"] = MC_PROTOCOL;
    json["players"]["max"] = conf["max-players"].as<int32_t>();
    {
        std::lock_guard _(srv->clientsMutex);
        json["players"]["online"] = std::count_if(cli.begin(), cli.end(), [](std::pair<size_t, const std::shared_ptr<const Client>> each) {
            return each.second->getStatus() == protocol::ClientStatus::Play;
        });
    }

    sendStatusResponse(json.dump());
}

void Client::_onPingRequest(protocol::PingRequest &pck)
{
    N_LDEBUG("Got a ping request");

    sendPingResponse(pck.payload);
}

void Client::_onLoginStart(protocol::LoginStart &pck)
{
    N_LDEBUG("Got a Login Start");
    protocol::LoginSuccess resPck;

    resPck.uuid = pck.hasPlayerUuid ? pck.playerUuid : u128::fromOfflinePlayerName(pck.name);
    resPck.username = pck.name;
    resPck.properties = {}; // TODO: figure out what to put there

    if (!Server::getInstance()->getWorldGroup("default")->isInitialized()) {
        this->disconnect("Server is not initialized yet.");
        return;
    } else if (Server::getInstance()->isWhitelistEnabled() && !Server::getInstance()->getWhitelist().isPlayerWhitelisted(resPck.uuid, resPck.username).first) {
        this->disconnect("You are not whitelisted on this server.");
        return;
    } else if (std::find_if(Server::getInstance()->getClients().begin(), Server::getInstance()->getClients().end(), [resPck](auto &each) {
                   if (each.second->_player == nullptr)
                       return false;
                   return each.second->getPlayer()->getUuid() == resPck.uuid;
               }) != Server::getInstance()->getClients().end()) {
        this->disconnect("You are already connected to this server or someone already has the same UUID as you.");
        return;
    }
    if (CONFIG["online-mode"].as<bool>()) {
        _resPck = resPck;
        sendEncryptionRequest();
    } else {
        this->_loginSequence(resPck);
    }
}

constexpr int encryptionMaximumLength = 512;

void Client::_onEncryptionResponse(UNUSED protocol::EncryptionResponse &pck)
{
    N_LDEBUG("Got a Encryption Response");
    if (pck.sharedSecret.size() > encryptionMaximumLength || pck.verifyToken.size() > encryptionMaximumLength) {
        LWARN("Encryption key too long");
        disconnect();
        return;
    }
    auto &rsaKey = Server::getInstance()->getPrivateKey();
    uint32_t decryptedToken[encryptionMaximumLength / sizeof(uint32_t)];
    int res = rsaKey.decrypt(pck.verifyToken, (uint8_t *) decryptedToken, sizeof(decryptedToken));
    if (res != 4) {
        LWARN("Bad verify token of size {}", res);
        disconnect();
        return;
    }
    if (decryptedToken[0] != (uint32_t) (uintptr_t) this) {
        LWARN("Bad verify token");
        disconnect();
        return;
    }
    uint8_t decryptedKey[encryptionMaximumLength];
    res = rsaKey.decrypt(pck.sharedSecret, decryptedKey, sizeof(decryptedKey));
    if (res != 16) {
        LWARN("Bad key length");
        disconnect();
        return;
    }
    N_LDEBUG("Starting encryption");

    _isEncrypted = true;
    std::array<uint8_t, 16> key;
    memcpy(key.data(), decryptedKey, 16);
    _encryption.initialize(key, key);

    if (!_handleOnline(key))
        return;

    _loginSequence(_resPck);
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}

bool Client::_handleOnline(const std::array<uint8_t, 16> &key)
{
    Checksum cs;
    cs.update(key.data(), key.size());
    cs.update(reinterpret_cast<const uint8_t *>(Server::getInstance()->getPrivateKey().getPublicKey().data()), Server::getInstance()->getPrivateKey().getPublicKey().size());
    uint8_t digest[20];
    cs.finalize(digest);
    auto serverID = Checksum::digestToProtocol(digest);

    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (!curl) {
        LERROR("Could not init curl");
        disconnect();
        return false;
    }
    curl_easy_setopt(curl, CURLOPT_URL, std::string("https://sessionserver.mojang.com/session/minecraft/hasJoined?username=" + _resPck.username + "&serverId=" + serverID).c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    if (res != CURLcode::CURLE_OK || readBuffer.empty()) {
        LERROR("Could not query mojang's API or authentication failed");
        disconnect();
        return false;
    }
    nlohmann::json result = nlohmann::json::parse(readBuffer);

    _resPck.uuid = u128::fromShortString(result["id"]);

    for (auto &i : result["properties"]) {
        if (i.contains("signature"))
            _resPck.properties.emplace_back(i["name"].get<std::string>(), i["value"].get<std::string>(), true, i["signature"].get<std::string>());
        else
            _resPck.properties.emplace_back(i["name"].get<std::string>(), i["value"].get<std::string>(), false, "");
    }

    return true;
}

void Client::sendEncryptionRequest()
{
    std::vector<uint8_t> verifyToken = {0, 0, 0, 0};
    ((uint32_t *) verifyToken.data())[0] = (uint32_t) (uintptr_t) this;
    auto pck = protocol::createEncryptionRequest({"", Server::getInstance()->getPrivateKey().getPublicKey(), verifyToken});
    doWrite(std::move(pck));

    N_LDEBUG("Sent encryption request");
}

void Client::sendStatusResponse(const std::string &json)
{
    auto pck = protocol::createStatusResponse({json});
    doWrite(std::move(pck));

    N_LDEBUG("Sent status response");
}

void Client::sendPingResponse(int64_t payload)
{
    auto pck = protocol::createPingResponse({payload});
    doWrite(std::move(pck));

    N_LDEBUG("Sent a ping response");
}

void Client::sendLoginSuccess(const protocol::LoginSuccess &packet)
{
    auto pck = protocol::createLoginSuccess(packet);
    doWrite(std::move(pck));
    N_LDEBUG("Sent a login success");
}

void Client::sendLoginPlay()
{
    protocol::LoginPlay resPck = {
        .entityID = _player->getId(), // TODO: figure out what is this
        .isHardcore = false, // TODO: something like this this->_player->_dim->getWorld()->getDifficulty(); Thats not difficulty tho (peaceful, easy, normal, hard)
        .gamemode = this->_player->getGamemode(),
        .previousGamemode = this->_player->getGamemode(),
        .dimensionNames = std::vector<std::string>({"minecraft:overworld", "minecraft:the_nether"}), // TODO: something like this this->_player->_dim->getWorld()->getDimensions();
        .registryCodec = Server::getInstance()->getRegistry().toNBT(),
        .dimensionType = _player->getDimension()->getDimensionTypeName(),
        .dimensionName = _player->getDimension()->getDimensionName(),
        .hashedSeed = 0, // TODO: something like this this->_player->_dim->getWorld()->getHashedSeed();
        .maxPlayers = 20, // TODO: something like this this->_player->_dim->getWorld()->maxPlayers;
        .viewDistance = this->_player->getWorld()->getRenderDistance(),
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
    doWrite(std::move(pck));
    _isRunning = false;
    N_LDEBUG("Sent a disconnect login packet");
}

void Client::sendSetCompression()
{
    auto pck = protocol::createSetCompression(CONFIG["compression-threshold"].as<int32_t>());
    doWrite(std::move(pck));
    _isCompressed = true;
    N_LDEBUG("Send a set compression packet");
}

void Client::_loginSequence(const protocol::LoginSuccess &pck)
{
    // Set Compression
    if (Server::getInstance()->isCompressed())
        this->sendSetCompression();
    this->sendLoginSuccess(pck);
    this->switchToPlayState(pck.uuid, pck.username);
    this->sendLoginPlay();
    this->_player->_continueLoginSequence();
}

std::shared_ptr<Player> Client::getPlayer() { return _player; }

std::shared_ptr<const Player> Client::getPlayer() const { return _player; }
