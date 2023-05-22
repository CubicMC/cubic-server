#include "Server.hpp"

#include "Item.hpp"

namespace LootTable {
namespace Entry {
Item::Item(const nlohmann::json &entry):
    Entry(entry)
{
    if (entry.contains("name") && entry["name"].is_string())
        this->_item = Server::getInstance()->getItemConverter().fromItemToProtocolId(entry["name"].get<std::string>());

    this->setValidity(true);
}

bool Item::poll(LootTablePoll &poll, LootContext *context) const
{
    (void) context;
    for (const auto &condition : this->_conditions) {
        if (condition->verify(context) == false)
            return (false);
    }
    poll.addRolledItem(this->_item, 1);
    return (true);
}

std::unique_ptr<Entry> Item::creator(const nlohmann::json &entry) { return (std::make_unique<Item>(entry)); }
};
};
