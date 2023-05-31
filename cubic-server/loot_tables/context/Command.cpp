#include "Command.hpp"

namespace LootTable {
namespace Context {
Command::Command(const FloatingPosition &origin, const Entity *entity):
    LootContext("minecraft:command"),
    origin(origin),
    entity(entity)
{
}
}
}
