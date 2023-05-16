#include "WorldGroup.hpp"

#include "Chat.hpp"
#include "Server.hpp"
#include "SoundSystem.hpp"
#include "World.hpp"
#include "Dimension.hpp"
#include "logging/Logger.hpp"
#include "scoreboard/Scoreboard.hpp"

WorldGroup::WorldGroup(std::shared_ptr<Chat> chat):
    _chat(std::move(chat)),
    _soundSystem(new SoundSystem(*this)),
    _running(false),
    _scoreboard(Server::getInstance()->scoreboardSystem, *this)
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

std::shared_ptr<Chat> WorldGroup::getChat() const { return _chat; }

std::shared_ptr<World> WorldGroup::getWorld(const std::string_view &name) const { return this->_worlds.at(name); }

std::unordered_map<std::string_view, std::shared_ptr<World>> &WorldGroup::getWorlds() { return this->_worlds; }

const std::unordered_map<std::string_view, std::shared_ptr<World>> &WorldGroup::getWorlds() const { return this->_worlds; }

Scoreboard::Scoreboard &WorldGroup::getScoreboard(void) { return (this->_scoreboard); }


// void WorldGroup::initialize()
//{
//     LWARN("Initialized empty world group");
// }

bool WorldGroup::isInitialized() const
{
    for (auto &[_, world] : _worlds)
        if (!world->isInitialized())
            return false;
    return true;
}
