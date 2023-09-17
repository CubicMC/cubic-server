#include "RandomChance.hpp"

namespace LootTable {
namespace Condition {
RandomChance::RandomChance(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool RandomChance::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> RandomChance::create(const nlohmann::json &condition) { return (std::make_unique<RandomChance>(condition)); }
};
};
