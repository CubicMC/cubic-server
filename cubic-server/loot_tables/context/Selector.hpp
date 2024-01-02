#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_SELECTOR_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_SELECTOR_HPP

#include <memory>

#include "LootContext.hpp"

class Entity;
struct FloatingPosition;

namespace LootTable {
namespace Context {
class Selector : public LootContext {
public:
    Selector(const FloatingPosition &origin, const Entity &entity);
    ~Selector() = default;

    const FloatingPosition &origin;
    const Entity &entity;
};
}
}

#endif // CUBIC_SERVER_LOOT_TABLES_CONTEXT_SELECTOR_HPP
