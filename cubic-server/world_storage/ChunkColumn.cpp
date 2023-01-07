#include "ChunkColumn.hpp"
#include <memory>

namespace world_storage {

ChunkColumn::~ChunkColumn()
{
}

void ChunkColumn::updateBlock(protocol::Position pos, Block id) {
    _blocks.at(pos.x + pos.z * 16 + pos.y * 16*16) = id;
}

Block ChunkColumn::getBlock(protocol::Position pos) {
    return _blocks.at(pos.x + pos.z * 16 + pos.y * 16*16);
}

const std::array<Block, CHUNK_3D_SIZE*NB_OF_CHUNKS> &ChunkColumn::getBlocks() const {
    return _blocks;
}

void ChunkColumn::updateSkyLight(protocol::Position pos, uint8_t light) {
    _skyLights.at(pos.x + pos.z * 16 + pos.y * 16*16) = light;
}

uint8_t ChunkColumn::getSkyLight(protocol::Position pos) {
    return _skyLights.at(pos.x + pos.z * 16 + pos.y * 16*16);
}

const std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> &ChunkColumn::getSkyLights() const {
    return _skyLights;
}

void ChunkColumn::updateBlockLight(protocol::Position pos, uint8_t light) {
    _blockLights.at(pos.x + pos.z * 16 + pos.y * 16*16) = light;
}

uint8_t ChunkColumn::getBlockLight(protocol::Position pos) {
    return _blockLights.at(pos.x + pos.z * 16 + pos.y * 16*16);
}

const std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> &ChunkColumn::getBlockLights() const {
    return _blockLights;
}

void ChunkColumn::updateBiome(protocol::Position pos, uint8_t biome) {
    _biomes.at(pos.x + pos.z * 4 + pos.y * 4*4) = biome;
}

uint8_t ChunkColumn::getBiome(protocol::Position pos) {
    return _biomes.at(pos.x + pos.z * 4 + pos.y * 4*4);
}

const std::array<uint8_t, BIOME_3D_SIZE*NB_OF_CHUNKS> &ChunkColumn::getBiomes() const {
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

// void ChunkColumn::updateEntity(__int128 uuid, Entity *e) {
// }

// void ChunkColumn::addEntity(Entity *e) { // TODO: entity must be a pointer or a reference ?
//     _entities.push_back(e); // TODO: see which of emplace_back of emplace_front is better or push_back or push_front
//     // _entities.emplace_back(std::make_shared<entity>(e));
// }

// void ChunkColumn::removeEntity(std::size_t id) {
//     _entities.erase(_entities.begin() + id);
// }

// void ChunkColumn::removeEntity(__int128 uuid) {
// }

// Entity *ChunkColumn::getEntity(std::size_t id) {
//     return _entities.at(id);
// }

// Entity *ChunkColumn::getEntity(__int128 uuid) {
//     return _entities.at(0);
// }

// const std::deque<Entity *> &ChunkColumn::getEntities() {
//     return _entities;
// }

void ChunkColumn::updateHeightMap(void){
}

const HeightMap &ChunkColumn::getHeightMap() {
    return _heightMap;
}
}
