#include "Entity.hpp"

namespace LootTable {
namespace Context {
Entity::Entity(const Entity &victim, const FloatingPosition &origin, const int32_t &damageSource, const Entity *killer, const Entity *direct_killer, const Player *killer_player):
    _victim(victim),
    _origin(origin),
    _damageSource(damageSource),
    _killer(killer),
    _direct_killer(direct_killer),
    _killer_player(killer_player)
{
}

const std::string &Entity::getType() const { return ("minecraft:entity"); }
};
};
