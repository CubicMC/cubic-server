#include "Server.hpp"

#include "Pool.hpp"
#include "conditions/Condition.hpp"
#include "context/LootContext.hpp"
#include "entries/Entry.hpp"
#include "functions/Function.hpp"
#include "rolls/Roll.hpp"

namespace LootTable {
Pool::Pool(const nlohmann::json &pool):
    _totalWeight(0),
    _validity(false)
{
    if (!pool.is_object() || !pool.contains("entries") || !pool.contains("rolls") || !pool["entries"].is_array() || !(pool["entries"].size() > 0))
        return; // invalid pool

    // get rool and bonus roll
    this->_roll = Server::getInstance()->getLootTableSystem().createRoll(pool["rolls"]);

    // get entries
    for (const auto &entry : pool["entries"]) {
        std::unique_ptr<Entry::Entry> newEntry = Server::getInstance()->getLootTableSystem().createEntry(entry);

        const auto &it = this->_entries.insert(this->_entries.end(), nullptr);
        it->swap(newEntry);
    }

    // get functions
    if (pool.contains("functions") && pool["functions"].is_array()) {
        for (const auto &function : pool["functions"]) {
            std::unique_ptr<Function::Function> newFunction = Server::getInstance()->getLootTableSystem().createFunction(function);

            const auto &it = this->_functions.insert(this->_functions.end(), nullptr);
            it->swap(newFunction);
        }
    }

    // get conditions
    if (pool.contains("conditions") && pool["conditions"].is_array()) {
        for (const auto &condition : pool["conditions"]) {
            std::unique_ptr<Condition::Condition> newCondition = Server::getInstance()->getLootTableSystem().createCondition(condition);

            const auto &it = this->_conditions.insert(this->_conditions.end(), nullptr);
            it->swap(newCondition);
        }
    }

    this->_totalWeight = this->getTotalWeight();

    // set validity, tables containing an invalid poll will be dropped
    this->setValidity();
}

bool Pool::isValid(void) const noexcept { return (this->_validity); }

void Pool::setValidity(void) noexcept
{
    for (const auto &condition : this->_conditions) {
        if (!condition->isValid()) {
            this->_validity = false;
            return;
        }
    }
    for (const auto &function : this->_functions) {
        if (!function->isValid()) {
            this->_validity = false;
            return;
        }
    }
    for (const auto &entry : this->_entries) {
        if (!entry->isValid()) {
            this->_validity = false;
            return;
        }
    }
    if (!this->_roll->isValid()) {
        this->_validity = false;
        return;
    }
    this->_validity = true;
}

void Pool::poll(LootTablePoll &_poll, LootContext *context) const
{
    // get number of entries to generate and their probability
    const Roll::RollResult roll = this->_roll->poll(context);

    for (int rolls = 0; rolls < roll.nbr; rolls++) {
        // proceeds if probability is superior or equal to 1 or if probability rolled is inferior to probability generated
        if (roll.probability >= 1.0 || static_cast<double>(rand() % 10000) < roll.probability * 10000.0) {
            int64_t rolledWeight = 0;
            int64_t elapsedWeight = 0;

            if (this->_totalWeight > 1)
                rolledWeight = rand() % this->_totalWeight;
            // get the right entry for the rolled weight
            for (const auto &entry : this->_entries) {
                // when entry is found, calls its poll function
                if (this->_totalWeight <= 1 || rolledWeight < elapsedWeight + entry->getWeight()) {
                    entry->poll(_poll, context);
                    break;
                }
                rolledWeight += entry->getWeight();
            }
        }
    }
}

int64_t Pool::getTotalWeight(void) const noexcept
{
    int64_t weight = 0;

    for (const auto &entry : this->_entries)
        weight += entry->getWeight();
    return (weight);
}
};
