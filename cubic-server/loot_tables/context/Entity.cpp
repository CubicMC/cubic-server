#include "Entity.hpp"

namespace LootTable {
namespace Context {
Entity::Entity(const Entity &victim, const FloatingPosition &origin, const int32_t &damageSource, const Entity *killer, const Entity *direct_killer, const Player *killer_player):
    LootContext("minecraft:entity"),
    victim(victim),
    origin(origin),
    damageSource(damageSource),
    killer(killer),
    direct_killer(direct_killer),
    killer_player(killer_player)
{
}
}
}
