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
#include "math/Vector3.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "ThreadPool.hpp"

class World;
class Player;
class Entity;

constexpr Position getChunkPosition(const Position &position)
{
    Position chunkPos(position.x % 16, position.y, position.z % 16);
    if (chunkPos.x < 0) chunkPos.x += 16;
    if (chunkPos.z < 0) chunkPos.z += 16;
    return chunkPos;
}

class Dimension
{
public:
    Dimension(World *world);
    virtual void initialize();
    virtual void tick();

    [[nodiscard]] virtual bool isInitialized() const;
    [[nodiscard]] virtual World *getWorld() const;
    [[nodiscard]] virtual std::vector<Player *> getPlayerList() const;
    virtual std::vector<Entity *> &getEntities();
    virtual void removeEntity(Entity *entity);
    virtual void addEntity(Entity *entity);
    virtual void forEachEntity(std::function<void(Entity *)> callback);
    virtual void forEachEntityIf(std::function<void(Entity *)> callback, std::function<bool(const Entity *)> predicate);
    virtual void forEachPlayer(std::function<void(Player *)> callback);
    virtual void forEachPlayerIf(std::function<void(Player *)> callback, std::function<bool(const Entity *)> predicate);

    const world_storage::Level &getLevel() const;
    world_storage::Level &getEditableLevel();
    virtual void generateChunk(int x, int z);
    virtual void blockUpdate(Position position, int32_t id);
    virtual void spawnPlayer(Player *player);

    virtual bool hasChunkLoaded(int x, int z) const;

    /**
     * @brief Get a loaded chunk
     *
     * @throws std::runtime_error if the chunk is not loaded
     *
     * @param x
     * @param z
     * @return world_storage::ChunkColumn&
     */
    virtual world_storage::ChunkColumn &getChunk(int x, int z);

    /**
     * @brief Loads a chunk from the world save or generates it if it doesn't exist
     *
     * @note This function is thread-safe
     *
     * @param x
     * @param z
     * @param callback
     * @return size_t a job id,
     */
    virtual std::shared_ptr<ThreadPool::Task> loadOrGenerateChunk(int x, int z, std::function<void(world_storage::ChunkColumn &)> callback = nullptr);
    virtual world_storage::ChunkColumn &loadOrGenerateChunkSync(int x, int z, std::function<void(world_storage::ChunkColumn &)> callback = nullptr);

public:
    std::counting_semaphore<1000> dimensionLock;

protected:
    std::vector<Entity *> _entities;
    logging::Logger *_log;
    World *_world;
    std::atomic<int> _numThreadsWaiting;
    std::mutex _processingMutex;
    bool _isInitialized;
    world_storage::Level _level;
};


#endif //CUBICSERVER_DIMENSION_HPP
