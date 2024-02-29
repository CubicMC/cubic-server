#include "Player.hpp"

#include "Chat.hpp"
#include "Client.hpp"
#include "Dimension.hpp"
#include "PlayerAttributes.hpp"
#include "PluginManager.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "blocks.hpp"
#include "command_parser/CommandParser.hpp"
#include "entities/ArmorStats.hpp"
#include "entities/Entity.hpp"
#include "entities/Item.hpp"
#include "entities/LivingEntity.hpp"
#include "events/CancelEvents.hpp"
#include "items/UsableItem.hpp"
#include "items/foodItems.hpp"
#include "items/toolsDamage.hpp"
#include "items/usable-items/FlintAndSteel.hpp"
#include "items/usable-items/Hoe.hpp"
#include "logging/logging.hpp"
#include "nbt.h"
#include "options.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/ServerPackets.hpp"
#include "protocol/Structures.hpp"
#include "protocol/common.hpp"
#include "protocol/container/Container.hpp"
#include "protocol/container/CraftingTable.hpp"
#include "protocol/container/Furnace.hpp"
#include "protocol/container/Inventory.hpp"
#include "protocol/metadata.hpp"
#include "tiles-entities/Furnace.hpp"
#include "world_storage/Level.hpp"

#include <algorithm>
#include <cstdint>
#include <memory>
#include <mutex>
#include <variant>
#include <vector>

#define GET_CLIENT()                 \
    auto client = this->_cli.lock(); \
    if (client == nullptr)           \
    return

Player::Player(std::weak_ptr<Client> cli, std::shared_ptr<Dimension> dim, u128 uuid, const std::string &username):
    LivingEntity(dim, EntityType::Player, uuid),
    _cli(cli),
    _username(username),
    _keepAliveId(0),
    _keepAliveIgnored(0),
    _gamemode(player_attributes::gamemodeFromString(CONFIG["gamemode"].as<std::string>())),
    _keepAliveClock(200, std::bind(&Player::_processKeepAlive, this)), // 5 seconds for keep-alives
    _synchronizeClock(20, std::bind(&Player::synchronize, this)), // 1 seconds for synchronization
    _inventory(std::make_shared<protocol::container::Inventory>()),
    _foodLevel(player_attributes::MAX_FOOD_LEVEL - 4), // TODO: Take this from the saved data
    _foodSaturationLevel(player_attributes::DEFAULT_FOOD_SATURATION_LEVEL), // TODO: Take this from the saved data
    _foodTickTimer(0), // TODO: Take this from the saved data
    _foodExhaustionLevel(0.0f), // TODO: Take this from the saved data
    _respawnPoint(0, 75, 0), // TODO: Take this from the saved data
    _chatVisibility(protocol::ClientInformation::ChatVisibility::Enabled),
    _isFlying(true), // TODO: Take this from the saved data
    _isJumping(false),
    _additionalHearts(0),
    _score(0),
    _skinParts(true, true, true, true, true, true, true),
    _mainHand(MainHand::Right),
    _nbTickBeforeNextAttack(0),
    _windowId(0)
{
    _keepAliveClock.start();
    _heldItem = 0;

    LINFO("Player {} with uuid {} just logged in", this->_username, this->_uuid.toString());
    this->setHealth(20);

    this->setOperator(Server::getInstance()->permissions.isOperator(username));
    this->_inventory->playerInventory().at(12) = protocol::Slot(true, 734, 42);
    this->_inventory->playerInventory().at(13) = protocol::Slot(true, 1, 12);
    this->_inventory->playerInventory().at(15) = protocol::Slot(true, 788, 64);

    // {display:{Name:'[{"text":"Cubic","italic":false}]'}}
    constexpr std::string_view NAME = "[{\"text\":\"Cubic\",\"italic\":false}]";
    constexpr std::string_view NAME_TAG = "Name";
    constexpr std::string_view DISPLAY_TAG = "display";
    auto root = nbt_new_tag_compound();
    auto display = nbt_new_tag_compound();
    auto name = nbt_new_tag_string(NAME.data(), NAME.size());
    nbt_set_tag_name(name, NAME_TAG.data(), NAME_TAG.size());
    nbt_set_tag_name(display, DISPLAY_TAG.data(), DISPLAY_TAG.size());
    nbt_tag_compound_append(display, name);
    nbt_tag_compound_append(root, display);
    Items::Hoe hoe = Items::Hoe("minecraft:wooden_hoe", 756, Items::ItemMaxDurabilityByType::WoodenItem, false, Items::UsabilityType::BothMouseClicksUsable);
    auto hoeRoot = hoe.setNbtTag();
    Items::FlintAndSteel flint = Items::FlintAndSteel();
    auto flintRoot = flint.setNbtTag();

    this->_inventory->playerInventory().at(14) = protocol::Slot(true, 1, 12, root);
    this->_inventory->playerInventory().at(15) = protocol::Slot(true, ITEM_CONVERTER.fromItemToProtocolId("minecraft:obsidian"), 40);
    this->_inventory->playerInventory().at(16) = protocol::Slot(true, flint._numeralId, 1, flintRoot);
    this->_inventory->playerInventory().at(17) = protocol::Slot(true, hoe._numeralId, 1, hoeRoot);
    this->_inventory->playerInventory().at(18) = protocol::Slot(true, ITEM_CONVERTER.fromItemToProtocolId("minecraft:wooden_sword"), 1);
    this->_inventory->playerInventory().at(19) = protocol::Slot(true, ITEM_CONVERTER.fromItemToProtocolId("minecraft:coal"), 1);
    this->_inventory->playerInventory().at(20) = protocol::Slot(true, ITEM_CONVERTER.fromItemToProtocolId("minecraft:oak_log"), 1);
    this->_inventory->playerInventory().at(21) = protocol::Slot(true, ITEM_CONVERTER.fromItemToProtocolId("minecraft:cobblestone"), 10);
    PEXP(incrementPlayerCountGlobal);
}

Player::~Player()
{
    this->_dim->getWorld()->sendPlayerInfoRemovePlayer(this);
    PEXP(decrementPlayerCountGlobal);

    // Send a disconnect message
    onEvent(Server::getInstance()->getPluginManager(), onPlayerLeave, this);
}

void Player::tick()
{
    _keepAliveClock.tick();
    _synchronizeClock.tick();
    if (_nbTickBeforeNextAttack > 0)
        _nbTickBeforeNextAttack--;

    _foodTick();

    Entity::tick();
    if (_pos.y < -100) // TODO: Change that
        teleport({_pos.x, -58, _pos.z});
}

void Player::synchronize()
{
    return;
    // TODO: synchronize further data (for example other entities)
}

std::weak_ptr<Client> Player::getClient() const { return _cli; }

const std::string &Player::getUsername() const { return _username; }

uint8_t Player::getHeldItem() const { return this->_heldItem; }

player_attributes::Gamemode Player::getGamemode() const { return _gamemode; }

const protocol::ClientInformation::ChatVisibility &Player::getChatVisibility() const { return this->_chatVisibility; }

void Player::setGamemode(player_attributes::Gamemode gamemode)
{
    _gamemode = gamemode;

    int8_t defense = 0;
    int8_t toughness = 0;

    for (int16_t armorPos = 0; armorPos < 4; armorPos++) {
        if (!this->getInventory()->armor()[armorPos].present)
            continue;
        for (const armor::ArmorPiece &gear : armor::armors) {
            if (this->getInventory()->armor()[armorPos].itemID == ITEM_CONVERTER.fromItemToProtocolId(gear.item)) {
                defense += gear.protectionLevel;
                toughness += gear.toughnessLevel;
            }
        }
    }
    this->setDefense(defense);
    this->setToughness(toughness);
}

