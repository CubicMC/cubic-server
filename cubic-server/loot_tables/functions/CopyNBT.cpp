#include "CopyNBT.hpp"

namespace LootTable {
namespace Function {
CopyNBT::CopyNBT(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void CopyNBT::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> CopyNBT::create(const nlohmann::json &function) { return (std::make_unique<CopyNBT>(function)); }
};
};
