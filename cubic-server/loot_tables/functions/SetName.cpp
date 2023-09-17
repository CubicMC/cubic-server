#include "SetName.hpp"

namespace LootTable {
namespace Function {
SetName::SetName(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void SetName::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> SetName::create(const nlohmann::json &function) { return (std::make_unique<SetName>(function)); }
};
};
