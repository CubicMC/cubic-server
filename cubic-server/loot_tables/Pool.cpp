#include "Server.hpp"

#include "Pool.hpp"
#include "context/LootContext.hpp"
#include "rolls/Roll.hpp"
#include "entries/Entry.hpp"
#include "functions/Function.hpp"
#include "conditions/Condition.hpp"

namespace LootTable {
    Pool::Pool(const nlohmann::json &pool):
        _totalWeight(0)
    {
        if (!pool.is_object() || \
            !pool.contains("entries") || \
            !pool.contains("rolls") || \
            !pool["entries"].is_array() || \
            !(pool["entries"].size() > 0))
            return; // invalid pool
        
        //get rool and bonus roll
        this->_roll = Server::getInstance()->lootTables.createRoll(pool["rolls"]);

        // get entries
        for (const auto &entry : pool["entries"]) {
            std::unique_ptr<Entry::Entry> newEntry = Server::getInstance()->lootTables.createEntry(entry);

            const auto &it = this->_entries.insert(this->_entries.end(), nullptr);
            it->swap(newEntry);
        }
        
        // get functions
        if (pool.contains("functions") && \
            pool["functions"].is_array()) {
            for (const auto &function : pool["functions"]) {
                std::unique_ptr<Function::Function> newFunction = Server::getInstance()->lootTables.createFunction(function);
                
                const auto &it = this->_functions.insert(this->_functions.end(), nullptr);
                it->swap(newFunction);
            }
        }

        // get conditions
        if (pool.contains("conditions") && \
            pool["conditions"].is_array()) {
            for (const auto &condition : pool["conditions"]) {
                std::unique_ptr<Condition::Condition> newCondition = Server::getInstance()->lootTables.createCondition(condition);

                const auto &it = this->_conditions.insert(this->_conditions.end(), nullptr);
                it->swap(newCondition);
            }
        }

        this->_totalWeight = this->getTotalWeight();
    }

    void Pool::poll(LootTablePoll &_poll, LootContext *context) const
    {
        const Roll::RollResult roll = this->_roll->poll(context);

        for (int rolls = 0; rolls < roll._nbr; rolls++) {
            if (roll._probability == 1.0 || static_cast<double>(rand() % 10000) < roll._probability * 10000.0) {
                int64_t rolledWeight = 0;
                int64_t elapsedWeight = 0;
                
                if (this->_totalWeight > 1)
                    rolledWeight = rand() % this->_totalWeight;
                for (const auto &entry : this->_entries) {
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