#ifndef CUBIC_SERVER_LOOT_TABLES_POOL_HPP
#define CUBIC_SERVER_LOOT_TABLES_POOL_HPP

#include <memory>
#include <list>

#include <nlohmann/json.hpp>

namespace LootTable {
    class LootTablePoll;
    class LootContext;
    namespace Roll {
        class Roll;
    };
    namespace Entry {
        class Entry;
    };
    namespace Function {
        class Function;
    };
    namespace Condition {
        class Condition;
    };

    class Pool {
    public:
        Pool(const nlohmann::json &pool);
        ~Pool() = default;

        void poll(LootTablePoll &_poll, LootContext *context) const;

        int64_t getTotalWeight(void) const noexcept;

    private:
        std::unique_ptr<Roll::Roll> _roll;
        std::list<std::unique_ptr<Entry::Entry>> _entries;
        std::list<std::unique_ptr<Function::Function>> _functions;
        std::list<std::unique_ptr<Condition::Condition>> _conditions;
        int64_t _totalWeight;
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_POOL_HPP