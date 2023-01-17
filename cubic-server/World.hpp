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
    World(WorldGroup *worldGroup);
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
    virtual void addPlayerInfo(Player *);

protected:
    std::shared_ptr<Chat> _chat;
    WorldGroup *_worldGroup;
    logging::Logger *_log;
    std::vector<std::thread *> _processingThreads;
    std::unordered_map<std::string_view, std::shared_ptr<Dimension>> _dimensions;
    long _age;
    long _time;
    world_storage::LevelData _levelData;
    TickClock _timeUpdateClock;
};


#endif //CUBICSERVER_WORLD_HPP
