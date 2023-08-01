#ifndef CUBIC_SERVER_LOOT_TABLES_ENTRIES_LOOTTABLE_HPP
#define CUBIC_SERVER_LOOT_TABLES_ENTRIES_LOOTTABLE_HPP

#include "Entry.hpp"
#include "loot_tables/LootTable.hpp"

namespace LootTable {
namespace Entry {
class LootTableEntry : public Entry {
public:
    LootTableEntry(const nlohmann::json &entry);
    ~LootTableEntry() = default;

    bool poll(LootTablePoll &poll, LootContext *context) const override;

    static std::unique_ptr<Entry> creator(const nlohmann::json &entry);

private:
    bool _isTable;
    LootTable *_table;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_ENTRIES_LOOTTABLE_HPP
