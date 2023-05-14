#include "TableBonus.hpp"

namespace LootTable {
    namespace Condition {
        TableBonus::TableBonus(const nlohmann::json &condition)
        {
            (void)condition;
        }

        bool TableBonus::verify(void) const
        {
            return (true);
        }

        std::unique_ptr<Condition> TableBonus::create(const nlohmann::json &condition)
        {
            return (std::make_unique<TableBonus>(condition));
        }
    };
};