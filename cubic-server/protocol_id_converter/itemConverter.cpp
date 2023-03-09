#include <fstream>
#include <filesystem>

#include "itemConverter.hpp"
#include "logging/Logger.hpp"

void Items::ItemConverter::initialize(const std::string path) {
    if (!std::filesystem::exists(path)) {
        LERROR("File " << path << " not found !");
        return;
    }
    nlohmann::json file = nlohmann::json::parse(std::ifstream("registries.json"));
    for(auto item : file["minecraft:item"]["entries"].items()) {
        Items::InternalItem i;
        i.name = item.key();
        i.protocolId = item.value()["protocol_id"];
        this->_items.push_back(i);
    }
}

Items::ItemId Items::ItemConverter::fromItemToProtocolId(std::string name) const {
    auto item = std::find_if(this->_items.begin(), this->_items.end(), [&name](Items::InternalItem i) {
        return i.name == name;
    });
    if (item == this->_items.end()) {
        LERROR("Item not found in palette (name: " << name << ")");
        return 0;
    }
    return item->protocolId;
}

std::string Items::ItemConverter::fromProtocolIdToItem(ItemId id) const {
    auto item = std::find_if(this->_items.begin(), this->_items.end(), [&id](Items::InternalItem i) {
        return i.protocolId == id;
    });
    if (item == this->_items.end()) {
        LERROR("Item not found in palette (id: " << id << ")");
        return "minecraft:air";
    }
    return item->name;
}
