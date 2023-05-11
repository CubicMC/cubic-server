#include "Server.hpp"

#include "Pool.hpp"

namespace LootTable {
    Pool::Pool(const nlohmann::json &pool)
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
    }

    void Pool::poll(LootTablePoll &_poll) const
    {
        (void)_poll;
        /*
//        uint64_t rollNumber = this->_rolls.poll();
        for (const auto &entry : this->_entries) {

        }
        */
    }
};