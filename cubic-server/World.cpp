#include "World.hpp"
#include "Dimension.hpp"
#include "protocol/ClientPackets.hpp"
#include "Player.hpp"
#include "Player.hpp"
#include "WorldGroup.hpp"
#include "protocol/typeSerialization.hpp"
#include <cstdint>

World::World(WorldGroup *worldGroup):
    _worldGroup(worldGroup),
    _age(0),
    _time(0),
    _renderDistance(8), // TODO: Should be loaded from config
    _timeUpdateClock(20, std::bind(&World::updateTime, this)), // 1 second for time updates
    _generationPool(16, "WorldGen", thread_pool::Pool::Behavior::Cancel)
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

WorldGroup *World::getWorldGroup() const
{
    return _worldGroup;
}

std::shared_ptr<Chat> World::getChat() const
{
    return _chat;
}

std::shared_ptr<Dimension> World::getDimension(const std::string_view &name) const
{
    return this->_dimensions.at(name);
}

std::vector<Entity *> World::getEntities() const
{
    std::vector<Entity *> entities;
    for (auto _dimension : _dimensions)
        for (auto _entity : _dimension.second->getEntities())
            entities.push_back(_entity);
    return entities;
}

std::vector<Player *> World::getPlayers() const
{
    std::vector<Player *> players;

    for (auto &entity : this->getEntities()) {
        auto player = dynamic_cast<Player *>(entity);

        if (player != nullptr) {
            players.push_back(player);
        }
    }
    return players;
}

void World::forEachEntity(std::function<void(Entity *)> callback)
{
    for (auto & _dimension : _dimensions)
        _dimension.second->forEachEntity(callback);
}

void World::forEachEntityIf(std::function<void(Entity *)> callback, std::function<bool(const Entity *)> predicate)
{
    for (auto & _dimension : _dimensions)
        _dimension.second->forEachEntityIf(callback, predicate);
}

const world_storage::LevelData &World::getLevelData() const
{
    return _levelData;
}

void World::setLevelData(const world_storage::LevelData &value)
{
    _levelData = value;
}

void World::updateTime() {
    std::shared_ptr<std::vector<uint8_t>> data;

    _age += 20;
    _time += 20;
    if (_time > 24000)
        _time = 0;

    // send packets to clients (missing clients in architecture)
    for (auto &entity : this->getEntities()) {
        auto player = dynamic_cast<Player *>(entity);

        if (player) {
            player->sendUpdateTime({ _age,_time });
        }
    }
}

void World::sendPlayerInfoAddPlayer(Player *current) {
    // get list of players
    std::vector<Player *> players = this->getPlayers();
    std::vector<protocol::_Actions> players_info;

    uint8_t actions =
        (uint8_t)protocol::PlayerInfoUpdateActions::AddPlayer |
        (uint8_t)protocol::PlayerInfoUpdateActions::InitializeChat |
        (uint8_t)protocol::PlayerInfoUpdateActions::UpdateGamemode |
        (uint8_t)protocol::PlayerInfoUpdateActions::UpdateListed |
        (uint8_t)protocol::PlayerInfoUpdateActions::UpdateLatency |
        (uint8_t)protocol::PlayerInfoUpdateActions::UpdateDisplayName;

    // iterate through the list of players
    for (auto &player : players) {
        // send to each player the info of the current added player
        if (player->getId() != current->getId()) {

            player->sendPlayerInfoUpdate({
                .actions = actions,
                .numberOfActions = 1,
                .actionSets = {
                    {
                        .uuid = current->getUuid(),
                        .addPlayer = {
                            .name = current->getUsername(),
                            .numberOfProperties = 0,
                        },
                        .initializeChat = {
                            .has_sig_data = false,
                        },
                        .updateGamemode = {
                            .gamemode = current->getGamemode(),
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
        players_info.push_back({
            .uuid = player->getUuid(),
            .addPlayer = {
                .name = player->getUsername(),
                .numberOfProperties = 0,
            },
            .initializeChat = {
                .has_sig_data = false,
            },
            .updateGamemode = {
                .gamemode = player->getGamemode(),
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
    }

    // send the infos of all players to the current added player
    current->sendPlayerInfoUpdate({
        .actions = actions,
        .numberOfActions = (int32_t) players_info.size(),
        .actionSets = players_info
    });
    LDEBUG("Sent player info to " + current->getUsername());
}

void World::sendPlayerInfoRemovePlayer(const Player *current) {
    // get list of players
    std::vector<Player *> players = this->getPlayers();

    // iterate through the list of players
    for (auto &player : players) {
        // send to each player the info of the current removed player
        if (player->getId() != current->getId()) {
            player->sendPlayerInfoRemove({
                std::vector<u128>({current->getUuid()})
            });
        }
    }
    LDEBUG("Sent player info to ", current->getUsername());
}

thread_pool::Pool &World::getGenerationPool()
{
    return _generationPool;
}

Seed World::getSeed() const
{
    return _seed;
}

uint8_t World::getRenderDistance() const
{
    return _renderDistance;
}
