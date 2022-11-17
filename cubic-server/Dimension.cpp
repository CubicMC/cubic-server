#include <algorithm>
#include <cmath>

#include "Dimension.hpp"
#include "../protocol/ClientPackets.hpp"

void Dimension::tick()
{

}

void Dimension::initialize()
{

}

World *Dimension::getWorld() const
{
    return _world;
}

std::vector<Entity *> &Dimension::getEntities()
{
    return _entities;
}

void Dimension::forEachEntity(std::function<void(Entity *)> callback)
{
    for (auto _entity : _entities)
        callback(_entity);
}

void Dimension::forEachEntityIf(std::function<void(Entity *)> callback, std::function<bool(const Entity *)> predicate)
{
    for (auto _entity : _entities)
        if (predicate(_entity))
            callback(_entity);
}

const world_storage::Level &Dimension::getLevel() const
{
    return _level;
}

world_storage::Level &Dimension::getEditableLevel()
{
    return _level;
}

void Dimension::generateChunk(int x, int z)
{

}

// fake player for testing
struct DummyPlayer {
    double x;
    double y;
    double z;
};

std::vector<DummyPlayer> createDummies()
{
    std::vector<DummyPlayer> dummies;

    DummyPlayer dummy1 = {0, 0, 0};
    DummyPlayer dummy2 = {15, 30, 10};

    dummies.push_back(dummy1);
    dummies.push_back(dummy2);
    return dummies;
}

// should be called at every movement for better efficiency
void Dimension::spawnPlayer()
{
    std::vector<DummyPlayer> dummies = createDummies();
    long distance;
    long render_distance = 12;
    std::shared_ptr<std::vector<uint8_t>> data;

    // scan every player to each other if entering render distance
    for (auto player = dummies.begin(); player < dummies.end(); player++) {
        for (auto other = player; other < dummies.end(); other++) {

            // calculate the distance between the two players
            distance = std::sqrt(std::pow(other->x - player->x, 2) + std::pow(other->z - player->z, 2));

            // send the packets to the client (no clients for now)
            if (distance <= render_distance) {
                data = protocol::createSpawnPlayer({
                    0,
                    0,
                    other->x,
                    other->y,
                    other->z,
                    0,
                    0
                });
            }
        }
    }
}