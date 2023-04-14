#include "World.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "WorldGroup.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/typeSerialization.hpp"
#include <cstdint>

World::World(WorldGroup *worldGroup):
    _worldGroup(worldGroup),
    _age(0),
    _time(0),
    _renderDistance(8), // TODO: Should be loaded from config
    _timeUpdateClock(20, std::bind(&World::updateTime, this)), // 1 second for time updates
    _generationPool(4, "WorldGen", thread_pool::Pool::Behavior::Cancel)
{
    _timeUpdateClock.start();
    _seed = -721274728; // TODO: Should be loaded from config or generated
    _chat = worldGroup->getChat();
}

void World::tick()
{
    // TODO: I don't think this should tick if there are no players / chunks loaded
    _timeUpdateClock.tick();
    for (auto &[_, dim] : this->_dimensions)
        dim->getDimensionLock().release();
}

void World::initialize()
{
    for (auto &[_, dim] : this->_dimensions)
        dim->initialize();
}

void World::stop()
{
    this->_generationPool.stop();
    this->_generationPool.wait();

    for (auto &[_, dim] : _dimensions)
        dim->stop();

    // TODO: Save the worlds
}

bool World::isInitialized() const
{
    for (auto &[_, dim] : _dimensions)
        if (!dim->isInitialized())
            return false;
    return true;
}

WorldGroup *World::getWorldGroup() { return _worldGroup; }

const WorldGroup *World::getWorldGroup() const { return _worldGroup; }

std::shared_ptr<Chat> World::getChat() { return _chat; }

const std::shared_ptr<Chat> World::getChat() const { return _chat; }

std::shared_ptr<Dimension> World::getDimension(const std::string_view &name) { return this->_dimensions.at(name); }

const std::shared_ptr<Dimension> World::getDimension(const std::string_view &name) const { return this->_dimensions.at(name); }

std::unordered_map<std::string_view, std::shared_ptr<Dimension>> &World::getDimensions() { return _dimensions; }

const std::unordered_map<std::string_view, std::shared_ptr<Dimension>> &World::getDimensions() const { return _dimensions; }

const world_storage::LevelData &World::getLevelData() const { return _levelData; }

void World::setLevelData(const world_storage::LevelData &value) { _levelData = value; }

void World::updateTime()
{
    std::shared_ptr<std::vector<uint8_t>> data;

    _age += 20;
    _time += 20;
    if (_time > 24000)
        _time -= 24000;

    for (auto [_, dim] : this->_dimensions) {
        for (auto player : dim->getPlayers()) {
            player->sendUpdateTime({_age, _time});
        }
    }
}

void World::sendPlayerInfoAddPlayer(Player *current)
{
    std::vector<protocol::_Actions> players_info;

    uint8_t actions = (uint8_t) protocol::PlayerInfoUpdateActions::AddPlayer | (uint8_t) protocol::PlayerInfoUpdateActions::InitializeChat |
        (uint8_t) protocol::PlayerInfoUpdateActions::UpdateGamemode | (uint8_t) protocol::PlayerInfoUpdateActions::UpdateListed |
        (uint8_t) protocol::PlayerInfoUpdateActions::UpdateLatency | (uint8_t) protocol::PlayerInfoUpdateActions::UpdateDisplayName;

    for (auto [_, dim] : this->getDimensions()) {
        for (auto &player : dim->getPlayers()) {
            // send to each player the info of the current added player
            if (player->getId() != current->getId()) {

                player->sendPlayerInfoUpdate(
                    {.actions = actions,
                     .numberOfActions = 1,
                     .actionSets =
                         {{.uuid = current->getUuid(),
                           .addPlayer =
                               {
                                   .name = current->getUsername(),
                                   .numberOfProperties = 0,
                               },
                           .initializeChat =
                               {
                                   .has_sig_data = false,
                               },
                           .updateGamemode =
                               {
                                   .gamemode = current->getGamemode(),
                               },
                           .updateListed =
                               {
                                   .listed = true,
                               },
                           .updateLatency =
                               {
                                   .latency = 0, // TODO
                               },
                           .updateDisplayName =
                               {
                                   .hasDisplayName = false,
                               }}}}
                );
            }

            // save the content of the iterated player for after
            players_info.push_back(
                {.uuid = player->getUuid(),
                 .addPlayer =
                     {
                         .name = player->getUsername(),
                         .numberOfProperties = 0,
                     },
                 .initializeChat =
                     {
                         .has_sig_data = false,
                     },
                 .updateGamemode =
                     {
                         .gamemode = player->getGamemode(),
                     },
                 .updateListed =
                     {
                         .listed = true,
                     },
                 .updateLatency =
                     {
                         .latency = 0, // TODO
                     },
                 .updateDisplayName =
                     {
                         .hasDisplayName = false,
                     }}
            );
        }
    }

    // send the infos of all players to the current added player
    current->sendPlayerInfoUpdate({.actions = actions, .numberOfActions = (int32_t) players_info.size(), .actionSets = players_info});
    LDEBUG("Sent player info to " + current->getUsername());
}

void World::sendPlayerInfoRemovePlayer(const Player *current)
{
    for (auto [_, dim] : _dimensions) {
        for (auto &player : dim->getPlayers()) {
            // send to each player the info of the current removed player
            if (player->getId() != current->getId()) {
                player->sendPlayerInfoRemove({std::vector<u128>({current->getUuid()})});
            }
        }
    }
    LDEBUG("Sent player info to ", current->getUsername());
}

thread_pool::Pool &World::getGenerationPool() { return _generationPool; }

Seed World::getSeed() const { return _seed; }

uint8_t World::getRenderDistance() const { return _renderDistance; }

long World::getTime() const { return _time; }

long World::getAge() const { return _age; }

int World::addTime(int time)
{
    if (time >= 0) {
        _time += time;
        while (_time > 24000)
            _time -= 24000;
        _age += time;
        return _time;
    } else {
        LERROR("Tick count must be non-negative");
        return -1;
    }
}

void World::setTime(int time)
{
    if (time >= 0)
        _time = time;
}
