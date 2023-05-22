#include "CraftingShaped.hpp"

#include "Server.hpp"

#include "protocol/PacketUtils.hpp"
#include "protocol/serialization/add.hpp"

namespace Recipe {
    CraftingShaped::MaybeItems::MaybeItems(void) : _empty(true)
    {}

    CraftingShaped::MaybeItems::MaybeItems(const std::shared_ptr<std::vector<ItemId>> &item) : _empty(false), _items(item)
    {}

    bool CraftingShaped::MaybeItems::isEmpty(void) const noexcept
    {
        return (this->_empty);
    }

    const std::shared_ptr<std::vector<ItemId>> &CraftingShaped::MaybeItems::getItems(void) const noexcept
    {
        return (this->_items);
    }

    CraftingShaped::CraftingShaped(const std::string &identifier, const nlohmann::json &recipe):
        Recipe(identifier, recipe)
    {
        // returns if any value is missing or does not have the right type
        if (!recipe.contains("pattern") || \
            !recipe.contains("key") || \
            !recipe.contains("result") || \
            !recipe["pattern"].is_array() || \
            !recipe["key"].is_object() || \
            !recipe["result"].is_object() || \
            !recipe["result"].contains("item") || \
            !recipe["result"]["item"].is_string())
            return;
        // get the recipe values
        this->_result = Server::getInstance()->getItemConverter().fromItemToProtocolId(recipe["result"]["item"].get<std::string>());
        if (recipe["result"].contains("count") && recipe["result"]["count"].is_number_unsigned())
            this->_count = recipe["result"]["count"].get<nlohmann::json::number_unsigned_t>();
        else
            this->_count = 1;

        this->_y = recipe["pattern"].size();
        for (size_t pattern_line_pos = 0; pattern_line_pos < recipe["pattern"].size(); pattern_line_pos++) {
            if (!recipe["pattern"][pattern_line_pos].is_string())
                return;
            this->_pattern.push_back(std::vector<MaybeItems>());

            std::string pattern_line = recipe["pattern"][pattern_line_pos].get<std::string>();

            this->_x = std::max(pattern_line.size(), this->_x);

            for (const auto &pattern_item : pattern_line) {
                if (pattern_item == ' ')
                    this->_pattern[pattern_line_pos].push_back(MaybeItems());
                else {
                    if (!recipe["key"].contains(&pattern_item))
                        return;
                    if (!this->getKey(pattern_item, recipe["key"][&pattern_item]))
                        return;
                    this->_pattern[pattern_line_pos].push_back(MaybeItems(this->_key[pattern_item]));
                }
            }
        }

        this->setValidity(true);
    }

    void CraftingShaped::dump(void) const
    {
        std::stringstream stream;

        for (const auto &line : this->_pattern) {
            for (const auto &item : line) {
                if (item.isEmpty())
                    stream << ' ';
                else {
                    bool found_key = false;

                    for (const auto &[key, items] : this->_key) {
                        if (item.getItems() == items) {
                            stream << key;
                            found_key = true;
                            break;
                        }
                    }
                    if (!found_key)
                        stream << '!';
                }
            }
            LINFO(stream.str());
            stream.str("");
        }
        for (const auto &[key, items] : this->_key) {
            stream << '\''<< key << "\': [";
            bool first_item = true;

            for (const auto &item : *items) {
                if (first_item)
                    first_item = false;
                else
                    stream << ", ";
                stream << '\"' << Server::getInstance()->getItemConverter().fromProtocolIdToItem(item) << '\"';
            }
            stream << ']';
            LINFO(stream.str());
            stream.str("");
        }
        stream << " -> " << Server::getInstance()->getItemConverter().fromProtocolIdToItem(this->_result) << " (x" << this->_count << ')';
        LINFO(stream.str());
    }

    void CraftingShaped::insertToPayload(std::vector<uint8_t> &payload) const
    {
        protocol::Slot slot{true, 0, 1};
        int category = 0;

        if (this->getCategory() == "building")
            category = 0;
        else if (this->getCategory() == "redstone")
            category = 1;
        else if (this->getCategory() == "equipment")
            category = 2;
        else // "misc" and other
            category = 3;

        protocol::serialize(payload,
            "minecraft:crafting_shapeless", protocol::addString,
            this->getIdentifier(), protocol::addString,
            this->_x, protocol::addVarInt,
            this->_y, protocol::addVarInt,
            this->getGroup(), protocol::addString,
            category, protocol::addVarInt,
            this->_x * this->_y, protocol::addVarInt
        );

        for (size_t y = 0; y < this->_y; y++) { // horizontally
            for (size_t x = 0; x < this->_x; x++) { // vertically
                if (y >= this->_pattern.size() || x >= this->_pattern[y].size()) { // out of range
                    // out of range of pattern data: add an empty list of slot (size 0 with nothing after)
                    protocol::serialize(payload,
                        0, protocol::addVarInt
                    );
                } else { // in range
                    if (this->_pattern[y][x].isEmpty()) { // empty
                        // no ingredient at this position: add an empty list of slot (size 0 with nothing after)
                        protocol::serialize(payload,
                            0, protocol::addVarInt
                        );
                    } else { // in range and items
                        // list of ingredient found at this position:
                        protocol::serialize(payload,
                            this->_pattern[y][x].getItems()->size(), protocol::addVarInt // add slot array size
                        );
                        for (const ItemId &item : *this->_pattern[y][x].getItems().get()) {
                            slot.itemID = item;
                            protocol::serialize(payload,
                                slot, protocol::addSlot // add slot
                            );
                        }
                    }
                }
            }
        }

        slot.itemID = this->_result;
        slot.itemCount = this->_count;
        protocol::serialize(payload,
            slot, protocol::addSlot
        );
    }

    bool CraftingShaped::getKey(char key, const nlohmann::json &content)
    {
        if (content.is_object()) {
            if (!content.contains("item") || !content["item"].is_string())
                return (false);
            this->_key[key] = std::make_shared<std::vector<ItemId>>(std::vector<ItemId>());
            this->_key[key]->push_back(Server::getInstance()->getItemConverter().fromItemToProtocolId(content["item"].get<std::string>()));
            return (true);
        } else if (content.is_array()) {
            this->_key[key] = std::make_shared<std::vector<ItemId>>(std::vector<ItemId>());
            for (const auto &item : content) {
                if (!item.is_object() || !item.contains("item") || !item["item"].is_string()) {
                    this->_key[key].reset();
                    return (false);
                }
                this->_key[key]->push_back(Server::getInstance()->getItemConverter().fromItemToProtocolId(item["item"].get<std::string>()));
            }
            return (true);
        }
        return (false);
    }

    std::unique_ptr<Recipe> CraftingShaped::create(const std::string &identifier, const nlohmann::json &recipe)
    {
        return (std::make_unique<CraftingShaped>(CraftingShaped(identifier, recipe)));
    }
};