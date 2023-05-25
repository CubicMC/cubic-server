#include "ChunkColumn.hpp"

#include "Server.hpp"
#include "blocks.hpp"
#include "generation/overworld.hpp"
#include "logging/logging.hpp"
#include "nbt.hpp"
#include "world_storage/Section.hpp"
#include <memory>

namespace world_storage {

ChunkColumn::ChunkColumn(const Position2D &chunkPos):
    _chunkPos(chunkPos),
    _heightMap(""),
    _ready(false)
{
    // OOF
    for (auto idx = 0; HEIGHTMAP_ENTRY[idx] != nullptr; idx++) {
        auto listBase = NBT_MAKE(nbt::List, HEIGHTMAP_ENTRY[idx]);
        auto list = std::dynamic_pointer_cast<nbt::List>(listBase);

        for (auto i = 0; i < HEIGHTMAP_ARRAY_SIZE; i++)
            list->push_back(std::make_shared<nbt::Long>("", 0));

        _heightMap.addValue(listBase);
    }
}

ChunkColumn::~ChunkColumn() { }

void ChunkColumn::updateBlock(const Position &pos, BlockId id)
{
    // TODO: Move the bitStoring to a separate class
    // Heightmap update
    // int blockNumber = pos.x + pos.z * SECTION_WIDTH;
    // int startLong = (blockNumber * HEIGHTMAP_BITS) / 64;
    // int startOffset = (blockNumber * HEIGHTMAP_BITS) % 64;
    // int endLong = ((blockNumber + 1) * HEIGHTMAP_BITS - 1) / 64;

    // if (pos.y > _heightMap.motionBlocking.at(startLong)->getValue() >> startOffset) {
    //     *_heightMap.motionBlocking[startLong] |= (pos.y << startOffset);

    //     if (startLong != endLong)
    //         *_heightMap.motionBlocking[endLong] |= (pos.y >> (64 - startOffset));
    // }

    // Block update
    // LINFO("ChunkColumn updateBlock: ", pos, "[", getSectionIndex(pos), "] -> ", id);
    _sections.at(getSectionIndex(pos)).updateBlock(Position {pos.x, pos.y - CHUNK_HEIGHT_MIN, pos.z} % SECTION_WIDTH, id);
    // _blocks.at(calculateBlockIdx(pos)) = id;
}

BlockId ChunkColumn::getBlock(const Position &pos) const { return _sections.at(getSectionIndex(pos)).getBlock(Position {pos.x, pos.y - CHUNK_HEIGHT_MIN, pos.z} % SECTION_WIDTH); }

uint8_t ChunkColumn::getSkyLight(const Position &pos) const
{
    return _sections.at(getSectionIndex(pos)).getSkyLight(Position {pos.x, pos.y - CHUNK_HEIGHT_MIN, pos.z} % SECTION_WIDTH);
}

void ChunkColumn::updateSkyLight(const Position &pos, uint8_t light)
{
    _sections.at(getSectionIndex(pos)).updateSkyLight(Position {pos.x, pos.y - CHUNK_HEIGHT_MIN, pos.z} % SECTION_WIDTH, light);
}

void ChunkColumn::updateBlockLight(const Position &pos, uint8_t light)
{
    _sections.at(getSectionIndex(pos)).updateBlockLight(Position {pos.x, pos.y - CHUNK_HEIGHT_MIN, pos.z} % SECTION_WIDTH, light);
}

uint8_t ChunkColumn::getBlockLight(const Position &pos) const
{
    return _sections.at(getSectionIndex(pos)).getBlockLight(Position {pos.x, pos.y - CHUNK_HEIGHT_MIN, pos.z} % SECTION_WIDTH);
}

void ChunkColumn::updateBiome(const Position &pos, uint8_t biome)
{
    _sections.at(getBiomeSectionIndex(pos)).updateBiome(Position {pos.x, pos.y - BIOME_HEIGHT_MIN, pos.z} % BIOME_SECTION_WIDTH, biome);
}

uint8_t ChunkColumn::getBiome(const Position &pos) const { return _sections.at(getBiomeSectionIndex(pos)).getBiome(pos % BIOME_SECTION_WIDTH); }

// const std::array<uint8_t, BIOME_SECTION_3D_SIZE * NB_OF_PLAYABLE_SECTIONS> &ChunkColumn::getBiomes() const { return _biomes; }

int64_t ChunkColumn::getTick() { return _tickData; }
void ChunkColumn::setTick(int64_t tick) { _tickData = tick; }
Position2D ChunkColumn::getChunkPos() const { return _chunkPos; }
bool ChunkColumn::isReady() const { return this->_ready; }

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

void ChunkColumn::updateHeightMap()
{
    for (auto &section : _sections) {
        for (int x = 0; x < SECTION_WIDTH; x++) {
            for (int z = 0; z < SECTION_WIDTH; z++) {
                for (int y = SECTION_WIDTH - 1; y >= 0; y--) {
                    if (section.getBlock({x, y, z}) != 0) {
                        _heightMap.getValueAs<nbt::List>("WORLD_SURFACE")->getValueAs<nbt::Long>(x + z * SECTION_WIDTH)->setValue(y + 1);
                        break;
                    }
                }
            }
        }
    }
}

void ChunkColumn::recalculateSkyLight()
{
    // TODO: REALY calculate the skylight
    for (auto &section : _sections) {
        for (auto x = 0; x < SECTION_WIDTH; x++) {
            for (auto y = 0; y < SECTION_WIDTH; y++) {
                for (auto z = 0; z < SECTION_WIDTH; z++)
                    section.setSkyLight({x, y, z}, 15);
            }
        }
    }
}

void ChunkColumn::recalculateBlockLight()
{
    // TODO: REALY calculate the blocklight
}

void ChunkColumn::generate(WorldType worldType, Seed seed)
{
    switch (worldType) {
    case WorldType::NORMAL:
        _generateOverworld(seed);
        break;
    case WorldType::NETHER:
        _generateNether(seed);
        break;
    case WorldType::END:
        _generateEnd(seed);
        break;
    case WorldType::FLAT:
        _generateFlat(seed);
        break;
    default:
        break;
    }
    this->recalculateSkyLight();
    this->_ready = true;
}

void ChunkColumn::_generateOverworld(Seed seed)
{
    auto generator = generation::Overworld(seed);
    int waterLevel = 86;

    // generate blocks
    for (int y = CHUNK_HEIGHT_MIN; y < CHUNK_HEIGHT_MAX; y++) {
        for (int z = 0; z < SECTION_WIDTH; z++) {
            for (int x = 0; x < SECTION_WIDTH; x++) {
                auto block = generator.getBlock(x + this->_chunkPos.x * SECTION_WIDTH, y, z + this->_chunkPos.z * SECTION_WIDTH);
                // if (block != Blocks::Air::toProtocol())
                updateBlock({x, y, z}, block);
            }
        }
    }

    // TODO: improve this to fill caves
    // generate water
    for (int z = 0; z < SECTION_WIDTH; z++) {
        for (int x = 0; x < SECTION_WIDTH; x++) {
            for (int y = waterLevel; 0 < y; y--) {
                if (getBlock({x, y, z}) == 1)
                    break;
                updateBlock({x, y, z}, Blocks::Water::toProtocol(Blocks::Water::Properties::Level::ZERO));
            }
        }
    }

    // generate grass
    for (int z = 0; z < SECTION_WIDTH; z++) {
        for (int x = 0; x < SECTION_WIDTH; x++) {
            auto lastBlock = 0;
            for (int y = CHUNK_HEIGHT_MAX - 2; CHUNK_HEIGHT_MIN <= y; y--) {
                auto block = getBlock({x, y, z});
                if (block == Blocks::Air::toProtocol())
                    continue;
                if (block == Blocks::Water::toProtocol(Blocks::Water::Properties::Level::ZERO)) {
                    lastBlock = Blocks::Water::toProtocol(Blocks::Water::Properties::Level::ZERO);
                    continue;
                }
                if (block == Blocks::Stone::toProtocol() && lastBlock == Blocks::Water::toProtocol(Blocks::Water::Properties::Level::ZERO)) {
                    updateBlock({x, y, z}, Blocks::Sand::toProtocol()); // sand
                    break;
                }
                if (block == Blocks::Stone::toProtocol() && lastBlock == Blocks::Air::toProtocol()) {
                    updateBlock({x, y, z}, Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE)); // grass
                    updateBlock({x, y - 1, z}, Blocks::Dirt::toProtocol()); // dirt
                    updateBlock({x, y - 2, z}, Blocks::Dirt::toProtocol()); // dirt
                    break;
                }
            }
        }
    }

