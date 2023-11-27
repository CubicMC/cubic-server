#include "blockDataConverter.hpp"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <type_traits>

#include <nlohmann/json.hpp>

#include "logging/logging.hpp"
#include "nlohmann/json_fwd.hpp"

bool Blocks::BlockDataConverter::initialize(const std::string &path)
{
    if (!std::filesystem::exists(path)) {
        LERROR("File {} not found !", path);
        return false;
    }
    nlohmann::json file = nlohmann::json::parse(std::ifstream(path));
    for (auto block : file.items()) {
        Blocks::BlockData b;
        b.id = block.value()["id"];
        b.name = block.value()["name"];
        b.displayName = block.value()["displayName"];
        b.hardness = block.value()["hardness"];
        b.resistance = block.value()["resistance"];
        b.stackSize = block.value()["stackSize"];
        b.diggable = block.value()["diggable"];
        b.material = block.value()["material"];
        b.transparent = block.value()["transparent"];
        b.emitLight = block.value()["emitLight"];
        b.filterLight = block.value()["filterLight"];
        b.defaultState = block.value()["defaultState"];
        b.minStateId = block.value()["minStateId"];
        b.maxStateId = block.value()["maxStateId"];
        // states
        for (auto tool = block.value()["harvestTools"].rbegin(); tool != block.value()["harvestTools"].rend(); ++tool)
            b.harvestTool.push_back({stoi(tool.key()), tool.value()});
        // b.drops = block.value()["drops"];
        b.boundingBox = block.value()["boundingBox"];
        this->_blocks.push_back(b);
    }
    return true;
}

const Blocks::BlockData Blocks::BlockDataConverter::fromBlockNameToBlockData(const std::string &blockName) const
{
    const auto block = std::find_if(this->_blocks.begin(), this->_blocks.end(), [blockName](const Blocks::BlockData &block) {
        return block.name == blockName;
    });
    return *(block != this->_blocks.end() ? block : this->_blocks.begin());
}

const Blocks::BlockData Blocks::BlockDataConverter::fromBlockIdToBlockData(const BlockId &blockId) const
{
    const auto block = std::find_if(this->_blocks.begin(), this->_blocks.end(), [blockId](const Blocks::BlockData &block) {
        return block.minStateId <= blockId && blockId <= block.maxStateId;
    });
    return *(block != this->_blocks.end() ? block : this->_blocks.begin());
}
