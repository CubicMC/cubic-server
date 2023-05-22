#include "Chest.hpp"

namespace LootTable {
namespace Context {
Chest::Chest(const Position &origin, const Entity *entity):
    _origin(origin),
    _entity(entity)
{
}

const std::string &Chest::getType() const { return ("minecraft:chest"); }
};
};
