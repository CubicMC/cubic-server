#include "Section.hpp"
#include "blocks.hpp"
#include "logging/logging.hpp"
#include "options.hpp"
#include "types.hpp"
#include "utility/PseudoRandomGenerator.hpp"
#include "utility/RandomTickBlockFunctions.hpp"
#include "world_storage/ChunkColumn.hpp"
#include <cstdint>
#include <stdexcept>

world_storage::Section::Section() noexcept:
    _blocks(0),
    _biomes(0),
    _skyLight(4),
    _blockLight(4),
    _skyLightCount(0),
    _blockLightCount(0)
{
    // this->_blockPalette.setCount(0, SECTION_3D_SIZE);
    // this->_biomePalette.setCount(0, BIOME_SECTION_3D_SIZE);
}

world_storage::Section::Section(world_storage::Section &&section) noexcept:
    _blocks(section._blocks),
    _biomes(section._biomes),
    _blockPalette(std::move(section._blockPalette)),
    _biomePalette(std::move(section._biomePalette)),
    _skyLight(section._skyLight),
    _blockLight(section._blockLight),
    _skyLightCount(section._skyLightCount),
    _blockLightCount(section._blockLightCount)
{
}

void world_storage::Section::updateBlock(const Position &pos, int32_t block)
{
    if (pos >= SECTION_WIDTH || pos < 0)
        throw std::out_of_range("Position is out of range");
    // TODO: Update the blocklight, heightmap, etc...
    this->setBlock(pos, block);
}

void world_storage::Section::updateBlock(uint64_t idx, int32_t block)
{
    if (idx >= SECTION_3D_SIZE)
        throw std::out_of_range("Position is out of range");
    // TODO: Update the blocklight, heightmap, etc...
    this->setBlock(idx, block);
}

void world_storage::Section::setBlock(const Position &pos, int32_t block)
{
    if (pos >= SECTION_WIDTH || pos < 0)
        throw std::out_of_range("Position is out of range");

    this->setBlock(calculateSectionBlockIdx(pos), block);
}

void world_storage::Section::setBlock(uint64_t idx, int32_t block)
{
    if (idx >= SECTION_3D_SIZE)
        throw std::out_of_range("Position is out of range");

    auto oldBits = this->_blockPalette.getBits();
    // if (this->_blocks.canContainData())
    //     this->_blockPalette.remove(this->_blocks.get(idx));
    this->_blockPalette.add(block);
    if (oldBits != this->_blockPalette.getBits() && this->_blockPalette.getBits() != 0)
        this->_blocks.setValueSize(this->_blockPalette.getBits());

    this->_blocks.set(idx, this->_blockPalette.getId(block));
    // LINFO("Indeed : " << pos << " " << block);
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
    // if (this->_biomes.canContainData())
    //     this->_biomePalette.remove(this->_biomes.get(calculateSectionBiomeIdx(pos)));
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
    uint64_t idx = calculateSectionBlockIdx(pos);
    uint8_t l = _skyLight.get(idx);
    if (l != 0 && light == 0)
        _skyLightCount--;
    if (l == 0 && light != 0)
        _skyLightCount++;
    _skyLight.set(idx, light);
}

void world_storage::Section::recalculateSkyLightCount()
{
    _skyLightCount = 0;
    for (auto i : _skyLight.data()) {
        _skyLightCount += ((i & 0b11110000) >= 1) + ((i & 0b00001111) >= 1);
    }
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

void world_storage::Section::recalculateBlockLightCount()
{
    _blockLightCount = 0;
    for (auto i : _blockLight.data()) {
        _blockLightCount += ((i & 0b11110000) >= 1) + ((i & 0b00001111) >= 1);
    }
}

void world_storage::Section::recalculateSkyLight()
{
    // huntears:
    // So... I know how this looks, but hear me out, this function took 50% of
    // the time spent in region loading. So until we have a proper way to
    // calculate skyLights this will do :)
    for (auto &x : _skyLight.data()) {
        x = 0xFF;
    }
    recalculateSkyLightCount();
    return;

    // for (auto x = 0; x < SECTION_WIDTH; x++) {
    //     for (auto y = 0; y < SECTION_WIDTH; y++) {
    //         for (auto z = 0; z < SECTION_WIDTH; z++)
    //             setSkyLight({x, y, z}, 15);
    //     }
    // }
}

void world_storage::Section::recalculateBlockLight()
{
    // TODO
}

int32_t world_storage::Section::getBlock(const Position &pos) const
{
    if (pos >= SECTION_WIDTH)
        throw std::out_of_range("Position is out of range");
    if (!this->_blocks.canContainData())
        return 0;
    return this->_blockPalette.getGlobalId(this->_blocks.get(calculateSectionBlockIdx(pos)));
}

int32_t world_storage::Section::getBiome(const Position &pos) const
{
    if (pos >= BIOME_SECTION_WIDTH)
        throw std::out_of_range("Position is out of range");
    if (!this->_biomes.canContainData())
        return 0;
    return this->_biomePalette.getGlobalId(this->_biomes.get(calculateSectionBiomeIdx(pos)));
}

int32_t world_storage::Section::getBlock(uint64_t idx) const
{
    if (!this->_blocks.canContainData())
        return 0;
    return this->_blockPalette.getGlobalId(this->_blocks.get(idx));
}

int32_t world_storage::Section::getBiome(uint64_t idx) const
{
    if (!this->_biomes.canContainData())
        return 0;
    return this->_biomePalette.getGlobalId(this->_biomes.get(idx));
}

uint8_t world_storage::Section::getSkyLight(const Position &pos) const
{
    if (pos >= SECTION_WIDTH)
        throw std::out_of_range("Position is out of range");
    return this->_skyLight.get(calculateSectionBlockIdx(pos));
}

uint8_t world_storage::Section::getSkyLight(uint64_t idx) const { return this->_skyLight.get(idx); }

uint8_t world_storage::Section::getBlockLight(const Position &pos) const
{
    if (pos >= SECTION_WIDTH)
        throw std::out_of_range("Position is out of range");
    return this->_blockLight.get(calculateSectionBlockIdx(pos));
}

uint8_t world_storage::Section::getBlockLight(uint64_t idx) const { return this->_blockLight.get(idx); }

void world_storage::Section::processRandomTick(uint32_t rts, ChunkColumn &chunkColumn, size_t sectionIndex)
{
    auto *rgen = utility::PseudoRandomGenerator::getInstance();
    for (uint32_t i = 0; i < rts; i++) {
        auto index = rgen->generateNumber(0, SECTION_3D_SIZE - 1);
        _processBlockRandomTick(index, chunkColumn, sectionIndex);
    }
}

void world_storage::Section::_processBlockRandomTick(uint32_t blockIndex, ChunkColumn &chunkColumn, size_t sectionIndex)
{
    BlockId block = getBlock(blockIndex);
    if (Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::ZERO) <= block &&
        block <= Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::SEVEN)) {
        auto ablsolutePosition = world_storage::calculateAbsolutePosition(blockIndex, chunkColumn.getChunkPos(), sectionIndex);
        utility::farmland(block, chunkColumn, ablsolutePosition);
        LTRACE("Farmland random tick at {}", ablsolutePosition);
    }
    if (Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::ZERO) <= block && block <= Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::SEVEN)) {
        auto ablsolutePosition = world_storage::calculateAbsolutePosition(blockIndex, chunkColumn.getChunkPos(), sectionIndex);
        utility::wheat(block, chunkColumn, ablsolutePosition);
        LTRACE("Wheat random tick at {}", ablsolutePosition);
    }
}
