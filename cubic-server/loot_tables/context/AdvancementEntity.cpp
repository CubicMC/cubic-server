#include "AdvancementEntity.hpp"

namespace LootTable {
namespace Context {
AdvancementEntity::AdvancementEntity(const Entity &gifter, const FloatingPosition &origin):
    _gifter(gifter),
    _origin(origin)
{
}

const std::string &AdvancementEntity::getType() const { return ("minecraft:advancement_entity"); }
};
};
