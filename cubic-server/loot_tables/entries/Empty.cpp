#include "Server.hpp"

#include "Empty.hpp"

namespace LootTable {
namespace Entry {
Empty::Empty(const nlohmann::json &entry):
    Entry(entry)
{
    (void) entry;

    this->setValidity(true);
}

bool Empty::poll(LootTablePoll &poll, LootContext *context) const
{
    (void) poll;
    (void) context;
    for (const auto &condition : this->_conditions) {
        if (condition->verify(context) == false)
            return (false);
    }
    return (true);
}

std::unique_ptr<Entry> Empty::creator(const nlohmann::json &entry) { return (std::make_unique<Empty>(entry)); }
};
};
