#include "Selector.hpp"

namespace LootTable {
namespace Context {
Selector::Selector(const FloatingPosition &origin, const Entity &entity):
    _origin(origin),
    _entity(entity)
{
}

const std::string &Selector::getType() const { return ("minecraft:selector"); }
};
};
