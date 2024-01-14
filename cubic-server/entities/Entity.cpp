#include "Entity.hpp"
#include "Item.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "chat/Message.hpp"
#include "default/Overworld.hpp"
#include "default/TheNether.hpp"
#include "entities/EntityType.hpp"
#include "logging/logging.hpp"
#include "math/Vector3.hpp"
#include "options.hpp"
#include "protocol/metadata.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Level.hpp"
#include <memory>
#include <optional>
#include <utility>

// clang-format off
Entity::Entity(std::shared_ptr<Dimension> dim,
    EntityType type,
    u128 uuid,
    bool onFire,
    bool crouching,
    bool sprinting,
    bool swimming,
    bool invisible,
    bool glowing,
    bool flyingWithElytra,
    int16_t airTicks,
    std::string customName,
    bool customNameVisible,
    bool silent,
    bool noGravity,
    Pose pose,
    int16_t tickFrozenInPowderedSnow,
    Vector3<double> pos,
    Vector2<uint8_t> rot,
    Vector3<double> lastPos,
    Vector2<uint8_t> lastRot,
    Vector3<double> vel):
    _dim(dim)
{
    static std::atomic<int32_t> currentID = 0;

    _uuid = uuid;
    _onFire = onFire;
    _crouching = crouching;
    _sprinting = sprinting;
    _swimming = swimming;
    _invisible = invisible;
    _glowing = glowing;
    _flyingWithElytra = flyingWithElytra;
    _airTicks = airTicks;
    _customName = customName;
    _customNameVisible = customNameVisible;
    _silent = silent;
    _noGravity = noGravity;
    _pose = pose;
    _tickFrozenInPowderedSnow = tickFrozenInPowderedSnow;
    _id = currentID.fetch_add(1);
    _pos = pos;
    _lastPos = lastPos;
    _rot = rot;
    _lastRot = lastRot;
    _type = type;
    _velocity = vel;
    _readyToRemove = false;
}
// clang-format on

void Entity::setDimension(std::shared_ptr<Dimension> dim)
{
    Player *player = dynamic_cast<Player *>(this);

    // if entity is a player
    if (player) {
        // send init scoreboard data if entered another worldgroup
        if (this->getDimension() == nullptr || // no previous dimension or
            this->getDimension() == dim || // different previous dimension or
            this->getWorld() == dim->getWorld() || // different previous world or
            this->getWorldGroup() == dim->getWorld()->getWorldGroup()) { // different previous worldgroup
            dim->getWorld()->getWorldGroup()->getScoreboard().sendScoreboardStatus(*player);
        }
    }
    _dim = dim;
}

void Entity::setPosition(const Vector3<double> &pos, UNUSED bool onGround) { _pos = pos; }

void Entity::setPosition(double x, double y, double z, bool onGround) { this->setPosition({x, y, z}, onGround); }

void Entity::setVelocity(const Vector3<double> &vel) { this->setVelocity(vel.x, vel.y, vel.z); };

void Entity::setVelocity(double x, double y, double z)
{
    _velocity.x = x;
    _velocity.y = y;
    _velocity.z = z;
};

void Entity::forceSetPosition(const Vector3<double> &pos)
{
    _pos = pos;
    _lastPos = _pos;
}

void Entity::forceSetPosition(double x, double y, double z) { this->forceSetPosition({x, y, z}); }

void Entity::setRotation(const Vector2<uint8_t> &rot) { _rot = rot; }

void Entity::setRotation(uint8_t x, uint8_t y) { this->setRotation({x, y}); }

void Entity::setRotation(float yaw, float pitch)
{
    while (yaw < 0) {
        yaw += 360;
    }
    while (yaw > 360) {
        yaw -= 360;
    }
    this->_rot.x = yaw * (256.0 / 360.0);
    this->_rot.z = pitch * (256.0 / 360.0);
}

std::shared_ptr<World> Entity::getWorld() { return _dim->getWorld(); }

std::shared_ptr<const World> Entity::getWorld() const { return _dim->getWorld(); }

std::shared_ptr<WorldGroup> Entity::getWorldGroup() { return _dim->getWorld()->getWorldGroup(); }

std::shared_ptr<const WorldGroup> Entity::getWorldGroup() const { return _dim->getWorld()->getWorldGroup(); }

