#include "Entity.hpp"

void Entity::setDimension(std::shared_ptr<Dimension> dim)
{
    _dim = dim;
}

std::shared_ptr<Dimension> Entity::getDimension() const
{
    return _dim;
}
