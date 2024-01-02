#ifndef CUBIC_SERVER_LOOT_TABLES_ENTRIES_SEQUENCE_HPP
#define CUBIC_SERVER_LOOT_TABLES_ENTRIES_SEQUENCE_HPP

#include "Entry.hpp"

namespace LootTable {
namespace Entry {
class Sequence : public Entry {
public:
    Sequence(const nlohmann::json &entry);
    ~Sequence() = default;

    bool poll(LootTablePoll &poll, LootContext *context) const override;

    static std::unique_ptr<Entry> creator(const nlohmann::json &entry);

private:
    std::list<std::unique_ptr<Entry>> _children;
};
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_ENTRIES_SEQUENCE_HPP
