#include "World.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "WorldGroup.hpp"
#include "logging/logging.hpp"
#include "types.hpp"
#include <cmath>
#include <cstdint>
#include <vector>

World::World(std::shared_ptr<WorldGroup> worldGroup, world_storage::WorldType worldType, std::string folder):
    _chat(worldGroup->getChat()),
    _worldGroup(worldGroup),
    _dimensions({}),
    _age(0),
    _time(0),
    _renderDistance(CONFIG["render-distance"].as<uint8_t>()),
    _levelData(),
    _timeUpdateClock(20, std::bind(&World::updateTime, this)), // 1 second for time updates
    _seed(CONFIG["seed"].as<int64_t>()),
    _generationPool(CONFIG["num-gen-thread"].as<uint16_t>(), "WorldGen"),
    _worldType(worldType),
    _folder(folder),
    _publishTpsClock(
        20,
        [this]() {
            const auto tps = this->getTps();
            double globalTps = 0;
            for (const auto &[dimensionName, dimensionTps] : tps) {
                if (dimensionName == "overworld" && dimensionTps.oneMinTps != 0) {
                    PEXPP(setTpsOverworld, dimensionTps.oneMinTps)
                } else if (dimensionName == "nether" && dimensionTps.oneMinTps != 0) {
                    PEXPP(setTpsNether, dimensionTps.oneMinTps)
                } else if (dimensionName == "end" && dimensionTps.oneMinTps != 0) {
                    PEXPP(setTpsEnd, dimensionTps.oneMinTps)
                }
                if (dimensionTps.oneMinTps != 0)
                    globalTps += dimensionTps.oneMinTps;
                else
                    globalTps = -MAXFLOAT;
            }
            if (globalTps >= 0)
                PEXPP(setTpsGlobal, globalTps / tps.size())
        }
    ),
    _publishMsptClock(20, [this]() {
        const auto mspt = this->getMSPTInfos();
        double globalMspt = 0;
        for (const auto &[dimensionName, dimensionMspt] : mspt) {
            if (dimensionName == "overworld" && dimensionMspt.mean != 0) {
                PEXPP(setMsptOverworld, dimensionMspt.mean)
            } else if (dimensionName == "nether" && dimensionMspt.mean != 0) {
                PEXPP(setMsptNether, dimensionMspt.mean)
            } else if (dimensionName == "end" && dimensionMspt.mean != 0) {
                PEXPP(setMsptEnd, dimensionMspt.mean)
            }
            if (dimensionMspt.mean != 0)
                globalMspt += dimensionMspt.mean;
            else
                globalMspt = -MAXFLOAT;
        }
        if (globalMspt >= 0)
            PEXPP(setMsptGlobal, globalMspt / mspt.size())
    })
{
    _timeUpdateClock.start();
    _publishTpsClock.start();
    _publishMsptClock.start();
}

void World::tick()
{
    onEvent(Server::getInstance()->getPluginManager(), tick);

    // TODO: I don't think this should tick if there are no players / chunks loaded
    _timeUpdateClock.tick();
    for (auto &[_, dim] : this->_dimensions)
        dim->getDimensionLock().release();
    _publishTpsClock.tick();
    _publishMsptClock.tick();
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

void World::updateTime()
{
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

std::vector<std::pair<std::string, Tps>> World::getTps() const
{
    std::vector<std::pair<std::string, Tps>> tps;
    for (const auto &[name, dim] : _dimensions)
        tps.emplace_back(name, dim->getTps());
    return tps;
}

std::vector<std::pair<std::string, MSPTInfos>> World::getMSPTInfos() const
{
    std::vector<std::pair<std::string, MSPTInfos>> msptInfos;
    for (const auto &[name, dim] : _dimensions)
        msptInfos.emplace_back(name, dim->getMSPTInfos());
    return msptInfos;
}
