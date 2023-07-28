#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_ADVANCEMENTREWARD_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_ADVANCEMENTREWARD_HPP

#include <memory>

#include "types.hpp"

#include "LootContext.hpp"

class Player;

namespace LootTable {
namespace Context {
class AdvancementReward : public LootContext {
public:
    AdvancementReward(const Player &player, const FloatingPosition &origin);
    ~AdvancementReward() = default;

    const Player &player;
    const FloatingPosition &origin;
};
}
}

#endif // CUBIC_SERVER_LOOT_TABLES_CONTEXT_ADVANCEMENTREWARD_HPP
