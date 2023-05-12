#include "Fishing.hpp"

namespace LootTable {
    namespace Context {
        Fishing::Fishing(const FloatingPosition &origin, const ItemId &tool, const Entity *entity):
            _origin(origin),
            _tool(tool),
            _entity(entity)
        {}

        const std::string &Fishing::getType() const
        {
            return ("minecraft:fishing");
        }
    };
};
