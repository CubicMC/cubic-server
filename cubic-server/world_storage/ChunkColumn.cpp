#include <memory>
#include <PerlinNoise.hpp>

#include "ChunkColumn.hpp"
#include "Palette.hpp"
#include "protocol/serialization/addPrimaryType.hpp"
#include "logging/Logger.hpp"
#include "globalPalette_TEMP.hpp"

namespace world_storage {

ChunkColumn::~ChunkColumn()
{
}

void ChunkColumn::updateBlock(protocol::Position pos, Block block)
{
    this->updateBlock(pos, getGlobalPaletteIdFromBlock(block));
}

void ChunkColumn::updateBlock(protocol::Position pos, GlobalBlockId id)
{
    // Heightmap update
    int blockNumber = pos.x + pos.z * SECTION_WIDTH;
    int startLong = (blockNumber * HEIGHTMAP_BITS) / 64;
    int startOffset = (blockNumber * HEIGHTMAP_BITS) % 64;
    int endLong = ((blockNumber + 1) * HEIGHTMAP_BITS - 1) / 64;

    if (pos.y > _heightMap.motionBlocking.at(startLong).get_value() >> startOffset) {
        _heightMap.motionBlocking[startLong] |= (pos.y << startOffset);

        if (startLong != endLong)
            _heightMap.motionBlocking[endLong] |= (pos.y >> (64 - startOffset));
    }

    // Block update
    _blocks.at(calculateBlockIdx(pos)) = id;
}

Block ChunkColumn::getBlock(protocol::Position pos) const
{
    return getBlockFromGlobalPaletteId(_blocks.at(calculateBlockIdx(pos)));
}

const std::array<GlobalBlockId, SECTION_3D_SIZE * NB_OF_SECTIONS> &ChunkColumn::getBlocks() const
{
    return _blocks;
}

void ChunkColumn::updateSkyLight(protocol::Position pos, uint8_t light)
{
    _skyLights.at(calculateBlockIdx(pos)) = light;
}

uint8_t ChunkColumn::getSkyLight(protocol::Position pos) const
{
    return _skyLights.at(calculateBlockIdx(pos));
}

const std::array<uint8_t, SECTION_3D_SIZE * NB_OF_SECTIONS> &ChunkColumn::getSkyLights() const
{
    return _skyLights;
}

void ChunkColumn::updateBlockLight(protocol::Position pos, uint8_t light)
{
    _blockLights.at(calculateBlockIdx(pos)) = light;
    // _blockLights.at(pos.x + pos.z * 16 + pos.y * 16*16) = light;
}

uint8_t ChunkColumn::getBlockLight(protocol::Position pos) const
{
    return _blockLights.at(calculateBlockIdx(pos));
    // return _blockLights.at(pos.x + pos.z * 16 + pos.y * 16*16);
}

const std::array<uint8_t, SECTION_3D_SIZE * NB_OF_SECTIONS> &ChunkColumn::getBlockLights() const
{
    return _blockLights;
}

void ChunkColumn::updateBiome(protocol::Position pos, uint8_t biome)
{
    _biomes.at(calculateBiomeIdx(pos)) = biome;
}

uint8_t ChunkColumn::getBiome(protocol::Position pos) const
{
    return _biomes.at(calculateBiomeIdx(pos));
}

const std::array<uint8_t, BIOME_SECTION_3D_SIZE * NB_OF_SECTIONS> &ChunkColumn::getBiomes() const {
    return _biomes;
}

void ChunkColumn::updateBlockEntity(protocol::Position pos, BlockEntity *BlockEntity) {
}

void ChunkColumn::addBlockEntity(protocol::Position pos, BlockEntity *BlockEntity) {// entity must be a pointer or a reference ?
    _blockEntities.push_back(BlockEntity);// TODO: see which of emplace_back of emplace_front is better or push_back or push_front
    // _blockEntities.emplace_back(std::make_shared<BlockEntity>(BlockEntity));
}

void ChunkColumn::removeBlockEntity(protocol::Position pos) {
}

BlockEntity *ChunkColumn::getBlockEntity(protocol::Position pos) {
    return _blockEntities.at(0);
}

const std::vector<BlockEntity *> &ChunkColumn::getBlockEntities() const {
    return _blockEntities;
}

int64_t ChunkColumn::getTick() {
    return _tickData;
}

void ChunkColumn::setTick(int64_t tick) {
    _tickData = tick;
}

// void ChunkColumn::updateEntity(std::size_t id, Entity *e) {
//     _entities.at(id) = e;
// }

// void ChunkColumn::updateEntity(u128 uuid, Entity *e) {
// }

// void ChunkColumn::addEntity(Entity *e) { // TODO: entity must be a pointer or a reference ?
//     _entities.push_back(e); // TODO: see which of emplace_back of emplace_front is better or push_back or push_front
//     // _entities.emplace_back(std::make_shared<entity>(e));
// }

// void ChunkColumn::removeEntity(std::size_t id) {
//     _entities.erase(_entities.begin() + id);
// }

// void ChunkColumn::removeEntity(u128 uuid) {
// }

// Entity *ChunkColumn::getEntity(std::size_t id) {
//     return _entities.at(id);
// }

// Entity *ChunkColumn::getEntity(u128 uuid) {
//     return _entities.at(0);
// }

// const std::deque<Entity *> &ChunkColumn::getEntities() {
//     return _entities;
// }

void ChunkColumn::updateHeightMap(void) {
}

const HeightMap &ChunkColumn::getHeightMap() {
    return _heightMap;
}

void ChunkColumn::generate(WorldType worldType) {
    switch (worldType)
    {
    case WorldType::OVERWORLD:
        _generateOverworld();
        break;
    case WorldType::NETHER:
        _generateNether();
        break;
    case WorldType::END:
        _generateEnd();
        break;
    case WorldType::FLAT:
        _generateFlat();
        break;
    default:
        break;
    }
}

void ChunkColumn::_generateOverworld()
{
    // TODO: Pass the seed to the chunk
    auto noiseMaker = siv::PerlinNoise();
    // generate biomes
    for (int y = 0; y < NB_OF_SECTIONS * 4; y++) {
        for (int z = 0; z < 4; z++) {
            for (int x = 0; x < 4; x++) {
                updateBiome({x, y - 16, z}, noiseMaker.noise3D(x, y, z) > 0 ? 1 : 0);
            }
        }
    }

    for (int z = 0; z < 16; z++) {
        for (int x = 0; x < 16; x++) {
            int yMax = std::floor(noiseMaker.noise2D_01(x, z) * (double)CHUNK_HEIGHT);
            for (int y = 0; y < yMax; y++)
                updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, getGlobalPaletteIdFromBlockName("minecraft:stone"));
        }
    }
}

