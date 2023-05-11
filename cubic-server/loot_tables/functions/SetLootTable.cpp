#include "SetLootTable.hpp"

namespace LootTable {
    namespace Function {
        SetLootTable::SetLootTable(const nlohmann::json &function) : Function(function)
        {}

        void SetLootTable::apply(void)
        {}

        std::unique_ptr<Function> SetLootTable::create(const nlohmann::json &function)
        {
            return (std::make_unique<SetLootTable>(function));
        }
    };
};