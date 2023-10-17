#include "Dimension.hpp"

#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "entities/Entity.hpp"
#include "entities/EntityType.hpp"
#include "logging/logging.hpp"
#include "math/Vector3.hpp"
#include "protocol/ClientPackets.hpp"
#include "types.hpp"
#include <cstdint>
#include <memory>
#include <mutex>
#include <thread>

Dimension::Dimension(std::shared_ptr<World> world, world_storage::DimensionType dimensionType):
    _playersMutex(),
    _entitiesMutex(),
    _newEntitiesMutex(),
    _loadingChunksMutex(),
    _dimensionLock(std::counting_semaphore<SEMAPHORE_MAX>(0)),
    _entities({}),
    _newEntities({}),
    _players({}),
    _world(world),
    _processingMutex(),
    _isInitialized(false),
    _isRunning(false),
    _level(),
    _loadingChunks({}),
    _processingThread(),
    _dimensionType(dimensionType),
    _tps({0, 0, 0})
{
}

void Dimension::tick()
{
    {
        std::lock_guard _(_entitiesMutex);
        for (auto ent : _entities) {
            ent->tick();
        }
    }
    uint32_t rts = CONFIG["randomtickspeed"].as<uint32_t>();
    if (rts != 0) {
        for (auto &[pos, chunk] : _level.getChunkColumns()) {
            // TODO(huntears): Test if a chunk is within simulation distance of a player
            if (!chunk.isReady())
                continue;
            chunk.processRandomTick(rts);
        }
    }
    {
        std::unique_lock a(_entitiesMutex, std::defer_lock);
        std::unique_lock b(_newEntitiesMutex, std::defer_lock);
        std::lock(a, b);

        if (_newEntities.size() != 0) {
            _entities.insert(_entities.end(), _newEntities.begin(), _newEntities.end());
            _newEntities.clear();
        }
    }
}

void Dimension::stop()
{
    this->_isRunning = false;
    this->_dimensionLock.release(_dimensionLock.max());

    if (_processingThread.joinable())
        _processingThread.join();
    // TODO: Save the dimension

    _level.clear();
}

void Dimension::initialize()
{
    this->_isRunning = true;
    this->_processingThread = std::thread(&Dimension::_run, this);
}

std::shared_ptr<Entity> Dimension::getEntityByID(int32_t id)
{
    std::lock_guard _(_entitiesMutex);
    for (auto &entity : _entities)
        if (entity->getId() == id)
            return entity;
    LERROR("Entity not found");
    return nullptr;
}

std::shared_ptr<const Entity> Dimension::getEntityByID(int32_t id) const
{
    std::lock_guard _(_entitiesMutex);
    for (auto &entity : _entities)
        if (entity->getId() == id)
            return entity;
    LERROR("Entity not found");
    return nullptr;
}

void Dimension::removeEntity(int32_t entity_id)
{
    {
        std::lock_guard _(_entitiesMutex);

        _entities.erase(
            std::remove_if(
                _entities.begin(), _entities.end(),
                [entity_id](const std::shared_ptr<Entity> ent) {
                    return entity_id == ent->getId();
                }
            ),
            _entities.end()
        );
    }

    std::lock_guard _(_playersMutex);
    for (auto player : _players)
        player->sendRemoveEntities({entity_id});
}

void Dimension::removePlayer(int32_t entity_id)
{
    std::lock_guard _(_playersMutex);
    LDEBUG("Removing player with id: {}", entity_id);
    _players.erase(
        std::remove_if(
            _players.begin(), _players.end(),
            [entity_id](const std::shared_ptr<Player> ent) {
                return entity_id == ent->getId();
            }
        ),
        _players.end()
    );
    for (auto player : _players)
        player->sendRemoveEntities({entity_id});
}

void Dimension::addEntity(std::shared_ptr<Entity> entity)
{
    std::lock_guard _(_newEntitiesMutex);
    _newEntities.emplace_back(entity);
}

void Dimension::addPlayer(std::shared_ptr<Player> entity)
{
    std::lock_guard _(_playersMutex);
    _players.emplace_back(entity);
}

void Dimension::generateChunk(Position2D pos, world_storage::GenerationState goalState) { generateChunk(pos.x, pos.z, goalState); }

void Dimension::generateChunk(UNUSED int x, UNUSED int z, UNUSED world_storage::GenerationState goalState) { }

void Dimension::loadOrGenerateChunk(int x, int z, const std::shared_ptr<Player> player)
{
    std::lock_guard<std::mutex> _(_loadingChunksMutex);
    if (this->_loadingChunks.contains({x, z})) {
        if (std::find_if(this->_loadingChunks[{x, z}].players.begin(), this->_loadingChunks[{x, z}].players.end(), [player](const std::weak_ptr<const Player> current_weak_player) {
                if (auto current_player = current_weak_player.lock())
                    return current_player->getId() == player->getId();
                return false;
            }) == this->_loadingChunks[{x, z}].players.end()) {
            this->_loadingChunks[{x, z}].players.push_back(player);
        }
        return;
    }

    auto id = this->_world->getGenerationPool().addJob(
        [this, x, z] {
            std::lock_guard _(this->_playersMutex);
            double current_min = 999999.0f; // TODO(huntears): Change this magic value xd;
            for (auto player : this->getPlayers()) {
                const auto &pos = player->getPosition();
                const Vector3<double> chunkPos = {(double) x * 16, pos.y, (double) z * 16};
                current_min = std::min(current_min, pos.distance(chunkPos));
            }
            return static_cast<int>(std::ceil(current_min));
        },
        [this, x, z] {
            // TODO: load chunk from disk if it exists
            this->generateChunk(x, z);

            if (!this->hasChunkLoaded(x, z))
                return;

            this->sendChunkToPlayers(x, z);
        }
    );

    auto request = ChunkRequest {id, {player}};

    this->_loadingChunks[{x, z}] = request;

    return;
}

