#include "Server.hpp"

#include "Dynamic.hpp"

namespace LootTable {
namespace Entry {
Dynamic::Dynamic(const nlohmann::json &entry):
    Entry(entry)
{
    (void) entry;

    this->setValidity(true);
}

bool Dynamic::poll(LootTablePoll &poll, LootContext *context) const
{
    (void) poll;
    (void) context;
    return (true);
}

std::unique_ptr<Entry> Dynamic::creator(const nlohmann::json &entry) { return (std::make_unique<Dynamic>(entry)); }
};
};
