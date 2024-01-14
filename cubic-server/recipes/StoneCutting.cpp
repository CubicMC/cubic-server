#include "StoneCutting.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
StoneCutting::StoneCutting(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    // returns if any value is missing or does not have the right type
    if (!recipe.contains("ingredient") || !recipe.contains("result") || !recipe.contains("count") || (!recipe["ingredient"].is_object() && !recipe["ingredient"].is_array()) ||
        !recipe["result"].is_string() || !recipe["count"].is_number_unsigned())
        return;

    // get the recipe values
    if (recipe["ingredient"].is_object()) { // if only one ingredient
        if (recipe["ingredient"].contains("item") && recipe["ingredient"]["item"].is_string())
            this->_ingredients.insert(Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["ingredient"]["item"].get<std::string>()));
        else
            return;
    } else if (recipe["ingredient"].is_array()) {
        for (const auto &ingredient : recipe["ingredient"]) { // if multiple ingredients
            if (ingredient.is_object() && ingredient.contains("item") && ingredient["item"].is_string())
                this->_ingredients.insert(Server::getInstance()->getItemConverter().fromItemToProtocolId(ingredient["item"].get<std::string>()));
            else
                return;
        }
    } else
        return;

    this->_result = Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["result"].get<std::string>());
    this->_count = recipe["count"].get<nlohmann::json::number_unsigned_t>();
    this->setValidity(true);
}

void StoneCutting::dump(void) const
{
    std::stringstream stream;
    bool first = true;

    stream << '[';
    for (const auto &ingredient : this->_ingredients) {
        if (first)
            first = false;
        else
            stream << ", ";
        stream << "\"" << Server::getInstance()->getItemConverter().fromProtocolIdToItem(ingredient) << "\"";
    }
    stream << "] -> \"" << Server::getInstance()->getItemConverter().fromProtocolIdToItem(this->_result) << "\" (x" << this->_count << ")";
    LTRACE(stream.str());
}

std::shared_ptr<Recipe> StoneCutting::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_shared<StoneCutting>(StoneCutting(identifier, recipe)));
}
} // namespace Recipe
