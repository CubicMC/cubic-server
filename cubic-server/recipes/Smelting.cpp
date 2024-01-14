#include "Smelting.hpp"

#include "Server.hpp"
#include "logging/logging.hpp"

namespace Recipe {
Smelting::Smelting(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
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

void Smelting::dump(void) const
{
    LTRACE(
        "\"{}\" -> \"{}\" (cooking for {} ticks and get {} xp)", ITEM_CONVERTER.fromProtocolIdToItem(this->_ingredient), ITEM_CONVERTER.fromProtocolIdToItem(this->_result),
        this->_cookingTime, this->_experience
    );
}

std::shared_ptr<Recipe> Smelting::create(const std::string &identifier, const nlohmann::json &recipe) { return (std::make_shared<Smelting>(Smelting(identifier, recipe))); }
} // namespace Recipe
