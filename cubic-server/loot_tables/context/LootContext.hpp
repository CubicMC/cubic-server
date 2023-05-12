#ifndef CUBIC_SERVER_LOOT_TABLES_LOOT_CONTEXT_HPP
#define CUBIC_SERVER_LOOT_TABLES_LOOT_CONTEXT_HPP

#include <string>

#include "AdvancementEntity.hpp"
#include "AdvancementReward.hpp"
#include "Barter.hpp"
#include "Block.hpp"
#include "Chest.hpp"
#include "Command.hpp"
#include "Empty.hpp"
#include "Entity.hpp"
#include "Fishing.hpp"
#include "Generic.hpp"
#include "Gift.hpp"
#include "Selector.hpp"

namespace LootTable {
    class LootContext {
    public:
        virtual const std::string &getType() const = 0;
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_LOOT_CONTEXT_HPP