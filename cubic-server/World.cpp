#include "World.hpp"
#include "Dimension.hpp"
#include "Player.hpp"

void World::tick()
{
    for (auto & _processingThread : _processingThreads)
        if (!_processingThread->joinable()) {
            delete _processingThread;
            _processingThread = nullptr;
        }

    std::remove_if(_processingThreads.begin(),
                   _processingThreads.end(),
                   [](const std::thread *cli)
                   { return cli == nullptr; });

    _keepAliveClock.tick();
}

WorldGroup *World::getWorldGroup() const
{
    return _worldGroup;
}

std::shared_ptr<Chat> World::getChat() const
{
    return _chat;
}

std::shared_ptr<Dimension> World::getDimension(const std::string_view &name) const
{
    return this->_dimensions.at(name);
}

std::vector<Entity *> World::getEntities()
{
    std::vector<Entity *> entities;
    for (auto _dimension : _dimensions)
        for (auto _entity : _dimension.second->getEntities())
            entities.push_back(_entity);
    return entities;
}

void World::forEachEntity(std::function<void(Entity *)> callback)
{
    for (auto & _dimension : _dimensions)
        _dimension.second->forEachEntity(callback);
}

void World::forEachEntityIf(std::function<void(Entity *)> callback, std::function<bool(const Entity *)> predicate)
{
    for (auto & _dimension : _dimensions)
        _dimension.second->forEachEntityIf(callback, predicate);
}

const world_storage::LevelData &World::getLevelData() const
{
    return _levelData;
}

void World::setLevelData(const world_storage::LevelData &value)
{
    _levelData = value;
}

void World::processKeepAlive()
{
    long id = 0;
    forEachEntityIf(
        [id](Entity *entity) {
            Player *player = dynamic_cast<Player *>(entity);
            if (player->keepAliveId() != 0) {
                player->disconnect();
                return;
            }
            player->sendKeepAlive(id);
        },
        [](const Entity *entity) {
            const Player *player = dynamic_cast<const Player *>(entity);
            if (player == nullptr)
                return false;
            return true;
        }
    );
}
