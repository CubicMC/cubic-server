#include "EntityProperties.hpp"

namespace LootTable {
namespace Condition {
EntityProperties::EntityProperties(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool EntityProperties::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> EntityProperties::create(const nlohmann::json &condition) { return (std::make_unique<EntityProperties>(condition)); }
};
};
