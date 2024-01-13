#include "blockIdConverter.hpp"

#include <filesystem>
#include <fstream>
#include <functional>
#include <iterator>
#include <optional>
#include <type_traits>

#include <nlohmann/json.hpp>

#include "logging/logging.hpp"
#include "types.hpp"

bool Blocks::GlobalPalette::initialize(const std::string &path)
{
    if (!std::filesystem::exists(path)) {
        LERROR("File {} not found !", path);
        return false;
    }
    nlohmann::json file = nlohmann::json::parse(std::ifstream(path));
    for (auto block : file.items()) {
        Blocks::InternalBlock b;
        b.name = block.key();
        if (block.value().size() == 2) {
            int maxThingy = 0; // Sorry for the name I don't how to call it
            int weight = 1;

            for (auto property = block.value()["properties"].rbegin(); property != block.value()["properties"].rend(); ++property) {
                Blocks::InternalProperty p;
                p.name = property.key();
                p.baseWeight = weight;
                for (auto value : property.value())
                    p.values.push_back(value);
                maxThingy += weight * (p.values.size() - 1);
                weight = maxThingy + 1;
                b.properties.push_back(p);
            }
        }
        b.baseProtocolId = block.value()["states"][0]["id"];
        b.maxProtocolId = block.value()["states"][block.value()["states"].size() - 1]["id"];

        // Init default state
        auto defaultState = std::find_if(block.value()["states"].begin(), block.value()["states"].end(), [](const nlohmann::json &state) {
            return state.contains("default") && state["default"] == true;
        });
        if (defaultState == block.value()["states"].end()) {
            LERROR("Default state not found for block {}", block.key());
            return false;
        }
        if (defaultState.value().contains("properties")) {
            for (auto property : defaultState.value()["properties"].items())
                b.defaultProperties.push_back({property.key(), property.value()});
        }
        this->_blocks.push_back(b);
    }
    return true;
}

BlockId Blocks::GlobalPalette::fromBlockToProtocolId(const std::string &blockName) const
{
    Blocks::Block block = {blockName, {}};

    auto internalBlock = std::find_if(this->_blocks.begin(), this->_blocks.end(), [&block](const Blocks::InternalBlock &b) {
        return b.name == block.name;
    });

    if (internalBlock == this->_blocks.end())
        return 0;

    for (auto property : internalBlock->defaultProperties)
        block.properties.push_back({property.first, property.second});

    return this->fromBlockToProtocolId(block);
}

BlockId Blocks::GlobalPalette::fromBlockToProtocolId(Blocks::Block &block) const
{
    auto internalBlock = std::find_if(this->_blocks.begin(), this->_blocks.end(), [&block](const Blocks::InternalBlock &b) {
        return b.name == block.name;
    });
    if (internalBlock == this->_blocks.end()) {
        LERROR("Block not found in palette (name: {})", block.name);
        return 0;
    }
    if (block.properties.size() != internalBlock->properties.size()) {
        for (auto &[h, hh] : internalBlock->defaultProperties) {
            bool found = false;
            for (auto &[c, cc] : block.properties) {
                if (c == h) {
                    found = true;
                    break;
                }
            }
            if (!found)
                block.properties.push_back({h, hh});
        }
    }
    if (block.properties.size() == 0 && internalBlock->properties.size() == 0)
        return internalBlock->baseProtocolId;

    BlockId id = internalBlock->baseProtocolId;
    for (auto property : block.properties) {
        auto internalProperty = std::find_if(internalBlock->properties.begin(), internalBlock->properties.end(), [&property](const Blocks::InternalProperty &p) {
            return p.name == property.first;
        });
        if (internalProperty == internalBlock->properties.end()) {
            LERROR("Property not found (name: {})", property.first);
            return 0;
        }
        auto value = std::find(internalProperty->values.begin(), internalProperty->values.end(), property.second);
        if (value == internalProperty->values.end()) {
            LERROR("Value not found (name: {})", property.second);
            return 0;
        }
        id += internalProperty->baseWeight * (value - internalProperty->values.begin());
    }
    return id;
}

Blocks::Block Blocks::GlobalPalette::fromProtocolIdToBlock(BlockId id)
{
    BlockId originalId = id;
    for (auto b : this->_blocks) {
        if (id < b.baseProtocolId || id > b.maxProtocolId)
            continue;
        Blocks::Block block;
        block.name = b.name;
        if (b.properties.size() == 0) {
            if (!_cache.contains(originalId))
                _cache.emplace(originalId, block);
            return block;
        }
        id -= b.baseProtocolId;
        for (auto it = b.properties.rbegin(); it != b.properties.rend(); ++it) {
            auto property = *it;
            block.properties.push_back({property.name, property.values[id / property.baseWeight]});
            id %= property.baseWeight;
        }
        if (!_cache.contains(originalId))
            _cache.emplace(originalId, block);
        return block;
    }
    LERROR("Block not found in palette (id: {})", id);
    return {"minecraft:air", {}};
}

std::optional<std::reference_wrapper<const Blocks::Block>> Blocks::GlobalPalette::fetchFromCache(BlockId protocolID) const
{
    if (!_cache.contains(protocolID))
        return std::nullopt;
    return std::optional<std::reference_wrapper<const Blocks::Block>>(std::reference_wrapper<const Blocks::Block>(_cache.at(protocolID)));
}
