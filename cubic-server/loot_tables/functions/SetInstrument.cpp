#include "SetInstrument.hpp"

namespace LootTable {
namespace Function {
SetInstrument::SetInstrument(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void SetInstrument::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> SetInstrument::create(const nlohmann::json &function) { return (std::make_unique<SetInstrument>(function)); }
};
};
