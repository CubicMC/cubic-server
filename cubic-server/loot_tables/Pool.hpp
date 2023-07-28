#ifndef CUBIC_SERVER_LOOT_TABLES_POOL_HPP
#define CUBIC_SERVER_LOOT_TABLES_POOL_HPP

#include <list>
#include <memory>

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

/*
  Loot table pool is a pool of entries that may be generated
  all conditions must be validated for the poll to be done
  all functions will be applied to the generated items
*/
class Pool {
public:
    Pool(const nlohmann::json &pool);
    ~Pool() = default;

    // a pool is valid if all its components are valid (roll, entries, functions, conditions)
    bool isValid(void) const noexcept;
    void setValidity(void) noexcept;

    void poll(LootTablePoll &_poll, LootContext *context) const;

    // get sum of weights of all entries
    int64_t getTotalWeight(void) const noexcept;

private:
    std::unique_ptr<Roll::Roll> _roll;
    std::list<std::unique_ptr<Entry::Entry>> _entries;
    std::list<std::unique_ptr<Function::Function>> _functions;
    std::list<std::unique_ptr<Condition::Condition>> _conditions;
    int64_t _totalWeight;
    bool _validity;
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_POOL_HPP
