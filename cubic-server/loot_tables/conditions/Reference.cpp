#include "Reference.hpp"

namespace LootTable {
namespace Condition {
Reference::Reference(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool Reference::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> Reference::create(const nlohmann::json &condition) { return (std::make_unique<Reference>(condition)); }
};
};
