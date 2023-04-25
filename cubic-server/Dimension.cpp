#include "Dimension.hpp"
#include "Entity.hpp"

#include "Player.hpp"
#include "World.hpp"
#include "logging/Logger.hpp"
#include "world_storage/ChunkColumn.hpp"
#include <memory>
#include "Server.hpp"

Dimension::Dimension(std::shared_ptr<World> world):
    _dimensionLock(std::counting_semaphore<1000>(0)),
    _world(world),
    _isInitialized(false),
    _isRunning(false)
{
}

void Dimension::tick()
{
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
    for (auto &entity : _entities)
        if (entity->getId() == id)
            return entity;
    throw std::runtime_error("Entity not found");
}

const std::shared_ptr<Entity> Dimension::getEntityByID(int32_t id) const
{
    for (auto &entity : _entities)
        if (entity->getId() == id)
            return entity;
    throw std::runtime_error("Entity not found");
}

void Dimension::removeEntity(int32_t entity_id)
{
    _entities.erase(
        std::remove_if(
            _entities.begin(), _entities.end(),
            [entity_id](const std::shared_ptr<Entity> ent) {
                return entity_id == ent->getId();
            }
        ),
        _entities.end()
    );
    for (auto &player : _players)
        player->sendRemoveEntities({entity_id});
}

void Dimension::removePlayer(int32_t entity_id)
{
    LDEBUG("Removing player with id: ", entity_id);
    _players.erase(
        std::remove_if(
            _players.begin(), _players.end(),
            [entity_id](const std::shared_ptr<Player> ent) {
                return entity_id == ent->getId();
            }
        ),
        _players.end()
    );
    for (auto &player : _players)
        player->sendRemoveEntities({entity_id});
}

void Dimension::addEntity(std::shared_ptr<Entity> entity) { _entities.push_back(entity); }

void Dimension::addPlayer(std::shared_ptr<Player> entity) { _players.push_back(entity); }

const world_storage::Level &Dimension::getLevel() const { return _level; }

world_storage::Level &Dimension::getLevel() { return _level; }

void Dimension::generateChunk(UNUSED int x, UNUSED int z) { }

std::shared_ptr<thread_pool::Task> Dimension::loadOrGenerateChunk(int x, int z, std::shared_ptr<Player> player)
{
    this->_loadingChunksMutex.lock();
    if (this->_loadingChunks.contains({x, z})) {
        if (std::find_if(this->_loadingChunks[{x, z}].players.begin(), this->_loadingChunks[{x, z}].players.end(), [player](const std::weak_ptr<Player> current_weak_player) {
                if (auto current_player = current_weak_player.lock())
                    return current_player->getId() == player->getId();
                return false;
            }) == this->_loadingChunks[{x, z}].players.end()) {
            this->_loadingChunks[{x, z}].players.push_back(player);
        }
        this->_loadingChunksMutex.unlock();
        return this->_loadingChunks[{x, z}].task;
    }

    auto task = this->_world->getGenerationPool().add([this, x, z] {
        // TODO: load chunk from disk if it exists
        this->generateChunk(x, z);

        // This send the chunk to the players that are loading it
        this->_loadingChunksMutex.lock();
        for (auto weak_player : this->_loadingChunks[{x, z}].players) {
            if (auto player = weak_player.lock()) {
                player->sendChunkAndLightUpdate(this->_level.getChunkColumn(x, z));
            }
        }
        this->_loadingChunks.erase({x, z});
        this->_loadingChunksMutex.unlock();
    });

    auto request = ChunkRequest {task, {player}};

    this->_loadingChunks[{x, z}] = request;
    this->_loadingChunksMutex.unlock();

    return request.task;
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
    this->_loadingChunksMutex.lock();
    if (!this->_loadingChunks.contains(pos)) {
        this->_loadingChunksMutex.unlock();
        return;
    }

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

    if (this->_loadingChunks[pos].players.empty()) {
        this->_loadingChunks[pos].task->cancel();
        this->_loadingChunks.erase(pos);
    }
    this->_loadingChunksMutex.unlock();
}

world_storage::ChunkColumn &Dimension::getChunk(int x, int z) { return this->_level.getChunkColumn(x, z); }

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
    auto &chunk = this->_level.getChunkColumnFromBlockPos(position.x, position.z);

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
