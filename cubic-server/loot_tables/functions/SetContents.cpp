#include "SetContents.hpp"

namespace LootTable {
namespace Function {
SetContents::SetContents(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void SetContents::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> SetContents::create(const nlohmann::json &function) { return (std::make_unique<SetContents>(function)); }
};
};