    // generate bedrock
    int64_t state = (((this->_chunkPos.x * 0x4F9939F508L + this->_chunkPos.z * 0x1EF1565BD5L) ^ 0x5DEECE66DL) * 0x9D89DAE4D6C29D9L + 0x1844E300013E5B56L) & 0xFFFFFFFFFFFFL;
    for (int x = 0; x < SECTION_WIDTH; x++) {
        for (int z = 0; z < SECTION_WIDTH; z++) {
            updateBlock({x, 0 + CHUNK_HEIGHT_MIN, z}, Blocks::Bedrock::toProtocol()); // bedrock
            if (4 <= (state >> 17) % 5)
                updateBlock({x, 1 + CHUNK_HEIGHT_MIN, z}, Blocks::Bedrock::toProtocol()); // bedrock
            state = ((state * 0x530F32EB772C5F11L + 0x89712D3873C4CD04L) * 0x9D89DAE4D6C29D9L + 0x1844E300013E5B56L) & 0xFFFFFFFFFFFFL;
        }
    }

    // generate biomes
    for (int y = 0; y < BIOME_HEIGHT_MAX; y++) {
        for (int z = 0; z < BIOME_SECTION_WIDTH; z++) {
            for (int x = 0; x < BIOME_SECTION_WIDTH; x++) {
                // TODO
                updateBiome({x, y + BIOME_HEIGHT_MIN, z}, generator.getBiome(x, y, z));
            }
        }
    }
}

