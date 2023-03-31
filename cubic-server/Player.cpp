#include <cstdint>
#include <string>
#include <iostream>
#include <sstream>

#include "Player.hpp"
#include "Server.hpp"
#include "command_parser/CommandParser.hpp"
#include "protocol/ClientPackets.hpp"
#include <cstdint>
#include "World.hpp"
#include "blocks.hpp"

Player::Player(Client *cli, std::shared_ptr<Dimension> dim, u128 uuid, const std::string &username):
    _cli(cli),
    Entity(dim),
    _uuid(uuid),
    _username(username),
    _keepAliveId(0),
    _keepAliveIgnored(0),
    _gamemode(0),
    _keepAliveClock(200, std::bind(&Player::_processKeepAlive, this)) // 5 seconds for keep-alives
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
}

Player::~Player()
{
    // Send a disconnect message to the chat
    chat::Message disconnectMsg = chat::Message("", {
        .color = "yellow",
        .translate = "multiplayer.player.left",
        .with = std::vector<chat::Message>({
            chat::Message(
                this->getUsername(),
                {
                    .insertion = this->getUsername(),
                },
                chat::message::ClickEvent(
                    chat::message::ClickEvent::Action::SuggestCommand,
                    "/tell " + this->getUsername()
                ),
                chat::message::HoverEvent(
                    chat::message::HoverEvent::Action::ShowEntity,
                    "{\"type\": \"minecraft:player\", \"id\": \"" + this->getUuidString() + "\", \"name\": \"" + this->getUsername() + "\"}"
                )
            )
        })
    });

    this->_dim->getWorld()->sendPlayerInfoRemovePlayer(this);
    this->_dim->removeEntity(this);

    // Send a disconnect message
    this->_dim->getWorld()->getChat()->sendSystemMessage(
        disconnectMsg,
        false,
        this->_dim->getWorld()->getWorldGroup()
    );
    // _player->_dim->getWorld()->getChat()->sendPlayerMessage(
    //     disconnectMsg,
    //     _player
    // );
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
            i->sendUpdateEntityPositionAndRotation({
                this->getId(),
                deltaX,
                deltaY,
                deltaZ,
                this->_rot.x,
                this->_rot.y,
                true
            });
            i->sendHeadRotation({
                this->getId(),
                _rot.x
            });
        }
    } else if (updatePos && !updateRot) {
        for (auto i : this->getDimension()->getPlayerList()) {
            if (i->getId() == this->getId())
                continue;
            i->sendUpdateEntityPosition({
                this->getId(),
                deltaX,
                deltaY,
                deltaZ,
                true
            });
        }
    } else if (!updatePos && updateRot) {
        for (auto i : this->getDimension()->getPlayerList()) {
            if (i->getId() == this->getId())
                continue;
            i->sendUpdateEntityRotation({
                this->getId(),
                this->_rot.x,
                this->_rot.y,
                true
            });
            i->sendHeadRotation({
                this->getId(),
                _rot.x
            });
        }
    }

    if (_pos.y < -100)
        teleport({_pos.x, -58, _pos.z});
}

Client *Player::getClient() const
{
    return _cli;
}

const std::string &Player::getUsername() const
{
    return _username;
}

const u128 &Player::getUuid() const
{
    return _uuid;
}

uint16_t Player::getHeldItem() const
{
    return this->_heldItem;
}

const std::string &Player::getUuidString() const
{
    return this->_uuidString;
}

uint8_t Player::getGamemode() const
{
    return _gamemode;
}

void Player::setGamemode(uint8_t gamemode)
{
    _gamemode = gamemode;
}

void Player::disconnect(const chat::Message &reason)
{
    auto pck = protocol::createPlayDisconnect({
        reason.serialize()
    });
    this->_cli->_sendData(*pck);
    this->_cli->_is_running = false;
    LDEBUG("Sent a disconnect play packet");
}

#pragma region ClientBound

long Player::keepAliveId() const
{
    return _keepAliveId;
}

void Player::setKeepAliveId(long id)
{
    _keepAliveId = id;
}

void Player::setKeepAliveIgnored(uint8_t ign)
{
    _keepAliveIgnored = ign;
}

uint8_t Player::keepAliveIgnored() const
{
    return _keepAliveIgnored;
}

void Player::setPosition(const Vector3<double> &pos)
{
    auto newChunkPos = Position2D(transformBlockPosToChunkPos(pos.x), transformBlockPosToChunkPos(pos.z));
    auto oldChunkPos = Position2D(transformBlockPosToChunkPos(_pos.x), transformBlockPosToChunkPos(_pos.z));

    Entity::setPosition(pos);

    _updateRenderedChunks(oldChunkPos, newChunkPos);
}

