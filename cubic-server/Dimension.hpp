#ifndef CUBICSERVER_DIMENSION_HPP
#define CUBICSERVER_DIMENSION_HPP

#include <atomic>
#include <functional>
#include <memory>
#include <semaphore>
#include <thread>
#include <vector>

#include "thread_pool/Task.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Level.hpp"

constexpr int SEMAPHORE_MAX = 1000;

class World;
class Player;
class Entity;

class Dimension {
private:
    struct ChunkRequest {
        std::shared_ptr<thread_pool::Task> task;
        std::vector<Player *> players;
    };

public:
    Dimension(World *world);
    virtual void initialize();
    virtual void tick();
    virtual void stop();

    [[nodiscard]] virtual bool isInitialized() const;
    [[nodiscard]] virtual World *getWorld() const;
    [[nodiscard]] virtual std::counting_semaphore<SEMAPHORE_MAX> &getDimensionLock();
    [[nodiscard]] virtual std::vector<Player *> getPlayerList() const;
    [[nodiscard]] virtual std::vector<Entity *> &getEntities();
    [[nodiscard]] virtual Entity *getEntityByID(int32_t id);

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

    /**
     * @brief Check if a chunk is loaded
     *
     * @param x int32_t
     * @param z int32_t
     * @return bool
     */
    virtual bool hasChunkLoaded(int x, int z) const;

    /**
     * @brief Remove a player from a chunk that is being loaded
     *
     * @note This function is thread-safe
     *
     * @param pos Position2D
     * @param player Player *
     */
    virtual void removePlayerFromLoadingChunk(const Position2D &pos, Player *player);

    /**
     * @brief Get a loaded chunk
     *
     * @throws std::runtime_error if the chunk is not loaded
     *
     * @param x int32_t
     * @param z int32_t
     * @return world_storage::ChunkColumn&
     */
    virtual world_storage::ChunkColumn &getChunk(int x, int z);

    /**
     * @brief Loads a chunk from the world save or generates it if it doesn't exist
     *
     * @note This function is thread-safe
     *
     * @param x int32_t
     * @param z int32_t
     * @return size_t a job id,
     */
    virtual std::shared_ptr<thread_pool::Task> loadOrGenerateChunk(int x, int z, Player *player);

protected:
    virtual void _run();

protected:
    std::counting_semaphore<SEMAPHORE_MAX> _dimensionLock;
    std::vector<Entity *> _entities;
    World *_world;
    std::mutex _processingMutex;
    std::atomic<bool> _isInitialized;
    std::atomic<bool> _isRunning;
    world_storage::Level _level;
    std::mutex _loadingChunksMutex;
    std::unordered_map<Position2D, ChunkRequest> _loadingChunks;
    std::thread _processingThread;
};

#endif // CUBICSERVER_DIMENSION_HPP
