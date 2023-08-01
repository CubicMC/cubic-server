#ifndef CUBIC_SERVER_LOOT_TABLES_ENTRIES_ITEM_HPP
#define CUBIC_SERVER_LOOT_TABLES_ENTRIES_ITEM_HPP

#include <list>
#include <memory>

#include "Entry.hpp"

#include "types.hpp"

namespace LootTable {
namespace Entry {
class Item : public Entry {
public:
    Item(const nlohmann::json &entry);
    ~Item() = default;

    bool poll(LootTablePoll &poll, LootContext *context) const override;

    static std::unique_ptr<Entry> creator(const nlohmann::json &entry);

private:
    ItemId _item;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_ENTRIES_ITEM_HPP