void Player::setPosition(double x, double y, double z)
{
    this->setPosition({x, y, z});
}

void Player::playSoundEffect(SoundsList sound, FloatingPosition position, SoundCategory category)
{
    auto pck = protocol::createSoundEffect({
        (int32_t) sound,
        (int32_t) category,
        // https://wiki.vg/Data_types#Fixed-point_numbers
        static_cast<int32_t>(position.x * 32.0),
        static_cast<int32_t>(position.y * 32.0),
        static_cast<int32_t>(position.z * 32.0),
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
        (int32_t) sound,
        (int32_t) category,
        entity->getId(),
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
        sound,
        (int32_t) category,
        // https://wiki.vg/Data_types#Fixed-point_numbers
        static_cast<int32_t>(position.x * 32.0),
        static_cast<int32_t>(position.y * 32.0),
        static_cast<int32_t>(position.z * 32.0),
        0.5, // TODO: get the right volume
        1.0, // TODO: get the right pitch
        0 // TODO: get the right seed
    });
    this->_cli->_sendData(*pck);
    LDEBUG("Sent a custom sound effect packet");
}

void Player::stopSound(uint8_t flags, SoundCategory category, std::string sound)
{
    auto pck = protocol::createStopSound({
        flags,
        (int32_t) category,
        sound
    });
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

void Player::sendUpdateTime(const protocol::UpdateTime &data)
{
    auto pck = protocol::createUpdateTime(data);
    this->_cli->_sendData(*pck);

    LDEBUG("Sent an Update Time packet");
}

void Player::sendChatMessageResponse(const protocol::PlayerChatMessage &packet)
{
    // auto pck = protocol::createPlayerChatMessage(packet);
    // this->_cli->_sendData(*pck);

    // LDEBUG("Sent a chat message response");
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
        0,
        0,
        0x08 | 0x10,
        0,
        true,

    });
    this->_cli->_sendData(*pck);
}

void Player::sendChunkAndLightUpdate(const Position2D &pos)
{
    this->sendChunkAndLightUpdate(pos.x, pos.z);
}

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
        nbt::Compound("", {
            motionBlockingList,
            worldSurfaceList
        }),
        chunk,
        {}, // TODO: BlockEntities
        false, // Trust Edges: If edges should be trusted for light updates.
        {}, // TODO: Sky light mask
        {}, // TODO: Block light mask
        {}, // TODO: empty sky light mask
        {}, // TODO: empty block light mask
        {}, // TODO: sky light
        {}  // TODO: block light
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
    auto pck = protocol::createEntityAnimation(
        main_hand ? protocol::EntityAnimationID::SwingMainArm : protocol::EntityAnimationID::SwingOffHand,
        swinger_id
    );
    _cli->_sendData(*pck);
}

void Player::sendTeleportEntity(int32_t id, const Vector3<double> &pos)
{
    auto pck = protocol::createTeleportEntity({
        id,
        pos.x,
        pos.y,
        pos.z
    });
    _cli->_sendData(*pck);
    LDEBUG("Sent a Teleport Entity");
}

void Player::sendPlayerAbilities(const protocol::PlayerAbilitiesClient &packet)
{
    auto pck = protocol::createPlayerAbilities(packet);
    _cli->_sendData(*pck);
    LDEBUG("Sent a Player Abilities packet");
}

#pragma endregion
#pragma region ServerBound

void Player::_onConfirmTeleportation(const std::shared_ptr<protocol::ConfirmTeleportation> &pck)
{
    LDEBUG("Got a Confirm Teleportation");
}

void Player::_onQueryBlockEntityTag(const std::shared_ptr<protocol::QueryBlockEntityTag> &pck)
{
    LDEBUG("Got a Query Block Entity Tag");
}

void Player::_onChangeDifficulty(const std::shared_ptr<protocol::ChangeDifficulty> &pck)
{
    LDEBUG("Got a Change difficulty");
}

