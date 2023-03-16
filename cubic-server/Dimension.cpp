#include "Dimension.hpp"
#include "Player.hpp"
#include "World.hpp"
#include "logging/Logger.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "Server.hpp"

Dimension::Dimension(World *world):
    _world(world),
    _dimensionLock(std::counting_semaphore<1000>(0)),
    _isInitialized(false),
    _isRunning(false)
{
}

void Dimension::tick()
{
    forEachEntity([](Entity *ent){
        ent->tick();
    });
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

bool Dimension::isInitialized() const
{
    return _isInitialized;
}

World *Dimension::getWorld() const
{
    return _world;
}

std::counting_semaphore<1000> &Dimension::getDimensionLock()
{
    return _dimensionLock;
}

std::vector<Entity *> &Dimension::getEntities()
{
    return _entities;
}

void Dimension::removeEntity(Entity *entity)
{
    LINFO("In remove entity in dimension");
    _entities.erase(std::remove(_entities.begin(), _entities.end(), entity), _entities.end());
    for (auto &player : getPlayerList())
        player->sendRemoveEntities({entity->getId()});
}

void Dimension::addEntity(Entity *entity)
{
    _entities.push_back(entity);
}

void Dimension::forEachEntity(std::function<void(Entity *)> callback)
{
    for (auto _entity : _entities)
        callback(_entity);
}

void Dimension::forEachEntityIf(std::function<void(Entity *)> callback, std::function<bool(const Entity *)> predicate)
{
    for (auto _entity : _entities)
        if (predicate(_entity))
            callback(_entity);
}

void Dimension::forEachPlayer(std::function<void(Player *)> callback)
{
    std::vector<Player *> _players = this->getPlayerList();

    for (auto _player : _players)
        callback(_player);
}

void Dimension::forEachPlayerIf(std::function<void(Player *)> callback, std::function<bool(const Entity *)> predicate)
{
    std::vector<Player *> _players = this->getPlayerList();

    for (auto _player : _players)
        if (predicate(_player))
            callback(_player);
}

const world_storage::Level &Dimension::getLevel() const
{
    return _level;
}

world_storage::Level &Dimension::getEditableLevel()
{
    return _level;
}

void Dimension::generateChunk(int x, int z)
{
}

std::shared_ptr<thread_pool::Task> Dimension::loadOrGenerateChunk(int x, int z, Player *player)
{
    this->_loadingChunksMutex.lock();
    if (this->_loadingChunks.contains({x, z})) {
        if (std::find(this->_loadingChunks[{x, z}].players.begin(), this->_loadingChunks[{x, z}].players.end(), player)
            == this->_loadingChunks[{x, z}].players.end()
        ) { this->_loadingChunks[{x, z}].players.push_back(player); }
        this->_loadingChunksMutex.unlock();
        return this->_loadingChunks[{x, z}].task;
    }

    auto request = ChunkRequest{
        this->_world->getGenerationPool().add([this, x, z]{
            // TODO: load chunk from disk if it exists
            this->generateChunk(x, z);

            // This send the chunk to the players that are loading it
            this->_loadingChunksMutex.lock();
            for (auto &entity: this->_entities) {
                // pls don't kill me
                // this is a hack to check if the client is still connected
                // And the best part ? I don't even know if it works
                if (
                    std::find_if(
                        this->_loadingChunks[{x, z}].players.begin(),
                        this->_loadingChunks[{x, z}].players.end(),
                        [entity](const Player *player) { return player == entity; }
                    ) == this->_loadingChunks[{x, z}].players.end()
                ) continue;
                reinterpret_cast<Player *>(entity)->sendChunkAndLightUpdate(this->_level.getChunkColumn(x, z));
            }
            this->_loadingChunks.erase({x, z});
            this->_loadingChunksMutex.unlock();
        }),
        {player}
    };

    this->_loadingChunks[{x, z}] = request;
    this->_loadingChunksMutex.unlock();

    return request.task;
}

void Dimension::_run()
{
    while (this->_isRunning && !this->_isInitialized)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    while (this->_isRunning) {
        this->_dimensionLock.acquire();
        this->tick();
    }
}

std::vector<Player *> Dimension::getPlayerList() const
{
    std::vector<Player *> player_list;

    for (auto &entity : this->_world->getEntities()) {
        auto player = dynamic_cast<Player *>(entity);

        if (player != nullptr && player->getDimension().get() == this) {
            player_list.push_back(player);
        }
    }
    return player_list;
}

bool Dimension::hasChunkLoaded(int x, int z) const
{
    return this->_level.hasChunkColumn(x, z);
}

void Dimension::removePlayerFromLoadingChunk(const Position2D &pos, Player *player)
{
    this->_loadingChunksMutex.lock();
    if (!this->_loadingChunks.contains(pos)) {
        this->_loadingChunksMutex.unlock();
        return;
    }

    this->_loadingChunks[pos].players.erase(
        std::remove(this->_loadingChunks[pos].players.begin(), this->_loadingChunks[pos].players.end(), player),
        this->_loadingChunks[pos].players.end()
    );

    if (this->_loadingChunks[pos].players.empty()) {
        this->_loadingChunks[pos].task->cancel();
        this->_loadingChunks.erase(pos);
    }
    this->_loadingChunksMutex.unlock();
}

world_storage::ChunkColumn &Dimension::getChunk(int x, int z)
{
    return this->_level.getChunkColumn(x, z);
}

void Dimension::spawnPlayer(Player *current)
{
    const std::vector<Player *> player_list = this->getPlayerList();

    for (auto &player : player_list) {
        LDEBUG("player is : ", player->getUsername());
        LDEBUG("current is : ", current->getUsername());
        //if (current->getPos().distance(player->getPos()) <= 12) {
        if (player->getId() != current->getId()) {
            player->sendSpawnPlayer({
                current->getId(),
                current->getUuid(),
                current->getPosition().x,
                current->getPosition().y,
                current->getPosition().z,
                current->getRotation().x,
                current->getRotation().y
            });
            LDEBUG("send spawn player to ", player->getUsername());
            current->sendSpawnPlayer({
                player->getId(),
                player->getUuid(),
                player->getPosition().x,
                player->getPosition().y,
                player->getPosition().z,
                player->getRotation().x,
                player->getRotation().y
            });
            LDEBUG("send spawn player to ", current->getUsername());
        //}
        }
    }
}

void Dimension::blockUpdate(Position position, int32_t id)
{
    LDEBUG("Dimension block update ", position, " -> ", id, ")");
    auto &chunk = this->_level.getChunkColumnFromBlockPos(position.x, position.z);

    // Weird ass modulo to get the correct block position in the chunk
    auto x = position.x % 16;
    auto z = position.z % 16;
    if (x < 0) x += 16;
    if (z < 0) z += 16;

    chunk.updateBlock({x, position.y, z}, id);
    this->forEachPlayer([&position, &id](Player *player)
        {
            player->sendBlockUpdate({position, id});
        }
    );
}
