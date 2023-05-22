#include "AdvancementReward.hpp"

namespace LootTable {
namespace Context {
AdvancementReward::AdvancementReward(const Player &player, const FloatingPosition &origin):
    _player(player),
    _origin(origin)
{
}

const std::string &AdvancementReward::getType() const { return ("minecraft:advancement_reward"); }
};
};
