#include "Dimension.hpp"

#include "Entity.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"
#include "math/Vector3.hpp"
#include "protocol/ClientPackets.hpp"
#include "types.hpp"
#include <cstdint>
#include <memory>
#include <mutex>

Dimension::Dimension(std::shared_ptr<World> world):
    _dimensionLock(std::counting_semaphore<1000>(0)),
    _world(world),
    _isInitialized(false),
    _isRunning(false)
{
}

void Dimension::tick()
{
    std::lock_guard _(_entitiesMutex);
    for (auto ent : _entities) {
        ent->tick();
    }
}

void Dimension::stop()
{
    this->_isRunning = false;
    this->_dimensionLock.release();

    if (_processingThread.joinable())
        _processingThread.join();
}

void Dimension::initialize()
{
    this->_isRunning = true;
    this->_processingThread = std::thread(&Dimension::_run, this);
}

bool Dimension::isInitialized() const { return _isInitialized; }

std::shared_ptr<World> Dimension::getWorld() { return _world; }

const std::shared_ptr<World> Dimension::getWorld() const { return _world; }

std::counting_semaphore<1000> &Dimension::getDimensionLock() { return _dimensionLock; }

std::vector<std::shared_ptr<Entity>> &Dimension::getEntities() { return _entities; }

const std::vector<std::shared_ptr<Entity>> &Dimension::getEntities() const { return _entities; }

std::shared_ptr<Entity> Dimension::getEntityByID(int32_t id)
{
    std::lock_guard _(_entitiesMutex);
    for (auto &entity : _entities)
        if (entity->getId() == id)
            return entity;
    throw std::runtime_error("Entity not found");
}

const std::shared_ptr<Entity> Dimension::getEntityByID(int32_t id) const
{
    std::lock_guard _(_entitiesMutex);
    for (auto &entity : _entities)
        if (entity->getId() == id)
            return entity;
    throw std::runtime_error("Entity not found");
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
    std::lock_guard _(_entitiesMutex);
    _entities.push_back(entity);
}

void Dimension::addPlayer(std::shared_ptr<Player> entity)
{
    std::lock_guard _(_playersMutex);
    _players.push_back(entity);
}

const world_storage::Level &Dimension::getLevel() const { return _level; }

world_storage::Level &Dimension::getLevel() { return _level; }

void Dimension::generateChunk(UNUSED int x, UNUSED int z) { }

void Dimension::loadOrGenerateChunk(int x, int z, std::shared_ptr<Player> player)
{
    std::lock_guard<std::mutex> _(_loadingChunksMutex);
    if (this->_loadingChunks.contains({x, z})) {
        if (std::find_if(this->_loadingChunks[{x, z}].players.begin(), this->_loadingChunks[{x, z}].players.end(), [player](const std::weak_ptr<Player> current_weak_player) {
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
            return static_cast<size_t>(std::ceil(current_min));
        },
        [this, x, z] {
            // TODO: load chunk from disk if it exists
            this->generateChunk(x, z);

            // This send the chunk to the players that are loading it
            std::lock_guard<std::mutex> _(_loadingChunksMutex);
            for (auto weak_player : this->_loadingChunks[{x, z}].players) {
                if (auto player = weak_player.lock()) {
                    player->sendChunkAndLightUpdate(this->_level.getChunkColumn(x, z));
                }
            }
            this->_loadingChunks.erase({x, z});
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

std::vector<std::shared_ptr<Player>> &Dimension::getPlayers() { return _players; }

const std::vector<std::shared_ptr<Player>> &Dimension::getPlayers() const { return _players; }

bool Dimension::hasChunkLoaded(int x, int z) const { return this->_level.hasChunkColumn(x, z); }

void Dimension::removePlayerFromLoadingChunk(const Position2D &pos, std::shared_ptr<Player> player)
{
    std::lock_guard<std::mutex> _(_loadingChunksMutex);
    if (!this->_loadingChunks.contains(pos))
        return;

    this->_loadingChunks[pos].players.erase(
        std::remove_if(
            this->_loadingChunks[pos].players.begin(), this->_loadingChunks[pos].players.end(),
            [player](const std::weak_ptr<Player> current_weak_player) {
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

const world_storage::ChunkColumn &Dimension::getChunk(int x, int z) const { return this->_level.getChunkColumn(x, z); }

void Dimension::spawnPlayer(Player &current)
{
    auto current_id = current.getId();
    std::lock_guard _(_playersMutex);
    for (auto player : _players) {
        LDEBUG("player is : {}", player->getUsername());
        LDEBUG("current is : {}", current.getUsername());
        // if (current->getPos().distance(player->getPos()) <= 12) {
        if (player->getId() != current_id) {
            player->sendSpawnPlayer(
                {current_id, current.getUuid(), current.getPosition().x, current.getPosition().y, current.getPosition().z, current.getRotation().x, current.getRotation().z}
            );
            LDEBUG("send spawn player to {}", player->getUsername());
            current.sendSpawnPlayer(
                {player->getId(), player->getUuid(), player->getPosition().x, player->getPosition().y, player->getPosition().z, player->getRotation().x, player->getRotation().z}
            );
            LDEBUG("send spawn player to {}", current.getUsername());
            //}
        }
    }
}

void Dimension::spawnEntity(std::shared_ptr<Entity> current)
{
    std::lock_guard _(_entitiesMutex);
    for (auto player : _players) {
        LDEBUG("spawn entity with id: {}", current->getId());
        player->sendSpawnEntity(
            {current->getId(), {(uint64_t) current->getId(), (uint64_t) current->getId()}, current->getType(), current->getPosition().x, current->getPosition().y,
             current->getPosition().z, 0, 0, 0, 0, 16, 0, 0}
        );
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

void Dimension::addEntityMetadata(const protocol::SetEntityMetadata &metadata)
{
    std::lock_guard _(_entitiesMutex);
    for (auto player : _players) {
        player->sendSetEntityMetadata(metadata);
    }
}
