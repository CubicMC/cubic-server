#include "ValueCheck.hpp"

namespace LootTable {
    namespace Condition {
        ValueCheck::ValueCheck(const nlohmann::json &condition)
        {
            (void)condition;
        }

        bool ValueCheck::verify(void) const
        {
            return (true);
        }

        std::unique_ptr<Condition> ValueCheck::create(const nlohmann::json &condition)
        {
            return (std::make_unique<ValueCheck>(condition));
        }
    };
};