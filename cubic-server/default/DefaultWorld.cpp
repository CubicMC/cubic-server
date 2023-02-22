#include "DefaultWorld.hpp"

DefaultWorld::DefaultWorld(WorldGroup *worldGroup):
    World(worldGroup),
    _running(true)
{
    this->_dimensions.emplace("end", std::make_shared<TheEnd>(reinterpret_cast<World *>(this)));
    this->_dimensions.emplace("nether", std::make_shared<TheNether>(reinterpret_cast<World *>(this)));
    this->_dimensions.emplace("overworld", std::make_shared<Overworld>(reinterpret_cast<World *>(this)));

    for (auto &[_, dim] : this->_dimensions) {
        _processingThreads.emplace_back([this, dim] {
            while (this->_running) {
                dim->dimensionLock.acquire();
                dim->tick();
            }
        });
    }
}

void DefaultWorld::tick()
{
    World::tick();
    for (auto &[_, dim] : this->_dimensions)
        dim->dimensionLock.release();
}

void DefaultWorld::initialize()
{
    for (auto &[_, dim] : this->_dimensions)
        dim->initialize();
}

void DefaultWorld::stop()
{
    World::stop();
    this->_running = false;

    for (auto &[_, dim] : this->_dimensions)
        dim->dimensionLock.release();

    for (auto &thread : _processingThreads) {
        if (thread.joinable())
            thread.join();
    }
}
