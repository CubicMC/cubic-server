#include "CopyBlockStates.hpp"

namespace LootTable {
namespace Function {
CopyBlockStates::CopyBlockStates(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void CopyBlockStates::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> CopyBlockStates::create(const nlohmann::json &function) { return (std::make_unique<CopyBlockStates>(function)); }
};
};
