#include "SetCount.hpp"

namespace LootTable {
namespace Function {
SetCount::SetCount(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void SetCount::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> SetCount::create(const nlohmann::json &function) { return (std::make_unique<SetCount>(function)); }
};
};
