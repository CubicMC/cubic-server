#include "SetDamage.hpp"

namespace LootTable {
namespace Function {
SetDamage::SetDamage(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void SetDamage::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> SetDamage::create(const nlohmann::json &function) { return (std::make_unique<SetDamage>(function)); }
};
};
