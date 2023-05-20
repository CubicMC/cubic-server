#include "Player.hpp"

#include "Chat.hpp"
#include "Client.hpp"
#include "Dimension.hpp"
#include "Entity.hpp"
#include "PlayerAttributes.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "blocks.hpp"
#include "command_parser/CommandParser.hpp"
#include "items/foodItems.hpp"
#include "logging/Logger.hpp"

Player::Player(Client *cli, std::shared_ptr<Dimension> dim, u128 uuid, const std::string &username):
    LivingEntity(dim),
    _cli(cli),
    _username(username),
    _uuid(uuid),
    _keepAliveId(0),
    _keepAliveIgnored(0),
    _gamemode(player_attributes::Gamemode::Survival),
    _keepAliveClock(200, std::bind(&Player::_processKeepAlive, this)), // 5 seconds for keep-alives
    _foodLevel(player_attributes::MAX_FOOD_LEVEL), // TODO: Take this from the saved data
    _foodSaturationLevel(player_attributes::DEFAULT_FOOD_SATURATION_LEVEL), // TODO: Take this from the saved data
    _foodTickTimer(0), // TODO: Take this from the saved data
    _foodExhaustionLevel(0.0f), // TODO: Take this from the saved data
    _chatVisibility(protocol::ClientInformation::ChatVisibility::Enabled),
    _isFlying(true), // TODO: Take this from the saved data
    _isSprinting(false),
    _isJumping(false)
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
    chat::Message disconnectMsg = chat::Message::fromTranslationKey<chat::message::TranslationKey::MultiplayerPlayerLeft>(*this);
    this->_cli = nullptr;

    this->_dim->getWorld()->sendPlayerInfoRemovePlayer(this);

    // Send a disconnect message
    this->_dim->getWorld()->getChat()->sendSystemMessage(disconnectMsg, *this);
}

void Player::tick()
{
    _keepAliveClock.tick();

    _tickPosition();
    _foodTick();
}

void Player::_tickPosition()
{
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
        for (auto i : this->getDimension()->getPlayers()) {
            if (i->getId() == this->getId())
                continue;
            i->sendUpdateEntityPositionAndRotation({this->getId(), deltaX, deltaY, deltaZ, this->_rot.x, this->_rot.z, true});
            i->sendHeadRotation({this->getId(), _rot.x});
        }
    } else if (updatePos && !updateRot) {
        for (auto i : this->getDimension()->getPlayers()) {
            if (i->getId() == this->getId())
                continue;
            i->sendUpdateEntityPosition({this->getId(), deltaX, deltaY, deltaZ, true});
        }
    } else if (!updatePos && updateRot) {
        for (auto i : this->getDimension()->getPlayers()) {
            if (i->getId() == this->getId())
                continue;
            i->sendUpdateEntityRotation({this->getId(), this->_rot.x, this->_rot.z, true});
            i->sendHeadRotation({this->getId(), _rot.x});
        }
    }

    if (_pos.y < -100) // TODO: Change that
        teleport({_pos.x, -58, _pos.z});
}

Client *Player::getClient() const { return _cli; }

const std::string &Player::getUsername() const { return _username; }

const u128 &Player::getUuid() const { return _uuid; }

uint16_t Player::getHeldItem() const { return this->_heldItem; }

const std::string &Player::getUuidString() const { return this->_uuidString; }

player_attributes::Gamemode Player::getGamemode() const { return _gamemode; }

const protocol::ClientInformation::ChatVisibility &Player::getChatVisibility() const { return this->_chatVisibility; }

void Player::setGamemode(player_attributes::Gamemode gamemode) { _gamemode = gamemode; }

void Player::setOperator(const bool isOp) { this->_isOperator = isOp; }

bool Player::isOperator() const { return this->_isOperator; }

void Player::disconnect(const chat::Message &reason)
{
    auto pck = protocol::createPlayDisconnect({reason.serialize()});
    this->_cli->_sendData(*pck);
    this->_cli->_isRunning = false;
    LDEBUG("Sent a disconnect play packet");
}

#pragma region ClientBound

long Player::keepAliveId() const { return _keepAliveId; }

void Player::setKeepAliveId(long id) { _keepAliveId = id; }

void Player::setKeepAliveIgnored(uint8_t ign) { _keepAliveIgnored = ign; }

uint8_t Player::keepAliveIgnored() const { return _keepAliveIgnored; }

