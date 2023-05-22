#include "Block.hpp"

namespace LootTable {
namespace Context {
Block::Block(const int32_t &blockState, const FloatingPosition &origin, const ItemId &tool, const Entity *breaker, const int32_t *blockEntityData, const int32_t *explosionRadius):
    _blockState(blockState),
    _origin(origin),
    _tool(tool),
    _breaker(breaker),
    _blockEntityData(blockEntityData),
    _explosionRadius(explosionRadius)
{
}

const std::string &Block::getType() const { return ("minecraft:block"); }
};
};