void Entity::teleport(const Vector3<double> &pos)
{
    this->forceSetPosition(pos);

    for (auto i : this->getDimension()->getPlayers()) {
        if (i->getId() == this->getId())
            continue;
        i->sendTeleportEntity(this->getId(), pos, {0, 0});
    }
}

const std::shared_ptr<Entity> Entity::pickupItem()
{
    auto collectorPosition = this->getPosition();
    Vector3<double> pickupBoxH = {1, 1, 1};
    Vector3<double> pickupBoxV = {0.5, 0.5, 0.5};

    for (auto item : this->getDimension()->getEntities()) {
        if (item->getType() == EntityType::Item && item->getId() != this->getId() && std::static_pointer_cast<Item>(item)->isPickable()) {
            if (collectorPosition.x - item->getPosition().x <= pickupBoxH.x && collectorPosition.x - item->getPosition().x >= -pickupBoxH.x &&
                collectorPosition.y - item->getPosition().y <= pickupBoxV.y && collectorPosition.y - item->getPosition().y >= -pickupBoxV.y &&
                collectorPosition.z - item->getPosition().z <= pickupBoxH.z && collectorPosition.z - item->getPosition().z >= -pickupBoxH.z) {
                // LINFO("There is an item to pickup at {}, {}, {}", (collectorPosition.x - item->getPosition().x), (collectorPosition.y -
                // item->getPosition().y),(collectorPosition.z - item->getPosition().z));
                return item;
            }
        }
    }
    return nullptr;
}

void Entity::tick()
{
    this->tickPosition();
    Position2D chunkPos = {transformBlockPosToChunkPos(_pos.x), transformBlockPosToChunkPos(_pos.z)};
    if (_dim->hasChunkLoaded(chunkPos.x, chunkPos.z)) {

        // here is an error arising from the '%' in the 'getBlock' below, so in negative positions, the gotten block position is 1 block less than needed
        Position pos = _pos;
        if (_pos.x < 0)
            pos.x -= 1;
        if (_pos.z < 0) {
            pos.z -= 1;
        }
        auto block = _dim->getBlock(pos);

        // LTRACE("Block: {}, {} . {} . {}", block, _pos.x, _pos.y, _pos.z);

        if (block == Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::Z) ||
            block == Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::X)) {
            if (_type == EntityType::Player) {
                _tickCounter++;
                LTRACE("Counter: {}", _tickCounter);
                if (_tickCounter >= 4 * 20) {
                    teleportPlayerThroughPortal(_dim);
                    _tickCounter = 0;
                }
            }
            // else {
            //     teleportEntityThroughPortal(_dim);
            // }
        } else {
            _tickCounter = 0;
        }
    }
}

void Entity::tickPosition()
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
}

void Entity::appendMetadataPacket(std::vector<uint8_t> &data) const
{
    using namespace protocol::entity_metadata;
    // Flags
    uint8_t flag = 0;
    if (_onFire)
        flag |= 0x01;
    if (_crouching)
        flag |= 0x02;
    if (_sprinting)
        flag |= 0x08;
    if (_swimming)
        flag |= 0x10;
    if (_invisible)
        flag |= 0x20;
    if (_glowing)
        flag |= 0x40;
    if (_flyingWithElytra)
        flag |= 0x80;
    addMByte(data, 0, flag);

    // Air ticks
    addMVarInt(data, 1, _airTicks);

    // Custom name
    if (_customName == "")
        addMOptChat(data, 2, std::nullopt);
    else
        addMOptChat(data, 2, chat::Message(_customName));

    // Is custom name visible
    addMBoolean(data, 3, _customNameVisible);

    // Is silent
    addMBoolean(data, 4, _silent);

    // Has no gravity
    addMBoolean(data, 5, _noGravity);

    // Pose
    addMPose(data, 6, _pose);

    // Ticks frozen in snow
    addMVarInt(data, 7, _tickFrozenInPowderedSnow);
}

void Entity::setCrouching(bool value)
{
    bool needRefresh = _crouching != value;

    _crouching = value;
    // TODO(huntears): Support other poses
    _pose = value ? Pose::Sneaking : Pose::Standing;
    if (!needRefresh)
        return;
    broadcastMetadata();
}

