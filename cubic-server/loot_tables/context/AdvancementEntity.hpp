#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_ADVANCEMENTENTITY_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_ADVANCEMENTENTITY_HPP

#include <memory>

#include "types.hpp"

#include "LootContext.hpp"

namespace LootTable {
    namespace Context {
        class AdvancementEntity {
        public:
            AdvancementEntity(const Entity &gifter, const FloatingPosition &origin);
            ~AdvancementEntity() = default;

            const std::string &getType() const;

            const Entity &_gifter;
            const FloatingPosition &_origin;
        };
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_CONTEXT_ADVANCEMENTENTITY_HPP