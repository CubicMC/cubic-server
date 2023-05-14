#ifndef CUBIC_SERVER_LOOT_TABLES_LOOT_TABLE_HPP
#define CUBIC_SERVER_LOOT_TABLES_LOOT_TABLE_HPP

#include <unordered_map>
#include <memory>
#include <list>

#include <nlohmann/json.hpp>

#include "types.hpp"

#include "Pool.hpp"
#include "functions/Function.hpp"

namespace LootTable {
    class LootTablePoll {
    public:
        LootTablePoll() = default;
        ~LootTablePoll() = default;

        const std::unordered_map<ItemId, uint8_t> &getRolledItems(void) const;

        void addRolledItem(ItemId item, uint8_t count);
        void addRolledItem(const std::unordered_map<ItemId, uint8_t> &items);
        void addRolledItem(const LootTablePoll &poll);

    private:
        std::unordered_map<ItemId, uint8_t> _items;
    };

    class LootContext;
    
    class LootTable {
    public:
        LootTable(const nlohmann::json &table);
        LootTable(LootTable &&other) = default;
        LootTable(const LootTable &other) = default;
        ~LootTable() = default;

        LootTablePoll poll(LootContext *context) const;

        const std::string &getType(void) const noexcept;

    private:
        std::list<std::unique_ptr<Pool>> _pools;
        std::string _type;
        std::list<std::unique_ptr<Function::Function>> _functions;
    };
};


#endif //CUBIC_SERVER_LOOT_TABLES_LOOT_TABLE_HPP
