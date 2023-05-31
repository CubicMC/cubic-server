#include "World.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "WorldGroup.hpp"
#include "logging/logging.hpp"
#include <cstdint>

World::World(std::shared_ptr<WorldGroup> worldGroup, world_storage::WorldType worldType, std::string folder):
    _worldGroup(worldGroup),
    _age(0),
    _time(0),
    _renderDistance(CONFIG["render-distance"].as<uint8_t>()),
    _timeUpdateClock(20, std::bind(&World::updateTime, this)), // 1 second for time updates
    _generationPool(CONFIG["num-gen-thread"].as<uint16_t>(), "WorldGen"),
    _worldType(worldType),
    _folder(folder)
{
    _timeUpdateClock.start();
    _seed = CONFIG["seed"].as<int64_t>();
    _chat = worldGroup->getChat();
}

void World::tick()
{
    onEvent(Server::getInstance()->getPluginManager(), tick);

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
    _generationPool.cancelAll();
    _generationPool.waitUntilJobsDone();

    for (auto &[_, dim] : _dimensions)
        dim->stop();

    // TODO: Save the world
}

bool World::isInitialized() const
{
    for (auto &[_, dim] : _dimensions)
        if (!dim->isInitialized())
            return false;
    return true;
}

std::shared_ptr<WorldGroup> World::getWorldGroup() { return _worldGroup; }

const std::shared_ptr<WorldGroup> World::getWorldGroup() const { return _worldGroup; }

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
    // get list of players
    std::vector<protocol::PlayerInfoUpdate::Action> playersInfo;

    uint8_t actions = (uint8_t) protocol::PlayerInfoUpdate::Actions::AddPlayer | (uint8_t) protocol::PlayerInfoUpdate::Actions::InitializeChat |
        (uint8_t) protocol::PlayerInfoUpdate::Actions::UpdateGamemode | (uint8_t) protocol::PlayerInfoUpdate::Actions::UpdateListed |
        (uint8_t) protocol::PlayerInfoUpdate::Actions::UpdateLatency | (uint8_t) protocol::PlayerInfoUpdate::Actions::UpdateDisplayName;

    // iterate through the list of players
    for (auto [_, dim] : _dimensions) {
        for (auto &player : dim->getPlayers()) {
            // send to each player the info of the current added player
            // clang-format off
            if (player->getId() != current->getId()) {
                player->sendPlayerInfoUpdate({
                    .actions = actions,
                    .actionSets = {
                        {
                            .uuid = current->getUuid(),
                            .addPlayer = {
                                .name = current->getUsername(),
                                .properties = current->getProperties(),
                            },
                        .initializeChat = {
                                .hasSigData = false,
                            },
                        .updateGamemode = {
                                .gamemode = (int32_t) current->getGamemode(),
                            },
                        .updateListed = {
                                .listed = true,
                            },
                        .updateLatency = {
                                .latency = 0, // TODO
                            },
                        .updateDisplayName = {
                                .hasDisplayName = false,
                            }
                        }
                    }
                });
            }

            // save the content of the iterated player for after
            playersInfo.push_back({
                .uuid = player->getUuid(),
                .addPlayer = {
                    .name = player->getUsername(),
                    .properties = player->getProperties(),
                },
                .initializeChat = {
                    .hasSigData = false,
                },
                .updateGamemode = {
                    .gamemode = (int32_t) player->getGamemode(),
                },
                .updateListed = {
                    .listed = true,
                },
                .updateLatency = {
                    .latency = 0, // TODO
                },
                .updateDisplayName = {
                    .hasDisplayName = false,
                }
            });
            // clang-format on
        }
    }

    // send the infos of all players to the current added player
    // clang-format off
    current->sendPlayerInfoUpdate({
        .actions = actions,
        .actionSets = playersInfo
    });
    // clang-format on
    LDEBUG("Sent player info to {}", current->getUsername());
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
    LDEBUG("Sent player info to {}", current->getUsername());
}

thread_pool::PriorityThreadPool &World::getGenerationPool() { return _generationPool; }

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
