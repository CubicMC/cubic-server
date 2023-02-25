#include "DefaultWorld.hpp"

DefaultWorld::DefaultWorld(WorldGroup *worldGroup):
    World(worldGroup)
{
    this->_dimensions.emplace("end", std::make_shared<TheEnd>(reinterpret_cast<World *>(this)));
    this->_dimensions.emplace("nether", std::make_shared<TheNether>(reinterpret_cast<World *>(this)));
    this->_dimensions.emplace("overworld", std::make_shared<Overworld>(reinterpret_cast<World *>(this)));
}

void DefaultWorld::tick()
{
    World::tick();
    for (auto &[_, dim] : this->_dimensions)
        dim->getDimensionLock().release();
}

void DefaultWorld::initialize()
{
    World::initialize();
}

void DefaultWorld::stop()
{
    World::stop();
}
