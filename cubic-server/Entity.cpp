#include "Entity.hpp"
#include "Player.hpp"
#include "types.hpp"
#include "World.hpp"

Entity::Entity(std::shared_ptr<Dimension> dim):
    _dim(dim)
{
    static std::atomic<int32_t> currentID = 0;

    _onFire = false;
    _crouching = false;
    _sprinting = false;
    _swimming = false;
    _invisible = false;
    _glowing = false;
    _flyingWithElytra = false;
    _airTicks = 300;
    _customName = "";
    _customNameVisible = false;
    _silent = false;
    _noGravity = false;
    _pose = Pose::Standing;
    _tickFrozenInPowderedSnow = 0;
    _id = currentID.fetch_add(1);
    _pos = {0, 0, 0};
    _lastPos = {0, 0, 0};
    _rot = {0, 0};
    _lastRot = {0, 0};
}

void Entity::setDimension(std::shared_ptr<Dimension> dim) { _dim = dim; }

void Entity::setPosition(const Vector3<double> &pos, bool on_ground) { _pos = pos; }

void Entity::setPosition(double x, double y, double z, bool on_ground) { this->setPosition({x, y, z}, on_ground); }

void Entity::forceSetPosition(const Vector3<double> &pos)
{
    _pos = pos;
    _lastPos = _pos;
}

void Entity::forceSetPosition(double x, double y, double z) { this->forceSetPosition({x, y, z}); }

void Entity::setRotation(const Vector2<uint8_t> &rot)
{
    float yaw_tmp = rot.x;
    while (yaw_tmp < 0) // TODO: change that completely
        yaw_tmp += 360;
    while (yaw_tmp > 360)
        yaw_tmp -= 360;
    _rot.x = yaw_tmp;
    _rot.y = rot.y / 1.5;
}

void Entity::setRotation(uint8_t yaw, uint8_t pitch) { this->setRotation({yaw, pitch}); }

std::shared_ptr<Dimension> Entity::getDimension() const { return _dim; }

World *Entity::getWorld() const { return _dim->getWorld(); }

WorldGroup *Entity::getWorldGroup() const { return _dim->getWorld()->getWorldGroup(); }

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

    for (auto i : this->getDimension()->getPlayerList()) {
        if (i->getId() == this->getId())
            continue;
        i->sendTeleportEntity(this->getId(), pos);
    }
}
