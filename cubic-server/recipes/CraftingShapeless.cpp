#include "CraftingShapeless.hpp"

#include "Server.hpp"
#include "logging/logging.hpp"

namespace Recipe {
CraftingShapeless::CraftingShapeless(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    // returns if any value is missing or does not have the right type
    if (!recipe.contains("ingredients") || !recipe.contains("result") || !recipe["ingredients"].is_array() || !recipe["result"].is_object() || !recipe["result"].contains("item") ||
        !recipe["result"]["item"].is_string())
        return;
    // get the recipe values
    this->_result = ITEM_CONVERTER.fromItemToProtocolId(recipe["result"]["item"].get<std::string>());
    if (recipe["result"].contains("count") && recipe["result"]["count"].is_number_unsigned())
        this->_count = recipe["result"]["count"].get<nlohmann::json::number_unsigned_t>();
    else
        this->_count = 1;
    this->_ingredients.resize(recipe["ingredients"].size());
    for (size_t i = 0; i < recipe["ingredients"].size(); i++) {
        if (recipe["ingredients"].at(i).is_object() && recipe["ingredients"].at(i).contains("item") && recipe["ingredients"].at(i)["item"].is_string())
            this->_ingredients.at(i).insert(ITEM_CONVERTER.fromItemToProtocolId(recipe["ingredients"].at(i)["item"].get<std::string>()));
        else if (recipe["ingredients"].at(i).is_array()) {
            for (const auto &ingredient : recipe["ingredients"].at(i)) {
                if (ingredient.is_object() && ingredient.contains("item") && ingredient["item"].is_string())
                    this->_ingredients[i].insert(ITEM_CONVERTER.fromItemToProtocolId(ingredient["item"].get<std::string>()));
            }
        } else
            return;
    }
    this->setValidity(true);
}

void CraftingShapeless::dump(void) const
{
    std::stringstream stream;

    bool first = true;

    for (const auto &ingredients : this->_ingredients) {
        if (first)
            first = false;
        else
            stream << "+ ";

        stream << "[";
        for (const auto &item : ingredients) {
            stream << "\"" << ITEM_CONVERTER.fromProtocolIdToItem(item) << "\"";
        }
        stream << "] ";
    }
    stream << "= \"" << ITEM_CONVERTER.fromProtocolIdToItem(this->_result) << "\" (x" << this->_count << ")";
    LTRACE(stream.str());
}

std::shared_ptr<Recipe> CraftingShapeless::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_shared<CraftingShapeless>(CraftingShapeless(identifier, recipe)));
}

const std::vector<std::unordered_set<ItemId>> &CraftingShapeless::getIngredients() const { return (this->_ingredients); }

ItemId CraftingShapeless::getCraftedItem() const noexcept { return (this->_result); }

uint64_t CraftingShapeless::getCraftedItemCount() const noexcept { return (this->_count); }
} // namespace Recipe
