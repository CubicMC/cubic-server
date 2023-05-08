#include "CampfireCooking.hpp"

#include "Server.hpp"

namespace Recipe {
    CampfireCooking::CampfireCooking(const nlohmann::json &recipe)
    {
        this->setCategory(recipe);
        this->setGroup(recipe);

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
        this->_ingredient = Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["ingredient"]["item"].get<std::string>());
        this->_result = Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["result"].get<std::string>());
        this->_experience = recipe["experience"].get<nlohmann::json::number_float_t>();
        this->_cookingTime = recipe["cookingtime"].get<nlohmann::json::number_unsigned_t>();
        this->setValidity(true);
    }

    void CampfireCooking::dump(void) const
    {
        std::cout << "\"" << Server::getInstance()->getItemConverter().fromProtocolIdToItem(this->_ingredient) << "\" -> \"" << Server::getInstance()->getItemConverter().fromProtocolIdToItem(this->_result) << "\" (cooking for " << this->_cookingTime << " ticks and get " << this->_experience << " xp)" << std::endl;
    }

    std::unique_ptr<Recipe> CampfireCooking::create(const nlohmann::json &recipe)
    {
        return (std::make_unique<CampfireCooking>(CampfireCooking(recipe)));
    }
};