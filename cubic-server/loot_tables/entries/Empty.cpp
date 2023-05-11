#include "Empty.hpp"

namespace LootTable {
    namespace Entry {
        Empty::Empty(const nlohmann::json &entry) : Entry(entry)
        {
            (void)entry;
        }

        bool Empty::poll(LootTablePoll &poll)
        {
            (void)poll;
            for (const auto &condition : this->_conditions) {
                if (condition->verify() == false)
                    return (false);
            }
            return (true);
        }

        std::unique_ptr<Entry> Empty::creator(const nlohmann::json &entry)
        {
            return (std::make_unique<Empty>(entry));
        }
    };
};
