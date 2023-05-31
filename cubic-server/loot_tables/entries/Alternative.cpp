#include "Server.hpp"

#include "Alternative.hpp"

namespace LootTable {
namespace Entry {
Alternative::Alternative(const nlohmann::json &entry):
    Entry(entry)
{
    // get entries
    for (const auto &child : entry["children"]) {
        std::unique_ptr<Entry> newChild = Server::getInstance()->getLootTableSystem().createEntry(child);

        const auto &it = this->_children.insert(this->_children.end(), nullptr);
        it->swap(newChild);
    }

    this->setValidity(true);
}

bool Alternative::poll(LootTablePoll &poll, LootContext *context) const
{
    for (const auto &child : this->_children) {
        for (const auto &condition : this->_conditions) {
            if (condition->verify(context) == false)
                continue;
        }
        child->poll(poll, context);
        return (true);
    }
    return (false);
}

std::unique_ptr<Entry> Alternative::creator(const nlohmann::json &entry) { return (std::make_unique<Alternative>(entry)); }
};
};
