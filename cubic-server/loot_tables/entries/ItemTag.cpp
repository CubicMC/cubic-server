#include "Server.hpp"

#include "ItemTag.hpp"

namespace LootTable {
namespace Entry {
ItemTag::ItemTag(const nlohmann::json &entry):
    Entry(entry)
{
    this->_name = entry["name"];

    this->setValidity(true);
}

bool ItemTag::poll(LootTablePoll &poll, LootContext *context) const
{
    (void) poll;
    (void) context;
    return (true);
}

std::unique_ptr<Entry> ItemTag::creator(const nlohmann::json &entry) { return (std::make_unique<ItemTag>(entry)); }
};
};
