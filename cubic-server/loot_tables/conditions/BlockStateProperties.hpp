#ifndef CUBIC_SERVER_LOOT_TABLES_CONDITIONS_BLOCKSTATEPROPERTIES_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONDITIONS_BLOCKSTATEPROPERTIES_HPP

#include <list>

#include "Condition.hpp"

namespace LootTable {
    namespace Condition {
        class BlockStateProperties : public Condition {
        public:
            BlockStateProperties(const nlohmann::json &condition);
            ~BlockStateProperties() = default;

            bool verify(void) override;

            static std::unique_ptr<Condition> create(const nlohmann::json &condition);
        private:
            std::list<std::unique_ptr<Condition>> _conditions;
        };
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_CONDITIONS_BLOCKSTATEPROPERTIES_HPP