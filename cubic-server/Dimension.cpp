#include "Dimension.hpp"

#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/Logger.hpp"
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
    LDEBUG("Removing player with id: ", entity_id);
    std::lock_guard _(_playersMutex);
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
        if (std::find_if(this->_loadingChunks[{x, z}].begin(), this->_loadingChunks[{x, z}].end(), [player](const std::weak_ptr<Player> current_weak_player) {
                if (auto current_player = current_weak_player.lock())
                    return current_player->getId() == player->getId();
                return false;
            }) == this->_loadingChunks[{x, z}].end()) {
            this->_loadingChunks[{x, z}].push_back(player);
        }
        return;
    }

    this->_world->getGenerationPool().addJob([this, x, z] {
        // TODO: load chunk from disk if it exists
        this->generateChunk(x, z);

        // This send the chunk to the players that are loading it
        std::lock_guard<std::mutex> _(_loadingChunksMutex);
        for (auto weak_player : this->_loadingChunks[{x, z}]) {
            if (auto player = weak_player.lock()) {
                player->sendChunkAndLightUpdate(this->_level.getChunkColumn(x, z));
            }
        }
        this->_loadingChunks.erase({x, z});
    });

    auto request = ChunkRequest {{player}};

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

    this->_loadingChunks[pos].erase(
        std::remove_if(
            this->_loadingChunks[pos].begin(), this->_loadingChunks[pos].end(),
            [player](const std::weak_ptr<Player> current_weak_player) {
                if (auto current_player = current_weak_player.lock())
                    return current_player->getId() == player->getId();
                return true;
            }
        ),
        this->_loadingChunks[pos].end()
    );

    if (this->_loadingChunks[pos].empty()) {
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
    for (auto player : _players) {
        LDEBUG("player is : ", player->getUsername());
        LDEBUG("current is : ", current.getUsername());
        // if (current->getPos().distance(player->getPos()) <= 12) {
        if (player->getId() != current_id) {
            player->sendSpawnPlayer(
                {current_id, current.getUuid(), current.getPosition().x, current.getPosition().y, current.getPosition().z, current.getRotation().x, current.getRotation().z}
            );
            LDEBUG("send spawn player to ", player->getUsername());
            current.sendSpawnPlayer(
                {player->getId(), player->getUuid(), player->getPosition().x, player->getPosition().y, player->getPosition().z, player->getRotation().x, player->getRotation().z}
            );
            LDEBUG("send spawn player to ", current.getUsername());
            //}
        }
    }
}

void Dimension::updateBlock(Position position, int32_t id)
{
    LDEBUG("Dimension block update ", position, " -> ", id, ")");
    auto chunk = this->_level.getChunkColumnFromBlockPos(position.x, position.z);

    // Weird ass modulo to get the correct block position in the chunk
    auto x = position.x % 16;
    auto z = position.z % 16;
    if (x < 0)
        x += 16;
    if (z < 0)
        z += 16;

    chunk.updateBlock({x, position.y, z}, id);
    for (auto player : _players) {
        player->sendBlockUpdate({position, id});
    }
}