void ChunkColumn::_generateNether() {
}

void ChunkColumn::_generateEnd() {
}

void ChunkColumn::_generateFlat() {
    // TODO: optimize this
    // This take forever because of the Block constructor
    for (int y = 0; y < 11; y++) {
        for (int z = 0; z < 16; z++) {
            for (int x = 0; x < 16; x++) {
                if (y == 0) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, getGlobalPaletteIdFromBlockName("minecraft:bedrock"));
                } else if (y == 1 || y == 2) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, getGlobalPaletteIdFromBlockName("minecraft:dirt"));
                } else if (y == 3) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, getGlobalPaletteIdFromBlockName("minecraft:grass_block"));
                } else if ((y == 4 || y == 5 || y == 6) && z == 8 && x == 8) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, getGlobalPaletteIdFromBlockName("minecraft:oak_log"));
                } else if (y == 7 || y == 8) {
                    switch (x + (z * 16)) {
                        case 6 + 6 * 16:
                        case 7 + 6 * 16:
                        case 8 + 6 * 16:
                        case 9 + 6 * 16:
                        case 10 + 6 * 16:
                            updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, getGlobalPaletteIdFromBlockName("minecraft:oak_leaves"));
                            break;
                        case 6 + 7 * 16:
                        case 7 + 7 * 16:
                        case 8 + 7 * 16:
                        case 9 + 7 * 16:
                        case 10 + 7 * 16:
                            updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, getGlobalPaletteIdFromBlockName("minecraft:oak_leaves"));
                            break;
                        case 6 + 8 * 16:
                        case 7 + 8 * 16:
                        case 9 + 8 * 16:
                        case 10 + 8 * 16:
                            updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, getGlobalPaletteIdFromBlockName("minecraft:oak_leaves"));
                            break;
                        case 6 + 9 * 16:
                        case 7 + 9 * 16:
                        case 8 + 9 * 16:
                        case 9 + 9 * 16:
                        case 10 + 9 * 16:
                            updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, getGlobalPaletteIdFromBlockName("minecraft:oak_leaves"));
                            break;
                        case 6 + 10 * 16:
                        case 7 + 10 * 16:
                        case 8 + 10 * 16:
                        case 9 + 10 * 16:
                        case 10 + 10 * 16:
                            updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, getGlobalPaletteIdFromBlockName("minecraft:oak_leaves"));
                            break;
                        case 8 + 8 * 16:
                            updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, getGlobalPaletteIdFromBlockName("minecraft:oak_log"));
                            break;
                    }
                } else if (y == 9 || y == 10) {
                    switch (x + (z * 16)) {
                        case 8 + 7 * 16:
                        case 7 + 8 * 16:
                        case 9 + 8 * 16:
                        case 8 + 9 * 16:
                        case 8 + 8 * 16:
                            updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, getGlobalPaletteIdFromBlockName("minecraft:oak_leaves"));
                            break;
                    }
                }
            }
        }
    }
}

} // namespace world_storage
