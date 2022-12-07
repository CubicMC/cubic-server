#ifndef CUBICSERVER_WORLD_HPP
#define CUBICSERVER_WORLD_HPP

#include <vector>
#include <algorithm>
#include <thread>
#include <memory>

#include "Entity.hpp"
#include "Chat.hpp"
#include "logging/Logger.hpp"

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

protected:
    std::vector<Entity *> _entities;
    std::shared_ptr<Chat> _chat;
    WorldGroup *_worldGroup;
    logging::Logger *_log;
    std::vector<std::thread *> _processingThreads;
    std::unordered_map<std::string_view, std::shared_ptr<Dimension>> _dimensions;
};


#endif //CUBICSERVER_WORLD_HPP
