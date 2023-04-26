#ifndef CUBICSERVER_WORLDGROUP_HPP
#define CUBICSERVER_WORLDGROUP_HPP

#include <atomic>
#include <functional>
#include <memory>
#include <thread>
#include <unordered_map>

class World;
class Chat;
class SoundSystem;

class WorldGroup {
public:
    WorldGroup(std::shared_ptr<Chat> chat);
    virtual ~WorldGroup();

    virtual void initialize();
    virtual void stop();
    virtual std::shared_ptr<Chat> getChat() const;
    virtual std::shared_ptr<World> getWorld(const std::string_view &name) const;
    virtual std::unordered_map<std::string_view, std::shared_ptr<World>> &getWorlds();
    virtual const std::unordered_map<std::string_view, std::shared_ptr<World>> &getWorlds() const;

    virtual bool isInitialized() const;

protected:
    virtual void _run();

    std::shared_ptr<Chat> _chat;
    std::unordered_map<std::string_view, std::shared_ptr<World>> _worlds;
    SoundSystem *_soundSystem;
    std::atomic<bool> _running;
    std::thread _thread;
};

#endif // CUBICSERVER_WORLDGROUP_HPP
