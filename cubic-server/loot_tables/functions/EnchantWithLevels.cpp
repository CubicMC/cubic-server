#include "EnchantWithLevels.hpp"

namespace LootTable {
namespace Function {
EnchantWithLevels::EnchantWithLevels(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void EnchantWithLevels::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> EnchantWithLevels::create(const nlohmann::json &function) { return (std::make_unique<EnchantWithLevels>(function)); }
};
};
