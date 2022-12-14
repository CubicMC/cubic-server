#ifndef CUBICSERVER_WORLD_HPP
#define CUBICSERVER_WORLD_HPP

#include <vector>
#include <algorithm>
#include <thread>
#include <memory>

#include "Entity.hpp"
#include "Chat.hpp"
#include "logging/Logger.hpp"
#include "world_storage/LevelData.hpp"

class WorldGroup;
class Dimension;

class World
{
public:
    World(WorldGroup *worldGroup): _worldGroup(worldGroup) {
        _log = logging::Logger::get_instance();
    }
    virtual void tick();
    virtual void initialize() = 0;
    virtual WorldGroup *getWorldGroup() const;
    virtual std::shared_ptr<Chat> getChat() const;
    virtual std::vector<Entity *> getEntities();
    virtual std::shared_ptr<Dimension> getDimension(const std::string_view &name) const;
    virtual void forEachEntity(std::function<void(Entity *)> callback);
    virtual void forEachEntityIf(std::function<void(Entity *)> callback, std::function<bool(const Entity *)> predicate);

    virtual const world_storage::LevelData &getLevelData() const;
    virtual void setLevelData(const world_storage::LevelData &value);

protected:
    std::shared_ptr<Chat> _chat;
    WorldGroup *_worldGroup;
    logging::Logger *_log;
    std::vector<std::thread *> _processingThreads;
    std::unordered_map<std::string_view, std::shared_ptr<Dimension>> _dimensions;
    world_storage::LevelData _levelData;
};


#endif //CUBICSERVER_WORLD_HPP
