#include "EntityProperties.hpp"

namespace LootTable {
    namespace Condition {
        EntityProperties::EntityProperties(const nlohmann::json &condition)
        {
            (void)condition;
        }

        bool EntityProperties::verify(void) const
        {
            return (true);
        }

        std::unique_ptr<Condition> EntityProperties::create(const nlohmann::json &condition)
        {
            return (std::make_unique<EntityProperties>(condition));
        }
    };
};