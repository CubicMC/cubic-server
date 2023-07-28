#include "EntityScores.hpp"

namespace LootTable {
namespace Condition {
EntityScores::EntityScores(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool EntityScores::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> EntityScores::create(const nlohmann::json &condition) { return (std::make_unique<EntityScores>(condition)); }
};
};
