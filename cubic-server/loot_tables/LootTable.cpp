#include "Server.hpp"

#include "LootTable.hpp"

#include "Pool.hpp"
#include "context/LootContext.hpp"

namespace LootTable {
const std::unordered_map<ItemId, uint8_t> &LootTablePoll::getRolledItems(void) const { return (this->_items); }

void LootTablePoll::addRolledItem(ItemId item, uint8_t count)
{
    if (!this->_items.contains(item))
        this->_items[item] = count;
    else
        this->_items[item] += count;
}

void LootTablePoll::addRolledItem(const std::unordered_map<ItemId, uint8_t> &items)
{
    for (const auto &[item, count] : items) {
        this->addRolledItem(item, count);
    }
}

void LootTablePoll::addRolledItem(const LootTablePoll &poll) { this->addRolledItem(poll.getRolledItems()); }

LootTable::LootTable(const nlohmann::json &table):
    _validity(false)
{
    if (!table.is_object() || !table.contains("pools") || !table["pools"].is_array())
        return; // invalid table

    // get type
    if (table.contains("type") && table["type"].is_string())
        this->_type = table["type"].get<std::string>();

    // get pools
    for (const auto &pool : table["pools"]) {
        std::unique_ptr<Pool> newPool = std::make_unique<Pool>(pool);

        const auto &it = this->_pools.insert(this->_pools.end(), nullptr);
        it->swap(newPool);
    }

    // get functions
    if (table.contains("functions") && table["functions"].is_array()) {
        for (const auto &function : table["functions"]) {
            std::unique_ptr<Function::Function> newFunction = Server::getInstance()->getLootTableSystem().createFunction(function);

            const auto &it = this->_functions.insert(this->_functions.end(), nullptr);
            it->swap(newFunction);
        }
    }

    // set validity, invalid tables will be dropped
    this->setValidity();
}

bool LootTable::isValid(void) const noexcept { return (this->_validity); }

void LootTable::setValidity(void) noexcept
{
    for (const auto &function : this->_functions) {
        if (!function->isValid()) {
            this->_validity = false;
            return;
        }
    }
    for (const auto &pool : this->_pools) {
        if (!pool->isValid()) {
            this->_validity = false;
            return;
        }
    }
    this->_validity = true;
}

// calls every Pool poll function with context
LootTablePoll LootTable::poll(LootContext *context) const
{
    LootTablePoll newPoll;

    for (const auto &pool : this->_pools) {
        pool->poll(newPoll, context);
    }
    return (newPoll);
}

const std::string &LootTable::getType(void) const noexcept { return (this->_type); }
};
