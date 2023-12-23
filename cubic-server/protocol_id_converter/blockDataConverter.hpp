#ifndef CUBICSERVER_PROTOCOLIDCONVERTER_BLOCKDATACONVERTER_HPP
#define CUBICSERVER_PROTOCOLIDCONVERTER_BLOCKDATACONVERTER_HPP

#include <vector>

#include "types.hpp"

namespace Blocks {
/**
 * @brief Representation of a block with a name and a list of properties
 */
struct BlockData {
    BlockId id;
    std::string name;
    std::string displayName;
    float hardness;
    float resistance;
    uint8_t stackSize;
    bool diggable;
    std::string material;
    bool transparent;
    uint8_t emitLight;
    uint8_t filterLight;
    BlockId defaultState;
    BlockId minStateId;
    BlockId maxStateId;
    // States but already exist in blockIdConverter
    std::vector<std::pair<ItemId, bool>> harvestTool;
    // std::vector<BlockId> drops;
    std::string boundingBox;
};

class BlockDataConverter {
public:
    BlockDataConverter() {};
    ~BlockDataConverter() {};

    /**
     * @brief Initialize the block data converter
     *
     * @param path The path to the blocks.json file containing the block data
     * @return true if the initialization was successful
     * @return false if the initialization failed
     */
    bool initialize(const std::string &path = "blocks.json");

    /**
     * @brief Get the block data from a block name
     *
     * @param blockName The block name to get the data from
     * @return The block data of the block
     */
    const BlockData fromBlockNameToBlockData(const std::string &blockName) const;

    /**
     * @brief Get the block data from a block id
     *
     * @param blockId The block id to get the data from
     * @return The block data of the block
     */
    const BlockData fromBlockIdToBlockData(const BlockId &blockId) const;

private:
    std::vector<BlockData> _blocks;
};
}

#endif // CUBICSERVER_PROTOCOLIDCONVERTER_BLOCKDATACONVERTER_HPP
