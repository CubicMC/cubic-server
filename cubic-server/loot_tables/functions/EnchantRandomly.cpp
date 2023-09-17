#include "EnchantRandomly.hpp"

namespace LootTable {
namespace Function {
EnchantRandomly::EnchantRandomly(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void EnchantRandomly::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> EnchantRandomly::create(const nlohmann::json &function) { return (std::make_unique<EnchantRandomly>(function)); }
};
};
