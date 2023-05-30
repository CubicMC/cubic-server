#include "Gift.hpp"

namespace LootTable {
namespace Context {
Gift::Gift(const FloatingPosition &origin, const Entity &gifter):
    LootContext("minecraft:gift"),
    origin(origin),
    gifter(gifter)
{
}
}
}
