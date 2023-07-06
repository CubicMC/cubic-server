#include "Entity.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "logging/logging.hpp"
#include "math/Vector3.hpp"
#include "options.hpp"

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

void Entity::setRotation(const Vector2<uint8_t> &rot)
{
    float yawTmp = rot.x;
    while (yawTmp < 0) // TODO: change that completely
        yawTmp += 360;
    while (yawTmp > 360)
        yawTmp -= 360;
    _rot.x = yawTmp;
    _rot.z = rot.z / 1.5;
}

void Entity::setRotation(uint8_t yaw, uint8_t pitch) { this->setRotation({yaw, pitch}); }

std::shared_ptr<Dimension> Entity::getDimension() const { return _dim; }

std::shared_ptr<World> Entity::getWorld() const { return _dim->getWorld(); }

std::shared_ptr<WorldGroup> Entity::getWorldGroup() const { return _dim->getWorld()->getWorldGroup(); }

int32_t Entity::getId() const { return _id; }

Vector3<double> &Entity::getPosition() { return _pos; }

const Vector3<double> &Entity::getPosition() const { return _pos; }

Vector2<uint8_t> &Entity::getRotation() { return _rot; }

const Vector2<uint8_t> &Entity::getRotation() const { return _rot; }

Vector3<double> &Entity::getLastPosition() { return _lastPos; }

Vector2<uint8_t> &Entity::getLastRotation() { return _lastRot; }

void Entity::teleport(const Vector3<double> &pos)
{
    this->forceSetPosition(pos);

    for (auto i : this->getDimension()->getPlayers()) {
        if (i->getId() == this->getId())
            continue;
        i->sendTeleportEntity(this->getId(), pos);
    }
}

bool Entity::checkPickupItem()
{
    auto collectorPosition = this->getPosition();
    Vector3<double> pickupBoxH = {1, 1, 1};
    Vector3<double> pickupBoxV = {0.5, 0.5, 0.5};

    for (auto i : this->getDimension()->getEntities()) {
        if (i->getType() == protocol::SpawnEntity::EntityType::Item && i->getId() != this->getId()) {
            if (((collectorPosition.x - i->getPosition().x) <= pickupBoxH.x && (collectorPosition.x - i->getPosition().x) >= -pickupBoxH.x) &&
                ((collectorPosition.y - i->getPosition().y) <= pickupBoxV.y && (collectorPosition.y - i->getPosition().y) >= -pickupBoxV.y) &&
                ((collectorPosition.z - i->getPosition().z) <= pickupBoxH.z && (collectorPosition.z - i->getPosition().z) >= -pickupBoxH.z)) {
                // LINFO("There is an item to pickup at {}, {}, {}", (collectorPosition.x - i->getPosition().x), (collectorPosition.y - i->getPosition().y),(collectorPosition.z - i->getPosition().z));
                return true;
            }
        }
    }
    return false;
}