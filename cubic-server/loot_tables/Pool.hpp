#ifndef CUBIC_SERVER_LOOT_TABLES_POOL_HPP
#define CUBIC_SERVER_LOOT_TABLES_POOL_HPP

#include <memory>
#include <list>

#include <nlohmann/json.hpp>

#include "rolls/Roll.hpp"
#include "entries/Entry.hpp"
#include "functions/Function.hpp"
#include "conditions/Condition.hpp"

namespace LootTable {
    class LootTablePoll;

    class Pool {
    public:
        Pool(const nlohmann::json &pool);
        ~Pool() = default;

        void poll(LootTablePoll &_poll) const;

    private:
        std::unique_ptr<Roll::Roll> _roll;
        std::list<std::unique_ptr<Entry::Entry>> _entries;
        std::list<std::unique_ptr<Function::Function>> _functions;
        std::list<std::unique_ptr<Condition::Condition>> _conditions;
        uint64_t _totalWeight;
        std::list<uint64_t> _weights;
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_POOL_HPP