#include "Condition.hpp"

namespace LootTable {
namespace Condition {

Condition::Condition(void):
    _validity(false)
{
}

bool Condition::isValid(void) const noexcept { return (this->_validity); }

void Condition::setValidity(bool validity) noexcept { this->_validity = validity; }

bool Condition::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}
};
};
