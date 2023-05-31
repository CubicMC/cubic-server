#include "Chest.hpp"

namespace LootTable {
namespace Context {
Chest::Chest(const Position &origin, const Entity *entity):
    LootContext("minecraft:chest"),
    origin(origin),
    entity(entity)
{
}
}
}
