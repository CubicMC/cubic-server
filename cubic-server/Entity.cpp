#include "Entity.hpp"
#include "Item.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "logging/logging.hpp"
#include "math/Vector3.hpp"
#include "options.hpp"
#include <memory>
#include <utility>

// clang-format off
Entity::Entity(std::shared_ptr<Dimension> dim,
    protocol::SpawnEntity::EntityType type,
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
    Vector2<uint8_t> lastRot):
    _dim(dim)
{
    static std::atomic<int32_t> currentID = 0;

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

std::shared_ptr<Dimension> Entity::getDimension() const { return _dim; }

std::shared_ptr<World> Entity::getWorld() const { return _dim->getWorld(); }

std::shared_ptr<WorldGroup> Entity::getWorldGroup() const { return _dim->getWorld()->getWorldGroup(); }

int32_t Entity::getId() const { return _id; }

Vector3<double> &Entity::getPosition() { return _pos; }

const Vector3<double> &Entity::getPosition() const { return _pos; }

Vector2<uint8_t> &Entity::getRotation() { return _rot; }

const Vector2<uint8_t> &Entity::getRotation() const { return _rot; }

Vector2<float> Entity::getRotationDegree() const { return Vector2<float>((float) _rot.x / (256.0 / 360.0), (float) _rot.z / (256.0 / 360.0)); }

Vector3<double> &Entity::getLastPosition() { return _lastPos; }

Vector2<uint8_t> &Entity::getLastRotation() { return _lastRot; }

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
        if (item->getType() == protocol::SpawnEntity::EntityType::Item && item->getId() != this->getId()) {
            if (((collectorPosition.x - item->getPosition().x) <= pickupBoxH.x && (collectorPosition.x - item->getPosition().x) >= -pickupBoxH.x) &&
                ((collectorPosition.y - item->getPosition().y) <= pickupBoxV.y && (collectorPosition.y - item->getPosition().y) >= -pickupBoxV.y) &&
                ((collectorPosition.z - item->getPosition().z) <= pickupBoxH.z && (collectorPosition.z - item->getPosition().z) >= -pickupBoxH.z)) {
                // LINFO("There is an item to pickup at {}, {}, {}", (collectorPosition.x - item->getPosition().x), (collectorPosition.y -
                // item->getPosition().y),(collectorPosition.z - item->getPosition().z));
                return item;
            }
        }
    }
    return nullptr;
}
