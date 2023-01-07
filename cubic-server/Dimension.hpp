#ifndef CUBICSERVER_DIMENSION_HPP
#define CUBICSERVER_DIMENSION_HPP


#include <atomic>
#include <thread>
#include <vector>

#include "logging/Logger.hpp"
#include "world_storage/Level.hpp"

class World;

class Dimension
{
public:
    Dimension(World *world): _world(world) {
        _log = logging::Logger::get_instance();
    }
    virtual void initialize();
    virtual void tick();
    virtual World *getWorld() const;

    const world_storage::Level &getLevel() const;
    world_storage::Level &getEditableLevel();

protected:
    logging::Logger *_log;
    World *_world;
    std::atomic<int> _numThreadsWaiting;
    std::mutex _processingMutex;
    world_storage::Level _level;
};


#endif //CUBICSERVER_DIMENSION_HPP
