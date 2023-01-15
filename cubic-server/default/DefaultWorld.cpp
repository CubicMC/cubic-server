#include "DefaultWorld.hpp"

DefaultWorld::DefaultWorld(WorldGroup *worldGroup)
    : World(worldGroup)
{
    this->_dimensions.emplace("end", std::make_shared<TheEnd>(reinterpret_cast<World *>(this)));
    this->_dimensions.emplace("nether", std::make_shared<TheNether>(reinterpret_cast<World *>(this)));
    this->_dimensions.emplace("overworld", std::make_shared<Overworld>(reinterpret_cast<World *>(this)));
    for (auto [_, dim] : this->_dimensions)
        _processingThreads.push_back(new std::thread([dim](){
            while (1) {
                dim->dimensionLock.acquire();
                dim->tick();
            }
        }));
}

void DefaultWorld::tick()
{
    World::tick();
    updateTime();
    for (auto [_, dim] : this->_dimensions)
        dim->dimensionLock.release();
}

void DefaultWorld::initialize()
{
    for (auto &dim : this->_dimensions)
        dim.second->initialize();
}