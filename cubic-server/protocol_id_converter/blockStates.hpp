#include <cstdint>
#include <string>
#include <vector>

#include "nlohmann/json.hpp"

namespace Blocks {
    // Using int32_t because it's the same size as a varint
    typedef int32_t BlockId;

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
        uint16_t baseProtocolId;
        uint16_t maxProtocolId;
    };

    /**
     * @brief Representation of a block with a name and a list of properties
     */
    struct Block {
        std::string name;
        std::vector<std::pair<std::string, std::string>> properties;
    };

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
            BlockId fromBlockToProtocolId(Block block) const;
            /**
             * @brief Convert a protocol id to a block
             * @param id The protocol id to convert
             * @return The block corresponding to the protocol id
             */
            Block fromProtocolIdToBlock(BlockId id) const;
            /**
             * @brief Initialize the global palette with the blocks from the given json file
             * @param path The path to the json file
             */
            void initialize(std::string path = "blocks.json");
        private:
            std::vector<InternalBlock> _blocks; // The internal blocks
    };
}
