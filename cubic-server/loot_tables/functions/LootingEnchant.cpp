#include "LootingEnchant.hpp"

namespace LootTable {
namespace Function {
LootingEnchant::LootingEnchant(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void LootingEnchant::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> LootingEnchant::create(const nlohmann::json &function) { return (std::make_unique<LootingEnchant>(function)); }
};
};
