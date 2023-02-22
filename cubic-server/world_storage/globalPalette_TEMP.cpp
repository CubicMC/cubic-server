#include "globalPalette_TEMP.hpp"
#include "Block.hpp"

GlobalBlockId world_storage::getGlobalPaletteIdFromBlock(const world_storage::Block &block)
{
    return world_storage::getGlobalPaletteIdFromBlockName(block.toString());
}
