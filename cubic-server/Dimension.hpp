#ifndef CUBICSERVER_DIMENSION_HPP
#define CUBICSERVER_DIMENSION_HPP

#include <atomic>
#include <boost/circular_buffer.hpp>
#include <functional>
#include <memory>
#include <semaphore>
#include <thread>
#include <vector>

#include "options.hpp"
#include "protocol/ClientPackets.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Level.hpp"

// TODO(huntears): Fix whatever this is
constexpr int SEMAPHORE_MAX = 1000;
constexpr int TICK_PER_MINUTE = 20 * 60;
constexpr float MICROSECS_IN_ONE_SEC = 1000000.0f;
constexpr float MILLIS_IN_ONE_SEC = 1000.0f;

class World;
class Player;
class Entity;

class Dimension : public std::enable_shared_from_this<Dimension> {
private:
    using ChunkRequest = struct {
        int32_t id;
        std::vector<std::weak_ptr<Player>> players;
    };

public:
    Dimension(std::shared_ptr<World> world, world_storage::DimensionType dimensionType);
    virtual ~Dimension() = default;
    virtual void initialize();
    virtual void tick();
    virtual void stop();

    NODISCARD virtual bool isInitialized() const { return _isInitialized; }

    NODISCARD virtual std::shared_ptr<World> getWorld() { return _world; }
    NODISCARD virtual std::counting_semaphore<SEMAPHORE_MAX> &getDimensionLock() { return _dimensionLock; }
    NODISCARD virtual std::vector<std::shared_ptr<Player>> &getPlayers() { return _players; }
    NODISCARD virtual std::vector<std::shared_ptr<Entity>> &getEntities() { return _entities; }
    NODISCARD virtual std::shared_ptr<Entity> getEntityByID(int32_t id);
    NODISCARD world_storage::Level &getLevel() { return _level; }

    NODISCARD virtual std::shared_ptr<const World> getWorld() const { return _world; }
    NODISCARD virtual const std::vector<std::shared_ptr<Player>> &getPlayers() const { return _players; }
    NODISCARD virtual const std::vector<std::shared_ptr<Entity>> &getEntities() const { return _entities; }
    NODISCARD virtual std::shared_ptr<const Entity> getEntityByID(int32_t id) const;
    NODISCARD const world_storage::Level &getLevel() const { return _level; }

    virtual void removeEntity(int32_t entity_id);
    virtual void removePlayer(int32_t entity_id);
    virtual void addEntity(std::shared_ptr<Entity> entity);
    virtual void addPlayer(std::shared_ptr<Player> player);

    virtual void generateChunk(Position2D pos, world_storage::GenerationState goalState = world_storage::GenerationState::READY);
    virtual void generateChunk(int x, int z, world_storage::GenerationState goalState = world_storage::GenerationState::READY);
    virtual void updateBlock(Position position, int32_t id);
    void updateEntityAttributes(const protocol::UpdateAttributes &attributes);
    virtual void spawnPlayer(Player &player);
    virtual void spawnEntity(const std::shared_ptr<const Entity> entity);

    template<isBaseOf<Entity> T, typename... Args>
    std::shared_ptr<T> makeEntity(Args &&...);

    /**
     * @brief Send the chunk to the players that are loading it
     *
     * @param x int
     * @param z int
     */
    virtual void sendChunkToPlayers(int x, int z);

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
    virtual void removePlayerFromLoadingChunk(const Position2D &pos, const std::shared_ptr<const Player> player);

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
     * @brief Get a loaded chunk
     *
     * @throws std::runtime_error if the chunk is not loaded
     *
     * @param pos Position2D
     * @return world_storage::ChunkColumn&
     */
    virtual world_storage::ChunkColumn &getChunk(const Position2D &pos);
    virtual const world_storage::ChunkColumn &getChunk(const Position2D &pos) const;

    /**
     * @brief Loads a chunk from the world save or generates it if it doesn't exist
     *
     * @note This function is thread-safe
     *
     * @param x int32_t
     * @param z int32_t
     * @param player std::shared_ptr<Player>
     */
    virtual void loadOrGenerateChunk(int x, int z, const std::shared_ptr<Player> player);

