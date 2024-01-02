#include "TimeCheck.hpp"

namespace LootTable {
namespace Condition {
TimeCheck::TimeCheck(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool TimeCheck::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> TimeCheck::create(const nlohmann::json &condition) { return (std::make_unique<TimeCheck>(condition)); }
};
};
