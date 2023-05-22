#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_ENTITY_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_ENTITY_HPP

#include <memory>

#include "types.hpp"

#include "LootContext.hpp"

class Player;
class Entity;

namespace LootTable {
namespace Context {
class Entity {
public:
    Entity(const Entity &victim, const FloatingPosition &origin, const int32_t &damageSource, const Entity *killer, const Entity *direct_killer, const Player *killer_player);
    ~Entity() = default;

    const std::string &getType() const;

    const Entity &_victim;
    const FloatingPosition &_origin;
    const int32_t &_damageSource;
    const Entity *_killer;
    const Entity *_direct_killer;
    const Player *_killer_player;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_CONTEXT_ENTITY_HPP