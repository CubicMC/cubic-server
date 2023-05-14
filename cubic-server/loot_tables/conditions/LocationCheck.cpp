#include "LocationCheck.hpp"

namespace LootTable {
    namespace Condition {
        LocationCheck::LocationCheck(const nlohmann::json &condition)
        {
            (void)condition;
        }

        bool LocationCheck::verify(void) const
        {
            return (true);
        }

        std::unique_ptr<Condition> LocationCheck::create(const nlohmann::json &condition)
        {
            return (std::make_unique<LocationCheck>(condition));
        }
    };
};