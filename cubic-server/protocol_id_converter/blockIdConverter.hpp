#ifndef CUBICSERVER_PROTOCOLIDCONVERTER_BLOCKIDCONVERTER_HPP
#define CUBICSERVER_PROTOCOLIDCONVERTER_BLOCKIDCONVERTER_HPP

#include <optional>
#include <string>
#include <vector>

#include <boost/container/flat_map.hpp>

#include "types.hpp"

namespace Blocks {
/**
 * @brief Internal representation of a block property (only used in the GlobalPalette class)
 */
struct InternalProperty {
    std::string name;
    std::vector<std::string> values;
    uint8_t baseWeight;
};

/**
 * @brief Internal representation of a block (only used in the GlobalPalette class)
 */
struct InternalBlock {
    std::string name;
    std::vector<InternalProperty> properties;
    std::vector<std::pair<std::string, std::string>> defaultProperties;
    uint16_t baseProtocolId;
    uint16_t maxProtocolId;
};

/**
 * @brief Representation of a block with a name and a list of properties
 */
struct Block {
    Block() {};
    Block(std::string name, std::vector<std::pair<std::string, std::string>> properties):
        name(std::move(name)),
        properties(std::move(properties))
    {
    }
    std::string name;
    std::vector<std::pair<std::string, std::string>> properties;
};

// minecraft:grass_block[snowy=false]

/**
 * @brief Global palette of blocks used to convert from protocol id to block and vice versa
 */
class GlobalPalette {
public:
    GlobalPalette() {};
    ~GlobalPalette() {};

    /**
     * @brief Convert a block to a protocol id
     * @param block The block to convert
     * @return The protocol id of the block
     */
    BlockId fromBlockToProtocolId(Block &block) const;
    BlockId fromBlockToProtocolId(const std::string &block) const;

    /**
     * @brief Convert a protocol id to a block
     * @param id The protocol id to convert
     * @return The block corresponding to the protocol id
     */
    Block fromProtocolIdToBlock(BlockId id);

    /**
     * @brief Initialize the global palette with the blocks from the given json file
     * @param path The path to the json file
     * @return bool True if the initialization was successful, false otherwise
     */
    bool initialize(const std::string &path = "blocks.json");

    /**
     * @brief Fetch a block from the cache
     *
     * @param protocolID The protocolID of the block to fetch
     * @return std::optional<std::reference_wrapper<const Block>> The block that has been fetched, empty if not in cache
     */
    std::optional<std::reference_wrapper<const Block>> fetchFromCache(BlockId protocolID) const;

private:
    std::vector<InternalBlock> _blocks; // The internal blocks

    boost::container::flat_map<BlockId, Block> _cache;
};
}

#endif // CUBICSERVER_PROTOCOLIDCONVERTER_BLOCKSTATES_HPP
