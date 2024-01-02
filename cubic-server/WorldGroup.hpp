#ifndef CUBICSERVER_WORLDGROUP_HPP
#define CUBICSERVER_WORLDGROUP_HPP

#include <atomic>
#include <functional>
#include <memory>
#include <thread>
#include <unordered_map>

#include "scoreboard/Scoreboard.hpp"

class World;
class Chat;
class SoundSystem;

class WorldGroup {
public:
    WorldGroup(std::shared_ptr<Chat> chat);
    virtual ~WorldGroup();

    virtual void initialize();
    virtual void stop();

    virtual std::shared_ptr<const Chat> getChat() const { return _chat; }
    virtual std::shared_ptr<const World> getWorld(const std::string_view &name) const { return _worlds.at(name); }
    virtual const std::unordered_map<std::string_view, std::shared_ptr<World>> &getWorlds() const { return _worlds; }
    virtual const Scoreboard::Scoreboard &getScoreboard() const { return _scoreboard; }

    virtual std::shared_ptr<Chat> getChat() { return _chat; }
    virtual std::shared_ptr<World> getWorld(const std::string_view &name) { return _worlds.at(name); }
    virtual std::unordered_map<std::string_view, std::shared_ptr<World>> &getWorlds() { return _worlds; }
    virtual Scoreboard::Scoreboard &getScoreboard() { return _scoreboard; }

    virtual bool isInitialized() const;

protected:
    virtual void _run();

    std::shared_ptr<Chat> _chat;
    std::unordered_map<std::string_view, std::shared_ptr<World>> _worlds;
    SoundSystem *_soundSystem;
    std::atomic<bool> _running;
    std::thread _thread;
    Scoreboard::Scoreboard _scoreboard;
};

#endif // CUBICSERVER_WORLDGROUP_HPP
