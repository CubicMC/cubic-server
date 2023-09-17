#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_ADVANCEMENTENTITY_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_ADVANCEMENTENTITY_HPP

#include <memory>

#include "types.hpp"

#include "LootContext.hpp"

class Entity;

namespace LootTable {
namespace Context {
class AdvancementEntity : public LootContext {
public:
    AdvancementEntity(const Entity &gifter, const FloatingPosition &origin);
    ~AdvancementEntity() = default;

    const std::string &getType() const;

    const Entity &gifter;
    const FloatingPosition &origin;
};
}
}

#endif // CUBIC_SERVER_LOOT_TABLES_CONTEXT_ADVANCEMENTENTITY_HPP
