#ifndef CUBICSERVER_DIMENSION_HPP
#define CUBICSERVER_DIMENSION_HPP


#include <atomic>
#include <thread>
#include <vector>
#include <functional>
#include <semaphore>

#include "logging/Logger.hpp"
#include "Entity.hpp"
#include "world_storage/Level.hpp"

class World;

class Player;

class Entity;

class Dimension
{
public:
    Dimension(World *world): _world(world), dimensionLock(std::counting_semaphore<1000>(0)) {
        _log = logging::Logger::get_instance();
    }
    virtual void initialize();
    virtual void tick();
    [[nodiscard]] virtual World *getWorld() const;
    [[nodiscard]] virtual std::vector<Player *> getPlayerList() const;
    virtual std::vector<Entity *> &getEntities();
    virtual void removeEntity(Entity *entity);
    virtual void addEntity(Entity *entity);
    virtual void forEachEntity(std::function<void(Entity *)> callback);
    virtual void forEachEntityIf(std::function<void(Entity *)> callback, std::function<bool(const Entity *)> predicate);

    const world_storage::Level &getLevel() const;
    world_storage::Level &getEditableLevel();
    virtual void generateChunk(int x, int z);
    virtual void spawnPlayer(const Player *);
    std::counting_semaphore<1000> dimensionLock;

protected:
    std::vector<Entity *> _entities;
    logging::Logger *_log;
    World *_world;
    std::atomic<int> _numThreadsWaiting;
    std::mutex _processingMutex;
    world_storage::Level _level;
};


#endif //CUBICSERVER_DIMENSION_HPP
