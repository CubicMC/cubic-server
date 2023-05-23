#include "CraftingShaped.hpp"

#include "Server.hpp"

namespace Recipe {
CraftingShaped::MaybeItems::MaybeItems(void):
    _empty(true)
{
}

CraftingShaped::MaybeItems::MaybeItems(const std::shared_ptr<std::vector<ItemId>> &item):
    _empty(false),
    _items(item)
{
}

bool CraftingShaped::MaybeItems::isEmpty(void) const noexcept { return (this->_empty); }

const std::weak_ptr<std::vector<ItemId>> &CraftingShaped::MaybeItems::getItems(void) const noexcept { return (this->_items); }

CraftingShaped::CraftingShaped(const nlohmann::json &recipe):
    Recipe(recipe)
{
    // returns if any value is missing or does not have the right type
    if (!recipe.contains("pattern") || !recipe.contains("key") || !recipe.contains("result") || !recipe["pattern"].is_array() || !recipe["key"].is_object() ||
        !recipe["result"].is_object() || !recipe["result"].contains("item") || !recipe["result"]["item"].is_string())
        return;
    // get the recipe values
    this->_result = Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["result"]["item"].get<std::string>());
    if (recipe["result"].contains("count") && recipe["result"]["count"].is_number_unsigned())
        this->_count = recipe["result"]["count"].get<nlohmann::json::number_unsigned_t>();
    else
        this->_count = 1;
    for (size_t pattern_line_pos = 0; pattern_line_pos < recipe["pattern"].size(); pattern_line_pos++) {
        if (!recipe["pattern"][pattern_line_pos].is_string())
            return;
        this->_pattern.push_back(std::vector<MaybeItems>());

        std::string pattern_line = recipe["pattern"][pattern_line_pos].get<std::string>();

        for (const auto &pattern_item : pattern_line) {
            if (pattern_item == ' ')
                this->_pattern[pattern_line_pos].push_back(MaybeItems());
            else {
                if (!recipe["key"].contains(&pattern_item))
                    return;
                if (!this->getKey(pattern_item, recipe["key"][&pattern_item]))
                    return;
                this->_pattern[pattern_line_pos].push_back(MaybeItems(this->_key[pattern_item]));
            }
        }
    }
    this->setValidity(true);
}

void CraftingShaped::dump(void) const
{
    std::stringstream stream;

    for (const auto &line : this->_pattern) {
        for (const auto &item : line) {
            if (item.isEmpty())
                stream << ' ';
            else {
                bool found_key = false;

                for (const auto &[key, items] : this->_key) {
                    if (item.getItems().lock() == items) {
                        stream << key;
                        found_key = true;
                        break;
                    }
                }
                if (!found_key)
                    stream << '!';
            }
        }
        LINFO(stream.str());
        stream.str("");
    }
    for (const auto &[key, items] : this->_key) {
        stream << '\'' << key << "\': [";
        bool first_item = true;

        for (const auto &item : *items) {
            if (first_item)
                first_item = false;
            else
                stream << ", ";
            stream << '\"' << Server::getInstance()->getItemConverter().fromProtocolIdToItem(item) << '\"';
        }
        stream << ']';
        LINFO(stream.str());
        stream.str("");
    }
    stream << " -> " << Server::getInstance()->getItemConverter().fromProtocolIdToItem(this->_result) << " (x" << this->_count << ')';
    LINFO(stream.str());
}

bool CraftingShaped::getKey(char key, const nlohmann::json &content)
{
    if (content.is_object()) {
        if (!content.contains("item") || !content["item"].is_string())
            return (false);
        this->_key[key] = std::make_shared<std::vector<ItemId>>(std::vector<ItemId>());
        this->_key[key]->push_back(Server::getInstance()->getItemConverter().fromItemToProtocolId(content["item"].get<std::string>()));
        return (true);
    } else if (content.is_array()) {
        this->_key[key] = std::make_shared<std::vector<ItemId>>(std::vector<ItemId>());
        for (const auto &item : content) {
            if (!item.is_object() || !item.contains("item") || !item["item"].is_string()) {
                this->_key[key].reset();
                return (false);
            }
            this->_key[key]->push_back(Server::getInstance()->getItemConverter().fromItemToProtocolId(item["item"].get<std::string>()));
        }
        return (true);
    }
    return (false);
}

std::unique_ptr<Recipe> CraftingShaped::create(const nlohmann::json &recipe) { return (std::make_unique<CraftingShaped>(CraftingShaped(recipe))); }
};