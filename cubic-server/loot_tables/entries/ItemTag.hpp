#ifndef CUBIC_SERVER_LOOT_TABLES_ENTRIES_ITEMTAG_HPP
#define CUBIC_SERVER_LOOT_TABLES_ENTRIES_ITEMTAG_HPP

#include "Entry.hpp"

namespace LootTable {
namespace Entry {
class ItemTag : public Entry {
public:
    ItemTag(const nlohmann::json &entry);
    ~ItemTag() = default;

    bool poll(LootTablePoll &poll, LootContext *context) const override;

    static std::unique_ptr<Entry> creator(const nlohmann::json &entry);

private:
    std::string _name;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_ENTRIES_ITEMTAG_HPP