void ChunkColumn::_generateNether(UNUSED Seed seed) { }

void ChunkColumn::_generateEnd(UNUSED Seed seed) { }

void ChunkColumn::_generateFlat(UNUSED Seed seed)
{
    // TODO: optimize this
    // This take forever because of the Block constructor
    for (int y = 0; y < 11; y++) {
        for (int z = 0; z < SECTION_WIDTH; z++) {
            for (int x = 0; x < SECTION_WIDTH; x++) {
                if (y == 0) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, Blocks::Bedrock::toProtocol());
                } else if (y == 1 || y == 2) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, Blocks::Dirt::toProtocol());
                } else if (y == 3) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE));
                } else if ((y == 4 || y == 5 || y == 6) && z == 8 && x == 8) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, Blocks::OakLog::toProtocol(Blocks::OakLog::Properties::Axis::Y));
                } else if (y == 7 || y == 8) {
                    switch (x + (z * 16)) {
                    case 6 + 6 * 16:
                    case 7 + 6 * 16:
                    case 8 + 6 * 16:
                    case 9 + 6 * 16:
                    case 10 + 6 * 16:
                        updateBlock(
                            {x, y + CHUNK_HEIGHT_MIN, z},
                            Blocks::OakLeaves::toProtocol(
                                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
                            )
                        );
                        break;
                    case 6 + 7 * 16:
                    case 7 + 7 * 16:
                    case 8 + 7 * 16:
                    case 9 + 7 * 16:
                    case 10 + 7 * 16:
                        updateBlock(
                            {x, y + CHUNK_HEIGHT_MIN, z},
                            Blocks::OakLeaves::toProtocol(
                                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
                            )
                        );
                        break;
                    case 6 + 8 * 16:
                    case 7 + 8 * 16:
                    case 9 + 8 * 16:
                    case 10 + 8 * 16:
                        updateBlock(
                            {x, y + CHUNK_HEIGHT_MIN, z},
                            Blocks::OakLeaves::toProtocol(
                                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
                            )
                        );
                        break;
                    case 6 + 9 * 16:
                    case 7 + 9 * 16:
                    case 8 + 9 * 16:
                    case 9 + 9 * 16:
                    case 10 + 9 * 16:
                        updateBlock(
                            {x, y + CHUNK_HEIGHT_MIN, z},
                            Blocks::OakLeaves::toProtocol(
                                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
                            )
                        );
                        break;
                    case 6 + 10 * 16:
                    case 7 + 10 * 16:
                    case 8 + 10 * 16:
                    case 9 + 10 * 16:
                    case 10 + 10 * 16:
                        updateBlock(
                            {x, y + CHUNK_HEIGHT_MIN, z},
                            Blocks::OakLeaves::toProtocol(
                                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
                            )
                        );
                        break;
                    case 8 + 8 * 16:
                        updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, Blocks::OakLog::toProtocol(Blocks::OakLog::Properties::Axis::Y));
                        break;
                    }
                } else if (y == 9 || y == 10) {
                    switch (x + (z * 16)) {
                    case 8 + 7 * 16:
                    case 7 + 8 * 16:
                    case 9 + 8 * 16:
                    case 8 + 9 * 16:
                    case 8 + 8 * 16:
                        updateBlock(
                            {x, y + CHUNK_HEIGHT_MIN, z},
                            Blocks::OakLeaves::toProtocol(
                                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
                            )
                        );
                        break;
                    }
                }
            }
        }
    }
}

} // namespace world_storage
