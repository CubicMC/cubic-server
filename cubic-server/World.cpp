#include "World.hpp"
#include "Dimension.hpp"
#include "protocol/ClientPackets.hpp"
#include "Player.hpp"
#include <chrono>
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

    updateTime();
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

void World::updateTime() {
    static auto clock = std::chrono::steady_clock::now();
    int64_t time_elapsed;
    std::shared_ptr<std::vector<uint8_t>> data;

    //compute elapsed time

    time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - clock).count();

    //add 20 ticks once every second (default minecraft SMP norm)
    if (time_elapsed > 1000) {
        _age += 20;
        _time += 20;
        if (_time > 24000)
            _time = 0;

        // send packets to clients (missing clients in architecture)
        for (auto &entity : this->getEntities()) {
            auto player = dynamic_cast<Player *>(entity);

            if (player) {
                player->getClient()->sendUpdateTime({ _age,_time });
            }
        }
        clock = std::chrono::steady_clock::now();
    }
}
void World::processKeepAlive()
{
    long id = std::chrono::system_clock::now().time_since_epoch().count();
    forEachEntityIf(
        [this, id](Entity *entity) {
            Player *player = dynamic_cast<Player *>(entity);
            if (player->keepAliveId() != 0) {
                player->setKeepAliveIgnored(player->keepAliveIgnored() + 1);
                if (this->_keepAliveClock.tickRate() * player->keepAliveIgnored() >= 600)
                    player->disconnect("Timed out from keep alive LOL");
                return;
            }
            player->setKeepAliveId(id);
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
