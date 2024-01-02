#include "Inverted.hpp"

namespace LootTable {
namespace Condition {
Inverted::Inverted(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool Inverted::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> Inverted::create(const nlohmann::json &condition) { return (std::make_unique<Inverted>(condition)); }
};
};
