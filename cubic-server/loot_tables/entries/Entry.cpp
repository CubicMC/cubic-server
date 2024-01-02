#include "Server.hpp"

#include "Entry.hpp"
#include "loot_tables/conditions/Condition.hpp"
#include "loot_tables/functions/Function.hpp"

namespace LootTable {
namespace Entry {
Entry::Entry(const nlohmann::json &entry):
    _weight(1),
    _quality(1),
    _validity(false)
{
    // get weight
    if (entry.contains("weight") && entry["weight"].is_number_integer())
        this->_weight = entry["weight"].get<nlohmann::json::number_integer_t>();

    // get quality
    if (entry.contains("quality") && entry["quality"].is_number_integer())
        this->_weight = entry["quality"].get<nlohmann::json::number_integer_t>();

    // get functions
    if (entry.contains("functions") && entry["functions"].is_array()) {
        for (const auto &function : entry["functions"]) {
            std::unique_ptr<Function::Function> newFunction = Server::getInstance()->getLootTableSystem().createFunction(function);

            const auto &it = this->_functions.insert(this->_functions.end(), nullptr);
            it->swap(newFunction);
        }
    }

    // get conditions
    if (entry.contains("conditions") && entry["conditions"].is_array()) {
        for (const auto &condition : entry["conditions"]) {
            std::unique_ptr<Condition::Condition> newCondition = Server::getInstance()->getLootTableSystem().createCondition(condition);

            const auto &it = this->_conditions.insert(this->_conditions.end(), nullptr);
            it->swap(newCondition);
        }
    }
}

bool Entry::isValid(void) const noexcept { return (this->_validity); }

void Entry::setValidity(bool validity) noexcept
{
    if (validity == false) {
        this->_validity = false;
        return;
    }
    for (const auto &condition : this->_conditions) {
        if (!condition->isValid()) {
            this->_validity = false;
            return;
        }
    }
    for (const auto &function : this->_functions) {
        if (!function->isValid()) {
            this->_validity = false;
            return;
        }
    }
    this->_validity = true;
}

const int64_t &Entry::getWeight(void) const noexcept { return (this->_weight); }

const int64_t &Entry::getQuality(void) const noexcept { return (this->_quality); }

void Entry::setWeight(int64_t weight) noexcept { this->_weight = weight; }

void Entry::setQuality(int64_t quality) noexcept { this->_quality = quality; }
};
};
