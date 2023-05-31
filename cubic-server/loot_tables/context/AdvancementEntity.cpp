#include "AdvancementEntity.hpp"

namespace LootTable {
namespace Context {
AdvancementEntity::AdvancementEntity(const Entity &gifter, const FloatingPosition &origin):
    LootContext("minecraft:advancement_entity"),
    gifter(gifter),
    origin(origin)
{
}
}
}
