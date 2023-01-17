#include "globalPalette_TEMP.hpp"
#include "Block.hpp"

uint32_t world_storage::getGlobalPaletteIdFromBlock(const world_storage::Block &block)
{
    return world_storage::getGlobalPaletteIdFromBlockName(block.toString());
}
