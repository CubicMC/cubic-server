#ifndef CUBICSERVER_WORLDGROUP_HPP
#define CUBICSERVER_WORLDGROUP_HPP


#include <memory>
#include <unordered_map>

#include "Chat.hpp"
#include "World.hpp"
#include "logging/Logger.hpp"
#include "SoundSystem.hpp"

class SoundSystem;
class WorldGroup
{
public:
    WorldGroup(std::shared_ptr<Chat> chat);
    ~WorldGroup();

    virtual void initialize() = 0;
    virtual void run();
    virtual void stop();
    virtual std::shared_ptr<Chat> getChat() const;
    virtual std::shared_ptr<World> getWorld(const std::string_view &name) const;
    virtual std::unordered_map<std::string_view, std::shared_ptr<World>> getWorlds() const;

protected:
    std::shared_ptr<Chat> _chat;
    std::unordered_map<std::string_view, std::shared_ptr<World>> _worlds;
    logging::Logger *_log;
    SoundSystem *_soundSystem;
    bool _running;
};


#endif //CUBICSERVER_WORLDGROUP_HPP
