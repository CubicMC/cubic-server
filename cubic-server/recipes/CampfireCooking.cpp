#include "CampfireCooking.hpp"

#include "Server.hpp"

#include "protocol/PacketUtils.hpp"
#include "protocol/serialization/add.hpp"

namespace Recipe {
    CampfireCooking::CampfireCooking(const std::string &identifier, const nlohmann::json &recipe):
        Recipe(identifier, recipe)
    {
        // returns if any value is missing or does not have the right type
        if (!recipe.contains("ingredient") || \
            !recipe.contains("result") || \
            !recipe.contains("experience") || \
            !recipe.contains("cookingtime") || \
            (
                !recipe["ingredient"].is_object() && \
                !recipe["ingredient"].is_array()
            ) || \
            !recipe["result"].is_string() || \
            !recipe["experience"].is_number() || \
            !recipe["cookingtime"].is_number_unsigned())
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
            stream << "\"" << Server::getInstance()->getItemConverter().fromProtocolIdToItem(ingredient) << "\"";
        }
        stream << "] -> \"" << Server::getInstance()->getItemConverter().fromProtocolIdToItem(this->_result) << "\" (cooking for " << this->_cookingTime << " ticks and get " << this->_experience << " xp)";
        LINFO(stream.str());
    }

    void CampfireCooking::insertToPayload(std::vector<uint8_t> &payload) const
    {
        protocol::Slot slot{true, 0, 1};
        int category = 0;

        if (this->getCategory() == "food")
            category = 0;
        else if (this->getCategory() == "blocks")
            category = 1;
        else // "misc" and other
            category = 2;

        protocol::serialize(payload,
            "minecraft:campfire_cooking", protocol::addIdentifier,
            this->getIdentifier(), protocol::addIdentifier,
            this->getGroup(), protocol::addString,
            category, protocol::addVarInt,
            this->_ingredients.size(), protocol::addVarInt
        );

        for (const ItemId &ingredient : this->_ingredients) {
            slot.itemID = ingredient;
            protocol::serialize(payload,
                slot, protocol::addSlot
            );
        }

        slot.itemID = this->_result;
        protocol::serialize(payload,
            slot, protocol::addSlot,
            this->_experience, protocol::addFloat,
            this->_cookingTime, protocol::addVarInt
        );
    }

    std::unique_ptr<Recipe> CampfireCooking::create(const std::string &identifier, const nlohmann::json &recipe)
    {
        return (std::make_unique<CampfireCooking>(CampfireCooking(identifier, recipe)));
    }
};