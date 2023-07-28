#include "LocationCheck.hpp"

namespace LootTable {
namespace Condition {
LocationCheck::LocationCheck(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool LocationCheck::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> LocationCheck::create(const nlohmann::json &condition) { return (std::make_unique<LocationCheck>(condition)); }
};
};
