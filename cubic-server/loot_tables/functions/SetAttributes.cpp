#include "SetAttributes.hpp"

namespace LootTable {
namespace Function {
SetAttributes::SetAttributes(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void SetAttributes::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> SetAttributes::create(const nlohmann::json &function) { return (std::make_unique<SetAttributes>(function)); }
};
};
