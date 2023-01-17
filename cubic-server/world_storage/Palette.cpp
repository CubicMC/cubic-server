#include "Palette.hpp"
#include "ChunkColumn.hpp"
#include "globalPalette_TEMP.hpp"
#include "protocol/serialization/addPrimaryType.hpp"
#include "logging/Logger.hpp"

void world_storage::Palette::addBlock(const Block &block)
{
    this->addBlock(block.toString());
}

uint64_t world_storage::Palette::getBlockId(const Block &block) const
{
    return this->getBlockId(block.toString());
}

world_storage::Block world_storage::Palette::getBlock(uint64_t id) const
{
    return getBlockFromGlobalPaletteId(_nameToId.at(id));
}
