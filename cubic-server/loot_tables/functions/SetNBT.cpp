#include "SetNBT.hpp"

namespace LootTable {
namespace Function {
SetNBT::SetNBT(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void SetNBT::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> SetNBT::create(const nlohmann::json &function) { return (std::make_unique<SetNBT>(function)); }
};
};
