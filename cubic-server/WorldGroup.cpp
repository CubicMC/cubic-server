#include "WorldGroup.hpp"
#include "logging/Logger.hpp"
#include "Server.hpp"
#include "SoundSystem.hpp"
#include "World.hpp"

#include <utility>
#include <thread>

WorldGroup::WorldGroup(std::shared_ptr<Chat> chat):
    _chat(std::move(chat)),
    _soundSystem(new SoundSystem(this)),
    _running(false)
{
}

WorldGroup::~WorldGroup()
{
    if (_soundSystem != nullptr)
        delete _soundSystem;
}

void WorldGroup::initialize()
{
    this->_running = true;
    this->_thread = std::thread(&WorldGroup::_run, this);
}

void WorldGroup::_run()
{
    while (_running) {
        auto start_time = std::chrono::system_clock::now();
        for (auto &[_, world] : _worlds) {
            world->tick();
        }
        _soundSystem->tick();
        auto end_time = std::chrono::system_clock::now();
        auto compute_time = end_time - start_time;
        if (compute_time > std::chrono::milliseconds(MS_PER_TICK)) {// If this happens there is a serious problem
            auto nb_ticks = compute_time / std::chrono::milliseconds(MS_PER_TICK);
            LWARN("Can't keep up! Did the system time change, or is the server overloaded? Running ", std::chrono::duration_cast<std::chrono::milliseconds>(compute_time).count(), "ms behind, skipping ", nb_ticks, " tick(s)");
            continue;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(MS_PER_TICK) - compute_time);
    }
}

void WorldGroup::stop()
{
    _running = false;

    if (_thread.joinable())
        _thread.join();

    // Stop all worlds
    for (auto &[_, world] : _worlds)
        world->stop();
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

bool WorldGroup::isInitialized() const
{
    for (auto &[_, world] : _worlds)
        if (!world->isInitialized())
            return false;
    return true;
}
