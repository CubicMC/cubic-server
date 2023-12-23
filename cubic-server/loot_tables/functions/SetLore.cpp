#include "SetLore.hpp"

namespace LootTable {
namespace Function {
SetLore::SetLore(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void SetLore::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> SetLore::create(const nlohmann::json &function) { return (std::make_unique<SetLore>(function)); }
};
};
