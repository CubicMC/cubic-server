#include "Constant.hpp"

namespace LootTable {
namespace Roll {
Constant::Constant(const nlohmann::json &roll)
{
    // get the constant number of rolls to be done
    if (roll.is_number())
        this->_rolls = roll.get<nlohmann::json::number_unsigned_t>();
    else
        this->_rolls = roll["value"].get<nlohmann::json::number_unsigned_t>();

    this->setValidity(true);
}

const RollResult Constant::poll(LootContext *context) const
{
    (void) context;
    return (RollResult(this->_rolls, 1.0));
}

std::unique_ptr<Roll> Constant::creator(const nlohmann::json &roll) { return (std::make_unique<Constant>(roll)); }

bool Constant::isOfType(const nlohmann::json &roll)
{
    return ( // roll is just a number, or
        roll.is_number() ||
        ( // roll is an object containing "type":"minecraft:constant" and "value":a-number
            roll.is_object() && roll.contains("type") && roll.contains("value") && roll["type"].is_string() && roll["value"].is_number() &&
            roll["type"].get<std::string>() == "minecraft:constant"
        )
    );
}
};
};
