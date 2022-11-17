#include "ChunkColumn.hpp"
#include <memory>

void ChunkColumn::updateBlock(_3d_pos pos, uint16_t id) {
    _blocks.at(pos.x + pos.y * 16 + pos.z * 16*16) = id;
}

uint16_t ChunkColumn::getBlock(_3d_pos pos) {
    return _blocks.at(pos.x + pos.y * 16 + pos.z * 16*16);
}

const std::array<uint16_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> &ChunkColumn::getBlocks() {
    return _blocks;
}

void ChunkColumn::updateSkyLight(_3d_pos pos, uint8_t light) {
    _skyLights.at(pos.x + pos.y * 16 + pos.z * 16*16) = light;
}

uint8_t ChunkColumn::getSkyLight(_3d_pos pos) {
    return _skyLights.at(pos.x + pos.y * 16 + pos.z * 16*16);
}

const std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> &ChunkColumn::getSkyLights() {
    return _skyLights;
}

void ChunkColumn::updateBlockLight(_3d_pos pos, uint8_t light) {
    _blockLights.at(pos.x + pos.y * 16 + pos.z * 16*16) = light;
}

uint8_t ChunkColumn::getBlockLight(_3d_pos pos) {
    return _blockLights.at(pos.x + pos.y * 16 + pos.z * 16*16);
}

const std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> &ChunkColumn::getBlockLights() {
    return _blockLights;
}

void ChunkColumn::updateBiome(_3d_pos pos, uint8_t biome) {
    _biomes.at(pos.x + pos.y * 4 + pos.z * 4*4) = biome;
}

uint8_t ChunkColumn::getBiome(_3d_pos pos) {
    return _biomes.at(pos.x + pos.y * 4 + pos.z * 4*4);
}

const std::array<uint8_t, BIOME_3D_SIZE*NB_OF_CHUNKS> &ChunkColumn::getBiomes() {
    return _biomes;
}

void ChunkColumn::updateBlockEntity(_3d_pos pos, block_entity *block_entity) {
}

void ChunkColumn::addBlockEntity(_3d_pos pos, block_entity *block_entity) {// entity must be a pointer or a reference ?
    _blockEntities.push_back(block_entity);// TODO: see which of emplace_back of emplace_front is better or push_back or push_front
    // _blockEntities.emplace_back(std::make_shared<block_entity>(block_entity));
}

void ChunkColumn::removeBlockEntity(_3d_pos pos) {
}

block_entity *ChunkColumn::getBlockEntity(_3d_pos pos) {
    return _blockEntities.at(0);
}

const std::vector<block_entity *> &ChunkColumn::getBlockEntities() {
    return _blockEntities;
}

int64_t ChunkColumn::getTick() {
    return _tickData;
}

void ChunkColumn::setTick(int64_t tick) {
    _tickData = tick;
}

void ChunkColumn::updateEntity(std::size_t id, entity *e) {
    _entities.at(id) = e;
}

void ChunkColumn::updateEntity(__int128 uuid, entity *e) {
}

void ChunkColumn::addEntity(entity *e) { // TODO: entity must be a pointer or a reference ?
    _entities.push_back(e); // TODO: see which of emplace_back of emplace_front is better or push_back or push_front
    // _entities.emplace_back(std::make_shared<entity>(e));
}

void ChunkColumn::removeEntity(std::size_t id) {
    _entities.erase(_entities.begin() + id);
}

void ChunkColumn::removeEntity(__int128 uuid) {
}

entity *ChunkColumn::getEntity(std::size_t id) {
    return _entities.at(id);
}

entity *ChunkColumn::getEntity(__int128 uuid) {
    return _entities.at(0);
}

const std::deque<entity *> &ChunkColumn::getEntities() {
    return _entities;
}

void ChunkColumn::updateHeightMap(void){
}

const height_map &ChunkColumn::getHeightMap() {
    return _heightMap;
}