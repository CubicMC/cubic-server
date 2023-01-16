#include "Dimension.hpp"
#include "Player.hpp"
#include "World.hpp"

void Dimension::tick()
{
    forEachEntity([](Entity *ent){
        ent->tick();
    });
}

void Dimension::initialize()
{

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
    _entities.erase(std::remove(_entities.begin(), _entities.end(), entity), _entities.end());
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

void Dimension::spawnPlayer(const Player *current)
{
    const std::vector<Player *> player_list = this->getPlayerList();

    for (auto &player : player_list) {

        //if (current->getPos().distance(player->getPos()) <= 12) {
            player->getClient()->sendSpawnPlayer({
                current->getId(),
                current->getUuid(),
                current->getPosition().x,
                current->getPosition().y,
                current->getPosition().z,
                current->getRotation().x,
                current->getRotation().y
            });
            current->getClient()->sendSpawnPlayer({
                player->getId(),
                player->getUuid(),
                player->getPosition().x,
                player->getPosition().y,
                player->getPosition().z,
                player->getRotation().x,
                player->getRotation().y
            });
        //}
    }
}

void Dimension::blockUpdate(protocol::Position position, int32_t id)
{
    this->forEachPlayer([&position, &id](Player *player)
        {
            player->getClient()->sendBlockUpdate({position, id});
        }
    );
}
