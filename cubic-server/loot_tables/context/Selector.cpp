#include "Selector.hpp"

namespace LootTable {
namespace Context {
Selector::Selector(const FloatingPosition &origin, const Entity &entity):
    LootContext("minecraft:selector"),
    origin(origin),
    entity(entity)
{
}
}
}