// Receive a chat message from the client, transmit it to the chat system.
void Player::_onChatMessage(const std::shared_ptr<protocol::ChatMessage> &pck)
{
    // TODO: verify that the message is valid (signature, etc.)
    _dim->getWorld()->getChat()->sendPlayerMessage(pck->message, this);
    LDEBUG("Got a Chat Message");
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

void Player::_onClientCommand(const std::shared_ptr<protocol::ClientCommand> &pck)
{
    LDEBUG("Got a Client Command");
}

void Player::_onClientInformation(const std::shared_ptr<protocol::ClientInformation> &pck)
{
    LDEBUG("Got a Client Information");
}

void Player::_onCommandSuggestionRequest(const std::shared_ptr<protocol::CommandSuggestionRequest> &pck)
{
    LDEBUG("Got a Command Suggestion Request");
}

void Player::_onClickContainerButton(const std::shared_ptr<protocol::ClickContainerButton> &pck)
{
    LDEBUG("Got a Click Container Button");
}

void Player::_onCloseContainerRequest(const std::shared_ptr<protocol::CloseContainerRequest> &pck)
{
    LDEBUG("Got a Close Container Request");
}

void Player::_onPluginMessage(const std::shared_ptr<protocol::PluginMessage> &pck)
{
    LDEBUG("Got a Plugin Message");
    if (pck->channel == "minecraft:brand") {
        LDEBUG("Got a branding request");
        auto pck = protocol::createPluginMessageResponse({
            "minecraft:brand",
            std::vector<uint8_t>({0x05, 0x43, 0x75, 0x62, 0x69, 0x63}) // 43 75 62 69 63 | "Cubic" in hex
        });
        _cli->_sendData(*pck);
        return;
    }
}

void Player::_onEditBook(const std::shared_ptr<protocol::EditBook> &pck)
{
    LDEBUG("Got a Edit Book");
}

void Player::_onQueryEntityTag(const std::shared_ptr<protocol::QueryEntityTag> &pck)
{
    LDEBUG("Got a Query Entity Tag");
}

void Player::_onInteract(const std::shared_ptr<protocol::Interact> &pck)
{
    LDEBUG("Got a Interact");
}

void Player::_onJigsawGenerate(const std::shared_ptr<protocol::JigsawGenerate> &pck)
{
    LDEBUG("Got a Jigsaw Generate");
}

void Player::_onKeepAliveResponse(const std::shared_ptr<protocol::KeepAliveResponse> &pck)
{
    if (pck->keep_alive_id != _keepAliveId) {
        LERROR("Got a Keep Alive Response with a wrong ID: ", pck->keep_alive_id, " (expected ",_keepAliveId, ")");
        this->disconnect("Wrong Keep Alive ID");
        return;
    }

    _keepAliveId = 0;
    LDEBUG("Got a Keep Alive Response");
}

void Player::_onLockDifficulty(const std::shared_ptr<protocol::LockDifficulty> &pck)
{
    LDEBUG("Got a Lock Difficulty");
}

void Player::_onSetPlayerPosition(const std::shared_ptr<protocol::SetPlayerPosition> &pck)
{
    LDEBUG("Got a Set Player Position (", pck->x, ", ", pck->feet_y, ", ", pck->z, ")");
    // TODO: Validate the position
    this->setPosition(pck->x, pck->feet_y, pck->z);
}

void Player::_onSetPlayerPositionAndRotation(const std::shared_ptr<protocol::SetPlayerPositionAndRotation> &pck)
{
    LDEBUG("Got a Set Player Position And Rotation (", pck->x, ", ", pck->feet_y, ", ", pck->z, ")");
    // TODO: Validate the position
    this->setPosition(pck->x, pck->feet_y, pck->z);
    float yaw_tmp = pck->yaw;
    while (yaw_tmp < 0)
        yaw_tmp += 360;
    while (yaw_tmp > 360)
        yaw_tmp -= 360;
    this->setRotation(yaw_tmp, pck->pitch/1.5);
}

void Player::_onSetPlayerRotation(const std::shared_ptr<protocol::SetPlayerRotation> &pck)
{
    LDEBUG("Got a Set Player Rotation");
    this->setRotation(pck->yaw, pck->pitch/1.5);
}

void Player::_onSetPlayerOnGround(const std::shared_ptr<protocol::SetPlayerOnGround> &pck)
{
    LDEBUG("Got a Set Player On Ground");
}

void Player::_onMoveVehicle(const std::shared_ptr<protocol::MoveVehicle> &pck)
{
    LDEBUG("Got a Move Vehicle");
}

void Player::_onPaddleBoat(const std::shared_ptr<protocol::PaddleBoat> &pck)
{
    LDEBUG("Got a Paddle Boat");
}

void Player::_onPickItem(const std::shared_ptr<protocol::PickItem> &pck)
{
    LDEBUG("Got a Pick Item");
}

void Player::_onPlaceRecipe(const std::shared_ptr<protocol::PlaceRecipe> &pck)
{
    LDEBUG("Got a Place Recipe");
}

void Player::_onPlayerAbilities(const std::shared_ptr<protocol::PlayerAbilities> &pck)
{
    this->_isFlying = pck->flags & protocol::PlayerAbilitiesFlags::Flying;
    uint8_t flags = this->_isFlying ? protocol::PlayerAbilitiesFlags::Flying : 0x00;
    flags |= protocol::PlayerAbilitiesFlags::Invulnerable | protocol::PlayerAbilitiesFlags::AllowFlying| protocol::PlayerAbilitiesFlags::CreativeMode;
    this->sendPlayerAbilities({
        flags,
        0.05f,
        0.1f
    });
    LDEBUG("Got a Player Abilities");
}

void Player::_onPlayerAction(const std::shared_ptr<protocol::PlayerAction> &pck)
{
    // LINFO("Got a Player Action ", pck->status, " at ", pck->location);
    LDEBUG("Got a Player Action and player is in gamemode ", this->getGamemode(), " and status is ", pck->status);
    if (pck->status == 0 && this->getGamemode() == 1) {
        this->getDimension()->blockUpdate(pck->location, 0);
    } else if (pck->status == 2) {
        this->getDimension()->blockUpdate(pck->location, 0);
    }
}

void Player::_onPlayerCommand(const std::shared_ptr<protocol::PlayerCommand> &pck)
{
    LDEBUG("Got a Player Command");
}

void Player::_onPlayerInput(const std::shared_ptr<protocol::PlayerInput> &pck)
{
    LDEBUG("Got a Player Input");
}

void Player::_onPong(const std::shared_ptr<protocol::Pong> &pck)
{
    LDEBUG("Got a Pong");
}

void Player::_onChangeRecipeBookSettings(const std::shared_ptr<protocol::ChangeRecipeBookSettings> &pck)
{
    LDEBUG("Got a Change Recipe Book Settings");
}

void Player::_onSetSeenRecipe(const std::shared_ptr<protocol::SetSeenRecipe> &pck)
{
    LDEBUG("Got a Set Seen Recipe");
}

void Player::_onRenameItem(const std::shared_ptr<protocol::RenameItem> &pck)
{
    LDEBUG("Got a Rename Item");
}

void Player::_onResourcePack(const std::shared_ptr<protocol::ResourcePack> &pck)
{
    LDEBUG("Got a Resource Pack");
}

void Player::_onSeenAdvancements(const std::shared_ptr<protocol::SeenAdvancements> &pck)
{
    LDEBUG("Got a Seen Advancements");
}

void Player::_onSelectTrade(const std::shared_ptr<protocol::SelectTrade> &pck)
{
    LDEBUG("Got a Select Trade");
}

void Player::_onSetBeaconEffect(const std::shared_ptr<protocol::SetBeaconEffect> &pck)
{
    LDEBUG("Got a Set Beacon Effect");
}

void Player::_onSetHeldItem(const std::shared_ptr<protocol::SetHeldItem> &pck)
{
    this->_heldItem = pck->slot;
    LDEBUG("Got a Set Held Item");
}

void Player::_onProgramCommandBlock(const std::shared_ptr<protocol::ProgramCommandBlock> &pck)
{
    LDEBUG("Got a Program Command Block");
}

void Player::_onProgramCommandBlockMinecart(const std::shared_ptr<protocol::ProgramCommandBlockMinecart> &pck)
{
    LDEBUG("Got a Program Command Block Minecart");
}

void Player::_onProgramJigsawBlock(const std::shared_ptr<protocol::ProgramJigsawBlock> &pck)
{
    LDEBUG("Got a Program Jigsaw Block");
}

void Player::_onProgramStructureBlock(const std::shared_ptr<protocol::ProgramStructureBlock> &pck)
{
    LDEBUG("Got a Program Structure Block");
}

void Player::_onUpdateSign(const std::shared_ptr<protocol::UpdateSign> &pck)
{
    LDEBUG("Got a Update Sign");
}

void Player::_onSwingArm(const std::shared_ptr<protocol::SwingArm> &pck)
{
    LDEBUG("Got a Swing Arm");
    for (auto i : this->getDimension()->getPlayerList()) {
        if (i->getId() == this->getId())
            continue;
        i->sendSwingArm(pck->hand == 0, this->getId());
    }
}

void Player::_onTeleportToEntity(const std::shared_ptr<protocol::TeleportToEntity> &pck)
{
    LDEBUG("Got a Teleport To Entity");
}

void Player::_onUseItemOn(const std::shared_ptr<protocol::UseItemOn> &pck)
{
    LDEBUG("Got a Use Item On ", pck->location, " -> ", this->_heldItem);
    switch (pck->face)
    {
        case 0: pck->location.y--; break;
        case 1: pck->location.y++; break;
        case 2: pck->location.z--; break;
        case 3: pck->location.z++; break;
        case 4: pck->location.x--; break;
        case 5: pck->location.x++; break;
    }
    switch (this->_heldItem) {
        case 0: this->getDimension()->blockUpdate(pck->location, Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE)); break;
        case 1: this->getDimension()->blockUpdate(pck->location, Blocks::Dirt::toProtocol()); break;
        case 2: this->getDimension()->blockUpdate(pck->location, Blocks::Bedrock::toProtocol()); break;
        case 3: this->getDimension()->blockUpdate(pck->location, Blocks::OakLog::toProtocol(Blocks::OakLog::Properties::Axis::Y)); break;
        case 4: this->getDimension()->blockUpdate(pck->location, Blocks::OakLeaves::toProtocol(
                                    Blocks::OakLeaves::Properties::Distance::ONE,
                                    Blocks::OakLeaves::Properties::Persistent::FALSE,
                                    Blocks::OakLeaves::Properties::Waterlogged::FALSE)); break;
        case 5: this->getDimension()->blockUpdate(pck->location, Blocks::Glass::toProtocol()); break;
        case 6: this->getDimension()->blockUpdate(pck->location, Blocks::Cobblestone::toProtocol()); break;
        case 7: this->getDimension()->blockUpdate(pck->location, Blocks::PinkTerracotta::toProtocol()); break;
        case 8: this->getDimension()->blockUpdate(pck->location, Blocks::PurpleCarpet::toProtocol()); break;
    }
}

