#include "Fishing.hpp"

namespace LootTable {
namespace Context {
Fishing::Fishing(const FloatingPosition &origin, const ItemId &tool, const Entity *entity):
    LootContext("minecraft:fishing"),
    origin(origin),
    tool(tool),
    entity(entity)
{
}
}
}
