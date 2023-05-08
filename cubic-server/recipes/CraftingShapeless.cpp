#include "CraftingShapeless.hpp"

#include "Server.hpp"

namespace Recipe {
    CraftingShapeless::CraftingShapeless(const nlohmann::json &recipe)
    {
        this->setCategory(recipe);
        this->setGroup(recipe);
        
        if (!recipe.contains("ingredients") || \
            !recipe.contains("result") || \
            !recipe["ingredients"].is_array() || \
            !recipe["result"].is_object() || \
            !recipe["result"].contains("item") || \
            !recipe["result"]["item"].is_string())
            return;
        this->_result = Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["result"]["item"].get<std::string>());
        if (recipe["result"].contains("count") && recipe["result"]["count"].is_number_unsigned())
            this->_count = recipe["result"]["count"].get<nlohmann::json::number_unsigned_t>();
        else
            this->_count = 1;
        for (const auto &ingredient : recipe["ingredients"]) {
            if (!ingredient.is_object() || !ingredient.contains("item") || !ingredient["item"].is_string())
                return;
            this->_ingredients.push_back(Server::getInstance()->getItemConverter().fromItemToProtocolId(ingredient["item"].get<std::string>()));
        }
        this->setValidity(true);
    }

    void CraftingShapeless::dump(void) const
    {
        bool first = true;
        for (const auto &item : this->_ingredients) {
            if (first == true)
                first = false;
            else 
                std::cout << "+ ";
            std::cout << "\"" << Server::getInstance()->getItemConverter().fromProtocolIdToItem(item) << "\" ";
        }
        std::cout << "= \"" << Server::getInstance()->getItemConverter().fromProtocolIdToItem(this->_result) << "\" (x" << this->_count << ")" << std::endl;
    }

    std::unique_ptr<Recipe> CraftingShapeless::create(const nlohmann::json &recipe)
    {
        return (std::make_unique<CraftingShapeless>(CraftingShapeless(recipe)));
    }
};