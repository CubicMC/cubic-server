#include "Smithing.hpp"

#include "Server.hpp"

#include "protocol/PacketUtils.hpp"
#include "protocol/serialization/add.hpp"

namespace Recipe {
    Smithing::Smithing(const std::string &identifier, const nlohmann::json &recipe):
        Recipe(identifier, recipe)
    {
        // returns if any value is missing or does not have the right type
        if (!recipe.contains("base") || \
            !recipe.contains("addition") || \
            !recipe.contains("result") || \
            (
                !recipe["base"].is_object() && \
                !recipe["base"].is_array()
            ) || \
            (
                !recipe["addition"].is_object() && \
                !recipe["addition"].is_array()
            ) || \
            !recipe["result"].is_object() || \
            !recipe["result"].contains("item") || \
            !recipe["result"]["item"].is_string())
            return;

        // get the recipe values
        // get base items
        if (recipe["base"].is_object()) { // if only one base
            if (recipe["base"].contains("item") && recipe["base"]["item"].is_string())
                this->_bases.insert(Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["base"]["item"].get<std::string>()));
            else
                return;
        } else if (recipe["base"].is_array()) {
            for (const auto &base : recipe["base"]) { // if multiple base items
                if (base.is_object() && base.contains("item") && base["item"].is_string())
                    this->_bases.insert(Server::getInstance()->getItemConverter().fromItemToProtocolId(base["item"].get<std::string>()));
                else
                    return;
            }
        } else
            return;

        // get addition items
        if (recipe["addition"].is_object()) { // if only one addition
            if (recipe["addition"].contains("item") && recipe["addition"]["item"].is_string())
                this->_additions.insert(Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["addition"]["item"].get<std::string>()));
            else
                return;
        } else if (recipe["addition"].is_array()) {
            for (const auto &addition : recipe["addition"]) { // if multiple addition items
                if (addition.is_object() && addition.contains("item") && addition["item"].is_string())
                    this->_additions.insert(Server::getInstance()->getItemConverter().fromItemToProtocolId(addition["item"].get<std::string>()));
                else
                    return;
            }
        } else
            return;

        this->_result = Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["result"]["item"].get<std::string>());
        this->setValidity(true);
    }

    void Smithing::dump(void) const
    {
        std::stringstream stream;
        bool first = true;

        stream << '[';
        for (const auto &base : this->_bases) {
            if (first)
                first = false;
            else
                stream << ", ";
            stream << "\"" << Server::getInstance()->getItemConverter().fromProtocolIdToItem(base) << "\"";
        }
        stream << "] + [";
        for (const auto &addition : this->_additions) {
            if (first)
                first = false;
            else
                stream << ", ";
            stream << "\"" << Server::getInstance()->getItemConverter().fromProtocolIdToItem(addition) << "\"";
        }

        stream << "] -> \"" << Server::getInstance()->getItemConverter().fromProtocolIdToItem(this->_result);
        LINFO(stream.str());
    }

    void Smithing::insertToPayload(std::vector<uint8_t> &payload) const
    {
        protocol::Slot slot{true, 0, 1};

        protocol::serialize(payload,
            "minecraft:smithing", protocol::addString,
            this->getIdentifier(), protocol::addString,
            this->_bases.size(), protocol::addVarInt
        );

        for (const ItemId &base : this->_bases) {
            slot.itemID = base;
            protocol::serialize(payload,
                slot, protocol::addSlot
            );
        }

        protocol::serialize(payload,
            this->_additions.size(), protocol::addVarInt
        );

        for (const ItemId &addition : this->_additions) {
            slot.itemID = addition;
            protocol::serialize(payload,
                slot, protocol::addSlot
            );
        }

        slot.itemID = this->_result;
        protocol::serialize(payload,
            slot, protocol::addSlot
        );
    }

    std::unique_ptr<Recipe> Smithing::create(const std::string &identifier, const nlohmann::json &recipe)
    {
        return (std::make_unique<Smithing>(Smithing(identifier, recipe)));
    }
};