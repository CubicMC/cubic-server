#include "ExplosionDecay.hpp"

namespace LootTable {
namespace Function {
ExplosionDecay::ExplosionDecay(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void ExplosionDecay::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> ExplosionDecay::create(const nlohmann::json &function) { return (std::make_unique<ExplosionDecay>(function)); }
};
};
