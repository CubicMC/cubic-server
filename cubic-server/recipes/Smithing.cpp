#include "Smithing.hpp"

#include "Server.hpp"

namespace Recipe {
    Smithing::Smithing(const nlohmann::json &recipe):
        Recipe(recipe)
    {
        // returns if any value is missing or does not have the right type
        if (!recipe.contains("base") || \
            !recipe.contains("addition") || \
            !recipe.contains("result") || \
            !recipe["base"].is_object() || \
            !recipe["addition"].is_object() || \
            !recipe["result"].is_object() || \
            !recipe["base"].contains("item") || \
            !recipe["base"]["item"].is_string() || \
            !recipe["addition"].contains("item") || \
            !recipe["addition"]["item"].is_string() || \
            !recipe["result"].contains("item") || \
            !recipe["result"]["item"].is_string())
            return;
        // get the recipe values
        this->_base = Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["base"]["item"].get<std::string>());
        this->_addition = Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["addition"]["item"].get<std::string>());
        this->_result = Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["result"]["item"].get<std::string>());
        this->setValidity(true);
    }

    void Smithing::dump(void) const
    {
        LINFO("\"", Server::getInstance()->getItemConverter().fromProtocolIdToItem(this->_base), "\" + \"", Server::getInstance()->getItemConverter().fromProtocolIdToItem(this->_addition), "\" = \"", Server::getInstance()->getItemConverter().fromProtocolIdToItem(this->_result), "\"");
    }

    void Smithing::insertToPayload(std::vector<uint8_t> &payload) const
    {

    }

    std::unique_ptr<Recipe> Smithing::create(const nlohmann::json &recipe)
    {
        return (std::make_unique<Smithing>(Smithing(recipe)));
    }
};