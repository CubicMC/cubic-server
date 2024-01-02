#include "RandomChanceWithLooting.hpp"

namespace LootTable {
namespace Condition {
RandomChanceWithLooting::RandomChanceWithLooting(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool RandomChanceWithLooting::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> RandomChanceWithLooting::create(const nlohmann::json &condition) { return (std::make_unique<RandomChanceWithLooting>(condition)); }
};
};