void Player::setOperator(const bool isOp) { this->_isOperator = isOp; }

bool Player::isOperator() const { return this->_isOperator; }

NODISCARD const std::vector<protocol::PlayerProperty> &Player::getProperties() const
{
    static std::vector<protocol::PlayerProperty> def;
    auto client = this->_cli.lock();
    if (client == nullptr)
        return def;
    return client->getProperties();
}

void Player::disconnect(const chat::Message &reason)
{
    GET_CLIENT();
    auto pck = protocol::createPlayDisconnect({reason.serialize()});
    client->doWrite(std::move(pck));
    client->_isRunning = false;
    N_LDEBUG("Sent a disconnect play packet");
    onEvent(Server::getInstance()->getPluginManager(), onPlayerLeave, this);
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

    if (_sprinting && !_isFlying)
        _foodExhaustionLevel += oldPos2d.distance(newPos2d) * player_attributes::FOOD_EXHAUSTION_SPRINTING_MULTIPLIER;
    if (_isJumping) {
        _foodExhaustionLevel += _sprinting ? player_attributes::FOOD_EXHAUSTION_SPRINTING_JUMP : player_attributes::FOOD_EXHAUSTION_JUMP;
        _isJumping = false;
    }

    Entity::setPosition(pos, onGround);

    _updateRenderedChunks(oldChunkPos, newChunkPos);
}

void Player::setPosition(double x, double y, double z, bool onGround) { this->setPosition({x, y, z}, onGround); }

void Player::updatePlayerInfo(const protocol::PlayerInfoUpdate &data)
{
    for (auto [_, dim] : this->getWorld()->getDimensions()) {
        for (auto &player : dim->getPlayers()) {
            player->sendPlayerInfoUpdate(data);
        }
    }
}

void Player::updateEquipment(bool mainHand, UNUSED bool offHand, UNUSED bool boots, UNUSED bool leggings, UNUSED bool chestplate, UNUSED bool helmet)
{
    protocol::SetEquipment equip;

    equip.entityId = this->getId();

    if (mainHand)
        equip.equipment.push_back(std::make_pair(protocol::SetEquipment::EquipmentPosition::MainHand, this->_inventory->hotbar().at(this->_heldItem)));

    for (const auto &player : this->getDimension()->getPlayers()) {
        if (player->getId() != this->getId())
            player->sendSetEquipment(equip);
    }
}

void Player::closeContainer(uint8_t id)
{
    if (id == 0) {
        _inventory->close(dynamicSharedFromThis<Player>());
        return;
    }

    auto it = std::find_if(_containers.begin(), _containers.end(), [id](const std::shared_ptr<const protocol::container::Container> &container) {
        return container->id() == id;
    });
    if (it == _containers.end())
        return;
    (*it)->close(dynamicSharedFromThis<Player>());
    _containers.erase(it);
    sendCloseContainer(id);
}

void Player::playSoundEffect(SoundsList sound, FloatingPosition position, SoundCategory category)
{
    GET_CLIENT();
    auto pck = protocol::createSoundEffect({
        (int32_t) sound, (int32_t) category,
        // https://wiki.vg/Data_types#Fixed-point_numbers
        static_cast<int32_t>(position.x * 32.0), static_cast<int32_t>(position.y * 32.0), static_cast<int32_t>(position.z * 32.0),
        0.5, // TODO: get the right volume
        1.0, // TODO: get the right pitch
        0 // TODO: get the right seed
    });
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a sound effect packet");
}

