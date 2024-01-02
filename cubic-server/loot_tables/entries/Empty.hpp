#ifndef CUBIC_SERVER_LOOT_TABLES_ENTRIES_EMPTY_HPP
#define CUBIC_SERVER_LOOT_TABLES_ENTRIES_EMPTY_HPP

#include <list>
#include <memory>

#include "Entry.hpp"

namespace LootTable {
namespace Entry {
class Empty : public Entry {
public:
    Empty(const nlohmann::json &entry);
    ~Empty() = default;

    bool poll(LootTablePoll &poll, LootContext *context) const override;

    static std::unique_ptr<Entry> creator(const nlohmann::json &entry);
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_ENTRIES_EMPTY_HPP
