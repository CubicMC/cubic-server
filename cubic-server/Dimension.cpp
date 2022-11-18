#include <algorithm>
#include <cmath>

#include "Dimension.hpp"

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

// should be called at every movement for better efficiency
/*
void Dimension::spawnPlayer(std::vector<Player *> players, long render_distance)
{
    long distance;
    std::shared_ptr<std::vector<uint8_t>> data;

    // scan every player to each other if entering render distance (to be optimized with incoming features)
    for (auto player = players.begin(); player <= players.end(); player++) {
        for (auto other = player; other < players.end(); other++) {

            // calculate the distance between the two players
            //distance = std::sqrt(std::pow(other->x - player->x, 2) + std::pow(other->z - player->z, 2));

            // send the packets to the client (no clients for now)
            if (distance <= render_distance) {
                (*player.base())->getClient()->sendSpawnPlayer({
                    0,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0
                });
                (*other.base())->getClient()->sendSpawnPlayer({
                    0,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0
                });
            }
        }
    }
}*/
