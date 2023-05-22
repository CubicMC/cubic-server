#include "Command.hpp"

namespace LootTable {
namespace Context {
Command::Command(const FloatingPosition &origin, const Entity *entity):
    _origin(origin),
    _entity(entity)
{
}

const std::string &Command::getType() const { return ("minecraft:command"); }
};
};
