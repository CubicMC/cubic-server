#include "EntityScores.hpp"

namespace LootTable {
    namespace Condition {
        EntityScores::EntityScores(const nlohmann::json &condition)
        {
            (void)condition;
        }

        bool EntityScores::verify(void) const
        {
            return (true);
        }

        std::unique_ptr<Condition> EntityScores::create(const nlohmann::json &condition)
        {
            return (std::make_unique<EntityScores>(condition));
        }
    };
};