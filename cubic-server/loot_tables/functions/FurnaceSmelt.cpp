#include "FurnaceSmelt.hpp"

namespace LootTable {
namespace Function {
FurnaceSmelt::FurnaceSmelt(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void FurnaceSmelt::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> FurnaceSmelt::create(const nlohmann::json &function) { return (std::make_unique<FurnaceSmelt>(function)); }
};
};
