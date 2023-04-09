#include "Entity.hpp"
#include "Player.hpp"

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

void Entity::setPosition(const Vector3<double> &pos) { _pos = pos; }

void Entity::setPosition(double x, double y, double z) { this->setPosition({x, y, z}); }

void Entity::forceSetPosition(const Vector3<double> &pos)
{
    _pos = pos;
    _lastPos = _pos;
}

void Entity::forceSetPosition(double x, double y, double z) { this->forceSetPosition({x, y, z}); }

void Entity::setRotation(const Vector2<uint8_t> &rot) { _rot = rot; }

void Entity::setRotation(uint8_t yaw, uint8_t pitch)
{
    _rot.x = yaw;
    _rot.y = pitch;
}

std::shared_ptr<Dimension> Entity::getDimension() const { return _dim; }

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
