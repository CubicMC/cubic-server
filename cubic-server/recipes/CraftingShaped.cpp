#include "CraftingShaped.hpp"

#include "Server.hpp"
#include "logging/logging.hpp"

namespace Recipe {
CraftingShaped::CraftingShaped(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe),
    _x(0),
    _y(0)

{
    // returns if any value is missing or does not have the right type
    if (!recipe.contains("pattern") || !recipe.contains("key") || !recipe.contains("result") || !recipe["pattern"].is_array() || !recipe["key"].is_object() ||
        !recipe["result"].is_object() || !recipe["result"].contains("item") || !recipe["result"]["item"].is_string())
        return;
    // get the recipe values
    this->_result = ITEM_CONVERTER.fromItemToProtocolId(recipe["result"]["item"].get<std::string>());
    if (recipe["result"].contains("count") && recipe["result"]["count"].is_number_unsigned())
        this->_count = recipe["result"]["count"].get<nlohmann::json::number_unsigned_t>();
    else
        this->_count = 1;

    // get the recipe pattern sizes
    this->_y = recipe["pattern"].size();
    for (const nlohmann::json &patternRow : recipe["pattern"])
        this->_x = std::max(this->_x, patternRow.get<std::string>().size());

    // get the recipe ingredients:
    //   go through the "pattern" entry of the recipe
    //   on encountering a new key, get that new key items from the "key" entry
    this->_pattern.resize(this->_x * this->_y, ' ');

    for (size_t pattern_line_pos = 0; pattern_line_pos < recipe["pattern"].size(); pattern_line_pos++) {
        if (!recipe["pattern"][pattern_line_pos].is_string())
            return;

        const std::string &pattern_line = recipe["pattern"][pattern_line_pos].get<std::string>();

        for (size_t pos_on_line = 0; pos_on_line < pattern_line.size(); pos_on_line++) {
            char key = pattern_line.at(pos_on_line);
            const char keystring[2] = {key, '\0'};

            this->_pattern[(pattern_line_pos * this->_x) + pos_on_line] = key;
            if (key != ' ' && !this->_key.contains(key)) {
                if (!recipe["key"].contains(keystring))
                    return;
                if (!this->getKey(key, recipe["key"][keystring]))
                    return;
            }
        }
    }
    this->setValidity(true);
}

void CraftingShaped::dump(void) const
{
    std::stringstream stream;
    size_t count = 0;

    stream << this->getIdentifier() << ':' << std::endl;
    stream << "pattern:";
    while (count < this->_x * this->_y) {
        if (count % this->_x == 0)
            stream << std::endl;
        stream << this->_pattern.at(count);
        count++;
    }
    stream << std::endl << "keys:";
    for (const auto &[key, ingredients] : this->_key) {
        stream << std::endl << key << ":";
        for (const ItemId &item : *ingredients) {
            stream << " \"" << ITEM_CONVERTER.fromProtocolIdToItem(item) << '\"';
        }
    }
    LTRACE(stream.str());
}

bool CraftingShaped::getKey(char key, const nlohmann::json &content)
{
    if (content.is_object()) {
        if (!content.contains("item") || !content["item"].is_string())
            return (false);
        this->_key[key] = std::make_shared<std::unordered_set<ItemId>>(std::unordered_set<ItemId>());
        this->_key[key]->insert(ITEM_CONVERTER.fromItemToProtocolId(content["item"].get<std::string>()));
        return (true);
    } else if (content.is_array()) {
        this->_key[key] = std::make_shared<std::unordered_set<ItemId>>(std::unordered_set<ItemId>());
        for (const auto &item : content) {
            if (!item.is_object() || !item.contains("item") || !item["item"].is_string()) {
                this->_key[key].reset();
                return (false);
            }
            this->_key[key]->insert(ITEM_CONVERTER.fromItemToProtocolId(item["item"].get<std::string>()));
        }
        return (true);
    }
    return (false);
}

std::shared_ptr<Recipe> CraftingShaped::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_shared<CraftingShaped>(CraftingShaped(identifier, recipe)));
}

const std::unordered_map<char, std::shared_ptr<std::unordered_set<ItemId>>> &CraftingShaped::getKeys() const { return (this->_key); }

const std::vector<char> &CraftingShaped::getPattern() const { return (this->_pattern); }

size_t CraftingShaped::getXSize() const noexcept { return (this->_x); }

size_t CraftingShaped::getYSize() const noexcept { return (this->_y); }

ItemId CraftingShaped::getCraftedItem() const noexcept { return (this->_result); }

uint64_t CraftingShaped::getCraftedItemCount() const noexcept { return (this->_count); }
} // namespace Recipe
