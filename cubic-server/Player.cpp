#include <cstdint>
#include <iostream>
#include <sstream>
#include <cstdint>
#include <string>

#include "Entity.hpp"
#include "Player.hpp"
#include "PlayerAttributes.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "blocks.hpp"
#include "chat/Message.hpp"
#include "command_parser/CommandParser.hpp"
#include "protocol/ClientPackets.hpp"
#include "types.hpp"

Player::Player(Client *cli, std::shared_ptr<Dimension> dim, u128 uuid, const std::string &username):
    _cli(cli),
    LivingEntity(dim),
    _uuid(uuid),
    _username(username),
    _keepAliveId(0),
    _keepAliveIgnored(0),
    _gamemode(player_attributes::Gamemode::Survival),
    _keepAliveClock(200, std::bind(&Player::_processKeepAlive, this)), // 5 seconds for keep-alives
    _foodLevel(player_attributes::MAX_FOOD_LEVEL), // TODO: Take this from the saved data
    _foodSaturationLevel(player_attributes::DEFAULT_FOOD_SATURATION_LEVEL), // TODO: Take this from the saved data
    _foodTickTimer(0), // TODO: Take this from the saved data
    _foodExhaustionLevel(0.0f) // TODO: Take this from the saved data
{
    _keepAliveClock.start();
    _heldItem = 0;

    // Generate uuid string
    std::stringstream uuidsstr;
    std::string uuidstr;

    uuidsstr << std::setfill('0') << std::setw(16) << std::hex << this->getUuid().most << std::setfill('0') << std::setw(16) << this->getUuid().least;
    uuidstr = uuidsstr.str();
    LINFO("Player with uuid ", uuidstr, " just logged in");
    uuidstr.insert(8, "-");
    uuidstr.insert(13, "-");
    uuidstr.insert(18, "-");
    uuidstr.insert(23, "-");
    this->_uuidString = uuidstr;
    this->setHealth(20);

    this->setOperator(Server::getInstance()->permissions.isOperator(username));
}

Player::~Player()
{
    chat::Message disconnectMsg = chat::Message::fromTranslationKey<chat::message::TranslationKey::multiplayer_player_left, const Player *>(this);

    this->_dim->getWorld()->sendPlayerInfoRemovePlayer(this);
    this->_dim->removeEntity(this);

    // Send a disconnect message
    this->_dim->getWorld()->getChat()->sendSystemMessage(disconnectMsg, false, this->_dim->getWorld()->getWorldGroup());
}

void Player::tick()
{
    _keepAliveClock.tick();

    bool updatePos = false;
    bool updateRot = false;
    int16_t deltaX = 0;
    int16_t deltaY = 0;
    int16_t deltaZ = 0;

    if (_pos != _lastPos) {
        updatePos = true;
        deltaX = static_cast<int16_t>((this->_pos.x * 32.0 - this->_lastPos.x * 32.0) * 128.0);
        deltaY = static_cast<int16_t>((this->_pos.y * 32.0 - this->_lastPos.y * 32.0) * 128.0);
        deltaZ = static_cast<int16_t>((this->_pos.z * 32.0 - this->_lastPos.z * 32.0) * 128.0);
        _lastPos = _pos;
    }
    if (_rot != _lastRot) {
        updateRot = true;
        _lastRot = _rot;
    }
    if (updatePos && updateRot) {
        for (auto i : this->getDimension()->getPlayerList()) {
            if (i->getId() == this->getId())
                continue;
            i->sendUpdateEntityPositionAndRotation({this->getId(), deltaX, deltaY, deltaZ, this->_rot.x, this->_rot.y, true});
            i->sendHeadRotation({this->getId(), _rot.x});
        }
    } else if (updatePos && !updateRot) {
        for (auto i : this->getDimension()->getPlayerList()) {
            if (i->getId() == this->getId())
                continue;
            i->sendUpdateEntityPosition({this->getId(), deltaX, deltaY, deltaZ, true});
        }
    } else if (!updatePos && updateRot) {
        for (auto i : this->getDimension()->getPlayerList()) {
            if (i->getId() == this->getId())
                continue;
            i->sendUpdateEntityRotation({this->getId(), this->_rot.x, this->_rot.y, true});
            i->sendHeadRotation({this->getId(), _rot.x});
        }
    }

    if (_pos.y < -100) // TODO: Change that
        teleport({_pos.x, -58, _pos.z});

    _foodTick();
}

Client *Player::getClient() const { return _cli; }

const std::string &Player::getUsername() const { return _username; }

const u128 &Player::getUuid() const { return _uuid; }

uint16_t Player::getHeldItem() const { return this->_heldItem; }

const std::string &Player::getUuidString() const { return this->_uuidString; }

player_attributes::Gamemode Player::getGamemode() const { return _gamemode; }

void Player::setGamemode(player_attributes::Gamemode gamemode) { _gamemode = gamemode; }

void Player::setOperator(const bool isOp) { this->_isOperator = isOp; }

bool Player::isOperator() const { return this->_isOperator; }

void Player::disconnect(const chat::Message &reason)
{
    auto pck = protocol::createPlayDisconnect({reason.serialize()});
    this->_cli->_sendData(*pck);
    this->_cli->_is_running = false;
    LDEBUG("Sent a disconnect play packet");
}

#pragma region ClientBound

long Player::keepAliveId() const { return _keepAliveId; }

void Player::setKeepAliveId(long id) { _keepAliveId = id; }

void Player::setKeepAliveIgnored(uint8_t ign) { _keepAliveIgnored = ign; }

uint8_t Player::keepAliveIgnored() const { return _keepAliveIgnored; }

