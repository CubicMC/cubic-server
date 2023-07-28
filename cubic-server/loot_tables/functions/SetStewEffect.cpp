#include "SetStewEffect.hpp"

namespace LootTable {
namespace Function {
SetStewEffect::SetStewEffect(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void SetStewEffect::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> SetStewEffect::create(const nlohmann::json &function) { return (std::make_unique<SetStewEffect>(function)); }
};
};
