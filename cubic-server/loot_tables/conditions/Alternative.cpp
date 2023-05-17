#include "Alternative.hpp"

namespace LootTable {
    namespace Condition {
        Alternative::Alternative(const nlohmann::json &condition)
        {
            (void)condition;

            this->setValidity(true);
        }

        bool Alternative::verify(void) const
        {
            return (true);
        }

        std::unique_ptr<Condition> Alternative::create(const nlohmann::json &condition)
        {
            return (std::make_unique<Alternative>(condition));
        }
    };
};