#include <algorithm>

#include "Dimension.hpp"

void Dimension::tick()
{

}

void Dimension::initialize()
{

}

World *Dimension::getWorld() const
{
    return _world;
}

std::vector<Entity *> Dimension::getEntities()
{
    return _entities;
}