void Player::_onUseItem(const std::shared_ptr<protocol::UseItem> &pck)
{
    LDEBUG("Got a Use Item");
}

#pragma endregion Serverbound

void Player::_processKeepAlive()
{
    long id = std::chrono::system_clock::now().time_since_epoch().count();
    if (this->keepAliveId() != 0) {
        this->setKeepAliveIgnored(this->keepAliveIgnored() + 1);
        if (this->_keepAliveClock.tickRate() * this->keepAliveIgnored() >= 6000)
            this->disconnect("Timed out from keep alive LOL");
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
        for (int32_t x = oldChunkPos.x - renderDistance ; x < oldChunkPos.x + renderDistance + 1 + (newChunkPos.x - oldChunkPos.x); x++)
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

void Player::_continueLoginSequence() {
    this->sendFeatureFlags({
        {"minecraft:vanilla"}
    });

    this->sendPlayerAbilities({
        (uint8_t)protocol::PlayerAbilitiesFlags::Invulnerable |
            (uint8_t)protocol::PlayerAbilitiesFlags::Flying |
            (uint8_t)protocol::PlayerAbilitiesFlags::AllowFlying |
            (uint8_t)protocol::PlayerAbilitiesFlags::CreativeMode,
        0.05,
        0.1
    });

    // TODO: set Held Item

    // TODO: update recipes

    // TODO: update tags

    // TODO: entity event ?

    // TODO: command list

    // TODO: update recipes book

    this->teleport({8.5, 100, 8.5});

    this->sendServerData({
        false,
        "",
        false,
        "",
        false
    });

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
    // for (auto &player : this->_player->getDimension()->getPlayerList())
    //     player->_synchronizePostion({0, -58, 0});
    // this->_player->sendChunkAndLightUpdate(0, 0);
    getDimension()->spawnPlayer(this);
    this->teleport({8.5, 100, 8.5});

    this->_sendLoginMessage();
}

void Player::_sendLoginMessage(void)
{
    // Send login message
    chat::Message connectionMsg = chat::Message("", {
        .color = "yellow",
        .translate = "multiplayer.player.joined",
        .with = std::vector<chat::Message>({
            chat::Message(
                this->getUsername(),
                {
                    .insertion = this->getUsername(),
                },
                chat::message::ClickEvent(
                    chat::message::ClickEvent::Action::SuggestCommand,
                    "/tell " + this->getUsername() + " "
                ),
                chat::message::HoverEvent(
                    chat::message::HoverEvent::Action::ShowEntity,
                    "{\"type\": \"minecraft:player\", \"id\": \"" + this->getUuidString() + "\", \"name\": \"" + this->getUsername() + "\"}"
                )
            )
        })
    });

    this->getDimension()->getWorld()->getChat()->sendSystemMessage(
        connectionMsg,
        false,
        this->getDimension()->getWorld()->getWorldGroup()
    );
}

void Player::_unloadChunk(int32_t x, int32_t z) {
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

void Player::teleport(const Vector3<double> &pos)
{
    this->sendSynchronizePosition(pos);
    LDEBUG("Synchronized player position");
    Entity::teleport(pos);
}
