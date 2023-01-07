#include "Entity.hpp"

Entity::Entity(std::shared_ptr<Dimension> dim) : _dim(dim)
{
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
}

void Entity::setDimension(std::shared_ptr<Dimension> dim)
{
    _dim = dim;
}

std::shared_ptr<Dimension> Entity::getDimension() const
{
    return _dim;
}

int32_t Entity::getId() const
{
    return _id;
}
