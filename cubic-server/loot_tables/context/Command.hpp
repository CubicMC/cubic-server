#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_COMMAND_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_COMMAND_HPP

#include <memory>

#include "types.hpp"

#include "LootContext.hpp"

class Entity;

namespace LootTable {
namespace Context {
class Command : public LootContext {
public:
    Command(const FloatingPosition &origin, const Entity *entity);
    ~Command();

    const FloatingPosition &origin;
    const Entity *entity;
};
}
}

#endif // CUBIC_SERVER_LOOT_TABLES_CONTEXT_COMMAND_HPP
