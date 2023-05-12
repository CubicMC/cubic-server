#include "Barter.hpp"

namespace LootTable {
    namespace Context {
        Barter::Barter(const Entity &barterer):
            _barterer(barterer)
        {}

        const std::string &Barter::getType() const
        {
            return ("minecraft:barter");
        }
    };
};