void Dimension::_run()
{
    // TODO(huntears): Remove this busy loop
    while (this->_isRunning && !this->_isInitialized)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    while (this->_isRunning) {
        this->_dimensionLock.acquire();
        this->tick();
    }
}

bool Dimension::hasChunkLoaded(int x, int z) const { return this->_level.hasChunkColumn(x, z); }

void Dimension::removePlayerFromLoadingChunk(const Position2D &pos, const std::shared_ptr<const Player> player)
{
    std::lock_guard<std::mutex> _(_loadingChunksMutex);
    if (!this->_loadingChunks.contains(pos))
        return;

    this->_loadingChunks[pos].players.erase(
        std::remove_if(
            this->_loadingChunks[pos].players.begin(), this->_loadingChunks[pos].players.end(),
            [player](const std::weak_ptr<const Player> current_weak_player) {
                if (auto current_player = current_weak_player.lock())
                    return current_player->getId() == player->getId();
                return true;
            }
        ),
        this->_loadingChunks[pos].players.end()
    );

    if (this->_loadingChunks[pos].players.empty() && this->getWorld()->getGenerationPool().cancelJob(this->_loadingChunks[pos].id)) {
        // this->_loadingChunks[pos].task->cancel();
        // This could be replaced using either an iterator, or something else (maybe an if condition inside the job? or simply integrated inside the overlay.)
        this->_loadingChunks.erase(pos);
    }
}

world_storage::ChunkColumn &Dimension::getChunk(int x, int z) { return this->_level.getChunkColumn(x, z); }
world_storage::ChunkColumn &Dimension::getChunk(const Position2D &pos) { return this->_level.getChunkColumn(pos); }

const world_storage::ChunkColumn &Dimension::getChunk(int x, int z) const { return this->_level.getChunkColumn(x, z); }
const world_storage::ChunkColumn &Dimension::getChunk(const Position2D &pos) const { return this->_level.getChunkColumn(pos); }

void Dimension::spawnPlayer(Player &current)
{
    auto current_id = current.getId();
    {

        std::lock_guard _(_playersMutex);
        for (auto player : _players) {
            LDEBUG("player is: {}", player->getUsername());
            LDEBUG("current is: {}", current.getUsername());
            // if (current->getPos().distance(player->getPos()) <= 12) {
            if (player->getId() != current_id) {
                player->sendSpawnPlayer(
                    {current_id, current.getUuid(), current.getPosition().x, current.getPosition().y, current.getPosition().z, current.getRotation().x, current.getRotation().z}
                );
                LDEBUG("send spawn player to {}", player->getUsername());
                current.sendSpawnPlayer(
                    {player->getId(), player->getUuid(), player->getPosition().x, player->getPosition().y, player->getPosition().z, player->getRotation().x,
                     player->getRotation().z}
                );
                LDEBUG("send spawn player to {}", current.getUsername());
                //}
            }
            player->sendEntityMetadata(current);
            current.sendEntityMetadata(*player);
        }
    }
    {
        std::lock_guard _(_entitiesMutex);
        for (auto ent : _entities) {
            if (ent->getType() == EntityType::Player)
                continue;
            current.sendSpawnEntity(*ent);
            current.sendEntityMetadata(*ent);
        }
    }
}

void Dimension::spawnEntity(const std::shared_ptr<const Entity> current)
{
    std::lock_guard _(_entitiesMutex);
    for (auto player : _players) {
        LDEBUG("spawn entity with id: {}", current->getId());
        player->sendSpawnEntity({
            current->getId(), // Entity ID
            current->getUuid(), // Entity UUID
            current->getType(), // Entity Type
            current->getPosition().x, // Entity Position X
            current->getPosition().y, // Entity Position Y
            current->getPosition().z, // Entity Position Z
            0, // Entity Pitch
            0, // Entity Yaw
            0, // Entity Head Yaw
            0, // Entity data
            0, // Entity Velocity X
            0, // Entity Velocity Y
            0 // Entity Velocity Z
        });
        player->sendEntityMetadata(*current);
    }
}

void Dimension::updateBlock(Position position, int32_t id)
{
    LDEBUG("Dimension block update {} -> {}", position, id);
    auto &chunk = this->_level.getChunkColumnFromBlockPos(position.x, position.z);

    // Weird ass modulo to get the correct block position in the chunk
    auto x = position.x % 16;
    auto z = position.z % 16;
    if (x < 0)
        x += 16;
    if (z < 0)
        z += 16;

    chunk.updateBlock({x, position.y, z}, id);
    std::lock_guard _(_playersMutex);
    for (auto player : _players) {
        player->sendBlockUpdate({position, id});
    }
}

void Dimension::updateEntityAttributes(const protocol::UpdateAttributes &attributes)
{
    std::lock_guard _(_entitiesMutex);
    for (auto player : _players) {
        player->sendUpdateAttributes(attributes);
    }
}

void Dimension::sendChunkToPlayers(int x, int z)
{
    // This send the chunk to the players that are loading it
    std::lock_guard<std::mutex> _(_loadingChunksMutex);
    for (auto weak_player : this->_loadingChunks[{x, z}].players) {
        if (auto player = weak_player.lock()) {
            player->sendChunkAndLightUpdate(this->_level.getChunkColumn(x, z));
        }
    }
    this->_loadingChunks.erase({x, z});
}