void Entity::setSprinting(bool value)
{
    bool needRefresh = _sprinting != value;

    _sprinting = value;
    if (!needRefresh)
        return;
    broadcastMetadata();
}

void Entity::broadcastMetadata() const
{
    for (auto player : _dim->getPlayers()) {
        if (!player->isInRenderDistance(_pos))
            continue;
        player->sendEntityMetadata(*this);
    }
}

void Entity::teleportEntityThroughPortal(std::shared_ptr<Dimension> currentDimension)
{
    if (currentDimension->getDimensionType() == world_storage::DimensionType::OVERWORLD) {
        auto dim = currentDimension->getWorld()->getDimensions().at("nether");
        dim->addEntity(this->dynamicSharedFromThis<Entity>());
        dim->spawnEntity(this->dynamicSharedFromThis<Entity>());
        currentDimension->removeEntity(_id);
    } else if (currentDimension->getDimensionType() == world_storage::DimensionType::NETHER) {
        auto dim = currentDimension->getWorld()->getDimensions().at("overworld");
        dim->addEntity(this->dynamicSharedFromThis<Entity>());
        dim->spawnEntity(this->dynamicSharedFromThis<Entity>());
        currentDimension->removeEntity(_id);
    }
}

void Entity::teleportPlayerThroughPortal(std::shared_ptr<Dimension> currentDimension)
{
    std::shared_ptr<Dimension> nextDimension = nullptr;
    std::shared_ptr<Player> thisPlayer = nullptr;
    for (auto player : currentDimension->getPlayers()) {
        if (player->_id == _id) {
            thisPlayer = player;
            break;
        }
    }
    if (thisPlayer == nullptr)
        return;
    LDEBUG("Player name: {}", thisPlayer->getUsername());

    if (currentDimension->getDimensionType() == world_storage::DimensionType::OVERWORLD) {
        nextDimension = currentDimension->getWorld()->getDimensions().at("nether");
    } else if (currentDimension->getDimensionType() == world_storage::DimensionType::NETHER) {
        nextDimension = currentDimension->getWorld()->getDimensions().at("overworld");
    } else {
        return;
    }
    auto augh = this->dynamicSharedFromThis<Entity>();
    currentDimension->pushBackIdToRemove(_id);
    thisPlayer->sendRemoveEntities({_id});
    thisPlayer->setDimension(nextDimension);
    thisPlayer->sendRespawn({
        nextDimension->getDimensionTypeName(),
        nextDimension->getDimensionName(),
        0,
        thisPlayer->getGamemode(),
        thisPlayer->getGamemode(),
        0,
        0,
        0,
        false,
    });
    thisPlayer->sendFeatureFlags({{"minecraft:vanilla"}});
    thisPlayer->sendPlayerAbilities({player_attributes::getAbilitiesByGamemode(thisPlayer->getGamemode()), 0.05, 0.1});
    thisPlayer->sendSetHeldItem({thisPlayer->getHeldItem()});
    thisPlayer->sendUpdateRecipes({});
    thisPlayer->sendUpdateTags({});
    thisPlayer->sendEntityEvent({thisPlayer->_id, 24});
    thisPlayer->sendCommands({{}, 0});
    thisPlayer->sendUpdateRecipiesBook({});
    thisPlayer->sendServerData({false, "", false, "", false});
    nextDimension->addEntity(augh);
    nextDimension->addPlayer(thisPlayer);
    auto renderDistance = nextDimension->getWorld()->getRenderDistance();
    thisPlayer->sendChunkAndLightUpdate(0, 0);
    for (int32_t x = -renderDistance; x < renderDistance + 1; x++) {
        for (int32_t z = -renderDistance; z < renderDistance + 1; z++) {
            if (x == 0 && z == 0)
                continue;
            thisPlayer->sendChunkAndLightUpdate(x, z);
        }
    }
    thisPlayer->sendSetContainerContent({thisPlayer->getInventory()});
    thisPlayer->sendEntityMetadata(*thisPlayer);
    thisPlayer->sendUpdateAttributes({thisPlayer->getId(), {}});
    thisPlayer->sendUpdateAdvancements({false, {}, {}, {}});
    thisPlayer->sendHealth();
    thisPlayer->sendSetExperience({0, 0, 0});
    thisPlayer->teleport({8.5, 70, 8.5});
    nextDimension->spawnPlayer(*thisPlayer);
}
