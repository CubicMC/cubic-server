#ifndef CUBIC_SERVER_LOOT_TABLES_ENTRIES_GROUP_HPP
#define CUBIC_SERVER_LOOT_TABLES_ENTRIES_GROUP_HPP

#include "Entry.hpp"

namespace LootTable {
namespace Entry {
class Group : public Entry {
public:
    Group(const nlohmann::json &entry);
    ~Group() = default;

    bool poll(LootTablePoll &poll, LootContext *context) const override;

    static std::unique_ptr<Entry> creator(const nlohmann::json &entry);

private:
    std::list<std::unique_ptr<Entry>> _children;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_ENTRIES_GROUP_HPP
