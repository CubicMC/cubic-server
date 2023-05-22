#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_CHEST_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_CHEST_HPP

#include <memory>

#include "types.hpp"

#include "LootContext.hpp"

class Entity;

namespace LootTable {
namespace Context {
class Chest {
public:
    Chest(const Position &origin, const Entity *entity);
    ~Chest() = default;

    const std::string &getType() const;

    const Position &_origin;
    const Entity *_entity;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_CONTEXT_CHEST_HPP