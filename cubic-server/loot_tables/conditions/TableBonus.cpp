#include "TableBonus.hpp"

namespace LootTable {
namespace Condition {
TableBonus::TableBonus(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool TableBonus::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> TableBonus::create(const nlohmann::json &condition) { return (std::make_unique<TableBonus>(condition)); }
};
};
