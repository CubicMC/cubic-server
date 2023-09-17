#include "Block.hpp"

namespace LootTable {
namespace Context {
Block::Block(const int32_t &blockState, const FloatingPosition &origin, const ItemId &tool, const Entity *breaker, const int32_t *blockEntityData, const int32_t *explosionRadius):
    LootContext("minecraft:block"),
    blockState(blockState),
    origin(origin),
    tool(tool),
    breaker(breaker),
    blockEntityData(blockEntityData),
    explosionRadius(explosionRadius)
{
}
}
}