    /**
     * @brief Get the dimension type
     *
     * @return world_storage::DimensionType
     */
    NODISCARD virtual world_storage::DimensionType getDimensionType() const { return _dimensionType; }

    /**
     * @brief Get the dimension type
     *
     * @return std::string dimension type
     */
    NODISCARD virtual const std::string getDimensionTypeName() const = 0;

    /**
     * @brief Get the dimension name
     *
     * @return std::string dimension name
     */
    NODISCARD virtual const std::string getDimensionName() const = 0;

    virtual void lockLoadingChunksMutex() { _loadingChunksMutex.lock(); };
    virtual void unlockLoadingChunksMutex() { _loadingChunksMutex.unlock(); };

    /**
     * @brief Get the BlockID of a block in the dimension
     *
     * @param pos The position of the block
     * @return BlockId The block ID
     */
    virtual BlockId getBlock(const Position &pos) const { return getLevel().getChunkColumnFromBlockPos(pos.x, pos.z).getBlock(world_storage::convertPositionToChunkPosition(pos)); }

    /**
     * @brief Get the tps of the dimension
     *
     * @return Tps
     */
    virtual Tps getTps() const;

    /**
     * @brief Get the MSPTInfos of the dimension
     *
     * @return MSPTInfos
     */
    virtual MSPTInfos getMSPTInfos() const;

    /**
     * @brief Add a new tile entity to the dimension
     *
     * @param position The position of the tile entity (in absolute coordinates)
     * @param type The type of the tile entity (as a BlockId)
     */
    virtual void addTileEntity(const Position &position, BlockId type);

    /**
     * @brief Remove a tile entity from the dimension
     *
     * @param position The position of the tile entity (in absolute coordinates)
     */
    virtual void removeTileEntity(const Position &position);

    /**
     * @brief Get a tile entity from the dimension using its position
     *
     * @param position The position of the tile entity (in absolute coordinates)
     * @return std::shared_ptr<tile_entity::TileEntity>
     */
    virtual std::shared_ptr<tile_entity::TileEntity> getTileEntity(const Position &position);

    /**
     * @brief Get a tile entity from the dimension using its position
     *
     * @param position The position of the tile entity (in absolute coordinates)
     * @return std::shared_ptr<const tile_entity::TileEntity>
     */
    virtual std::shared_ptr<const tile_entity::TileEntity> getTileEntity(const Position &position) const;

    virtual void pushBackIdToRemove(int32_t id) { _idsToRemove.push_back(id); }

protected:
    virtual void _run();
    virtual void _removeDeadEntities();
    virtual void _removeDeadPlayers();

public:
    mutable std::recursive_mutex _playersMutex;
    mutable std::recursive_mutex _entitiesMutex;
    mutable std::recursive_mutex _newEntitiesMutex;
    mutable std::mutex _loadingChunksMutex;

protected:
    std::counting_semaphore<SEMAPHORE_MAX> _dimensionLock;
    std::vector<std::shared_ptr<Entity>> _entities;
    std::vector<std::shared_ptr<Entity>> _newEntities;
    std::vector<std::shared_ptr<Player>> _players;
    std::shared_ptr<World> _world;
    std::mutex _processingMutex;
    std::atomic<bool> _isInitialized;
    std::atomic<bool> _isRunning;
    world_storage::Level _level;
    std::unordered_map<Position2D, ChunkRequest> _loadingChunks;
    std::thread _processingThread;
    world_storage::DimensionType _dimensionType;
    boost::circular_buffer_space_optimized<float> _circularBufferTps;
    std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<long, std::ratio<1, 1000000000>>> _previousTickTime;
    boost::circular_buffer_space_optimized<float> _circularBufferMSPT;
    std::vector<int32_t> _idsToRemove;
};

template<isBaseOf<Entity> T, typename... Args>
std::shared_ptr<T> Dimension::makeEntity(Args &&...args)
{
    auto entity = std::make_shared<T>(shared_from_this(), args...);
    this->addEntity(entity);
    return entity;
}

#endif // CUBICSERVER_DIMENSION_HPP
