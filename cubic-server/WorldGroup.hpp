#ifndef CUBICSERVER_WORLDGROUP_HPP
#define CUBICSERVER_WORLDGROUP_HPP


#include <memory>
#include <unordered_map>

#include "Chat.hpp"
#include "World.hpp"
#include "Logger.hpp"

class WorldGroup
{
public:
    WorldGroup(std::shared_ptr<Chat> chat);

    virtual void initialize() = 0;

    virtual void run();

protected:
    std::shared_ptr<Chat> _chat;
    std::unordered_map<std::string, std::shared_ptr<World>> _worlds;
    logging::Logger *_log;
};


#endif //CUBICSERVER_WORLDGROUP_HPP
