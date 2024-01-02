#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_BARTER_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_BARTER_HPP

#include <memory>

#include "LootContext.hpp"

class Entity;

namespace LootTable {
namespace Context {
class Barter : public LootContext {
public:
    Barter(const Entity &barterer);
    ~Barter() = default;

    const Entity &barterer;
};
}
}

#endif // CUBIC_SERVER_LOOT_TABLES_CONTEXT_BARTER_HPP
