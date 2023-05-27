#ifndef CUBICSERVER_DIMENSION_HPP
#define CUBICSERVER_DIMENSION_HPP

#include <atomic>
#include <functional>
#include <memory>
#include <semaphore>
#include <thread>
#include <vector>

#include "options.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Level.hpp"

// TODO(huntears): Fix whatever this is
constexpr int SEMAPHORE_MAX = 1000;

class World;
class Player;
class Entity;

class Dimension {
private:
    using ChunkRequest = struct {
        int32_t id;
        std::vector<std::weak_ptr<Player>> players;
    };

public:
    Dimension(std::shared_ptr<World> world);
    virtual ~Dimension() = default;
    virtual void initialize();
    virtual void tick();
    virtual void stop();

    NODISCARD virtual bool isInitialized() const;
    NODISCARD virtual std::shared_ptr<World> getWorld();
    NODISCARD virtual const std::shared_ptr<World> getWorld() const;
    NODISCARD virtual std::counting_semaphore<SEMAPHORE_MAX> &getDimensionLock();
    NODISCARD virtual std::vector<std::shared_ptr<Player>> &getPlayers();
    NODISCARD virtual std::vector<std::shared_ptr<Entity>> &getEntities();
    NODISCARD virtual const std::vector<std::shared_ptr<Player>> &getPlayers() const;
    NODISCARD virtual const std::vector<std::shared_ptr<Entity>> &getEntities() const;
    NODISCARD virtual std::shared_ptr<Entity> getEntityByID(int32_t id);
    NODISCARD virtual const std::shared_ptr<Entity> getEntityByID(int32_t id) const;

    virtual void removeEntity(int32_t entity_id);
    virtual void removePlayer(int32_t entity_id);
    virtual void addEntity(std::shared_ptr<Entity> entity);
    virtual void addPlayer(std::shared_ptr<Player> player);

    const world_storage::Level &getLevel() const;
    world_storage::Level &getLevel();
    virtual void generateChunk(int x, int z);
    virtual void updateBlock(Position position, int32_t id);
    virtual void spawnPlayer(Player &player);

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
    virtual void removePlayerFromLoadingChunk(const Position2D &pos, std::shared_ptr<Player> player);

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

    virtual const world_storage::ChunkColumn &getChunk(int x, int z) const;

    /**
     * @brief Loads a chunk from the world save or generates it if it doesn't exist
     *
     * @note This function is thread-safe
     *
     * @param x int32_t
     * @param z int32_t
     */
    virtual void loadOrGenerateChunk(int x, int z, std::shared_ptr<Player> player);

protected:
    virtual void _run();

public:
    mutable std::mutex _playersMutex;
    mutable std::mutex _entitiesMutex;
    mutable std::mutex _loadingChunksMutex;

protected:
    std::counting_semaphore<SEMAPHORE_MAX> _dimensionLock;
    std::vector<std::shared_ptr<Entity>> _entities;
    std::vector<std::shared_ptr<Player>> _players;
    std::shared_ptr<World> _world;
    std::mutex _processingMutex;
    std::atomic<bool> _isInitialized;
    std::atomic<bool> _isRunning;
    world_storage::Level _level;
    std::unordered_map<Position2D, ChunkRequest> _loadingChunks;
    std::thread _processingThread;
};

#endif // CUBICSERVER_DIMENSION_HPP
