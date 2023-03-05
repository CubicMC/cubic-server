#include <fstream>
#include <filesystem>

#include "blockStates.hpp"
#include "logging/Logger.hpp"

void Blocks::GlobalPalette::initialize(std::string path) {
    if (!std::filesystem::exists(path)) {
        LERROR("File " << path << " not found !");
        return;
    }
    nlohmann::json file = nlohmann::json::parse(std::ifstream("blocks.json"));
    for(auto block : file.items()) {
        Blocks::InternalBlock b;
        b.name = block.key();
        if (block.value().size() == 2) {
            int maxThingy = 0; // Sorry for the name I don't how to call it
            int wheight = 1;
            for (auto property : block.value()["properties"].items()) {
                Blocks::InternalProperty p;
                p.name = property.key();
                p.baseWeight = wheight;
                for (auto value : property.value()) {
                    p.values.push_back(value);
                }
                maxThingy += wheight * (p.values.size() - 1);
                wheight = maxThingy + 1;
                b.properties.push_back(p);
            }
        }
        b.baseProtocolId = block.value()["states"][0]["id"];
        b.maxProtocolId = block.value()["states"][block.value()["states"].size() - 1]["id"];
        this->_blocks.push_back(b);
    }
}

Blocks::BlockId Blocks::GlobalPalette::fromBlockToProtocolId(Blocks::Block block) const {
    auto internalBlock = std::find_if(this->_blocks.begin(), this->_blocks.end(), [&block](Blocks::InternalBlock b) {
        return b.name == block.name;
    });
    if (internalBlock == this->_blocks.end()) {
        LERROR("Block not found in palette (name: " << block.name << ")");
        return 0;
    }
    if (block.properties.size() != internalBlock->properties.size()) {
        LERROR("Block properties size mismatch with block " << block.name);
        return 0;
    }
    if (block.properties.size() == 0 && internalBlock->properties.size() == 0)
        return internalBlock->baseProtocolId;

    BlockId id = internalBlock->baseProtocolId;
    for (auto property : block.properties) {
        auto internalProperty = std::find_if(internalBlock->properties.begin(), internalBlock->properties.end(), [&property](Blocks::InternalProperty p) {
            return p.name == property.first;
        });
        if (internalProperty == internalBlock->properties.end()) {
            LERROR("Property not found (name: " << property.first << ")");
            return 0;
        }
        auto value = std::find(internalProperty->values.begin(), internalProperty->values.end(), property.second);
        if (value == internalProperty->values.end()) {
            LERROR("Value not found (name: " << property.second << ")");
            return 0;
        }
        id += internalProperty->baseWeight * (value - internalProperty->values.begin());
    }
    return id;
}

Blocks::Block Blocks::GlobalPalette::fromProtocolIdToBlock(Blocks::BlockId id) const {
    for (auto b : this->_blocks) {
        if (id >= b.baseProtocolId && id <= b.maxProtocolId) {
            Blocks::Block block;
            block.name = b.name;
            if (b.properties.size() == 0)
                return block;
            id -= b.baseProtocolId;
            for (auto property : b.properties) {
                block.properties.push_back({property.name, property.values[id / property.baseWeight]});
                id %= property.baseWeight;
            }
            return block;
        }
    }
    LERROR("Block not found in palette (id: " << id << ")");
    return {"minecraft:air", {}};
}
