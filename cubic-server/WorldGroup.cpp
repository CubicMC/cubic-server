#include "WorldGroup.hpp"

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Server.hpp"
#include "SoundSystem.hpp"
#include "World.hpp"
#include "logging/logging.hpp"
#include "scoreboard/Scoreboard.hpp"

WorldGroup::WorldGroup(std::shared_ptr<Chat> chat):
    _chat(std::move(chat)),
    _soundSystem(new SoundSystem(*this)),
    _running(false),
    _scoreboard(Server::getInstance()->getScoreboardSystem(), *this)
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
        auto startTime = std::chrono::system_clock::now();
        for (auto &[_, world] : _worlds) {
            world->tick();
        }
        _soundSystem->tick();
        auto endTime = std::chrono::system_clock::now();
        auto compute_time = endTime - startTime;
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

bool WorldGroup::isInitialized() const
{
    for (auto &[_, world] : _worlds)
        if (!world->isInitialized())
            return false;
    return true;
}
