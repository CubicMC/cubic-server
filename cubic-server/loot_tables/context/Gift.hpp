#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_GIFT_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_GIFT_HPP

#include <memory>

#include "types.hpp"

#include "LootContext.hpp"

class Entity;

namespace LootTable {
namespace Context {
class Gift {
public:
    Gift(const FloatingPosition &origin, const Entity &gifter);
    ~Gift() = default;

    const std::string &getType() const;

    const FloatingPosition &_origin;
    const Entity &_gifter;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_CONTEXT_GIFT_HPP