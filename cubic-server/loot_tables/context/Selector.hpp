#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_SELECTOR_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_SELECTOR_HPP

#include <memory>

#include "LootContext.hpp"

class Entity;

namespace LootTable {
namespace Context {
class Selector {
public:
    Selector(const FloatingPosition &origin, const Entity &entity);
    ~Selector() = default;

    const std::string &getType() const;

    const FloatingPosition &_origin;
    const Entity &_entity;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_CONTEXT_SELECTOR_HPP