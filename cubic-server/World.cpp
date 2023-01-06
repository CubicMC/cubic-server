#include "World.hpp"
#include "Dimension.hpp"
#include "protocol/ClientPackets.hpp"
#include "Player.hpp"
#include <chrono>

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
    return _entities;
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
        for (auto &entity : _entities) {
            auto player = dynamic_cast<Player *>(entity);

            if (player) {
                player->getClient()->sendUpdateTime({ _age,_time });
            }
        }
        clock = std::chrono::steady_clock::now();
    }
}