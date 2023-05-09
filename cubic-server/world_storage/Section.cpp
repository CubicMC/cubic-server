#include "Section.hpp"
#include "logging/Logger.hpp"

world_storage::Section::Section() noexcept:
    _blocks(4),
    _biomes(3)
    // _blockLight(4),
    // _skyLight(4)
{
    this->_blockPalette.setCount(0, SECTION_3D_SIZE);
    this->_biomePalette.setCount(0, BIOME_SECTION_3D_SIZE);
}

void world_storage::Section::updateBlock(const Position &pos, int32_t block)
{
    if (pos >= SECTION_WIDTH || pos < 0)
        throw std::out_of_range("Position is out of range");
    // TODO: Update the blocklight, heightmap, etc...
    this->setBlock(pos, block);
}

void world_storage::Section::setBlock(const Position &pos, int32_t block)
{
    if (pos >= SECTION_WIDTH || pos < 0)
        throw std::out_of_range("Position is out of range");

    auto oldBits = this->_blockPalette.getBits();
    this->_blockPalette.remove(this->_blocks.get(calculateSectionBlockIdx(pos)));
    this->_blockPalette.add(block);
    if (oldBits != this->_blockPalette.getBits() && this->_blockPalette.getBits() != 0)
        this->_blocks.setValueSize(this->_blockPalette.getBits());

    this->_blocks.set(calculateSectionBlockIdx(pos), this->_blockPalette.getId(block));
}

void world_storage::Section::updateBiome(const Position &pos, int32_t biome)
{
    if (pos >= BIOME_SECTION_WIDTH || pos < 0)
        throw std::out_of_range("Position is out of range");
    // TODO: Is there anything to do here?
    this->setBiome(pos, biome);
}

void world_storage::Section::setBiome(const Position &pos, int32_t biome)
{
    if (pos >= BIOME_SECTION_WIDTH || pos < 0)
        throw std::out_of_range("Position is out of range");

    auto oldBits = this->_biomePalette.getBits();
    this->_biomePalette.add(biome);
    if (oldBits != this->_biomePalette.getBits() && this->_biomePalette.getBits() != 0)
        this->_biomes.setValueSize(this->_biomePalette.getBits());

    this->_biomes.set(calculateSectionBiomeIdx(pos), this->_biomePalette.getId(biome));
}

int32_t world_storage::Section::getBlock(const Position &pos) const
{
    if (pos >= SECTION_WIDTH)
        throw std::out_of_range("Position is out of range");
    return this->_blocks.get(calculateSectionBlockIdx(pos));
}

int32_t world_storage::Section::getBiome(const Position &pos) const
{
    if (pos >= BIOME_SECTION_WIDTH)
        throw std::out_of_range("Position is out of range");
    return this->_biomes.get(calculateSectionBiomeIdx(pos));
}

int32_t world_storage::Section::getBlock(uint64_t idx) const
{
    return this->_blocks.get(idx);
}

int32_t world_storage::Section::getBiome(uint64_t idx) const
{
    return this->_biomes.get(idx);
}
