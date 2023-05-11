#include "Server.hpp"

#include "Group.hpp"

namespace LootTable {
    namespace Entry {
        Group::Group(const nlohmann::json &entry) : Entry(entry)
        {
            // get entries
            for (const auto &child : entry["children"]) {
                std::unique_ptr<Entry> newChild = Server::getInstance()->lootTables.createEntry(child);

                const auto &it = this->_children.insert(this->_children.end(), nullptr);
                it->swap(newChild);
            }
        }

        bool Group::poll(LootTablePoll &poll)
        {
            for (const auto &child : this->_children) {
                for (const auto &condition : this->_conditions) {
                    if (condition->verify() == false)
                        continue;
                    child->poll(poll);
                }
            }
            return (true);
        }

        std::unique_ptr<Entry> Group::creator(const nlohmann::json &entry)
        {
            return (std::make_unique<Group>(entry));
        }
    };
};
