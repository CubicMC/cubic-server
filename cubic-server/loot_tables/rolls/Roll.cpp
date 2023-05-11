#include <iostream>

#include "Roll.hpp"

namespace LootTable {
    namespace Roll {
        RollResult::RollResult(int64_t nbr, double probability) : _nbr(nbr), _probability(probability)
        {}

        NoRollContructor::NoRollContructor(const nlohmann::json &roll) : 
            _message("No constructor fitting the roll: " + roll.dump())
        {}

        const char *NoRollContructor::what() const noexcept
        {
            return (this->_message.c_str());
        }
    };
};