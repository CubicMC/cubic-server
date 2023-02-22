#include "Dimension.hpp"
#include "Player.hpp"
#include "World.hpp"
#include "logging/Logger.hpp"
#include "world_storage/ChunkColumn.hpp"

Dimension::Dimension(World *world):
    _world(world),
    dimensionLock(std::counting_semaphore<1000>(0)),
    _isInitialized(false)
{
    _log = logging::Logger::get_instance();
}

void Dimension::tick()
{
    forEachEntity([](Entity *ent){
        ent->tick();
    });
}

void Dimension::initialize()
{
}

bool Dimension::isInitialized() const
{
    return _isInitialized;
}

World *Dimension::getWorld() const
{
    return _world;
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

std::shared_ptr<ThreadPool::Task> Dimension::loadOrGenerateChunk(int x, int z, std::function<void(world_storage::ChunkColumn &)> callback)
{
    return this->_world->getGenerationPool().add(&Dimension::loadOrGenerateChunkSync, this, x, z, callback);
}

world_storage::ChunkColumn &Dimension::loadOrGenerateChunkSync(int x, int z, std::function<void(world_storage::ChunkColumn &)> callback)
{
    // TODO: add a way to load chunks from disk. Maybe load it in the generation pool task ?
    this->generateChunk(x, z);
    if (callback)
        callback(this->_level.getChunkColumn(x, z));
    return this->_level.getChunkColumn(x, z);
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

world_storage::ChunkColumn &Dimension::getChunk(int x, int z)
{
    return this->_level.getChunkColumn(x, z);
}

void Dimension::spawnPlayer(Player *current)
{
    const std::vector<Player *> player_list = this->getPlayerList();

    for (auto &player : player_list) {
        LDEBUG("player is : " + player->getUsername());
        LDEBUG("current is : " + current->getUsername());
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
            LDEBUG("send spawn player to " + player->getUsername());
            current->sendSpawnPlayer({
                player->getId(),
                player->getUuid(),
                player->getPosition().x,
                player->getPosition().y,
                player->getPosition().z,
                player->getRotation().x,
                player->getRotation().y
            });
            LDEBUG("send spawn player to " + current->getUsername());
        //}
        }
    }
}

void Dimension::blockUpdate(Position position, int32_t id)
{
    LINFO("Dimension block update (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ", " + std::to_string(position.z) + ") -> " + std::to_string(id) + ")");
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
