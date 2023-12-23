#include "ValueCheck.hpp"

namespace LootTable {
namespace Condition {
ValueCheck::ValueCheck(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool ValueCheck::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> ValueCheck::create(const nlohmann::json &condition) { return (std::make_unique<ValueCheck>(condition)); }
};
};