void Player::setPosition(const Vector3<double> &pos, bool onGround)
{
    auto newChunkPos = Position2D(transformBlockPosToChunkPos(pos.x), transformBlockPosToChunkPos(pos.z));
    auto oldChunkPos = Position2D(transformBlockPosToChunkPos(_pos.x), transformBlockPosToChunkPos(_pos.z));
    auto oldPos2d = Vector2<double>(_pos.x, _pos.z);
    auto newPos2d = Vector2<double>(pos.x, pos.z);

    if (onGround && _isFlying)
        _isFlying = false;
    if (!onGround && !_isJumping && !_isFlying && ((pos.y + (-world_storage::CHUNK_HEIGHT_MIN)) - (_pos.y + (-world_storage::CHUNK_HEIGHT_MIN)) > 0)) {
        _isJumping = true;
        _isFlying = true;
    }

    if (_isSprinting && !_isFlying)
        _foodExhaustionLevel += oldPos2d.distance(newPos2d) * player_attributes::FOOD_EXHAUSTION_SPRINTING_MULTIPLIER;
    if (_isJumping) {
        _foodExhaustionLevel += _isSprinting ? player_attributes::FOOD_EXHAUSTION_SPRINTING_JUMP : player_attributes::FOOD_EXHAUSTION_JUMP;
        _isJumping = false;
    }

    Entity::setPosition(pos, onGround);

    _updateRenderedChunks(oldChunkPos, newChunkPos);
}

void Player::setPosition(double x, double y, double z, bool onGround) { this->setPosition({x, y, z}, onGround); }

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

