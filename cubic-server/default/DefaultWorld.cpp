#include "DefaultWorld.hpp"

DefaultWorld::DefaultWorld(WorldGroup *worldGroup)
    : World(worldGroup)
{
    this->_dimensions.emplace("end", std::make_shared<TheEnd>(reinterpret_cast<World *>(this)));
    this->_dimensions.emplace("nether", std::make_shared<TheNether>(reinterpret_cast<World *>(this)));
    this->_dimensions.emplace("overworld", std::make_shared<Overworld>(reinterpret_cast<World *>(this)));
    this->_worldStorage.addLevel("end");
    this->_worldStorage.addLevel("nether");
    this->_worldStorage.addLevel("overworld");
}

void DefaultWorld::tick()
{
    World::tick();
    // TODO: Launch threads for all the dimensions
    for (auto &dim : this->_dimensions)
        _processingThreads.push_back(new std::thread(&Dimension::tick, dim.second));
}

void DefaultWorld::initialize()
{
    for (auto &dim : this->_dimensions)
        dim.second->initialize();
}
