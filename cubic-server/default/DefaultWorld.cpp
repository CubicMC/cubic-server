#include "DefaultWorld.hpp"
#include "../protocol/ClientPackets.hpp"

DefaultWorld::DefaultWorld(WorldGroup *worldGroup)
    : World(worldGroup)
{
    this->_dimensions.emplace("end", std::make_shared<TheEnd>(reinterpret_cast<World *>(this)));
    this->_dimensions.emplace("nether", std::make_shared<TheNether>(reinterpret_cast<World *>(this)));
    this->_dimensions.emplace("overworld", std::make_shared<Overworld>(reinterpret_cast<World *>(this)));
}

void DefaultWorld::tick()
{
    World::tick();
    // TODO: Launch threads for all the dimensions
    for (auto &dim : this->_dimensions)
        _processingThreads.push_back(new std::thread(&Dimension::tick, dim.second));

    updateTime();
}

void DefaultWorld::initialize()
{
    for (auto &dim : this->_dimensions)
        dim.second->initialize();
}

void DefaultWorld::updateTime() {
    std::shared_ptr<std::vector<uint8_t>> data;
    // add tick to age of the world and time
    _age += 1;
    _time += 1;
    if (_time > 24000)
        _time = 0;

    // send packets to clients (missing clients in architecture)
    data = protocol::createUpdateTime({_age, _time});
}