#include "Roll.hpp"

namespace LootTable {
namespace Roll {
RollResult::RollResult(int64_t nbr, double probability):
    nbr(nbr),
    probability(probability)
{
}

Roll::Roll(void):
    _validity(false)
{
}

bool Roll::isValid(void) const noexcept { return (this->_validity); }

void Roll::setValidity(bool validity) noexcept { this->_validity = validity; }
}
}
