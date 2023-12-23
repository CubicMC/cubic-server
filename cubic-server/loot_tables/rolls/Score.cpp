#include "Server.hpp"

#include "Score.hpp"

namespace LootTable {
namespace Roll {
Score::Score(const nlohmann::json &roll):
    _target(This),
    _isTargetFixed(false),
    _scale(1.0)
{
    // get target, objective and scale
    std::string target;

    if (roll["target"].is_string() || roll["target"]["type"].get<std::string>() == "minecraft:context") {
        if (roll["target"].is_string())
            target = roll["target"].get<std::string>();
        else
            target = roll["target"]["target"].get<std::string>();
        if (target == "this")
            this->_target = This;
        else if (target == "killer")
            this->_target = Killer;
        else if (target == "direct_killer")
            this->_target = DirectKiller;
        else if (target == "killer_player")
            this->_target = KillerPlayer;
    } else if (roll["target"]["type"].get<std::string>() == "minecraft:fixed") {
        this->_isTargetFixed = true;
        this->_fixedTarget = roll["target"]["name"].get<std::string>();
    }
    this->_objective = roll["score"].get<std::string>();
    if (roll.contains("scale") && roll["scale"].is_number_float())
        this->_scale = roll["scale"].get<nlohmann::json::number_float_t>();

    this->setValidity(true);
}

const RollResult Score::poll(LootContext *context) const
{
    // score roll is not yet handled: returns 1 roll and 1.0 probability
    (void) context;
    return (RollResult(1, 1.0));
}

std::unique_ptr<Roll> Score::creator(const nlohmann::json &roll) { return (std::make_unique<Score>(roll)); }

bool Score::isOfType(const nlohmann::json &roll)
{
    return (
        roll.is_object() && roll.contains("type") && roll["type"].is_string() && roll["type"].get<std::string>() == "minecraft:score" && roll.contains("score") &&
        roll.contains("target") && roll["score"].is_string() &&
        (roll["target"].is_string() || (roll["target"].is_object() && roll["target"].contains("target") && roll["target"]["target"].is_string()))
    );
}
};
};
