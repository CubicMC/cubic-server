#include "Section.hpp"
#include "logging/Logger.hpp"
#include "types.hpp"
#include <cstdint>
#include <stdexcept>

world_storage::Section::Section() noexcept:
    _blocks(BLOCKS_BIT_STORAGE_SIZE),
    _biomes(BIOME_BIT_STORAGE_SIZE),
    _skyLight(SKYLIGHT_BIT_STORAGE_SIZE),
    _blockLight(BLOCKLIGHT_BIT_STORAGE_SIZE)
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

void world_storage::Section::updateSkyLight(const Position &pos, uint8_t light)
{
    // TODO: do something, like calculate the light LOL
    setSkyLight(pos, light);
}

void world_storage::Section::setSkyLight(const Position &pos, uint8_t light)
{
    if (getSkyLight(pos) != 0 && light == 0)
        _skyLightCount--;
    if (getSkyLight(pos) == 0 && light != 0)
        _skyLightCount++;
    _skyLight.set(calculateSectionBlockIdx(pos), light);
}

void world_storage::Section::updateBlockLight(const Position &pos, uint8_t light)
{
    // TODO: do something, like calculate the light LOL
    setBlockLight(pos, light);
}

void world_storage::Section::setBlockLight(const Position &pos, uint8_t light)
{
    if (getBlockLight(pos) != 0 && light == 0)
        _blockLightCount--;
    if (getBlockLight(pos) == 0 && light != 0)
        _blockLightCount++;
    _blockLight.set(calculateSectionBlockIdx(pos), light);
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

uint8_t world_storage::Section::getSkyLight(const Position &pos) const
{
    if (pos >= SECTION_WIDTH)
        throw std::out_of_range("Position is out of range");
    return this->_skyLight.get(calculateSectionBlockIdx(pos));
}

uint8_t world_storage::Section::getSkyLight(uint64_t idx) const
{
    return this->_skyLight.get(idx);
}

uint8_t world_storage::Section::getBlockLight(const Position &pos) const
{
    if (pos >= SECTION_WIDTH)
        throw std::out_of_range("Position is out of range");
    return this->_blockLight.get(calculateSectionBlockIdx(pos));
}

uint8_t world_storage::Section::getBlockLight(uint64_t idx) const
{
    return this->_blockLight.get(idx);
}
