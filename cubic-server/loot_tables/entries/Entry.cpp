#include "Server.hpp"

#include "Entry.hpp"

namespace LootTable {
    namespace Entry {
        NoEntryContructor::NoEntryContructor(const nlohmann::json &entry) : _message("No constructor fitting the entry: " + entry.dump())
        {}

        const char *NoEntryContructor::what() const noexcept
        {
            return (this->_message.c_str());
        }

        Entry::Entry(const nlohmann::json &entry) : _weight(1), _quality(1)
        {
            // get weight
            if (entry.contains("weight") && entry["weight"].is_number_integer())
                this->_weight = entry["weight"].get<nlohmann::json::number_integer_t>();

            // get quality
            if (entry.contains("quality") && entry["quality"].is_number_integer())
                this->_weight = entry["quality"].get<nlohmann::json::number_integer_t>();

            // get functions
            if (entry.contains("functions") && \
                entry["functions"].is_array()) {
                for (const auto &function : entry["functions"]) {
                    std::unique_ptr<Function::Function> newFunction = Server::getInstance()->lootTables.createFunction(function);
                
                    const auto &it = this->_functions.insert(this->_functions.end(), nullptr);
                    it->swap(newFunction);
                }
            }

            // get conditions
            if (entry.contains("conditions") && \
                entry["conditions"].is_array()) {
                for (const auto &condition : entry["conditions"]) {
                    std::unique_ptr<Condition::Condition> newCondition = Server::getInstance()->lootTables.createCondition(condition);

                    const auto &it = this->_conditions.insert(this->_conditions.end(), nullptr);
                    it->swap(newCondition);
                }
            }
        }

        const int32_t &Entry::getWeight(void) const noexcept
        {
            return (this->_weight);
        }

        const int32_t &Entry::getQuality(void) const noexcept
        {
            return (this->_quality);
        }

        void Entry::setWeight(int32_t weight) noexcept
        {
            this->_weight = weight;
        }

        void Entry::setQuality(int32_t quality) noexcept
        {
            this->_quality = quality;
        }
    };
};