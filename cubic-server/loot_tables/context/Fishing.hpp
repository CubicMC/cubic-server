#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_FISHING_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_FISHING_HPP

#include <memory>

#include "types.hpp"

#include "LootContext.hpp"

class Entity;

namespace LootTable {
namespace Context {
class Fishing : public LootContext {
public:
    Fishing(const FloatingPosition &origin, const ItemId &tool, const Entity *entity);
    ~Fishing() = default;

    const FloatingPosition &origin;
    const ItemId &tool;
    const Entity *entity;
};
}
}

#endif // CUBIC_SERVER_LOOT_TABLES_CONTEXT_FISHING_HPP
