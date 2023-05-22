#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_ADVANCEMENTREWARD_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_ADVANCEMENTREWARD_HPP

#include <memory>

#include "types.hpp"

#include "LootContext.hpp"

class Player;

namespace LootTable {
namespace Context {
class AdvancementReward {
public:
    AdvancementReward(const Player &player, const FloatingPosition &origin);
    ~AdvancementReward() = default;

    const std::string &getType() const;

    const Player &_player;
    const FloatingPosition &_origin;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_CONTEXT_ADVANCEMENTREWARD_HPP