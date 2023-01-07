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

const world_storage::Level &Dimension::getLevel() const
{
    return _level;
}

world_storage::Level &Dimension::getEditableLevel()
{
    return _level;
}
