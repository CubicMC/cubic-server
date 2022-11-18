#include "World.hpp"
#include "Dimension.hpp"
#include "ClientPackets.hpp"

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

    updateTime();
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

void World::updateTime() {
    std::shared_ptr<std::vector<uint8_t>> data;
    // add tick to age of the world and time
    _age += 1;
    _time += 1;
    if (_time > 24000)
        _time = 0;

    // send packets to clients (missing clients in architecture)
    data = protocol::createUpdateTime({_age, _time});
}