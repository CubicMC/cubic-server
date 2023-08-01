#ifndef CUBIC_SERVER_LOOT_TABLES_LOOT_TABLE_HPP
#define CUBIC_SERVER_LOOT_TABLES_LOOT_TABLE_HPP

#include <list>
#include <memory>
#include <unordered_map>

#include <nlohmann/json.hpp>

#include "types.hpp"

#include "Pool.hpp"
#include "functions/Function.hpp"

namespace LootTable {
/**
 * Loot table poll is the result of a poll on a loot table
 * It holds every item generated
 * TODO: handling item tags and NBT
 */
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

/**
 * Loot table class, invalid tables will be dropped
 */
class LootTable {
public:
    LootTable(const nlohmann::json &table);
    ~LootTable() = default;

    // for a table to be validated, it needs to have all its components valid (pools, and function)
    bool isValid(void) const noexcept;
    void setValidity(void) noexcept;

    // generate items from the loot table given a context
    LootTablePoll poll(LootContext *context) const;

    // type does not matter for now
    // used to determine the context that should be provided
    const std::string &getType(void) const noexcept;

private:
    std::list<std::unique_ptr<Pool>> _pools;
    std::string _type;
    std::list<std::unique_ptr<Function::Function>> _functions;
    bool _validity;
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_LOOT_TABLE_HPP