void Player::setPosition(const Vector3<double> &pos, bool on_ground)
{
    auto newChunkPos = Position2D(transformBlockPosToChunkPos(pos.x), transformBlockPosToChunkPos(pos.z));
    auto oldChunkPos = Position2D(transformBlockPosToChunkPos(_pos.x), transformBlockPosToChunkPos(_pos.z));
    auto oldPos2d = Vector2<double>(_pos.x, _pos.z);
    auto newPos2d = Vector2<double>(pos.x, pos.z);

    if (on_ground && _isFlying)
        _isFlying = false;
    if (!on_ground && !_isJumping && !_isFlying && ((pos.y + (-world_storage::CHUNK_HEIGHT_MIN)) - (_pos.y + (-world_storage::CHUNK_HEIGHT_MIN)) > 0)) {
        _isJumping = true;
        _isFlying = true;
    }

    if (_isSprinting && !_isFlying)
        _foodExhaustionLevel += oldPos2d.distance(newPos2d) * player_attributes::FOOD_EXHAUSTION_SPRINTING_MULTIPLIER;
    if (_isJumping) {
        _foodExhaustionLevel += _isSprinting ? player_attributes::FOOD_EXHAUSTION_SPRINTING_JUMP : player_attributes::FOOD_EXHAUSTION_JUMP;
        _isJumping = false;
    }

    Entity::setPosition(pos, on_ground);

    _updateRenderedChunks(oldChunkPos, newChunkPos);
}

void Player::setPosition(double x, double y, double z, bool on_ground) { this->setPosition({x, y, z}, on_ground); }

void Player::playSoundEffect(SoundsList sound, FloatingPosition position, SoundCategory category)
{
    auto pck = protocol::createSoundEffect({
        (int32_t) sound, (int32_t) category,
        // https://wiki.vg/Data_types#Fixed-point_numbers
        static_cast<int32_t>(position.x * 32.0), static_cast<int32_t>(position.y * 32.0), static_cast<int32_t>(position.z * 32.0),
        0.5, // TODO: get the right volume
        1.0, // TODO: get the right pitch
        0 // TODO: get the right seed
    });
    this->_cli->_sendData(*pck);
    LDEBUG("Sent a sound effect packet");
}

void Player::playSoundEffect(SoundsList sound, const Entity *entity, SoundCategory category)
{
    auto pck = protocol::createEntitySoundEffect({
        (int32_t) sound, (int32_t) category, entity->getId(),
        1.0, // TODO: get the right volume
        1.0, // TODO: get the right pitch
        1 // TODO: get the right seed
    });
    this->_cli->_sendData(*pck);
    LDEBUG("Sent a entity sound effect packet");
}

void Player::playCustomSound(std::string sound, FloatingPosition position, SoundCategory category)
{
    auto pck = protocol::createCustomSoundEffect({
        sound, (int32_t) category,
        // https://wiki.vg/Data_types#Fixed-point_numbers
        static_cast<int32_t>(position.x * 32.0), static_cast<int32_t>(position.y * 32.0), static_cast<int32_t>(position.z * 32.0),
        0.5, // TODO: get the right volume
        1.0, // TODO: get the right pitch
        0 // TODO: get the right seed
    });
    this->_cli->_sendData(*pck);
    LDEBUG("Sent a custom sound effect packet");
}

void Player::stopSound(uint8_t flags, SoundCategory category, std::string sound)
{
    auto pck = protocol::createStopSound({flags, (int32_t) category, sound});
    this->_cli->_sendData(*pck);
    LDEBUG("Sent a stop sound packet");
}

void Player::sendBlockUpdate(const protocol::BlockUpdate &packet)
{
    auto pck = protocol::createBlockUpdate(packet);
    this->_cli->_sendData(*pck);

    LDEBUG("Sent a block update at ", packet.location, " = ", packet.block_id, " to ", this->getUsername());
}

void Player::sendFeatureFlags(const protocol::FeatureFlags &packet)
{
    auto pck = protocol::createFeatureFlags(packet);
    _cli->_sendData(*pck);
}

void Player::sendServerData(const protocol::ServerData &packet)
{
    auto pck = protocol::createServerData(packet);
    _cli->_sendData(*pck);
}

