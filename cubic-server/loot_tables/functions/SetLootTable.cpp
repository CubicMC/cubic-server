#include "SetLootTable.hpp"

namespace LootTable {
namespace Function {
SetLootTable::SetLootTable(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void SetLootTable::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> SetLootTable::create(const nlohmann::json &function) { return (std::make_unique<SetLootTable>(function)); }
};
};
