#include "Server.hpp"

#include "Uniform.hpp"

namespace LootTable {
namespace Roll {
Uniform::Uniform(const nlohmann::json &roll)
{
    // get min and max value
    this->_min = roll["min"].get<nlohmann::json::number_integer_t>();
    this->_max = roll["max"].get<nlohmann::json::number_integer_t>();

    this->setValidity(true);
}

const RollResult Uniform::poll(LootContext *context) const
{
    // roll a number between min and max, if max < min, returns min; probability always 1.0
    (void) context;
    if (this->_max <= this->_min)
        return (RollResult(this->_min, 1.0));
    else
        return (RollResult(this->_min + (rand() % (this->_max - this->_min + 1)), 1.0));
}

std::unique_ptr<Roll> Uniform::creator(const nlohmann::json &roll) { return (std::make_unique<Uniform>(roll)); }

bool Uniform::isOfType(const nlohmann::json &roll)
{
    return (roll.is_object() && roll.contains("min") && roll.contains("max") && roll["min"].is_number() && roll["max"].is_number());
}
};
};
