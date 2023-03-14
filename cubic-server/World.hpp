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
#include "thread_pool/Pool.hpp"
#include "types.hpp"

class WorldGroup;
class Dimension;

constexpr int NB_SPAWN_CHUNKS = 19;

class World
{
public:
    World(WorldGroup *worldGroup);

    virtual void tick();
    virtual void initialize();
    virtual void stop();

    virtual bool isInitialized() const;
    virtual WorldGroup *getWorldGroup() const;
    virtual std::shared_ptr<Chat> getChat() const;
    virtual std::vector<Entity *> getEntities() const;
    [[nodiscard]] virtual std::vector<Player *> getPlayers() const;
    virtual std::shared_ptr<Dimension> getDimension(const std::string_view &name) const;
    virtual void forEachEntity(std::function<void(Entity *)> callback);
    virtual void forEachEntityIf(std::function<void(Entity *)> callback, std::function<bool(const Entity *)> predicate);
    virtual void forEachPlayer(std::function<void(Player *)> callback);
    virtual void forEachPlayerIf(std::function<void(Player *)> callback, std::function<bool(const Entity *)> predicate);
    virtual void forEachDimension(std::function<void(Dimension &)> callback);
    virtual void forEachDimensionIf(std::function<void(Dimension &)> callback, std::function<bool(const Dimension &)> predicate);

    virtual const world_storage::LevelData &getLevelData() const;
    virtual void setLevelData(const world_storage::LevelData &value);
    virtual void updateTime();
    virtual void sendPlayerInfoAddPlayer(Player *);
    virtual void sendPlayerInfoRemovePlayer(const Player *current);

    virtual thread_pool::Pool &getGenerationPool();

    virtual Seed getSeed() const;
    virtual uint8_t getRenderDistance() const;

protected:
    std::shared_ptr<Chat> _chat;
    WorldGroup *_worldGroup;
    std::unordered_map<std::string_view, std::shared_ptr<Dimension>> _dimensions;
    long _age;
    long _time;
    uint8_t _renderDistance;
    world_storage::LevelData _levelData;
    TickClock _timeUpdateClock;
    Seed _seed;
    thread_pool::Pool _generationPool;
};


#endif //CUBICSERVER_WORLD_HPP
