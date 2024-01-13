#include "CampfireCooking.hpp"

#include "Server.hpp"
#include "logging/logging.hpp"

namespace Recipe {
CampfireCooking::CampfireCooking(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    // returns if any value is missing or does not have the right type
    if (!recipe.contains("ingredient") || !recipe.contains("result") || !recipe.contains("experience") || !recipe.contains("cookingtime") ||
        (!recipe["ingredient"].is_object() && !recipe["ingredient"].is_array()) || !recipe["result"].is_string() || !recipe["experience"].is_number() ||
        !recipe["cookingtime"].is_number_unsigned())
        return;

    // get the recipe values
    if (recipe["ingredient"].is_object()) { // if only one ingredient
        if (recipe["ingredient"].contains("item") && recipe["ingredient"]["item"].is_string())
            this->_ingredients.insert(ITEM_CONVERTER.fromItemToProtocolId(recipe["ingredient"]["item"].get<std::string>()));
        else
            return;
    } else if (recipe["ingredient"].is_array()) {
        for (const auto &ingredient : recipe["ingredient"]) { // if multiple ingredients
            if (ingredient.is_object() && ingredient.contains("item") && ingredient["item"].is_string())
                this->_ingredients.insert(ITEM_CONVERTER.fromItemToProtocolId(ingredient["item"].get<std::string>()));
            else
                return;
        }
    } else
        return;

    this->_result = ITEM_CONVERTER.fromItemToProtocolId(recipe["result"].get<std::string>());
    this->_experience = recipe["experience"].get<nlohmann::json::number_float_t>();
    this->_cookingTime = recipe["cookingtime"].get<nlohmann::json::number_unsigned_t>();
    this->setValidity(true);
}

void CampfireCooking::dump(void) const
{
    std::stringstream stream;
    bool first = true;

    stream << '[';
    for (const auto &ingredient : this->_ingredients) {
        if (first)
            first = false;
        else
            stream << ", ";
        stream << "\"" << ITEM_CONVERTER.fromProtocolIdToItem(ingredient) << "\"";
    }
    stream << "] -> \"" << ITEM_CONVERTER.fromProtocolIdToItem(this->_result) << "\" (cooking for " << this->_cookingTime << " ticks and get " << this->_experience << " xp)";
    LTRACE(stream.str());
}

std::shared_ptr<Recipe> CampfireCooking::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_shared<CampfireCooking>(CampfireCooking(identifier, recipe)));
}
} // namespace Recipe
