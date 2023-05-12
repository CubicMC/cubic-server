#include "Gift.hpp"

namespace LootTable {
    namespace Context {
        Gift::Gift(const FloatingPosition &origin, const Entity &gifter):
            _origin(origin),
            _gifter(gifter)
        {}

        const std::string &Gift::getType() const
        {
            return ("minecraft:gift");
        }
    };
};
