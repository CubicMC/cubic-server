#ifndef CUBIC_SERVER_LOOT_TABLES_ENTRIES_ENTRY_HPP
#define CUBIC_SERVER_LOOT_TABLES_ENTRIES_ENTRY_HPP

#include <list>
#include <memory>

#include <nlohmann/json.hpp>

#include "exceptions.hpp"

namespace LootTable {
class LootTablePoll;
class LootContext;
namespace Function {
class Function;
};
namespace Condition {
class Condition;
};

namespace Entry {
/*
  Entry class to be overloaded,
  invalid by default
  automatically fills the weight and quality of the entry, both are 1 by default
*/
class Entry {
public:
    Entry(const nlohmann::json &entry);
    virtual ~Entry() = default;

    // entry must be valid, call setValidity(true) to validate
    bool isValid(void) const noexcept;
    // setValitidy(true) will not set the validity to true if any component (function, condition) is invalid
    void setValidity(bool validity) noexcept;

    const int64_t &getWeight(void) const noexcept;
    const int64_t &getQuality(void) const noexcept;

    void setWeight(int64_t weight) noexcept;
    void setQuality(int64_t quality) noexcept;

    virtual bool poll(LootTablePoll &poll, LootContext *context) const = 0;

protected:
    int64_t _weight;
    int64_t _quality;
    std::list<std::unique_ptr<Function::Function>> _functions;
    std::list<std::unique_ptr<Condition::Condition>> _conditions;
    bool _validity;
};

// type definition for creator, may return nullptr or a invalid entry
typedef std::unique_ptr<Entry> (*Creator)(const nlohmann::json &entry);

DEFINE_EXCEPTION(NoEntryContructor);
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_ENTRIES_ENTRY_HPP
