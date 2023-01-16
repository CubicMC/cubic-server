#include "Entity.hpp"

Entity::Entity(std::shared_ptr<Dimension> dim) : _dim(dim)
{
    static int32_t currentID = 0;

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
    _id = currentID++;
}

void Entity::setDimension(std::shared_ptr<Dimension> dim)
{
    _dim = dim;
}

void Entity::setPosition(const Vector3<double> &pos)
{
    _pos = pos;
}

void Entity::setPosition(double x, double y, double z)
{
    _pos.x = x;
    _pos.y = y;
    _pos.z = z;
}

void Entity::setRotation(const Vector2<uint8_t> &rot)
{
    _rot = rot;
}

void Entity::setRotation(uint8_t yaw, uint8_t pitch)
{
    _rot.x = yaw;
    _rot.y = pitch;
}

std::shared_ptr<Dimension> Entity::getDimension() const
{
    return _dim;
}

int32_t Entity::getId() const
{
    return _id;
}

Vector3<double> &Entity::getPosition() {
    return _pos;
}

const Vector3<double> &Entity::getPosition() const {
    return _pos;
}

Vector2<uint8_t> &Entity::getRotation() {
    return _rot;
}

const Vector2<uint8_t> &Entity::getRotation() const {
    return _rot;
}