#include "WorldGroup.hpp"
#include "logging/Logger.hpp"
#include "Server.hpp"
#include "SoundSystem.hpp"

#include <utility>
#include <thread>

WorldGroup::WorldGroup(std::shared_ptr<Chat> chat)
    : _chat(std::move(chat)), _soundSystem(new SoundSystem(this))
{
    _log = logging::Logger::get_instance();
}

void WorldGroup::run()
{
    while (true) {
        auto start_time = std::chrono::system_clock::now();
        for (auto &world : _worlds) {
            world.second->tick();
        }
        _soundSystem->tick();
        auto end_time = std::chrono::system_clock::now();
        auto compute_time = end_time - start_time;
        if (compute_time > std::chrono::milliseconds(MS_PER_TICK)) // If this happens there is a serious problem
            continue;
        std::this_thread::sleep_for(std::chrono::milliseconds(MS_PER_TICK) - compute_time);
    }
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

//void WorldGroup::initialize()
//{
//    LWARN("Initialized empty world group");
//}