void Player::playSoundEffect(SoundsList sound, const Entity &entity, SoundCategory category)
{
    auto pck = protocol::createEntitySoundEffect({
        (int32_t) sound, (int32_t) category, entity.getId(),
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

    LDEBUG("Sent a block update at ", packet.location, " = ", packet.blockId, " to ", this->getUsername());
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

void Player::sendSpawnEntity(const protocol::SpawnEntity &data)
{
    auto pck = protocol::createSpawnEntity(data);
    this->_cli->_sendData(*pck);

    LDEBUG("Sent a Spawn Entity packet");
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

    LDEBUG("Sent an Entity Velocity packet with velocity: x -> ", data.velocityX, " | ", "y -> ", data.velocityY, " | ", "z -> ", data.velocityZ);
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

void Player::sendChatMessageResponse(UNUSED const protocol::PlayerChatMessage &packet)
{
    auto pck = protocol::createPlayerChatMessage(packet);
    this->_cli->_sendData(*pck);

    LDEBUG("Sent a chat message response");
}

void Player::sendSystemChatMessage(const protocol::SystemChatMessage &packet)
{
    // TODO(huntears): Find another way to do this
    if (!_cli)
        return;
    auto pck = protocol::createSystemChatMessage(packet);
    this->_cli->_sendData(*pck);

    LDEBUG("Sent a system chat message to ", this->getUsername());
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

void Player::sendSynchronizePosition(const Vector3<double> &pos)
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
        this->_dim->loadOrGenerateChunk(x, z, dynamic_pointer_cast<Player>(shared_from_this()));
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

    std::vector<std::shared_ptr<nbt::Base>> motionBlocking;
    std::vector<std::shared_ptr<nbt::Base>> worldSurface;
    motionBlocking.reserve(heightMap.motionBlocking.size());
    worldSurface.reserve(heightMap.worldSurface.size());

    for (auto i = 0; i < world_storage::HEIGHTMAP_ARRAY_SIZE; i++) {
        motionBlocking.push_back(heightMap.motionBlocking.at(i));
        worldSurface.push_back(heightMap.worldSurface.at(i));
    }

    auto motionBlockingList = NBT_MAKE(nbt::List, "MOTION_BLOCKING", motionBlocking);
    auto worldSurfaceList = NBT_MAKE(nbt::List, "WORLD_SURFACE", worldSurface);

    auto packet = protocol::createChunkDataAndLightUpdate({
        chunkPos.x,
        chunkPos.z,
        std::shared_ptr<nbt::Compound>(new nbt::Compound("", {motionBlockingList, worldSurfaceList})),
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

void Player::sendSwingArm(bool mainHand, int32_t swingerId)
{
    sendEntityAnimation(mainHand ? protocol::EntityAnimation::ID::SwingMainArm : protocol::EntityAnimation::ID::SwingOffHand, swingerId);
}

void Player::sendEntityAnimation(protocol::EntityAnimation::ID animId, int32_t entityID)
{
    auto pck = protocol::createEntityAnimation(animId, entityID);
    _cli->_sendData(*pck);
}

void Player::sendTeleportEntity(int32_t id, const Vector3<double> &pos)
{
    auto pck = protocol::createTeleportEntity({id, pos.x, pos.y, pos.z, _rot.x, _rot.z, false});
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

void Player::sendInitializeWorldBorder(const protocol::InitializeWorldBorder &packet)
{
    auto pck = protocol::createInitializeWorldBorder(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent initialize world border packet");
}

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

void Player::sendUpdateAttributes(const protocol::UpdateAttributes &packet)
{
    auto pck = protocol::createUpdateAttributes(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent update attributes packet");
}

void Player::sendUpdateAdvancements(const protocol::UpdateAdvancements &packet)
{
    auto pck = protocol::createUpdateAdvancements(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent update advancements packet");
}

void Player::sendSetExperience(const protocol::SetExperience &packet)
{
    auto pck = protocol::createSetExperience(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent set experience packet");
}

void Player::sendUpdateObjective(const protocol::UpdateObjectives &packet)
{
    auto pck = protocol::createUpdateObjectives(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent update objectives packet");
}

void Player::sendDisplayObjective(const protocol::DisplaySlot &packet)
{
    auto pck = protocol::createDisplayObjective(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent display objective packet");
}

void Player::sendUpdateScore(const protocol::UpdateScore &packet)
{
    auto pck = protocol::createUpdateScore(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent update score packet");
}

void Player::sendUpdateTeams(const protocol::UpdateTeams &packet)
{
    auto pck = protocol::createUpdateTeams(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent update teams packet");
}

#pragma endregion
#pragma region ServerBound

void Player::_onConfirmTeleportation(UNUSED const std::shared_ptr<protocol::ConfirmTeleportation> &pck) { LDEBUG("Got a Confirm Teleportation"); }

void Player::_onQueryBlockEntityTag(UNUSED const std::shared_ptr<protocol::QueryBlockEntityTag> &pck) { LDEBUG("Got a Query Block Entity Tag"); }

void Player::_onChangeDifficulty(UNUSED const std::shared_ptr<protocol::ChangeDifficulty> &pck) { LDEBUG("Got a Change difficulty"); }

// Receive a chat message from the client, transmit it to the chat system.
void Player::_onChatMessage(const std::shared_ptr<protocol::ChatMessage> &pck)
{
    // TODO: verify that the message is valid (signature, etc.)
    _dim->getWorld()->getChat()->sendPlayerMessage(pck->message, *this);
    LDEBUG("Got a Chat Message");
}

void Player::_onMessageAcknowledgement(UNUSED const std::shared_ptr<protocol::MessageAcknowledgement> &pck) { LINFO("Got a Message Acknowledgement"); }

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

void Player::_onClientCommand(UNUSED const std::shared_ptr<protocol::ClientCommand> &pck) { LDEBUG("Got a Client Command"); }

void Player::_onClientInformation(const std::shared_ptr<protocol::ClientInformation> &pck)
{
    this->_chatVisibility = pck->chatMode;
    LDEBUG("Got a Client Information");
}

void Player::_onCommandSuggestionRequest(UNUSED const std::shared_ptr<protocol::CommandSuggestionRequest> &pck) { LDEBUG("Got a Command Suggestion Request"); }

void Player::_onClickContainerButton(UNUSED const std::shared_ptr<protocol::ClickContainerButton> &pck) { LDEBUG("Got a Click Container Button"); }

void Player::_onClickContainer(UNUSED const std::shared_ptr<protocol::ClickContainer> &pck) { LDEBUG("Got a Click Container"); }

void Player::_onCloseContainerRequest(UNUSED const std::shared_ptr<protocol::CloseContainerRequest> &pck) { LDEBUG("Got a Close Container Request"); }

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

void Player::_onEditBook(UNUSED const std::shared_ptr<protocol::EditBook> &pck) { LDEBUG("Got a Edit Book"); }

void Player::_onQueryEntityTag(UNUSED const std::shared_ptr<protocol::QueryEntityTag> &pck) { LDEBUG("Got a Query Entity Tag"); }

/*
 * @brief Handle a player's interaction with an entity.
 */
void Player::_onInteract(const std::shared_ptr<protocol::Interact> &pck)
{
    auto target = dynamic_pointer_cast<LivingEntity>(_dim->getEntityByID(pck->entityId));
    auto player = dynamic_pointer_cast<Player>(target);

    switch (pck->type) {
    case protocol::Interact::Type::Interact:
        break;
    case protocol::Interact::Type::Attack:
        if (player != nullptr && player->_gamemode != player_attributes::Gamemode::Creative) {
            player->attack(_pos);
            player->sendHealth();
        } else if (target != nullptr) {
            target->attack(_pos);
        }
        _foodExhaustionLevel += player_attributes::FOOD_EXHAUSTION_ATTACK;
        break;
    case protocol::Interact::Type::InteractAt:
        break;
    default:
        LERROR("Got a Interact with an unknown type: ", (int32_t) pck->type);
    }
    LDEBUG("Got a Interact");
}

void Player::_onJigsawGenerate(UNUSED const std::shared_ptr<protocol::JigsawGenerate> &pck) { LDEBUG("Got a Jigsaw Generate"); }

void Player::_onKeepAliveResponse(const std::shared_ptr<protocol::KeepAliveResponse> &pck)
{
    if (pck->keepAliveId != _keepAliveId) {
        LERROR("Got a Keep Alive Response with a wrong ID: ", pck->keepAliveId, " (expected ", _keepAliveId, ")");
        this->disconnect("Wrong Keep Alive ID");
        return;
    }

    _keepAliveId = 0;
    LDEBUG("Got a Keep Alive Response");
}

void Player::_onLockDifficulty(UNUSED const std::shared_ptr<protocol::LockDifficulty> &pck) { LDEBUG("Got a Lock Difficulty"); }

void Player::_onSetPlayerPosition(const std::shared_ptr<protocol::SetPlayerPosition> &pck)
{
    LDEBUG("Got a Set Player Position (", pck->x, ", ", pck->feetY, ", ", pck->z, ")");
    // TODO: Validate the position
    this->setPosition(pck->x, pck->feetY, pck->z, pck->onGround);
}

void Player::_onSetPlayerPositionAndRotation(const std::shared_ptr<protocol::SetPlayerPositionAndRotation> &pck)
{
    LDEBUG("Got a Set Player Position And Rotation (", pck->x, ", ", pck->feetY, ", ", pck->z, ")");
    // TODO: Validate the position
    this->setPosition(pck->x, pck->feetY, pck->z, pck->onGround);
    this->setRotation(pck->yaw, pck->pitch);
}

void Player::_onSetPlayerRotation(const std::shared_ptr<protocol::SetPlayerRotation> &pck)
{
    LDEBUG("Got a Set Player Rotation");
    this->setRotation(pck->yaw, pck->pitch);
}

void Player::_onSetPlayerOnGround(UNUSED const std::shared_ptr<protocol::SetPlayerOnGround> &pck) { LDEBUG("Got a Set Player On Ground"); }

void Player::_onMoveVehicle(UNUSED const std::shared_ptr<protocol::MoveVehicle> &pck) { LDEBUG("Got a Move Vehicle"); }

void Player::_onPaddleBoat(UNUSED const std::shared_ptr<protocol::PaddleBoat> &pck) { LDEBUG("Got a Paddle Boat"); }

void Player::_onPickItem(UNUSED const std::shared_ptr<protocol::PickItem> &pck) { LDEBUG("Got a Pick Item"); }

void Player::_onPlaceRecipe(UNUSED const std::shared_ptr<protocol::PlaceRecipe> &pck) { LDEBUG("Got a Place Recipe"); }

void Player::_onPlayerAbilities(const std::shared_ptr<protocol::PlayerAbilities> &pck)
{
    this->_isFlying = pck->flags & protocol::PlayerAbilities::Flags::Flying;
    uint8_t flags = this->_isFlying ? protocol::PlayerAbilities::Flags::Flying : 0x00;
    flags |= protocol::PlayerAbilities::Flags::Invulnerable | protocol::PlayerAbilities::Flags::AllowFlying | protocol::PlayerAbilities::Flags::CreativeMode;
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
            this->getDimension()->updateBlock(pck->location, 0);
        break;
    case protocol::PlayerAction::Status::CancelledDigging:
        break;
    case protocol::PlayerAction::Status::FinishedDigging:
        this->getDimension()->updateBlock(pck->location, 0);
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
    if (pck->actionId == protocol::PlayerCommand::ActionId::StartSprinting) {
        _isSprinting = true;
    }
    if (pck->actionId == protocol::PlayerCommand::ActionId::StopSprinting) {
        _isSprinting = false;
    }
}

void Player::_onPlayerInput(UNUSED const std::shared_ptr<protocol::PlayerInput> &pck) { LDEBUG("Got a Player Input"); }

void Player::_onPong(UNUSED const std::shared_ptr<protocol::Pong> &pck) { LDEBUG("Got a Pong"); }

void Player::_onPlayerSession(UNUSED const std::shared_ptr<protocol::PlayerSession> &pck) { LDEBUG("Got a Player Session"); }

void Player::_onChangeRecipeBookSettings(UNUSED const std::shared_ptr<protocol::ChangeRecipeBookSettings> &pck) { LDEBUG("Got a Change Recipe Book Settings"); }

void Player::_onSetSeenRecipe(UNUSED const std::shared_ptr<protocol::SetSeenRecipe> &pck) { LDEBUG("Got a Set Seen Recipe"); }

void Player::_onRenameItem(UNUSED const std::shared_ptr<protocol::RenameItem> &pck) { LDEBUG("Got a Rename Item"); }

void Player::_onResourcePack(UNUSED const std::shared_ptr<protocol::ResourcePack> &pck) { LDEBUG("Got a Resource Pack"); }

void Player::_onSeenAdvancements(UNUSED const std::shared_ptr<protocol::SeenAdvancements> &pck) { LDEBUG("Got a Seen Advancements"); }

void Player::_onSelectTrade(UNUSED const std::shared_ptr<protocol::SelectTrade> &pck) { LDEBUG("Got a Select Trade"); }

void Player::_onSetBeaconEffect(UNUSED const std::shared_ptr<protocol::SetBeaconEffect> &pck) { LDEBUG("Got a Set Beacon Effect"); }

void Player::_onSetHeldItem(const std::shared_ptr<protocol::SetHeldItem> &pck)
{
    this->_heldItem = pck->slot;
    LDEBUG("Got a Set Held Item");
}

void Player::_onProgramCommandBlock(UNUSED const std::shared_ptr<protocol::ProgramCommandBlock> &pck) { LDEBUG("Got a Program Command Block"); }

void Player::_onProgramCommandBlockMinecart(UNUSED const std::shared_ptr<protocol::ProgramCommandBlockMinecart> &pck) { LDEBUG("Got a Program Command Block Minecart"); }

void Player::_onSetCreativeModeSlot(UNUSED const std::shared_ptr<protocol::SetCreativeModeSlot> &pck) { LDEBUG("Got a Set Creative Mode Slot"); }

void Player::_onProgramJigsawBlock(UNUSED const std::shared_ptr<protocol::ProgramJigsawBlock> &pck) { LDEBUG("Got a Program Jigsaw Block"); }

void Player::_onProgramStructureBlock(UNUSED const std::shared_ptr<protocol::ProgramStructureBlock> &pck) { LDEBUG("Got a Program Structure Block"); }

void Player::_onUpdateSign(UNUSED const std::shared_ptr<protocol::UpdateSign> &pck) { LDEBUG("Got a Update Sign"); }

void Player::_onSwingArm(const std::shared_ptr<protocol::SwingArm> &pck)
{
    LDEBUG("Got a Swing Arm");
    for (auto i : this->getDimension()->getPlayers()) {
        if (i->getId() == this->getId())
            continue;
        i->sendSwingArm(pck->hand == protocol::SwingArm::Hand::MainHand, this->getId());
    }
}

void Player::_onTeleportToEntity(UNUSED const std::shared_ptr<protocol::TeleportToEntity> &pck) { LDEBUG("Got a Teleport To Entity"); }

void Player::_onUseItemOn(const std::shared_ptr<protocol::UseItemOn> &pck)
{
    LDEBUG("Got a Use Item On ", pck->location, " -> ", this->_heldItem);
    switch (pck->face) {
    case protocol::UseItemOn::Face::Bottom:
        pck->location.y--;
        break;
    case protocol::UseItemOn::Face::Top:
        pck->location.y++;
        break;
    case protocol::UseItemOn::Face::North:
        pck->location.z--;
        break;
    case protocol::UseItemOn::Face::South:
        pck->location.z++;
        break;
    case protocol::UseItemOn::Face::West:
        pck->location.x--;
        break;
    case protocol::UseItemOn::Face::East:
        pck->location.x++;
        break;
    }
    switch (this->_heldItem) {
    case 0:
        this->getDimension()->updateBlock(pck->location, Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE));
        break;
    case 1:
        this->getDimension()->updateBlock(pck->location, Blocks::Dirt::toProtocol());
        break;
    case 2:
        this->getDimension()->updateBlock(pck->location, Blocks::Bedrock::toProtocol());
        break;
    case 3:
        this->getDimension()->updateBlock(pck->location, Blocks::OakLog::toProtocol(Blocks::OakLog::Properties::Axis::Y));
        break;
    case 4:
        this->getDimension()->updateBlock(
            pck->location,
            Blocks::OakLeaves::toProtocol(
                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
            )
        );
        break;
    case 5:
        this->getDimension()->updateBlock(pck->location, Blocks::Glass::toProtocol());
        break;
    case 6:
        this->getDimension()->updateBlock(pck->location, Blocks::Cobblestone::toProtocol());
        break;
    case 7:
        this->getDimension()->updateBlock(pck->location, Blocks::PinkTerracotta::toProtocol());
        break;
    case 8:
        this->getDimension()->updateBlock(pck->location, Blocks::PurpleCarpet::toProtocol());
        break;
    }
}

void Player::_onUseItem(UNUSED const std::shared_ptr<protocol::UseItem> &pck) { LDEBUG("Got a Use Item"); }

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

    // TODO: Fix that to the real values (currently it's in easy and it's locked for the client)
    this->sendChangeDifficulty({1, true});

    this->sendPlayerAbilities(
        {(uint8_t) protocol::PlayerAbilitiesClient::Flags::Invulnerable | (uint8_t) protocol::PlayerAbilitiesClient::Flags::Flying |
             (uint8_t) protocol::PlayerAbilitiesClient::Flags::AllowFlying | (uint8_t) protocol::PlayerAbilitiesClient::Flags::CreativeMode,
         0.05, 0.1}
    );
    // TODO: send the value stored in the player data
    this->sendSetHeldItem({4});

    // TODO: send the recipes
    this->sendUpdateRecipes({});

    // TODO: send the tags
    this->sendUpdateTags({});

    // TODO: implement the event Statues correctly // 24 (set op permission level)
    this->sendEntityEvent({this->_id, 24});

    // TODO: send all the commands avaliable in the server
    this->sendCommands({{}, 0});

    // TODO: send the player recipies book
    this->sendUpdateRecipiesBook({});

    this->teleport({8.5, 100, 8.5}); // TODO: change that to player_attributes::DEFAULT_SPAWN_POINT

    this->sendServerData({false, "", false, "", false});

    _dim->addEntity(shared_from_this());
    _dim->addPlayer(dynamic_pointer_cast<Player>(shared_from_this()));
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
    this->sendInitializeWorldBorder({0, 0, 0, 10000, 0, 29999984, 10, 10});

    this->sendSetDefaultSpawnPosition({{0, 100, 0}, 0.0f});

    this->sendSetContainerContent({0, 0, {}, {false}});

    // TODO: set entity metadata
    // this->sendEntityMetadata({this->_id, {}});

    // TODO: send the player's attributes
    this->sendUpdateAttributes({this->getId(), {}});

    // TODO: send the player's advancements
    this->sendUpdateAdvancements({false, {}, {}, {}});

    this->sendHealth();

    // TODO: send the player's experience
    this->sendSetExperience({0, 0, 0});

    // TODO: set entity metadata

    // for (auto &player : this->_player->getDimension()->getPlayerList())
    //     player->_synchronizePostion({0, -58, 0});
    // this->_player->sendChunkAndLightUpdate(0, 0);
    getDimension()->spawnPlayer(*this);
    this->teleport({8.5, 100, 8.5}); // TODO: change that to player_attributes::DEFAULT_SPAWN_POINT

    // send scoreboard status (objectives and teams)
    _dim->getWorld()->getWorldGroup()->getScoreboard().sendScoreboardStatus(*this);

    // Send login message
    chat::Message connectionMsg = chat::Message::fromTranslationKey<chat::message::TranslationKey::MultiplayerPlayerJoined>(*this);

    this->getWorld()->getChat()->sendSystemMessage(connectionMsg, *this);
}

void Player::_unloadChunk(int32_t x, int32_t z)
{
    if (!this->_chunks.contains({x, z}))
        return;
    else if (this->_chunks[{x, z}] == ChunkState::Loading) {
        this->_dim->removePlayerFromLoadingChunk({x, z}, dynamic_pointer_cast<Player>(shared_from_this()));
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
