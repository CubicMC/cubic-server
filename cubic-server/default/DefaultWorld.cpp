#include "DefaultWorld.hpp"

DefaultWorld::DefaultWorld(WorldGroup *worldGroup):
    World(worldGroup)
{
}

void DefaultWorld::tick() { World::tick(); }

void DefaultWorld::initialize()
{
    this->_dimensions.emplace("end", std::make_shared<TheEnd>(shared_from_this()));
    this->_dimensions.emplace("nether", std::make_shared<TheNether>(shared_from_this()));
    this->_dimensions.emplace("overworld", std::make_shared<Overworld>(shared_from_this()));

    World::initialize();
}

void DefaultWorld::stop() { World::stop(); }
