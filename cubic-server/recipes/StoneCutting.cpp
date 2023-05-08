#include "StoneCutting.hpp"

#include "Server.hpp"

namespace Recipe {
    StoneCutting::StoneCutting(const nlohmann::json &recipe)
    {
        this->setCategory(recipe);
        this->setGroup(recipe);

        if (!recipe.contains("ingredient") || \
            !recipe.contains("result") || \
            !recipe.contains("count") || \
            !recipe["ingredient"].is_object() || \
            !recipe["result"].is_string() || \
            !recipe["count"].is_number_unsigned() || \
            !recipe["ingredient"].contains("item") || \
            !recipe["ingredient"]["item"].is_string())
            return;
        this->_ingredient = Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["ingredient"]["item"].get<std::string>());
        this->_result = Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["result"].get<std::string>());
        this->_count = recipe["count"].get<nlohmann::json::number_unsigned_t>();
        this->setValidity(true);
    }

    void StoneCutting::dump(void) const
    {
        std::cout << "\"" << Server::getInstance()->getItemConverter().fromProtocolIdToItem(this->_ingredient) << "\" -> \"" << Server::getInstance()->getItemConverter().fromProtocolIdToItem(this->_result) << "\" (x" << this->_count << ")" << std::endl;
    }

    std::unique_ptr<Recipe> StoneCutting::create(const nlohmann::json &recipe)
    {
        return (std::make_unique<StoneCutting>(StoneCutting(recipe)));
    }
};