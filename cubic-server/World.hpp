#ifndef CUBICSERVER_WORLD_HPP
#define CUBICSERVER_WORLD_HPP

#include <vector>
#include <algorithm>
#include <thread>
#include <memory>

#include "Entity.hpp"
#include "Chat.hpp"
#include "Logger.hpp"

class World
{
public:
    World() {
        _log = logging::Logger::get_instance();
    }
    virtual void tick();
    virtual void initialize() = 0;

protected:
    std::vector<Entity> _entities;
    std::shared_ptr<Chat> _chat;
    logging::Logger *_log;
    std::vector<std::thread *> _processingThreads;
};


#endif //CUBICSERVER_WORLD_HPP
