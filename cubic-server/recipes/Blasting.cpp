#include "Blasting.hpp"

#include "Server.hpp"

namespace Recipe {
Blasting::Blasting(const nlohmann::json &recipe):
    Recipe(recipe)
{
    // returns if any value is missing or does not have the right type
    // clang-format off
    if (!recipe.contains("ingredient") || \
        !recipe.contains("result") || \
        !recipe.contains("experience") || \
        !recipe.contains("cookingtime") || \
        !recipe["ingredient"].is_object() || \
        !recipe["result"].is_string() || \
        !recipe["experience"].is_number() || \
        !recipe["cookingtime"].is_number_unsigned() || \
        !recipe["ingredient"].contains("item") || \
        !recipe["ingredient"]["item"].is_string())
        return;
    // clang-format on
    // get the recipe values
    this->_ingredient = ITEM_CONVERTER.fromItemToProtocolId(recipe["ingredient"]["item"].get<std::string>());
    this->_result = ITEM_CONVERTER.fromItemToProtocolId(recipe["result"].get<std::string>());
    this->_experience = recipe["experience"].get<nlohmann::json::number_float_t>();
    this->_cookingTime = recipe["cookingtime"].get<nlohmann::json::number_unsigned_t>();
    this->setValidity(true);
}

void Blasting::dump(void) const
{
    LINFO(
        "\"", ITEM_CONVERTER.fromProtocolIdToItem(this->_ingredient), "\" -> \"", ITEM_CONVERTER.fromProtocolIdToItem(this->_result), "\" (cooking for ", this->_cookingTime,
        " ticks and get ", this->_experience, " xp)"
    );
}

std::unique_ptr<Recipe> Blasting::create(const nlohmann::json &recipe) { return (std::make_unique<Blasting>(Blasting(recipe))); }
};
