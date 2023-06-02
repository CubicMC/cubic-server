#include "Server.hpp"

#include "Sequence.hpp"

namespace LootTable {
namespace Entry {
Sequence::Sequence(const nlohmann::json &entry):
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

bool Sequence::poll(LootTablePoll &poll, LootContext *context) const
{
    bool polled = false;

    for (const auto &child : this->_children) {
        for (const auto &condition : this->_conditions) {
            if (condition->verify(context) == false)
                return (polled);
        }
        child->poll(poll, context);
        polled = true;
    }
    return (polled);
}

std::unique_ptr<Entry> Sequence::creator(const nlohmann::json &entry) { return (std::make_unique<Sequence>(entry)); }
};
};
