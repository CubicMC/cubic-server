#include "DamageSourceProperties.hpp"

namespace LootTable {
namespace Condition {
DamageSourceProperties::DamageSourceProperties(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool DamageSourceProperties::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> DamageSourceProperties::create(const nlohmann::json &condition) { return (std::make_unique<DamageSourceProperties>(condition)); }
};
};
