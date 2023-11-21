#include "blockDataConverter.hpp"

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
        // b.defaultState = block.value()["defaultState"];
        // b.minState = block.value()["minState"];
        // b.maxState = block.value()["maxState"];
        b.harvestTool = [block]() {
            auto harvestTools = std::vector<std::pair<ItemId, bool>> {};
            for (auto tool = block.value()["harvestTools"].rbegin(); tool != block.value()["harvestTools"].rend(); ++tool)
                harvestTools.push_back({stoi(tool.key()), tool.value()});
            return harvestTools;
        }();
        // b.drops = block.value()["drops"];
        b.boundingBox = block.value()["boundingBox"];
        this->_blocks.push_back(b);
    }
    return true;
}

Blocks::BlockData Blocks::BlockDataConverter::fromBlockNameToBlockData(const std::string &blockName) const { }

Blocks::BlockData Blocks::BlockDataConverter::fromBlockIdToBlockData(const BlockId &blockId) const { }