void Player::playSoundEffect(const protocol::SoundEffect &packet)
{
    GET_CLIENT();
    auto pck = protocol::createSoundEffect(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a sound effect packet");
}

void Player::playSoundEffect(SoundsList sound, const Entity &entity, SoundCategory category)
{
    GET_CLIENT();
    auto pck = protocol::createEntitySoundEffect({
        (int32_t) sound, (int32_t) category, entity.getId(),
        1.0, // TODO: get the right volume
        1.0, // TODO: get the right pitch
        1 // TODO: get the right seed
    });
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a entity sound effect packet");
}

void Player::playSoundEffect(const protocol::EntitySoundEffect &packet)
{
    GET_CLIENT();
    auto pck = protocol::createEntitySoundEffect(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a entity sound effect packet");
}

void Player::stopSound(uint8_t flags, SoundCategory category, std::string sound)
{
    GET_CLIENT();
    auto pck = protocol::createStopSound({flags, (int32_t) category, sound});
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a stop sound packet");
}

void Player::sendBlockUpdate(const protocol::BlockUpdate &packet)
{
    GET_CLIENT();
    auto pck = protocol::createBlockUpdate(packet);
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent a block update at {} = {} to {}", packet.location, packet.blockId, this->getUsername());
}

void Player::sendBlockEntityData(const protocol::BlockEntityData &packet)
{
    GET_CLIENT();
    auto pck = protocol::createBlockEntityData(packet);
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent a block entity data packet");
}

void Player::sendOpenScreen(const protocol::OpenScreen &packet)
{
    GET_CLIENT();
    auto pck = protocol::createOpenScreen(packet);
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent a open screen");
}

void Player::sendFeatureFlags(const protocol::FeatureFlags &packet)
{
    GET_CLIENT();
    auto pck = protocol::createFeatureFlags(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a feature flags packet");
}

void Player::sendServerData(const protocol::ServerData &packet)
{
    GET_CLIENT();
    auto pck = protocol::createServerData(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a server data packet");
}

void Player::sendLoginPlay(const protocol::LoginPlay &packet)
{
    GET_CLIENT();
    auto pck = protocol::createLoginPlay(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a login play");
}

void Player::sendPlayerInfoUpdate(const protocol::PlayerInfoUpdate &data)
{
    GET_CLIENT();
    auto pck = protocol::createPlayerInfoUpdate(data);
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent a Player Info packet");
}

void Player::sendPlayerInfoRemove(const protocol::PlayerInfoRemove &data)
{
    GET_CLIENT();
    auto pck = protocol::createPlayerInfoRemove(data);
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent a Player Info packet");
}

void Player::sendSpawnEntity(const protocol::SpawnEntity &data)
{
    GET_CLIENT();
    auto pck = protocol::createSpawnEntity(data);
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent a Spawn Entity packet");
}

void Player::sendSpawnEntity(const Entity &data)
{
    GET_CLIENT();
    auto pck = protocol::createSpawnEntity({
        data.getId(), // Entity ID
        data.getUuid(), // Entity UUID
        data.getType(), // Entity Type
        data.getPosition().x, // Entity Position X
        data.getPosition().y, // Entity Position Y
        data.getPosition().z, // Entity Position Z
        0, // Entity Pitch
        0, // Entity Yaw
        0, // Entity Head Yaw
        0, // Entity data
        0, // Entity Velocity X
        0, // Entity Velocity Y
        0 // Entity Velocity Z
    });
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent a Spawn Entity packet");
}

void Player::sendSpawnPlayer(const protocol::SpawnPlayer &data)
{
    GET_CLIENT();
    auto pck = protocol::createSpawnPlayer(data);
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent a Spawn Player packet on coords: ({}, {}, {})", data.x, data.y, data.z);
}

void Player::sendEntityVelocity(const protocol::EntityVelocity &data)
{
    GET_CLIENT();
    auto pck = protocol::createEntityVelocity(data);
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent an Entity Velocity packet with velocity: x -> {} | y -> {} | z -> {}", data.velocityX, data.velocityY, data.velocityZ);
}

void Player::sendSetEquipment(const protocol::SetEquipment &data)
{
    GET_CLIENT();
    auto pck = protocol::createSetEquipment(data);
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent a Set Equipment packet");
}

void Player::sendHealth(void)
{
    GET_CLIENT();
    auto pck = protocol::createHealth({_health, _foodLevel, _foodSaturationLevel});
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent a Health packet");
}

void Player::sendUpdateTime(const protocol::UpdateTime &data)
{
    GET_CLIENT();
    auto pck = protocol::createUpdateTime(data);
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent an Update Time packet");
}

void Player::sendChatMessageResponse(UNUSED const protocol::PlayerChatMessage &packet)
{
    GET_CLIENT();
    auto pck = protocol::createPlayerChatMessage(packet);
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent a chat message response");
}

void Player::sendSystemChatMessage(const protocol::SystemChatMessage &packet)
{
    GET_CLIENT();
    auto pck = protocol::createSystemChatMessage(packet);
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent a system chat message to {}", this->getUsername());
}

void Player::sendWorldEvent(const protocol::WorldEvent &packet)
{
    GET_CLIENT();
    auto pck = protocol::createWorldEvent(packet);
    client->doWrite(std::move(pck));

    N_LDEBUG("Sent a world event");
}

void Player::sendKeepAlive(long id)
{
    GET_CLIENT();
    auto pck = protocol::createKeepAlive(id);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a keep alive packet");
}

void Player::sendUpdateEntityPosition(const protocol::UpdateEntityPosition &data)
{
    GET_CLIENT();
    auto pck = protocol::createUpdateEntityPosition(data);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent an entity position packet");
}

void Player::sendUpdateEntityPositionAndRotation(const protocol::UpdateEntityPositionRotation &data)
{
    GET_CLIENT();
    auto pck = protocol::createUpdateEntityPositionRotation(data);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent an entity position and rotation packet");
}

void Player::sendUpdateEntityRotation(const protocol::UpdateEntityRotation &data)
{
    GET_CLIENT();
    auto pck = protocol::createUpdateEntityRotation(data);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent an entity rotation packet");
}

void Player::sendHeadRotation(const protocol::HeadRotation &data)
{
    GET_CLIENT();
    auto pck = protocol::createHeadRotation(data);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent an entity head rotation packet");
}

void Player::sendUpdateSectionBlock(const protocol::UpdateSectionBlock &data)
{
    GET_CLIENT();
    auto pck = protocol::createUpdateSectionBlock(data);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent an UpdateSectionBlock packet");
}

void Player::sendSetCenterChunk(const Position2D &pos)
{
    GET_CLIENT();
    auto pck = protocol::createCenterChunk(pos);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a center chunk packet");
}

void Player::sendSynchronizePosition(const Vector3<double> &pos)
{
    GET_CLIENT();
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
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a synchronize position packet");
}

void Player::sendSynchronizePlayerPosition(const protocol::SynchronizePlayerPosition &data)
{
    GET_CLIENT();
    auto pck = protocol::createSynchronizePlayerPosition(data);
    client->doWrite(std::move(pck));
    LDEBUG("Synchronized player position");
}

void Player::sendSynchronizePlayerPosition()
{
    Vector2<float> rotDegree = this->getRotationDegree();
    GET_CLIENT();
    auto pck = protocol::createSynchronizePlayerPosition({
        this->_pos.x,
        this->_pos.y,
        this->_pos.z,
        static_cast<float>(rotDegree.x),
        static_cast<float>(rotDegree.z),
        0,
        0,
        false,
    });
    client->doWrite(std::move(pck));
    LDEBUG("Synchronized player position");
}

void Player::sendChunkAndLightUpdate(const Position2D &pos) { this->sendChunkAndLightUpdate(pos.x, pos.z); }

void Player::sendChunkAndLightUpdate(int32_t x, int32_t z)
{
    if (!this->_dim->hasChunkLoaded(x, z)) {
        this->_dim->loadOrGenerateChunk(x, z, dynamic_pointer_cast<Player>(shared_from_this()));
        this->_chunks[{x, z}] = ChunkState::Loading;
        return;
    }

    std::lock_guard _(this->getDimension()->_loadingChunksMutex);
    this->sendChunkAndLightUpdate(this->_dim->getChunk(x, z));
}

void Player::sendChunkAndLightUpdate(const world_storage::ChunkColumn &chunk)
{
    GET_CLIENT();
    // auto heightMap = chunk.getHeightMap();
    auto chunkPos = chunk.getChunkPos();

    // std::vector<std::shared_ptr<nbt::Base>> motionBlocking;
    // std::vector<std::shared_ptr<nbt::Base>> worldSurface;
    // motionBlocking.reserve(heightMap.motionBlocking.size());
    // worldSurface.reserve(heightMap.worldSurface.size());

    // for (auto i = 0; i < world_storage::HEIGHTMAP_ARRAY_SIZE; i++) {
    //     motionBlocking.push_back(heightMap.motionBlocking.at(i));
    //     worldSurface.push_back(heightMap.worldSurface.at(i));
    // }

    // auto motionBlockingList = NBT_MAKE(nbt::List, "MOTION_BLOCKING", motionBlocking);
    // auto worldSurfaceList = NBT_MAKE(nbt::List, "WORLD_SURFACE", worldSurface);

    auto packet = protocol::createChunkDataAndLightUpdate(
        {chunkPos.x, chunkPos.z,
         // std::shared_ptr<nbt::Compound>(new nbt::Compound("", {motionBlockingList, worldSurfaceList})),
         chunk}
    );

    client->doWrite(std::move(packet));

    std::lock_guard _(_chunksMutex);
    this->_chunks[chunkPos] = ChunkState::Loaded;

    N_LDEBUG("Sent a chunk data and light update packet {}", chunkPos);
}

void Player::sendUnloadChunk(int32_t x, int32_t z)
{
    GET_CLIENT();
    auto pck = protocol::createUnloadChunk({x, z});
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent an unload chunk packet ({}, {})", x, z);
}

void Player::sendRemoveEntities(const std::vector<int32_t> &entities)
{
    GET_CLIENT();
    auto pck = protocol::createRemoveEntities({entities});
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a Remove Entities packet");
}

void Player::sendRespawn(const protocol::Respawn &packet)
{
    GET_CLIENT();
    auto pck = protocol::createRespawn(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a Respawn packet");
}

void Player::sendSwingArm(bool mainHand, int32_t swingerId)
{
    sendEntityAnimation(mainHand ? protocol::EntityAnimation::ID::SwingMainArm : protocol::EntityAnimation::ID::SwingOffHand, swingerId);
    N_LDEBUG("Sent a Swing Arm packet");
}

void Player::sendEntityAnimation(protocol::EntityAnimation::ID animId, int32_t entityID)
{
    GET_CLIENT();
    auto pck = protocol::createEntityAnimation(animId, entityID);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent an Entity Animation packet");
}

void Player::sendTeleportEntity(int32_t id, const Vector3<double> &pos, const Vector2<uint8_t> &rot)
{
    GET_CLIENT();
    auto pck = protocol::createTeleportEntity({id, pos.x, pos.y, pos.z, rot.x, rot.z, false});
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a Teleport Entity");
}

void Player::sendPlayerAbilities(const protocol::PlayerAbilitiesClient &packet)
{
    GET_CLIENT();
    auto pck = protocol::createPlayerAbilities(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a Player Abilities packet");
}

void Player::sendGameEvent(const protocol::GameEvent &packet)
{
    GET_CLIENT();
    auto pck = protocol::createGameEvent(packet);
    client->doWrite(std::move(pck));
    LDEBUG("Sent a Game Event packet");
}

void Player::sendCloseContainer(uint8_t containerId)
{
    GET_CLIENT();
    auto pck = protocol::createCloseContainer({containerId});
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent a Close Container packet");
}

void Player::sendSetContainerContent(const protocol::SetContainerContent &packet)
{
    GET_CLIENT();
    auto pck = protocol::createSetContainerContent(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent set container content packet");
}

void Player::sendSetContainerProperty(const protocol::SetContainerProperty &packet)
{
    GET_CLIENT();
    auto pck = protocol::createSetContainerProperty(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent set container property packet");
}

void Player::sendSetContainerSlot(const protocol::SetContainerSlot &packet)
{
    GET_CLIENT();
    auto pck = protocol::createSetContainerSlot(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent set container slot packet");
}

void Player::sendUpdateRecipes(const protocol::UpdateRecipes &packet)
{
    GET_CLIENT();
    auto pck = protocol::createUpdateRecipes(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent update recipes packet");
}

void Player::sendUpdateTags(const protocol::UpdateTags &packet)
{
    GET_CLIENT();
    auto pck = protocol::createUpdateTags(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent update tags packet");
}

void Player::sendCommands(const protocol::Commands &packet)
{
    GET_CLIENT();
    auto pck = protocol::createCommands(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent commands packet");
}

void Player::sendChangeDifficulty(const protocol::ChangeDifficultyClient &packet)
{
    GET_CLIENT();
    auto pck = protocol::createChangeDifficultyClient(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent change difficulty packet");
}

void Player::sendSetHeldItem(const protocol::SetHeldItemClient &packet)
{
    GET_CLIENT();
    auto pck = protocol::createSetHeldItemClient(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent set held item packet");
}

void Player::sendEntityEvent(const protocol::EntityEvent &packet)
{
    GET_CLIENT();
    auto pck = protocol::createEntityEvent(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent entity event packet");
}

void Player::sendUpdateRecipiesBook(const protocol::UpdateRecipesBook &packet)
{
    GET_CLIENT();
    auto pck = protocol::createUpdateRecipesBook(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent update recipies book packet");
}

void Player::sendInitializeWorldBorder(const protocol::InitializeWorldBorder &packet)
{
    GET_CLIENT();
    auto pck = protocol::createInitializeWorldBorder(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent initialize world border packet");
}

void Player::sendSetDefaultSpawnPosition(const protocol::SetDefaultSpawnPosition &packet)
{
    GET_CLIENT();
    auto pck = protocol::createSetDefaultSpawnPosition(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent set default spawn position packet");
}

void Player::sendUpdateAttributes(const protocol::UpdateAttributes &packet)
{
    GET_CLIENT();
    auto pck = protocol::createUpdateAttributes(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent update attributes packet");
}

void Player::sendUpdateAdvancements(const protocol::UpdateAdvancements &packet)
{
    GET_CLIENT();
    auto pck = protocol::createUpdateAdvancements(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent update advancements packet");
}

void Player::sendSetExperience(const protocol::SetExperience &packet)
{
    GET_CLIENT();
    auto pck = protocol::createSetExperience(packet);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent set experience packet");
}

void Player::sendUpdateObjective(const protocol::UpdateObjectives &packet)
{
    GET_CLIENT();
    auto pck = protocol::createUpdateObjectives(packet);
    client->doWrite(std::move(pck));
    LDEBUG("Sent update objectives packet");
}

void Player::sendDisplayObjective(const protocol::DisplayObjective &packet)
{
    GET_CLIENT();
    auto pck = protocol::createDisplayObjective(packet);
    client->doWrite(std::move(pck));
    LDEBUG("Sent display objective packet");
}

void Player::sendUpdateScore(const protocol::UpdateScore &packet)
{
    GET_CLIENT();
    auto pck = protocol::createUpdateScore(packet);
    client->doWrite(std::move(pck));
    LDEBUG("Sent update score packet");
}

void Player::sendUpdateTeams(const protocol::UpdateTeams &packet)
{
    GET_CLIENT();
    auto pck = protocol::createUpdateTeams(packet);
    client->doWrite(std::move(pck));
    LDEBUG("Sent update teams packet");
}

void Player::sendPickupItem(const protocol::PickupItem &packet)
{
    GET_CLIENT();
    auto pck = protocol::createPickupItem(packet);
    client->doWrite(std::move(pck));
    LDEBUG("Sent pickup item packet");
}

void Player::sendSubtitleText(const protocol::SetSubtitleText &packet)
{
    GET_CLIENT();
    auto pck = protocol::createSetSubtitleText(packet);
    client->doWrite(std::move(pck));
    LDEBUG("Sent subtitle text packet");
}

void Player::sendTitleText(const protocol::SetTitleText &packet)
{
    GET_CLIENT();
    auto pck = protocol::createSetTitleText(packet);
    client->doWrite(std::move(pck));
    LDEBUG("Sent title text packet");
}

void Player::sendTitleAnimationTimes(const protocol::SetTitleAnimationTimes &packet)
{
    GET_CLIENT();
    auto pck = protocol::createSetTitleAnimationTimes(packet);
    client->doWrite(std::move(pck));
    LDEBUG("Sent title animation times packet");
}

#pragma endregion
#pragma region ServerBound

void Player::_onConfirmTeleportation(UNUSED protocol::ConfirmTeleportation &pck) { N_LDEBUG("Got a Confirm Teleportation"); }

void Player::_onQueryBlockEntityTag(UNUSED protocol::QueryBlockEntityTag &pck) { N_LDEBUG("Got a Query Block Entity Tag"); }

void Player::_onChangeDifficulty(UNUSED protocol::ChangeDifficulty &pck) { N_LDEBUG("Got a Change difficulty"); }

// Receive a chat message from the client, transmit it to the chat system.
void Player::_onChatMessage(protocol::ChatMessage &pck)
{
    // TODO: verify that the message is valid (signature, etc.)
    _dim->getWorld()->getChat()->sendPlayerMessage(pck.message, *this);
    N_LDEBUG("Got a Chat Message");
}

void Player::_onMessageAcknowledgement(UNUSED protocol::MessageAcknowledgement &pck) { N_LINFO("Got a Message Acknowledgement"); }

/**
 * @brief This function is called when a client sends a command in the chat.
 *
 * @param pck The packet recieved from the client.
 */
void Player::_onChatCommand(protocol::ChatCommand &pck)
{
    N_LDEBUG("Got a Chat Command");
    N_LDEBUG("The command is :\"{}\"", pck.command);
    command_parser::parseCommand(pck.command, this);
}

void Player::_onClientCommand(UNUSED protocol::ClientCommand &pck) { N_LDEBUG("Got a Client Command"); }

void Player::_onClientInformation(protocol::ClientInformation &pck)
{
    this->_chatVisibility = pck.chatMode;
    N_LDEBUG("Got a Client Information");
}

void Player::_onCommandSuggestionRequest(UNUSED protocol::CommandSuggestionRequest &pck) { N_LDEBUG("Got a Command Suggestion Request"); }

void Player::_onClickContainerButton(protocol::ClickContainerButton &pck)
{
    N_LDEBUG("Got a Click Container Button");
    if (pck.windowId == 0) {
        _inventory->onButtonClick(dynamicSharedFromThis<Player>(), pck.buttonId);
        return;
    }
    auto it = std::find_if(_containers.begin(), _containers.end(), [&](const auto &container) {
        if (container->id() == pck.windowId)
            return true;
        return false;
    });
    (*it)->onButtonClick(dynamicSharedFromThis<Player>(), pck.buttonId);
}

void Player::_onClickContainer(protocol::ClickContainer &pck)
{
    N_LDEBUG("Got a Click Container");
    if (pck.windowId == 0) {
        _inventory->onClick(dynamicSharedFromThis<Player>(), pck.slot, pck.button, pck.mode, pck.arrayOfSlots);
        return;
    }
    auto it = std::find_if(_containers.begin(), _containers.end(), [&](const auto &container) {
        if (container->id() == pck.windowId)
            return true;
        return false;
    });
    if (it == _containers.end())
        return;
    (*it)->onClick(dynamicSharedFromThis<Player>(), pck.slot, pck.button, pck.mode, pck.arrayOfSlots);
}

void Player::_onCloseContainerRequest(protocol::CloseContainerRequest &pck)
{
    N_LDEBUG("Got a Close Container Request");
    this->closeContainer(pck.windowId);
}

void Player::_onPluginMessage(protocol::PluginMessage &pck)
{
    GET_CLIENT();
    N_LDEBUG("Got a Plugin Message");
    if (pck.channel == "minecraft:brand") {
        N_LDEBUG("Got a branding request");
        auto pck = protocol::createPluginMessageResponse({
            "minecraft:brand", std::vector<uint8_t>({0x05, 0x43, 0x75, 0x62, 0x69, 0x63}) // 43 75 62 69 63 | "Cubic" in hex
        });
        client->doWrite(std::move(pck));
        return;
    }
}

void Player::_onEditBook(UNUSED protocol::EditBook &pck) { N_LDEBUG("Got a Edit Book"); }

void Player::_onQueryEntityTag(UNUSED protocol::QueryEntityTag &pck) { N_LDEBUG("Got a Query Entity Tag"); }

/*
 * @brief Handle a player's interaction with an entity.
 */
void Player::_onInteract(protocol::Interact &pck)
{
    auto target = dynamic_pointer_cast<LivingEntity>(_dim->getEntityByID(pck.entityId));
    auto player = dynamic_pointer_cast<Player>(target);
    if (target == nullptr) {
        N_LERROR("Got a Interact with an invalid target");
        return;
    }

    switch (pck.type) {
    case protocol::Interact::Type::Interact:
        break;
    case protocol::Interact::Type::Attack: {
        onEvent(Server::getInstance()->getPluginManager(), onEntityInteractEntity, this, target.get());
        if (_nbTickBeforeNextAttack > 0) {
            LINFO("Player {} is attacking too fast", this->getUsername());
            return;
        }
        Items::ToolDescription tool;
        const auto currentTool = std::find_if(Items::toolsDamage.begin(), Items::toolsDamage.end(), [&](const auto &tool) {
            return tool.id == _inventory->hotbar().at(_heldItem).itemID;
        });
        if (currentTool == Items::toolsDamage.end()) {
            tool.damage = 1;
            tool.attackSpeed = 4;
        } else {
            tool = *currentTool;
        }
        _nbTickBeforeNextAttack = int(20.0 / tool.attackSpeed);
        if (player != nullptr && player->_gamemode != player_attributes::Gamemode::Creative) {
            player->attack(tool.damage, _pos);
            player->sendHealth();
        } else if (target != nullptr) {
            target->attack(tool.damage, _pos);
        }
        _foodExhaustionLevel += player_attributes::FOOD_EXHAUSTION_ATTACK;
        break;
    }
    case protocol::Interact::Type::InteractAt:
        break;
    default:
        N_LERROR("Got a Interact with an unknown type: ", pck.type);
    }
    N_LDEBUG("Got a Interact");
}

void Player::_onJigsawGenerate(UNUSED protocol::JigsawGenerate &pck) { N_LDEBUG("Got a Jigsaw Generate"); }

void Player::_onKeepAliveResponse(protocol::KeepAliveResponse &pck)
{
    if (pck.keepAliveId != _keepAliveId) {
        N_LERROR("Got a Keep Alive Response with a wrong ID: {} (expected {})", pck.keepAliveId, _keepAliveId);
        this->disconnect("Wrong Keep Alive ID");
        return;
    }

    _keepAliveId = 0;
    N_LDEBUG("Got a Keep Alive Response");
}

void Player::_onLockDifficulty(UNUSED protocol::LockDifficulty &pck) { N_LDEBUG("Got a Lock Difficulty"); }

void Player::playerPickupItem()
{
    auto entity = Entity::pickupItem();
    if (entity != nullptr) {
        auto item = std::dynamic_pointer_cast<Item>(entity)->getItem();
        this->sendPickupItem({entity->getId(), this->getId(), item.itemCount});
        this->_inventory->insert(item);
        this->sendSetContainerContent({_inventory});
        this->getDimension()->removeEntity(entity->getId());
        this->updateEquipment(true, false, false, false, false, false);
    }
}

void Player::_onSetPlayerPosition(protocol::SetPlayerPosition &pck)
{
    N_LDEBUG("Got a Set Player Position ({}, {}, {})", pck.x, pck.feetY, pck.z);
    // TODO: Validate the position
    onEvent(Server::getInstance()->getPluginManager(), onEntityMove, this, _pos, {pck.x, pck.feetY, pck.z});
    this->setPosition(pck.x, pck.feetY, pck.z, pck.onGround);
    playerPickupItem();
}

void Player::_onSetPlayerPositionAndRotation(protocol::SetPlayerPositionAndRotation &pck)
{
    N_LDEBUG("Got a Set Player Position And Rotation ({}, {}, {})", pck.x, pck.feetY, pck.z);
    // TODO: Validate the position

    onEvent(Server::getInstance()->getPluginManager(), onEntityMove, this, _pos, {pck.x, pck.feetY, pck.z});
    onEvent(Server::getInstance()->getPluginManager(), onEntityRotate, this, {_rot.x, _rot.z, 0}, {(uint8_t) pck.yaw, (uint8_t) pck.pitch, 0});
    this->setPosition(pck.x, pck.feetY, pck.z, pck.onGround);
    this->setRotation(pck.yaw, pck.pitch);
    playerPickupItem();
}

void Player::_onSetPlayerRotation(protocol::SetPlayerRotation &pck)
{
    N_LDEBUG("Got a Set Player Rotation");
    this->setRotation(pck.yaw, pck.pitch);
    onEvent(Server::getInstance()->getPluginManager(), onEntityRotate, this, {_rot.x, _rot.z, 0}, {(uint8_t) pck.yaw, (uint8_t) pck.pitch, 0});
}

void Player::_onSetPlayerOnGround(UNUSED protocol::SetPlayerOnGround &pck) { N_LDEBUG("Got a Set Player On Ground"); }

void Player::_onMoveVehicle(UNUSED protocol::MoveVehicle &pck) { N_LDEBUG("Got a Move Vehicle"); }

void Player::_onPaddleBoat(UNUSED protocol::PaddleBoat &pck) { N_LDEBUG("Got a Paddle Boat"); }

void Player::_onPickItem(UNUSED protocol::PickItem &pck) { N_LDEBUG("Got a Pick Item"); }

void Player::_onPlaceRecipe(UNUSED protocol::PlaceRecipe &pck) { N_LDEBUG("Got a Place Recipe"); }

void Player::_onPlayerAbilities(protocol::PlayerAbilities &pck)
{
    this->_isFlying = pck.flags & player_attributes::AbilitiesFlags::Flying;
    uint8_t flags = this->_isFlying ? player_attributes::AbilitiesFlags::Flying : 0x00;
    flags |= player_attributes::getAbilitiesByGamemode(getGamemode());
    this->sendPlayerAbilities({flags, 0.05f, 0.1f});
    N_LDEBUG("Got a Player Abilities");
}

void Player::_onPlayerAction(protocol::PlayerAction &pck)
{
    bool canceled = false;
    Vector3<int> tmp(pck.location.x, pck.location.y, pck.location.z);
    BlockId targetedBlock = this->getDimension()->getBlock(pck.location);

    // N_LINFO("Got a Player Action {} at {}", pck.status, pck.location);
    N_LDEBUG("Got a Player Action and player is in gamemode {} and status is {}", this->getGamemode(), pck.status);
    switch (pck.status) {
    case protocol::PlayerAction::Status::StartedDigging:
        if (this->getGamemode() == player_attributes::Gamemode::Creative) {
            onEventCancelable(Server::getInstance()->getPluginManager(), onBlockDestroy, canceled, 0, tmp);
            if (canceled) {
                Event::cancelBlockDestroy(this, targetedBlock, pck.location);
                return;
            }
            this->getDimension()->updateBlock(pck.location, 0);
        }
        if (this->getGamemode() == player_attributes::Gamemode::Survival) {
            onEventCancelable(Server::getInstance()->getPluginManager(), onBlockDestroy, canceled, 0, tmp);
            if (canceled) {
                Event::cancelBlockDestroy(this, targetedBlock, pck.location);
                return;
            }
            if (BLOCK_DATA_CONVERTER.fromBlockIdToBlockData(targetedBlock).hardness == 0) {
                int id = ITEM_CONVERTER.fromItemToProtocolId(GLOBAL_PALETTE.fromProtocolIdToBlock(targetedBlock).name);
                this->getDimension()->updateBlock(pck.location, 0);
                _foodExhaustionLevel += 0.005;
                _dim->makeEntity<Item>(protocol::Slot {true, id, 1})
                    ->dropItem({static_cast<double>(pck.location.x) + 0.5, static_cast<double>(pck.location.y), static_cast<double>(pck.location.z) + 0.5});
            }
        }
        break;
    case protocol::PlayerAction::Status::CancelledDigging:
        break;
    case protocol::PlayerAction::Status::FinishedDigging: {
        onEventCancelable(Server::getInstance()->getPluginManager(), onBlockDestroy, canceled, 0, tmp);
        if (canceled) {
            Event::cancelBlockDestroy(this, targetedBlock, pck.location);
            return;
        }
        auto item = this->_inventory->hotbar().at(this->_heldItem).getUsableItemFromSlot();
        if (Items::Hoe *usedItem = std::get_if<Items::Hoe>(&item)) {
            if (usedItem->_usabilityType == Items::UsabilityType::LeftMouseClickUsable || usedItem->_usabilityType == Items::UsabilityType::BothMouseClicksUsable) {
                usedItem->onUseOn(this->getDimension(), pck.location, Items::UsabilityType::LeftMouseClickUsable, 1, *this);
                if (usedItem->canUpdateDamage) {
                    this->_inventory->hotbar().at(this->_heldItem).updateDamage();
                }
            }
        }
        int id = ITEM_CONVERTER.fromItemToProtocolId(GLOBAL_PALETTE.fromProtocolIdToBlock(targetedBlock).name);
        this->getDimension()->updateBlock(pck.location, 0);
        _foodExhaustionLevel += 0.005;
        _dim->makeEntity<Item>(protocol::Slot {true, id, 1})
            ->dropItem({static_cast<double>(pck.location.x) + 0.5, static_cast<double>(pck.location.y), static_cast<double>(pck.location.z) + 0.5});
        break;
    }
    case protocol::PlayerAction::Status::DropItemStack:
        getDimension()->makeEntity<Item>(_inventory->hotbar().at(this->_heldItem))->dropItem(this->getPosition());
        _inventory->hotbar().at(this->_heldItem).reset();
        // update item in hand for other players
        this->updateEquipment(true, false, false, false, false, false);
        break;
    case protocol::PlayerAction::Status::DropItem:
        if (!_inventory->hotbar().at(this->_heldItem).present)
            break;
        getDimension()->makeEntity<Item>(_inventory->hotbar().at(this->_heldItem).takeOne())->dropItem(this->getPosition());
        _inventory->hotbar().at(this->_heldItem).itemCount--;
        if (_inventory->hotbar().at(this->_heldItem).itemCount == 0) {
            _inventory->hotbar().at(this->_heldItem).reset();

            // update item in hand for other players
            this->updateEquipment(true, false, false, false, false, false);
        }
        break;
    case protocol::PlayerAction::Status::ShootArrowOrFinishEating:
        // TODO(huntears): Cancel eating if shooting succeeded
        _shoot();
        _eat();
        break;
    case protocol::PlayerAction::Status::SwapItemInHand:
        _inventory->offhand().swap(_inventory->hotbar().at(this->_heldItem));
        break;
    default:
        N_LERROR("Got a Player Action with an unknown status: {}", pck.status);
        break;
    }
}

void Player::_shoot()
{
    if (this->_inventory->hotbar().at(this->_heldItem).present == false)
        return;

    // Check if the item in hand is a bow or a crossbox
    // Yes this is hardcoded, but it will do
    auto heldItem = this->_inventory->hotbar().at(this->_heldItem).itemID;
    auto item = this->_inventory->hotbar().at(this->_heldItem).getUsableItemFromSlot();
    if (heldItem == 735) {
        // Bow
        Items::Bow *usedItem = std::get_if<Items::Bow>(&item);
        usedItem->onUse(_dim, *this, Items::UsabilityType::RightMouseClickUsable);
    } else if (heldItem == 1112) {
        // Crossbow
    }
}

void Player::_onPlayerCommand(protocol::PlayerCommand &pck)
{
    N_LDEBUG("Got a Player Command");

    switch (pck.actionId) {
    case (protocol::PlayerCommand::ActionId::StartSprinting):
        setSprinting(true);
        break;
    case (protocol::PlayerCommand::ActionId::StopSprinting):
        setSprinting(false);
        break;
    case (protocol::PlayerCommand::ActionId::StartSneaking):
        setCrouching(true);
        break;
    case (protocol::PlayerCommand::ActionId::StopSneaking):
        setCrouching(false);
        break;
    default:
        break;
    }
}

void Player::_onPlayerInput(UNUSED protocol::PlayerInput &pck) { N_LDEBUG("Got a Player Input"); }

void Player::_onPong(UNUSED protocol::Pong &pck) { N_LDEBUG("Got a Pong"); }

void Player::_onPlayerSession(UNUSED protocol::PlayerSession &pck) { N_LDEBUG("Got a Player Session"); }

void Player::_onChangeRecipeBookSettings(UNUSED protocol::ChangeRecipeBookSettings &pck) { N_LDEBUG("Got a Change Recipe Book Settings"); }

void Player::_onSetSeenRecipe(UNUSED protocol::SetSeenRecipe &pck) { N_LDEBUG("Got a Set Seen Recipe"); }

void Player::_onRenameItem(UNUSED protocol::RenameItem &pck) { N_LDEBUG("Got a Rename Item"); }

void Player::_onResourcePack(UNUSED protocol::ResourcePack &pck) { N_LDEBUG("Got a Resource Pack"); }

void Player::_onSeenAdvancements(UNUSED protocol::SeenAdvancements &pck) { N_LDEBUG("Got a Seen Advancements"); }

void Player::_onSelectTrade(UNUSED protocol::SelectTrade &pck) { N_LDEBUG("Got a Select Trade"); }

void Player::_onSetBeaconEffect(UNUSED protocol::SetBeaconEffect &pck) { N_LDEBUG("Got a Set Beacon Effect"); }

void Player::_onSetHeldItem(protocol::SetHeldItem &pck)
{
    this->_heldItem = pck.slot;

    this->updateEquipment(true, false, false, false, false, false);
    N_LDEBUG("Got a Set Held Item");
}

void Player::_onProgramCommandBlock(UNUSED protocol::ProgramCommandBlock &pck) { N_LDEBUG("Got a Program Command Block"); }

void Player::_onProgramCommandBlockMinecart(UNUSED protocol::ProgramCommandBlockMinecart &pck) { N_LDEBUG("Got a Program Command Block Minecart"); }

void Player::_onSetCreativeModeSlot(protocol::SetCreativeModeSlot &pck)
{
    N_LDEBUG("Got a Set Creative Mode Slot");
    if (_gamemode != player_attributes::Gamemode::Creative) {
        return;
    }
    this->_inventory->at(pck.slot) = pck.clickedItem;
}

void Player::_onProgramJigsawBlock(UNUSED protocol::ProgramJigsawBlock &pck) { N_LDEBUG("Got a Program Jigsaw Block"); }

void Player::_onProgramStructureBlock(UNUSED protocol::ProgramStructureBlock &pck) { N_LDEBUG("Got a Program Structure Block"); }

void Player::_onUpdateSign(UNUSED protocol::UpdateSign &pck) { N_LDEBUG("Got a Update Sign"); }

void Player::_onSwingArm(protocol::SwingArm &pck)
{
    N_LDEBUG("Got a Swing Arm");
    for (auto i : this->getDimension()->getPlayers()) {
        if (i->getId() == this->getId())
            continue;
        i->sendSwingArm(pck.hand == protocol::SwingArm::Hand::MainHand, this->getId());
    }
}

void Player::_onTeleportToEntity(UNUSED protocol::TeleportToEntity &pck) { N_LDEBUG("Got a Teleport To Entity"); }

void Player::_onUseItemOn(protocol::UseItemOn &pck)
{
    N_LDEBUG("Got a Use Item On {} -> {}", pck.location, this->_heldItem);

    if (!this->_crouching) {
        if (GLOBAL_PALETTE.fromProtocolIdToBlock(this->getDimension()->getBlock(pck.location)).name == "minecraft:crafting_table") {
            _containers.emplace_back(std::make_shared<protocol::container::CraftingTable>(this->dynamicWeakFromThis<Player>()));
            return;
        }
        if (auto tileEntity = this->getDimension()->getTileEntity(pck.location); tileEntity != nullptr) {
            switch (tileEntity->blockEntityType) {
            case tile_entity::TileEntityType::UnknownType:
                LERROR("tile entity at {} has type UnknownType", pck.location);
                break;
            case tile_entity::TileEntityType::Furnace: {
                auto &container = _containers.emplace_back(
                    std::make_shared<protocol::container::Furnace>(this->dynamicWeakFromThis<Player>(), std::dynamic_pointer_cast<tile_entity::Furnace>(tileEntity))
                );
                this->sendSetContainerContent({container});
                break;
            }
            default:
                LERROR("tile entity at {} has unhandled type {}", pck.location, tileEntity->blockEntityType);
                break;
            }
        }
    }

    switch (pck.face) {
    case protocol::UseItemOn::Face::Bottom:
        pck.location.y--;
        break;
    case protocol::UseItemOn::Face::Top:
        pck.location.y++;
        break;
    case protocol::UseItemOn::Face::North:
        pck.location.z--;
        break;
    case protocol::UseItemOn::Face::South:
        pck.location.z++;
        break;
    case protocol::UseItemOn::Face::West:
        pck.location.x--;
        break;
    case protocol::UseItemOn::Face::East:
        pck.location.x++;
        break;
    }

    if (this->_inventory->hotbar().at(this->_heldItem).itemID == ITEM_CONVERTER.fromItemToProtocolId("minecraft:wheat_seeds")) {
        const BlockId &belowBlock = this->getDimension()->getBlock({pck.location.x, pck.location.y - 1, pck.location.z});

        if (this->getDimension()->getBlock(pck.location) == Blocks::Air::toProtocol() &&
            (belowBlock == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::ZERO) ||
             belowBlock == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::ONE) ||
             belowBlock == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::TWO) ||
             belowBlock == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::THREE) ||
             belowBlock == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::FOUR) ||
             belowBlock == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::FIVE) ||
             belowBlock == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::SIX) ||
             belowBlock == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::SEVEN))) {
            this->getDimension()->updateBlock(pck.location, Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::ZERO));
            this->_inventory->hotbar().at(this->_heldItem).takeOne();
            return;
        }
    }

    auto item = this->_inventory->hotbar().at(this->_heldItem).getUsableItemFromSlot();
    if (Items::Hoe *usedItem = std::get_if<Items::Hoe>(&item)) {
        if (usedItem->_usabilityType == Items::UsabilityType::RightMouseClickUsable || usedItem->_usabilityType == Items::UsabilityType::BothMouseClicksUsable) {
            usedItem->onUseOn(this->getDimension(), pck.location, Items::UsabilityType::RightMouseClickUsable, (int32_t) pck.face, *this);
            if (usedItem->canUpdateDamage) {
                this->_inventory->hotbar().at(this->_heldItem).updateDamage();
            }
            this->sendSetContainerSlot({this->_inventory, static_cast<int16_t>(this->_heldItem + HOTBAR_OFFSET)});
        }
        return;
    } else if (Items::FlintAndSteel *usedItem = std::get_if<Items::FlintAndSteel>(&item)) {
        usedItem->onUseOn(this->getDimension(), pck.location, Items::UsabilityType::RightMouseClickUsable, (int32_t) pck.face, *this);
        this->_inventory->hotbar().at(this->_heldItem).updateDamage();
        this->sendSetContainerSlot({this->_inventory, static_cast<int16_t>(this->_heldItem + HOTBAR_OFFSET)});
        return;
    }
    if (_inventory->hotbar().at(this->_heldItem).present) {
        this->getDimension()->updateBlock(pck.location, GLOBAL_PALETTE.fromBlockToProtocolId(ITEM_CONVERTER.fromProtocolIdToItem(_inventory->hotbar().at(this->_heldItem).itemID)));
    }
    if (_gamemode == player_attributes::Gamemode::Creative)
        return;
    this->_inventory->hotbar().at(this->_heldItem).itemCount--;
    if (_inventory->hotbar().at(this->_heldItem).itemCount == 0) {
        _inventory->hotbar().at(this->_heldItem).reset();

        // update item in hand for other players
        this->updateEquipment(true, false, false, false, false, false);
    }
}

void Player::_onUseItem(UNUSED protocol::UseItem &pck) { N_LDEBUG("Got a Use Item"); }

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

    this->sendPlayerAbilities({player_attributes::getAbilitiesByGamemode(getGamemode()), 0.05, 0.1});
    // TODO: send the value stored in the player data
    this->sendSetHeldItem({4});

    // TODO: send the recipes
    this->sendUpdateRecipes({});

    // TODO: send the tags
    // this->sendUpdateTags({});

    // TODO: implement the event Statues correctly // 24 (set op permission level)
    this->sendEntityEvent({this->_id, 24});

    // TODO: send all the commands avaliable in the server
    // this->sendCommands({{}, 0});

    // TODO: send the player recipies book
    // this->sendUpdateRecipiesBook({});

    // TODO: change that to player_attributes::DEFAULT_SPAWN_POINT
    this->teleport({8.5, 75, 8.5});

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
    this->sendInitializeWorldBorder({0, 0, 0, CONFIG["world-border"].as<double>(), 0, 29999984, 10, 10});

    this->sendSetDefaultSpawnPosition({{0, 100, 0}, 0.0f});

    this->sendSetContainerContent({_inventory});

    // TODO: set entity metadata
    this->sendEntityMetadata(*this);

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

    // send scoreboard status (objectives and teams)
    _dim->getWorld()->getWorldGroup()->getScoreboard().sendScoreboardStatus(*this);

    // send other player's held item
    for (std::shared_ptr<Player> other : _dim->getPlayers()) {
        if (other->getInventory()->hotbar().at(other->getHeldItem()).present) {
            protocol::SetEquipment equip;

            equip.entityId = other->getId();
            equip.equipment.push_back(std::make_pair(protocol::SetEquipment::EquipmentPosition::MainHand, other->getInventory()->hotbar().at(other->getHeldItem())));
            this->sendSetEquipment(equip);
        }
    }

    // Send login message
    chat::Message connectionMsg = chat::Message::fromTranslationKey<chat::message::TranslationKey::MultiplayerPlayerJoined>(*this);

    this->getWorld()->getChat()->sendSystemMessage(connectionMsg, *this->getWorldGroup());
    onEvent(Server::getInstance()->getPluginManager(), onPlayerJoin, this);
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
        LDEBUG("Health is now {} and food level is now {}", _health, _foodLevel);
    }
    if (needUpdate == false &&
        ((_foodLevel >= MIN_FOOD_LEVEL_FOR_REGENERATION && _health < _maxHealth) || (_foodLevel == MIN_FOOD_LEVEL && _health > 10))) // TODO: Make it depends on difficulty
        _foodTickTimer++;
}

void Player::_eat()
{
    if (_gamemode != player_attributes::Gamemode::Survival && _gamemode != player_attributes::Gamemode::Adventure)
        return;
    if (this->_inventory->hotbar().at(this->_heldItem).present == false)
        return;

    using namespace player_attributes;

    auto food = std::find_if(Items::foodItems.begin(), Items::foodItems.end(), [this](const Items::FoodItem &item) {
        return item.id == this->_inventory->hotbar().at(this->_heldItem).itemID;
    });
    if (food == Items::foodItems.end()) {
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
    _inventory->hotbar().at(this->_heldItem).itemCount--;
    this->sendSetContainerSlot({_inventory, static_cast<int16_t>(this->_heldItem + HOTBAR_OFFSET)});
    if (_inventory->hotbar().at(this->_heldItem).itemCount == 0) {
        _inventory->hotbar().at(this->_heldItem).reset();

        // update item in hand for other players
        this->updateEquipment(true, false, false, false, false, false);
    }
}

void Player::teleport(const Vector3<double> &pos)
{
    this->sendSynchronizePosition(pos);
    LDEBUG("Synchronize player position");
    Entity::teleport(pos);
}

void Player::_respawn()
{
    // this->setIsReadyToRemove(false);
    this->_dim->addEntity(shared_from_this());
    this->_dim->addPlayer(dynamic_pointer_cast<Player>(shared_from_this()));

    // Perform the respawn
    this->sendRespawn({
        this->_dim->getDimensionTypeName(), // Dimension Type
        this->_dim->getDimensionName(), // Dimension name
        0, // Hashed seed
        this->_gamemode, // Gamemode
        this->_gamemode, // Previous gamemode
        0, // Is debug
        0, // Is flat
        0, // Copy metadata
        true, // Has death location
        this->_dim->getDimensionName(), // Dimension name
        {
            static_cast<long>(this->_pos.x), // death X
            static_cast<long>(this->_pos.y), // death Y
            static_cast<long>(this->_pos.z) // death Z
        }, // Position
    });

    _health = 20;

    this->forceSetPosition(this->_respawnPoint);
    this->sendSynchronizePlayerPosition();
    this->_pose = Pose::Standing;
    this->_dim->spawnPlayer(*this);
}

bool Player::isInRenderDistance(UNUSED const Vector2<double> &pos) const { return true; }

void Player::sendEntityMetadata(const Entity &entity)
{
    GET_CLIENT();
    auto pck = protocol::createSetEntityMetadata(entity);
    client->doWrite(std::move(pck));
    N_LDEBUG("Sent change difficulty packet");
}

void Player::appendMetadataPacket(std::vector<uint8_t> &data) const
{
    LivingEntity::appendMetadataPacket(data);

    using namespace protocol::entity_metadata;

    // Additional hearts
    addMFloat(data, 15, _additionalHearts);

    // Score
    addMVarInt(data, 16, _score);

    // Skin parts
    uint8_t flag = 0;
    if (_skinParts.capeEnabled)
        flag |= 0x01;
    if (_skinParts.jacketEnabled)
        flag |= 0x02;
    if (_skinParts.leftSleeveEnabled)
        flag |= 0x04;
    if (_skinParts.rightSleeveEnabled)
        flag |= 0x08;
    if (_skinParts.leftPantsEnabled)
        flag |= 0x10;
    if (_skinParts.rightPantsEnabled)
        flag |= 0x20;
    if (_skinParts.hatEnabled)
        flag |= 0x40;
    addMByte(data, 17, flag);

    // Main hand
    addMByte(data, 18, (uint8_t) _mainHand);

    // TODO(huntears): Handle parrots on shoulders here (Way later xd)
    // Left shoulder

    // Right shoulder
}

std::shared_ptr<protocol::container::Container> Player::getContainer(uint8_t windowId)
{
    if (windowId == 0)
        return _inventory;
    auto it = std::find_if(_containers.begin(), _containers.end(), [&](const auto &container) {
        if (container->id() == windowId)
            return true;
        return false;
    });
    if (it == _containers.end())
        return nullptr;
    return *it;
}
