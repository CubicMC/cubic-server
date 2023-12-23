#include "LimitCount.hpp"

namespace LootTable {
namespace Function {
LimitCount::LimitCount(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void LimitCount::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> LimitCount::create(const nlohmann::json &function) { return (std::make_unique<LimitCount>(function)); }
};
};
