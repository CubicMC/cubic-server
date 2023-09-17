#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_CHEST_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_CHEST_HPP

#include <memory>

#include "types.hpp"

#include "LootContext.hpp"

class Entity;

namespace LootTable {
namespace Context {
class Chest : public LootContext {
public:
    Chest(const Position &origin, const Entity *entity);
    ~Chest() = default;

    const Position &origin;
    const Entity *entity;
};
}
}

#endif // CUBIC_SERVER_LOOT_TABLES_CONTEXT_CHEST_HPP