void Player::sendLoginPlay(const protocol::LoginPlay &packet)
{
    auto pck = protocol::createLoginPlay(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent a login play");
}

void Player::sendPlayerInfoUpdate(const protocol::PlayerInfoUpdate &data)
{
    auto pck = protocol::createPlayerInfoUpdate(data);
    this->_cli->_sendData(*pck);

    LDEBUG("Sent a Player Info packet");
}

void Player::sendPlayerInfoRemove(const protocol::PlayerInfoRemove &data)
{
    auto pck = protocol::createPlayerInfoRemove(data);
    this->_cli->_sendData(*pck);

    LDEBUG("Sent a Player Info packet");
}

void Player::sendSpawnPlayer(const protocol::SpawnPlayer &data)
{
    auto pck = protocol::createSpawnPlayer(data);
    this->_cli->_sendData(*pck);

    LDEBUG("Sent a Spawn Player packet on coords: ", data.x, " ", data.y, " ", data.z);
}

void Player::sendEntityVelocity(const protocol::EntityVelocity &data)
{
    auto pck = protocol::createEntityVelocity(data);
    this->_cli->_sendData(*pck);

    LDEBUG("Sent an Entity Velocity packet with velocity: x -> ", data.velocity_x, " | ", "y -> ", data.velocity_y, " | ", "z -> ", data.velocity_z);
}

void Player::sendHealth(void)
{
    auto pck = protocol::createHealth({_health, _foodLevel, _foodSaturationLevel});
    this->_cli->_sendData(*pck);

    LDEBUG("Sent a Health packet");
}

void Player::sendUpdateTime(const protocol::UpdateTime &data)
{
    auto pck = protocol::createUpdateTime(data);
    this->_cli->_sendData(*pck);

    LDEBUG("Sent an Update Time packet");
}

void Player::sendChatMessageResponse(const protocol::PlayerChatMessage &packet)
{
    auto pck = protocol::createPlayerChatMessage(packet);
    this->_cli->_sendData(*pck);

    LINFO("Sent a chat message response", packet.unsignedContent);
}

void Player::sendSystemChatMessage(const protocol::SystemChatMessage &packet)
{
    auto pck = protocol::createSystemChatMessage(packet);
    this->_cli->_sendData(*pck);

    LDEBUG("Sent a system chat message to ", this->getUsername());
    LDEBUG("message: ", packet.JSONData);
}

void Player::sendWorldEvent(const protocol::WorldEvent &packet)
{
    auto pck = protocol::createWorldEvent(packet);
    this->_cli->_sendData(*pck);

    LDEBUG("Sent a world event");
}

void Player::sendKeepAlive(long id)
{
    auto pck = protocol::createKeepAlive(id);
    this->_cli->_sendData(*pck);
    LDEBUG("Sent a keep alive packet");
}

void Player::sendUpdateEntityPosition(const protocol::UpdateEntityPosition &data)
{
    auto pck = protocol::createUpdateEntityPosition(data);
    this->_cli->_sendData(*pck);
    LDEBUG("Sent an entity position packet");
}

void Player::sendUpdateEntityPositionAndRotation(const protocol::UpdateEntityPositionRotation &data)
{
    auto pck = protocol::createUpdateEntityPositionRotation(data);
    this->_cli->_sendData(*pck);
    LDEBUG("Sent an entity position and rotation packet");
}

void Player::sendUpdateEntityRotation(const protocol::UpdateEntityRotation &data)
{
    auto pck = protocol::createUpdateEntityRotation(data);
    this->_cli->_sendData(*pck);
    LDEBUG("Sent an entity rotation packet");
}

void Player::sendHeadRotation(const protocol::HeadRotation &data)
{
    auto pck = protocol::createHeadRotation(data);
    this->_cli->_sendData(*pck);
    LDEBUG("Sent an entity head rotation packet");
}

void Player::sendSetCenterChunk(const Position2D &pos)
{
    auto pck = protocol::createCenterChunk(pos);
    this->_cli->_sendData(*pck);
    LDEBUG("Sent a center chunk packet");
}

void Player::sendSynchronizePosition(Vector3<double> pos)
{
    auto pck = protocol::createSynchronizePlayerPosition({
        pos.x,
        pos.y,
        pos.z,
        0, // TODO: document those magic numbers
        0,
        0x08 | 0x10,
        0,
        true,

    });
    this->_cli->_sendData(*pck);
}

void Player::sendChunkAndLightUpdate(const Position2D &pos) { this->sendChunkAndLightUpdate(pos.x, pos.z); }

void Player::sendChunkAndLightUpdate(int32_t x, int32_t z)
{
    if (!this->_dim->hasChunkLoaded(x, z)) {
        this->_dim->loadOrGenerateChunk(x, z, this);
        this->_chunks[{x, z}] = ChunkState::Loading;
        //     [this](const world_storage::ChunkColumn &chunk) {
        //         // pls don't kill me
        //         // this is a hack to check if the client is still connected
        //         // And the best part ? I don't even know if it works
        //         if (
        //             std::find_if(
        //                 Server::getInstance()->getClients().begin(),
        //                 Server::getInstance()->getClients().end(),
        //                 [this](const std::shared_ptr<Client> &cli) { return (&(*cli) == this->_cli); }
        //             ) == Server::getInstance()->getClients().end()
        //         ) return;
        //         if (this->_chunks.contains(chunk.getChunkPos()) && this->_chunks[chunk.getChunkPos()].state == ChunkState::Loading)
        //             this->sendChunkAndLightUpdate(chunk);
        //     }
        // )};
        return;
    }

    this->sendChunkAndLightUpdate(this->_dim->getChunk(x, z));
}

void Player::sendChunkAndLightUpdate(const world_storage::ChunkColumn &chunk)
{
    auto heightMap = chunk.getHeightMap();
    auto chunkPos = chunk.getChunkPos();

    std::vector<nbt::Base *> motionBlocking;
    std::vector<nbt::Base *> worldSurface;

    // HeightMap preparation
    for (auto &it : heightMap.motionBlocking)
        motionBlocking.push_back(&it);
    for (auto &it : heightMap.worldSurface)
        worldSurface.push_back(&it);

    auto motionBlockingList = new nbt::List("MOTION_BLOCKING", motionBlocking);
    auto worldSurfaceList = new nbt::List("WORLD_SURFACE", worldSurface);

    auto packet = protocol::createChunkDataAndLightUpdate({
        chunkPos.x,
        chunkPos.z,
        nbt::Compound("", {motionBlockingList, worldSurfaceList}),
        chunk,
        {}, // TODO: BlockEntities
        false, // Trust Edges: If edges should be trusted for light updates.
        {}, // TODO: Sky light mask
        {}, // TODO: Block light mask
        {}, // TODO: empty sky light mask
        {}, // TODO: empty block light mask
        {}, // TODO: sky light
        {} // TODO: block light
    });
    this->_cli->_sendData(*packet);

    this->_chunks[chunkPos] = ChunkState::Loaded;

    LDEBUG("Sent a chunk data and light update packet ", chunkPos, ")");
    delete motionBlockingList;
    delete worldSurfaceList;
}

void Player::sendUnloadChunk(int32_t x, int32_t z)
{
    auto pck = protocol::createUnloadChunk({x, z});
    this->_cli->_sendData(*pck);
    LDEBUG("Sent an unload chunk packet (", x, ", ", z, ")");
}

void Player::sendRemoveEntities(const std::vector<int32_t> &entities)
{
    auto pck = protocol::createRemoveEntities({entities});
    this->_cli->_sendData(*pck);
    LDEBUG("Sent a Remove Entities packet");
}

void Player::sendSwingArm(bool main_hand, int32_t swinger_id)
{
    auto pck = protocol::createEntityAnimation(main_hand ? protocol::EntityAnimationID::SwingMainArm : protocol::EntityAnimationID::SwingOffHand, swinger_id);
    _cli->_sendData(*pck);
}

void Player::sendTeleportEntity(int32_t id, const Vector3<double> &pos)
{
    auto pck = protocol::createTeleportEntity({id, pos.x, pos.y, pos.z});
    _cli->_sendData(*pck);
    LDEBUG("Sent a Teleport Entity");
}

void Player::sendPlayerAbilities(const protocol::PlayerAbilitiesClient &packet)
{
    auto pck = protocol::createPlayerAbilities(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent a Player Abilities packet");
}

void Player::sendSetContainerContent(const protocol::SetContainerContent &packet)
{
    auto pck = protocol::createSetContainerContent(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent set container content packet");
}

void Player::sendUpdateRecipes(const protocol::UpdateRecipes &packet)
{
    auto pck = protocol::createUpdateRecipes(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent update recipes packet");
}

void Player::sendUpdateTags(const protocol::UpdateTags &packet)
{
    auto pck = protocol::createUpdateTags(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent update tags packet");
}

void Player::sendCommands(const protocol::Commands &packet)
{
    auto pck = protocol::createCommands(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent commands packet");
}

void Player::sendChangeDifficulty(const protocol::ChangeDifficultyClient &packet)
{
    auto pck = protocol::createChangeDifficultyClient(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent change difficulty packet");
}

void Player::sendSetHeldItem(const protocol::SetHeldItemClient &packet)
{
    auto pck = protocol::createSetHeldItemClient(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent set held item packet");
}

void Player::sendEntityEvent(const protocol::EntityEvent &packet)
{
    auto pck = protocol::createEntityEvent(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent entity event packet");
}

void Player::sendUpdateRecipiesBook(const protocol::UpdateRecipesBook &packet)
{
    auto pck = protocol::createUpdateRecipesBook(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent update recipies book packet");
}

// void Player::sendInitializeWorldBorder(const protocol::InitializeWorldBorder &packet)
// {
//     auto pck = protocol::createInitializeWorldBorder(packet);
//     _cli->_sendData(*pck);
//     LDEBUG("Sent initialize world border packet");
// }

void Player::sendSetDefaultSpawnPosition(const protocol::SetDefaultSpawnPosition &packet)
{
    auto pck = protocol::createSetDefaultSpawnPosition(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent set default spawn position packet");
}

// void Player::sendSetEntityMetadata(const protocol::SetEntityMetadata &packet)
// {
//     auto pck = protocol::createSetEntityMetadata(packet);
//     _cli->_sendData(*pck);
//     LDEBUG("Sent set entity metadata packet");
// }

// void Player::sendUpdateAttributes(const protocol::UpdateAttributes &packet)
// {
//     auto pck = protocol::createUpdateAttributes(packet);
//     _cli->_sendData(*pck);
//     LDEBUG("Sent update attributes packet");
// }

// void Player::sendUpdateAdvancements(const protocol::SeenAdvancements &packet)
// {
//     auto pck = protocol::createSeenAdvancements(packet);
//     _cli->_sendData(*pck);
//     LDEBUG("Sent update advancements packet");
// }

// void Player::sendSetExperience(const protocol::SetExperience &packet)
// {
//     auto pck = protocol::createSetExperience(packet);
//     _cli->_sendData(*pck);
//     LDEBUG("Sent set experience packet");
// }

#pragma endregion
#pragma region ServerBound

void Player::_onConfirmTeleportation(const std::shared_ptr<protocol::ConfirmTeleportation> &pck) { LDEBUG("Got a Confirm Teleportation"); }

void Player::_onQueryBlockEntityTag(const std::shared_ptr<protocol::QueryBlockEntityTag> &pck) { LDEBUG("Got a Query Block Entity Tag"); }

void Player::_onChangeDifficulty(const std::shared_ptr<protocol::ChangeDifficulty> &pck) { LDEBUG("Got a Change difficulty"); }

// Receive a chat message from the client, transmit it to the chat system.
void Player::_onChatMessage(const std::shared_ptr<protocol::ChatMessage> &pck)
{
    // TODO: verify that the message is valid (signature, etc.)
    _dim->getWorld()->getChat()->sendPlayerMessage(pck->message, this);
    LDEBUG("Got a Chat Message");
}

void Player::_onMessageAcknowledgement(const std::shared_ptr<protocol::MessageAcknowledgement> &pck)
{
    LINFO("Got a Message Acknowledgement");
}

/**
 * @brief This function is called when a client sends a command in the chat.
 *
 * @param pck The packet recieved from the client.
 */
void Player::_onChatCommand(const std::shared_ptr<protocol::ChatCommand> &pck)
{
    LDEBUG("Got a Chat Command");
    LDEBUG("The command is :\"" + pck->command + "\"");
    command_parser::parseCommand(pck->command, this);
}

void Player::_onClientCommand(const std::shared_ptr<protocol::ClientCommand> &pck) { LDEBUG("Got a Client Command"); }

void Player::_onClientInformation(const std::shared_ptr<protocol::ClientInformation> &pck) { LDEBUG("Got a Client Information"); }

void Player::_onCommandSuggestionRequest(const std::shared_ptr<protocol::CommandSuggestionRequest> &pck) { LDEBUG("Got a Command Suggestion Request"); }

void Player::_onClickContainerButton(const std::shared_ptr<protocol::ClickContainerButton> &pck) { LDEBUG("Got a Click Container Button"); }

void Player::_onCloseContainerRequest(const std::shared_ptr<protocol::CloseContainerRequest> &pck) { LDEBUG("Got a Close Container Request"); }

void Player::_onPluginMessage(const std::shared_ptr<protocol::PluginMessage> &pck)
{
    LDEBUG("Got a Plugin Message");
    if (pck->channel == "minecraft:brand") {
        LDEBUG("Got a branding request");
        auto pck = protocol::createPluginMessageResponse({
            "minecraft:brand", std::vector<uint8_t>({0x05, 0x43, 0x75, 0x62, 0x69, 0x63}) // 43 75 62 69 63 | "Cubic" in hex
        });
        _cli->_sendData(*pck);
        return;
    }
}

void Player::_onEditBook(const std::shared_ptr<protocol::EditBook> &pck) { LDEBUG("Got a Edit Book"); }

void Player::_onQueryEntityTag(const std::shared_ptr<protocol::QueryEntityTag> &pck) { LDEBUG("Got a Query Entity Tag"); }

/*
 * @brief Handle a player's interaction with an entity.
 */
void Player::_onInteract(const std::shared_ptr<protocol::Interact> &pck)
{
    LivingEntity *target = dynamic_cast<LivingEntity *>(_dim->getEntityByID(pck->entity_id));
    Player *player = dynamic_cast<Player *>(target);

    switch (pck->type) {
    case 0: // interact type
        break;
    case 1: // attack type
        if (player != nullptr && player->_gamemode != player_attributes::Gamemode::Creative) {
            player->attack(_pos);
            player->sendHealth();
        } else if (target != nullptr) {
            target->attack(_pos);
        }
        _foodExhaustionLevel += player_attributes::FOOD_EXHAUSTION_ATTACK;
        break;
    case 2: // interact at type
        break;
    }
    LDEBUG("Got a Interact");
}

void Player::_onJigsawGenerate(const std::shared_ptr<protocol::JigsawGenerate> &pck) { LDEBUG("Got a Jigsaw Generate"); }

void Player::_onKeepAliveResponse(const std::shared_ptr<protocol::KeepAliveResponse> &pck)
{
    if (pck->keep_alive_id != _keepAliveId) {
        LERROR("Got a Keep Alive Response with a wrong ID: ", pck->keep_alive_id, " (expected ", _keepAliveId, ")");
        this->disconnect("Wrong Keep Alive ID");
        return;
    }

    _keepAliveId = 0;
    LDEBUG("Got a Keep Alive Response");
}

void Player::_onLockDifficulty(const std::shared_ptr<protocol::LockDifficulty> &pck) { LDEBUG("Got a Lock Difficulty"); }

void Player::_onSetPlayerPosition(const std::shared_ptr<protocol::SetPlayerPosition> &pck)
{
    LDEBUG("Got a Set Player Position (", pck->x, ", ", pck->feet_y, ", ", pck->z, ")");
    // TODO: Validate the position
    this->setPosition(pck->x, pck->feet_y, pck->z, pck->on_ground);
}

void Player::_onSetPlayerPositionAndRotation(const std::shared_ptr<protocol::SetPlayerPositionAndRotation> &pck)
{
    LDEBUG("Got a Set Player Position And Rotation (", pck->x, ", ", pck->feet_y, ", ", pck->z, ")");
    // TODO: Validate the position
    this->setPosition(pck->x, pck->feet_y, pck->z, pck->on_ground);
    this->setRotation(pck->yaw, pck->pitch);
}

void Player::_onSetPlayerRotation(const std::shared_ptr<protocol::SetPlayerRotation> &pck)
{
    LDEBUG("Got a Set Player Rotation");
    this->setRotation(pck->yaw, pck->pitch);
}

void Player::_onSetPlayerOnGround(const std::shared_ptr<protocol::SetPlayerOnGround> &pck) { LDEBUG("Got a Set Player On Ground"); }

void Player::_onMoveVehicle(const std::shared_ptr<protocol::MoveVehicle> &pck) { LDEBUG("Got a Move Vehicle"); }

void Player::_onPaddleBoat(const std::shared_ptr<protocol::PaddleBoat> &pck) { LDEBUG("Got a Paddle Boat"); }

void Player::_onPickItem(const std::shared_ptr<protocol::PickItem> &pck) { LDEBUG("Got a Pick Item"); }

void Player::_onPlaceRecipe(const std::shared_ptr<protocol::PlaceRecipe> &pck) { LDEBUG("Got a Place Recipe"); }

void Player::_onPlayerAbilities(const std::shared_ptr<protocol::PlayerAbilities> &pck)
{
    this->_isFlying = pck->flags & protocol::PlayerAbilitiesFlags::Flying;
    uint8_t flags = this->_isFlying ? protocol::PlayerAbilitiesFlags::Flying : 0x00;
    flags |= protocol::PlayerAbilitiesFlags::Invulnerable | protocol::PlayerAbilitiesFlags::AllowFlying | protocol::PlayerAbilitiesFlags::CreativeMode;
    this->sendPlayerAbilities({flags, 0.05f, 0.1f});
    LDEBUG("Got a Player Abilities");
}

void Player::_onPlayerAction(const std::shared_ptr<protocol::PlayerAction> &pck)
{
    // LINFO("Got a Player Action ", pck->status, " at ", pck->location);
    LDEBUG("Got a Player Action and player is in gamemode ", this->getGamemode(), " and status is ", (int32_t) pck->status);
    switch (pck->status) {
    case protocol::PlayerAction::Status::StartedDigging:
        if (this->getGamemode() == player_attributes::Gamemode::Creative)
            this->getDimension()->blockUpdate(pck->location, 0);
        break;
    case protocol::PlayerAction::Status::CancelledDigging:
        break;
    case protocol::PlayerAction::Status::FinishedDigging:
        this->getDimension()->blockUpdate(pck->location, 0);
        _foodExhaustionLevel += 0.005;
        break;
    case protocol::PlayerAction::Status::DropItemStack:
        break;
    case protocol::PlayerAction::Status::DropItem:
        break;
    case protocol::PlayerAction::Status::ShootArrowOrFinishEating:
        _eat(922); // TODO: Change that to use the item in hand (for instance it's a raw chicken)
        break;
    case protocol::PlayerAction::Status::SwapItemInHand:
        break;
    default:
        LERROR("Got a Player Action with an unknown status: ", (int32_t) pck->status);
        break;
    }
}

void Player::_onPlayerCommand(const std::shared_ptr<protocol::PlayerCommand> &pck)
{
    LDEBUG("Got a Player Command");
    if (pck->action_id == protocol::PlayerCommand::ActionId::StartSprinting) {
        _isSprinting = true;
    }
    if (pck->action_id == protocol::PlayerCommand::ActionId::StopSprinting) {
        _isSprinting = false;
    }
}

void Player::_onPlayerInput(const std::shared_ptr<protocol::PlayerInput> &pck) { LDEBUG("Got a Player Input"); }

void Player::_onPong(const std::shared_ptr<protocol::Pong> &pck) { LDEBUG("Got a Pong"); }

void Player::_onChangeRecipeBookSettings(const std::shared_ptr<protocol::ChangeRecipeBookSettings> &pck) { LDEBUG("Got a Change Recipe Book Settings"); }

void Player::_onSetSeenRecipe(const std::shared_ptr<protocol::SetSeenRecipe> &pck) { LDEBUG("Got a Set Seen Recipe"); }

void Player::_onRenameItem(const std::shared_ptr<protocol::RenameItem> &pck) { LDEBUG("Got a Rename Item"); }

void Player::_onResourcePack(const std::shared_ptr<protocol::ResourcePack> &pck) { LDEBUG("Got a Resource Pack"); }

void Player::_onSeenAdvancements(const std::shared_ptr<protocol::SeenAdvancements> &pck) { LDEBUG("Got a Seen Advancements"); }

void Player::_onSelectTrade(const std::shared_ptr<protocol::SelectTrade> &pck) { LDEBUG("Got a Select Trade"); }

void Player::_onSetBeaconEffect(const std::shared_ptr<protocol::SetBeaconEffect> &pck) { LDEBUG("Got a Set Beacon Effect"); }

void Player::_onSetHeldItem(const std::shared_ptr<protocol::SetHeldItem> &pck)
{
    this->_heldItem = pck->slot;
    LDEBUG("Got a Set Held Item");
}

void Player::_onProgramCommandBlock(const std::shared_ptr<protocol::ProgramCommandBlock> &pck) { LDEBUG("Got a Program Command Block"); }

void Player::_onProgramCommandBlockMinecart(const std::shared_ptr<protocol::ProgramCommandBlockMinecart> &pck) { LDEBUG("Got a Program Command Block Minecart"); }

void Player::_onProgramJigsawBlock(const std::shared_ptr<protocol::ProgramJigsawBlock> &pck) { LDEBUG("Got a Program Jigsaw Block"); }

void Player::_onProgramStructureBlock(const std::shared_ptr<protocol::ProgramStructureBlock> &pck) { LDEBUG("Got a Program Structure Block"); }

void Player::_onUpdateSign(const std::shared_ptr<protocol::UpdateSign> &pck) { LDEBUG("Got a Update Sign"); }

void Player::_onSwingArm(const std::shared_ptr<protocol::SwingArm> &pck)
{
    LDEBUG("Got a Swing Arm");
    for (auto i : this->getDimension()->getPlayerList()) {
        if (i->getId() == this->getId())
            continue;
        i->sendSwingArm(pck->hand == 0, this->getId());
    }
}

void Player::_onTeleportToEntity(const std::shared_ptr<protocol::TeleportToEntity> &pck) { LDEBUG("Got a Teleport To Entity"); }

void Player::_onUseItemOn(const std::shared_ptr<protocol::UseItemOn> &pck)
{
    LDEBUG("Got a Use Item On ", pck->location, " -> ", this->_heldItem);
    switch (pck->face) {
    case 0:
        pck->location.y--;
        break;
    case 1:
        pck->location.y++;
        break;
    case 2:
        pck->location.z--;
        break;
    case 3:
        pck->location.z++;
        break;
    case 4:
        pck->location.x--;
        break;
    case 5:
        pck->location.x++;
        break;
    }
    switch (this->_heldItem) {
    case 0:
        this->getDimension()->blockUpdate(pck->location, Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE));
        break;
    case 1:
        this->getDimension()->blockUpdate(pck->location, Blocks::Dirt::toProtocol());
        break;
    case 2:
        this->getDimension()->blockUpdate(pck->location, Blocks::Bedrock::toProtocol());
        break;
    case 3:
        this->getDimension()->blockUpdate(pck->location, Blocks::OakLog::toProtocol(Blocks::OakLog::Properties::Axis::Y));
        break;
    case 4:
        this->getDimension()->blockUpdate(
            pck->location,
            Blocks::OakLeaves::toProtocol(
                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
            )
        );
        break;
    case 5:
        this->getDimension()->blockUpdate(pck->location, Blocks::Glass::toProtocol());
        break;
    case 6:
        this->getDimension()->blockUpdate(pck->location, Blocks::Cobblestone::toProtocol());
        break;
    case 7:
        this->getDimension()->blockUpdate(pck->location, Blocks::PinkTerracotta::toProtocol());
        break;
    case 8:
        this->getDimension()->blockUpdate(pck->location, Blocks::PurpleCarpet::toProtocol());
        break;
    }
}

void Player::_onUseItem(const std::shared_ptr<protocol::UseItem> &pck) { LDEBUG("Got a Use Item"); }

#pragma endregion Serverbound

void Player::_processKeepAlive()
{
    long id = std::chrono::system_clock::now().time_since_epoch().count();
    if (this->keepAliveId() != 0) {
        this->setKeepAliveIgnored(this->keepAliveIgnored() + 1);
        if (this->_keepAliveClock.tickRate() * this->keepAliveIgnored() >= player_attributes::MAX_TICK_BEFORE_TIMEOUT)
            this->disconnect("Skill issues detected");
        return;
    }
    this->setKeepAliveId(id);
    this->sendKeepAlive(id);
}

void Player::_updateRenderedChunks(const Position2D &oldChunkPos, const Position2D &newChunkPos)
{
    if (newChunkPos == oldChunkPos)
        return;

    auto renderDistance = this->getDimension()->getWorld()->getRenderDistance();

    // Load and unload chunks
    this->sendSetCenterChunk(newChunkPos);

    //* Old chunks
    // Positive changes
    for (int32_t x = oldChunkPos.x - renderDistance; x < std::min(newChunkPos.x - renderDistance, oldChunkPos.x + renderDistance + 1); x++) {
        for (int32_t z = oldChunkPos.z - renderDistance; z < oldChunkPos.z + renderDistance + 1; z++)
            this->_unloadChunk(x, z);
    }
    for (int32_t z = oldChunkPos.z - renderDistance; z < std::min(newChunkPos.z - renderDistance, oldChunkPos.z + renderDistance + 1); z++) {
        for (int32_t x = oldChunkPos.x - renderDistance + (newChunkPos.x - oldChunkPos.x); x < oldChunkPos.x + renderDistance + 1; x++)
            this->_unloadChunk(x, z);
    }

    // Negative changes
    for (int32_t x = oldChunkPos.x + renderDistance; x >= std::max(newChunkPos.x + renderDistance + 1, oldChunkPos.x - renderDistance); x--) {
        for (int32_t z = oldChunkPos.z - renderDistance; z < oldChunkPos.z + renderDistance + 1; z++)
            this->_unloadChunk(x, z);
    }
    for (int32_t z = oldChunkPos.z + renderDistance; z >= std::max(newChunkPos.z + renderDistance + 1, oldChunkPos.z - renderDistance); z--) {
        for (int32_t x = oldChunkPos.x - renderDistance; x < oldChunkPos.x + renderDistance + 1 + (newChunkPos.x - oldChunkPos.x); x++)
            this->_unloadChunk(x, z);
    }

    //* New chunks
    // Positive changes
    for (int32_t x = newChunkPos.x + renderDistance; x >= std::max(oldChunkPos.x + renderDistance + 1, newChunkPos.x - renderDistance); x--) {
        for (int32_t z = newChunkPos.z - renderDistance; z < newChunkPos.z + renderDistance + 1; z++)
            this->sendChunkAndLightUpdate(x, z);
    }
    for (int32_t z = newChunkPos.z + renderDistance; z >= std::max(oldChunkPos.z + renderDistance + 1, newChunkPos.z - renderDistance); z--) {
        for (int32_t x = newChunkPos.x - renderDistance; x < newChunkPos.x + renderDistance + 1 - (newChunkPos.x - oldChunkPos.x); x++)
            this->sendChunkAndLightUpdate(x, z);
    }

    // Negative changes
    for (int32_t x = newChunkPos.x - renderDistance; x < std::min(oldChunkPos.x - renderDistance, newChunkPos.x + renderDistance + 1); x++) {
        for (int32_t z = newChunkPos.z - renderDistance; z < newChunkPos.z + renderDistance + 1; z++)
            this->sendChunkAndLightUpdate(x, z);
    }
    for (int32_t z = newChunkPos.z - renderDistance; z < std::min(oldChunkPos.z - renderDistance, newChunkPos.z + renderDistance + 1); z++) {
        for (int32_t x = newChunkPos.x - renderDistance - (newChunkPos.x - oldChunkPos.x); x < newChunkPos.x + renderDistance + 1; x++)
            this->sendChunkAndLightUpdate(x, z);
    }
}

void Player::_continueLoginSequence()
{
    this->sendFeatureFlags({{"minecraft:vanilla"}});

    // TODO: send Change Difficulty

    this->sendPlayerAbilities(
        {(uint8_t) protocol::PlayerAbilitiesFlags::Invulnerable | (uint8_t) protocol::PlayerAbilitiesFlags::Flying | (uint8_t) protocol::PlayerAbilitiesFlags::AllowFlying |
             (uint8_t) protocol::PlayerAbilitiesFlags::CreativeMode,
         0.05, 0.1}
    );

    // TODO: set Held Item

    this->sendUpdateRecipes({});

    this->sendUpdateTags({});

    // TODO: entity event entity id and byte enum = 0x18 -> 24 (set op permission level)

    this->sendCommands({{}, 0});

    // TODO: update recipes book

    this->teleport({8.5, 100, 8.5}); // TODO: change that to player_attributes::DEFAULT_SPAWN_POINT

    this->sendServerData({false, "", false, "", false});

    _dim->addEntity(this);
    LDEBUG("Added entity player to dimension");
    getDimension()->getWorld()->sendPlayerInfoAddPlayer(this);

    this->sendSetCenterChunk({0, 0});

    auto renderDistance = this->getDimension()->getWorld()->getRenderDistance();
    // Send all chunks around the player
    // TODO: send chunk closer to the player first
    sendChunkAndLightUpdate(0, 0);
    for (int32_t x = -renderDistance; x < renderDistance + 1; x++) {
        for (int32_t z = -renderDistance; z < renderDistance + 1; z++) {
            if (x == 0 && z == 0)
                continue;
            sendChunkAndLightUpdate(x, z);
        }
    }

    // TODO: Initialize world border

    this->sendSetDefaultSpawnPosition({{0, 100, 0}, 0.0f});

    this->sendSetContainerContent({0, 0, {}, {false}});

    // TODO: set entity metadata

    // TODO: update attributes

    // TODO: update Advancements

    this->sendHealth();

    // TODO: set experience

    // TODO: set entity metadata

    // for (auto &player : this->_player->getDimension()->getPlayerList())
    //     player->_synchronizePostion({0, -58, 0});
    // this->_player->sendChunkAndLightUpdate(0, 0);
    getDimension()->spawnPlayer(this);
    this->teleport({8.5, 100, 8.5}); // TODO: change that to player_attributes::DEFAULT_SPAWN_POINT

    this->_sendLoginMessage();
}

void Player::_sendLoginMessage()
{
    // Send login message
    chat::Message connectionMsg = chat::Message::fromTranslationKey<chat::message::TranslationKey::multiplayer_player_joined, const Player *>(this);

    this->getDimension()->getWorld()->getChat()->sendSystemMessage(connectionMsg, false, this->getDimension()->getWorld()->getWorldGroup());
}

void Player::_unloadChunk(int32_t x, int32_t z)
{
    if (!this->_chunks.contains({x, z}))
        return;
    else if (this->_chunks[{x, z}] == ChunkState::Loading) {
        this->_dim->removePlayerFromLoadingChunk({x, z}, this);
        this->_chunks.erase({x, z});
        return;
    }

    this->sendUnloadChunk(x, z);
    this->_chunks.erase({x, z});
}

void Player::_foodTick()
{
    using namespace player_attributes;
    if (_gamemode != Gamemode::Survival && _gamemode != Gamemode::Adventure)
        return;
    bool needUpdate = false;
    if (_foodLevel == MIN_FOOD_LEVEL && _health > 10 && _foodTickTimer >= 80) { // TODO: Make it depends on difficulty
        _health -= 1;
        _foodTickTimer = 0;
        needUpdate = true;
    }
    if (_foodLevel >= MIN_FOOD_LEVEL_FOR_REGENERATION && _health < _maxHealth) {
        if (_foodSaturationLevel > 0 && _foodLevel == MAX_FOOD_LEVEL && _foodTickTimer >= 10) {
            _health += ((1.0 / 6) * _foodSaturationLevel >= 1) ? 1 : (1.0 / 6) * _foodSaturationLevel;
            _foodExhaustionLevel += 6;
            _foodTickTimer = 0;
            needUpdate = true;
        }
        if (_foodTickTimer >= 80) {
            _health += 1;
            _foodExhaustionLevel += 6;
            _foodTickTimer = 0;
            needUpdate = true;
        }
    }
    if (_foodExhaustionLevel >= 4 && needUpdate == false) {
        _foodExhaustionLevel -= 4;
        if (_foodSaturationLevel > 0) {
            _foodSaturationLevel -= 1;
            needUpdate = true;
        } else {
            _foodLevel -= _foodLevel > 0 ? 1 : 0;
            needUpdate = true;
        }
    }
    if (_foodLevel < MIN_FOOD_LEVEL_FOR_REGENERATION && _foodLevel > 0 && _foodTickTimer > 0)
        _foodTickTimer = 0;
    if (needUpdate) {
        this->sendHealth();
        LDEBUG("Health is now ", _health, " and food level is now ", _foodLevel);
    }
    if (needUpdate == false &&
        ((_foodLevel >= MIN_FOOD_LEVEL_FOR_REGENERATION && _health < _maxHealth) || (_foodLevel == MIN_FOOD_LEVEL && _health > 10))) // TODO: Make it depends on difficulty
        _foodTickTimer++;
}

void Player::_eat(ItemId itemId)
{
    using namespace player_attributes;
    auto food = std::find_if(Items::foodItems.begin(), Items::foodItems.end(), [itemId](const Items::FoodItem &item) {
        return item.id == itemId;
    });
    if (food == Items::foodItems.end()) {
        LERROR("Trying to eat an item that is not food");
        return;
    }
    if (_foodLevel >= MAX_FOOD_LEVEL) {
        LERROR("Trying to eat while food level is already at max");
        return;
    }
    _foodLevel += food->foodValue;
    _foodSaturationLevel += food->saturation;
    if (_foodLevel > MAX_FOOD_LEVEL)
        _foodLevel = MAX_FOOD_LEVEL;
    if (_foodSaturationLevel > _foodLevel)
        _foodSaturationLevel = _foodLevel;
    this->sendHealth();
}

void Player::teleport(const Vector3<double> &pos)
{
    this->sendSynchronizePosition(pos);
    LDEBUG("Synchronized player position");
    Entity::teleport(pos);
}
