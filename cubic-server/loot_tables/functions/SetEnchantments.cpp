#include "SetEnchantments.hpp"

namespace LootTable {
namespace Function {
SetEnchantments::SetEnchantments(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void SetEnchantments::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> SetEnchantments::create(const nlohmann::json &function) { return (std::make_unique<SetEnchantments>(function)); }
};
};
