#include "WorldGroup.hpp"
#include "Logger.hpp"
#include "Server.hpp"

#include <utility>
#include <thread>

WorldGroup::WorldGroup(std::shared_ptr<Chat> chat)
    : _chat(std::move(chat))
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
        auto end_time = std::chrono::system_clock::now();
        auto compute_time = end_time - start_time;
        if (compute_time > std::chrono::milliseconds(MS_PER_TICK)) // If this happens there is a serious problem
            continue;
        std::this_thread::sleep_for(std::chrono::milliseconds(MS_PER_TICK) - compute_time);
    }
}

//void WorldGroup::initialize()
//{
//    LWARN("Initialized empty world group");
//}
