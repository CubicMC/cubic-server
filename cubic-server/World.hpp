#ifndef CUBICSERVER_WORLD_HPP
#define CUBICSERVER_WORLD_HPP

#include <vector>
#include <algorithm>
#include <thread>
#include <memory>
#include <functional>

#include "Entity.hpp"
#include "Chat.hpp"
#include "logging/Logger.hpp"
#include "world_storage/LevelData.hpp"
#include "TickClock.hpp"

class WorldGroup;
class Dimension;

constexpr int NB_SPAWN_CHUNKS = 19;

class World
{
public:
    World(WorldGroup *worldGroup):
        _worldGroup(worldGroup),
        _keepAliveClock(100, std::bind(&World::processKeepAlive, this)), // 5 seconds for keep-alives
        _timeUpdateClock(20, std::bind(&World::updateTime, this)) // 1 second for time updates
    {
        _log = logging::Logger::get_instance();
        _seed = -721274728;
        _keepAliveClock.start();
        _timeUpdateClock.start();
    }
    int64_t getSeed() const {
        return _seed;
    }
    virtual void tick();
    virtual void initialize() = 0;
    virtual WorldGroup *getWorldGroup() const;
    virtual std::shared_ptr<Chat> getChat() const;
    virtual std::vector<Entity *> getEntities() const;
    [[nodiscard]] virtual std::vector<Player *> getPlayers() const;
    virtual std::shared_ptr<Dimension> getDimension(const std::string_view &name) const;
    virtual void forEachEntity(std::function<void(Entity *)> callback);
    virtual void forEachEntityIf(std::function<void(Entity *)> callback, std::function<bool(const Entity *)> predicate);

    virtual const world_storage::LevelData &getLevelData() const;
    virtual void setLevelData(const world_storage::LevelData &value);
    virtual void updateTime();

    virtual void processKeepAlive();

protected:
    std::shared_ptr<Chat> _chat;
    WorldGroup *_worldGroup;
    logging::Logger *_log;
    std::vector<std::thread *> _processingThreads;
    std::unordered_map<std::string_view, std::shared_ptr<Dimension>> _dimensions;
    long _age;
    long _time;
    world_storage::LevelData _levelData;
    TickClock _keepAliveClock;
    TickClock _timeUpdateClock;
    int64_t _seed;
};


#endif //CUBICSERVER_WORLD_HPP
