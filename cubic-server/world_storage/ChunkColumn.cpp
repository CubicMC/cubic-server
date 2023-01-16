#include <memory>
#include <iostream>

#include "ChunkColumn.hpp"
#include "Palette.hpp"
#include "protocol/serialization/addPrimaryType.hpp"

namespace world_storage {

ChunkColumn::~ChunkColumn()
{
}

void ChunkColumn::updateBlock(protocol::Position pos, Block id)
{
    _sections.at(pos.y / SECTION_HEIGHT).at(pos.x + pos.z * 16 + (pos.y % 16) * 16*16) = id;
}

Block ChunkColumn::getBlock(protocol::Position pos)
{
    return _sections.at(pos.y / SECTION_HEIGHT).at(pos.x + pos.z * 16 + (pos.y % 16) * 16*16);
}

const std::array<std::array<Block, SECTION_3D_SIZE>, NB_OF_CHUNKS> &ChunkColumn::getSections() const {
    return _sections;
}

void ChunkColumn::updateSkyLight(protocol::Position pos, uint8_t light) {
    _skyLights.at(pos.y / SECTION_HEIGHT).at(pos.x + pos.z * 16 + (pos.y % 16) * 16*16) = light;
}

uint8_t ChunkColumn::getSkyLight(protocol::Position pos) {
    return _skyLights.at(pos.y / SECTION_HEIGHT).at(pos.x + pos.z * 16 + (pos.y % 16) * 16*16);
}

const std::array<std::array<uint8_t, SECTION_3D_SIZE>, NB_OF_CHUNKS> &ChunkColumn::getSkyLights() const {
    return _skyLights;
}

void ChunkColumn::updateBlockLight(protocol::Position pos, uint8_t light) {
    _blockLights.at(pos.y / SECTION_HEIGHT).at(pos.x + pos.z * 16 + (pos.y % 16) * 16*16) = light;
}

uint8_t ChunkColumn::getBlockLight(protocol::Position pos) {
    return _blockLights.at(pos.y / SECTION_HEIGHT).at(pos.x + pos.z * 16 + (pos.y % 16) * 16*16);
}

const std::array<std::array<uint8_t, SECTION_3D_SIZE>, NB_OF_CHUNKS> &ChunkColumn::getBlockLights() const {
    return _blockLights;
}

void ChunkColumn::updateBiome(protocol::Position pos, uint8_t biome) {
    _biomes.at(pos.y / SECTION_HEIGHT).at(pos.x + pos.z * 16 + (pos.y % 16) * 16*16) = biome;
}

uint8_t ChunkColumn::getBiome(protocol::Position pos) {
    return _biomes.at(pos.y / SECTION_HEIGHT).at(pos.x + pos.z * 16 + (pos.y % 16) * 16*16);
}

const std::array<std::array<uint8_t, BIOME_SECTION_3D_SIZE>, NB_OF_CHUNKS> &ChunkColumn::getBiomes() const {
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

void ChunkColumn::_generateOverworld() {
}

void ChunkColumn::_generateNether() {
}

void ChunkColumn::_generateEnd() {
}

void ChunkColumn::_generateFlat() {
    for (int x = 0; x < 16; x++) {
        for (int z = 0; z < 16; z++) {
            for (int y = 0; y < 4; y++) {
                if (y == 0) {
                    updateBlock({x, y, z}, {"minecraft:bedrock"});
                } else if (y == 1 || y == 2) {
                    updateBlock({x, y, z}, {"minecraft:dirt"});
                } else {
                    updateBlock({x, y, z}, {"minecraft:grass_block"});
                }
            }
        }
    }
}

std::vector<uint8_t> ChunkColumn::serialize() const
{
    std::vector<uint8_t> out;
    this->serialize(out);
    return out;
}

void ChunkColumn::serialize(std::vector<uint8_t> &out) const
{
//     // Byte per block
//     if (this->_bytePerBlock == 0)
//         return;
//     if (this->_bytePerBlock <= 4)
//         out.push_back(4);
//     else if (this->_bytePerBlock <= 8)
//         out.push_back(this->_bytePerBlock);
//     else
//         out.push_back(15); // HARD CODED BECAUSE I DON'T WANT TO THINK ABOUT LOGARITHMS
    Palette blockPalette(4);

    for (auto &section : _sections) {
        uint16_t blockInsideSection = 0;
        for (auto &block : section) {
            if (block.name != "minecraft:air") {
                blockPalette.addBlock(block);
                blockInsideSection++;
            }
        }
        // Number of block inside the section
        protocol::addShort(out, blockInsideSection);
        blockPalette.serialize(out);

        // Size of the long array
        uint32_t longArraySize = SECTION_3D_SIZE * blockPalette.getBytePerBlock() / 64;
        std::vector<uint64_t> longArray;
        for (uint32_t i = 0; i < longArraySize; i++) {
            longArray.push_back(0);
        }

    // A bitmask that contains bitsPerBlock set bits
    uint32_t individualValueMask = (uint32_t)((1 << blockPalette.getBytePerBlock()) - 1);

        for (uint8_t y = 0; y < SECTION_HEIGHT; y++) {
            for (uint8_t z = 0; z < SECTION_WIDTH; z++) {
                for (uint8_t x = 0; x < SECTION_WIDTH; x++) {
                    int blockNumber = (((y * SECTION_HEIGHT) + z) * SECTION_WIDTH) + x;
                    int startLong = (blockNumber * blockPalette.getBytePerBlock()) / 64;
                    int startOffset = (blockNumber * blockPalette.getBytePerBlock()) % 64;
                    int endLong = ((blockNumber + 1) * blockPalette.getBytePerBlock() - 1) / 64;

                    std::cout << "blockNumber: " << blockNumber << std::endl;
                    std::cout << "start offset: " << startOffset << std::endl;
                    std::cout << "start long: " << startLong << std::endl;
                    std::cout << "end long: " << endLong << std::endl;

                    Block block = section[blockNumber];

                    uint64_t value = blockPalette.getBlockId(block);
                    value &= individualValueMask;
                    std::cout << "value: " << value << std::endl;
                    std::cout << "longArraySize: " << longArraySize << std::endl;
                    std::cout << "value offset: " << (value << startOffset) << std::endl;
                    longArray.at(startLong) = longArray.at(startLong) | (value << startOffset);
                    std::cout << "value: " << value << std::endl;

                    if (startLong != endLong)
                        longArray[endLong] = (value >> (64 - startOffset));
                }
            }
        }
        protocol::addArray<uint64_t, protocol::addUnsignedLong>(out, longArray);
    }

    // BIOMES
    out.push_back(0);
    protocol::addVarInt(out, 0);
    protocol::addVarInt(out, 0);
}

} // namespace world_storage
