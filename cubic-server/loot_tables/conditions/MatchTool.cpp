#include "MatchTool.hpp"

namespace LootTable {
namespace Condition {
MatchTool::MatchTool(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool MatchTool::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> MatchTool::create(const nlohmann::json &condition) { return (std::make_unique<MatchTool>(condition)); }
};
};
