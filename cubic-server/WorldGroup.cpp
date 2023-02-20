#include "WorldGroup.hpp"
#include "logging/Logger.hpp"
#include "Server.hpp"
#include "SoundSystem.hpp"
#include "World.hpp"

#include <utility>
#include <thread>

WorldGroup::WorldGroup(std::shared_ptr<Chat> chat)
    : _chat(std::move(chat)), _soundSystem(new SoundSystem(this)), _running(true)
{
    _log = logging::Logger::get_instance();
}

WorldGroup::~WorldGroup()
{
    if (_soundSystem != nullptr)
        delete _soundSystem;
}

void WorldGroup::run()
{
    while (_running) {
        auto start_time = std::chrono::system_clock::now();
        for (auto &world : _worlds) {
            world.second->tick();
        }
        _soundSystem->tick();
        auto end_time = std::chrono::system_clock::now();
        auto compute_time = end_time - start_time;
        if (compute_time > std::chrono::milliseconds(MS_PER_TICK)) {// If this happens there is a serious problem
            auto nb_ticks = compute_time / std::chrono::milliseconds(MS_PER_TICK);
            LWARN("Can't keep up! Did the system time change, or is the server overloaded? Running " + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(compute_time).count()) + "ms behind, skipping " + std::to_string(nb_ticks) + " tick(s)");
            continue;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(MS_PER_TICK) - compute_time);
    }
}

void WorldGroup::stop()
{
    _running = false;
}

std::shared_ptr<Chat> WorldGroup::getChat() const
{
    return _chat;
}

std::shared_ptr<World> WorldGroup::getWorld(const std::string_view &name) const
{
    return this->_worlds.at(name);
}

std::unordered_map<std::string_view, std::shared_ptr<World>> WorldGroup::getWorlds() const
{
    return this->_worlds;
}

void WorldGroup::forEachWorld(std::function<void(World &)> callback)
{
    for (auto &world : this->_worlds)
        callback(*world.second.get());
}

void WorldGroup::forEachWorldIf(std::function<void(World &)> callback, std::function<bool(const World &)> predicate)
{
    for (auto &world : this->_worlds) {
        if (predicate(*world.second.get()))
            callback(*world.second.get());
    }
}

//void WorldGroup::initialize()
//{
//    LWARN("Initialized empty world group");
//}
