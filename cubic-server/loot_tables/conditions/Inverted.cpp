#include "Inverted.hpp"

namespace LootTable {
    namespace Condition {
        Inverted::Inverted(const nlohmann::json &condition)
        {
            (void)condition;
        }

        bool Inverted::verify(void) const
        {
            return (true);
        }

        std::unique_ptr<Condition> Inverted::create(const nlohmann::json &condition)
        {
            return (std::make_unique<Inverted>(condition));
        }
    };
};