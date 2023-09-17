#include "Server.hpp"

#include "Binomial.hpp"

namespace LootTable {
namespace Roll {
Binomial::Binomial(const nlohmann::json &roll)
{
    // net n number of rolls and p the probability
    this->_n = roll["n"].get<nlohmann::json::number_integer_t>();
    this->_p = roll["p"].get<nlohmann::json::number_float_t>();

    this->setValidity(true);
}

const RollResult Binomial::poll(LootContext *context) const
{
    (void) context;
    return (RollResult(this->_n, this->_p));
}

std::unique_ptr<Roll> Binomial::creator(const nlohmann::json &roll) { return (std::make_unique<Binomial>(roll)); }

bool Binomial::isOfType(const nlohmann::json &roll) { return (roll.is_object() && roll.contains("n") && roll.contains("p") && roll["p"].is_number() && roll["n"].is_number()); }
};
};
