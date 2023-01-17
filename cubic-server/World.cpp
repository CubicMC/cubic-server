#include "World.hpp"
#include "Dimension.hpp"
#include "protocol/ClientPackets.hpp"
#include "Player.hpp"
#include "Player.hpp"
#include "WorldGroup.hpp"

World::World(WorldGroup *worldGroup):
    _worldGroup(worldGroup),
    _timeUpdateClock(20, std::bind(&World::updateTime, this)) // 1 second for time updates
{
    _log = logging::Logger::get_instance();
    _timeUpdateClock.start();
    _chat = worldGroup->getChat();
}

void World::tick()
{
    _timeUpdateClock.tick();
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
            player->getClient()->sendUpdateTime({ _age,_time });
        }
    }
}

void World::addPlayerInfo(Player *current) {
    // get list of players
    std::vector<Player *> players = this->getPlayers();
    std::vector<protocol::_Player> players_info;

    // iterate through the list of players
    for (auto &player : players) {

        // send to each player the info of the current added player
        if (player != current) {
            player->getClient()->sendPlayerInfo({
                .action = 0,
                .numberOfPlayers = 1,
                .players = {
                    {
                        .uuid = current->getUuid(),
                        .addPlayer = {
                            .name = current->getUsername(),
                            .numberOfProperties = 0,
                            .gamemode = current->getGamemode(),
                            .ping = 0,
                            .hasDisplayName = false
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
                .gamemode = player->getGamemode(),
                .ping = 0,
                .hasDisplayName = false
            }
        });
    }

    // send the infos of all players to the current added player
    current->getClient()->sendPlayerInfo({
        .action = 0,
        .numberOfPlayers = (int32_t) players.size(),
        .players = players_info
    });
    LDEBUG("Sent player info to " + current->getUsername());
}
