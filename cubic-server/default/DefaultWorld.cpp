#include "DefaultWorld.hpp"

#include "Overworld.hpp"
#include "TheEnd.hpp"
#include "TheNether.hpp"

DefaultWorld::DefaultWorld(WorldGroup *worldGroup, world_storage::WorldType worldType):
    World(worldGroup, worldType)
{
    this->_dimensions.emplace("end", std::make_shared<TheEnd>(this));
    this->_dimensions.emplace("nether", std::make_shared<TheNether>(this));
    this->_dimensions.emplace("overworld", std::make_shared<Overworld>(this));
}

void DefaultWorld::tick() { World::tick(); }

void DefaultWorld::initialize() { World::initialize(); }

void DefaultWorld::stop() { World::stop(); }
