#include "AdvancementReward.hpp"

namespace LootTable {
namespace Context {
AdvancementReward::AdvancementReward(const Player &player, const FloatingPosition &origin):
    LootContext("minecraft:advancement_reward"),
    player(player),
    origin(origin)
{
}
}
}
