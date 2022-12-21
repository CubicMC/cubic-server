#include <cstdint>
#include <array>
#include <vector>
#include <deque>

// #include "Entity.hpp"
#include "protocol/Structures.hpp"

#ifndef CHUNKCOLUMN_HPP
#define CHUNKCOLUMN_HPP

constexpr int CHUNK_2D_SIZE = 16*16;
constexpr int CHUNK_3D_SIZE = CHUNK_2D_SIZE*16;
constexpr int BIOME_3D_SIZE = 4*4*4;
constexpr int NB_OF_CHUNKS = 20;

struct block_entity {
};

struct height_map {
        std::array<uint16_t, CHUNK_2D_SIZE> motionBlocking;
        std::array<uint16_t, CHUNK_2D_SIZE> worldSurface;
};

namespace world_storage {
class ChunkColumn
{
public:
    ChunkColumn();
    ~ChunkColumn();

    void updateBlock(protocol::Position pos, uint16_t id);
    uint16_t getBlock(protocol::Position pos);
    const std::array<uint16_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> &getBlocks();

    void updateSkyLight(protocol::Position pos, uint8_t light);
    uint8_t getSkyLight(protocol::Position pos);
    const std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> &getSkyLights();

    void updateBlockLight(protocol::Position pos, uint8_t light);
    uint8_t getBlockLight(protocol::Position pos);
    const std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> &getBlockLights();

    void updateBiome(protocol::Position pos, uint8_t biome);
    uint8_t getBiome(protocol::Position pos);
    const std::array<uint8_t, BIOME_3D_SIZE*NB_OF_CHUNKS> &getBiomes();

    void updateBlockEntity(protocol::Position pos, block_entity *block_entity);
    void addBlockEntity(protocol::Position pos, block_entity *block_entity);
    void removeBlockEntity(protocol::Position pos);
    block_entity *getBlockEntity(protocol::Position pos);
    const std::vector<block_entity *> &getBlockEntities();

    int64_t getTick();
    void setTick(int64_t tick);

    // void updateEntity(std::size_t id, Entity *e);
    // void updateEntity(__int128 uuid, Entity *e);
    // void addEntity(Entity *e);
    // void removeEntity(std::size_t id);
    // void removeEntity(__int128 uuid);
    // Entity *getEntity(std::size_t id);
    // Entity *getEntity(__int128 uuid);
    // const std::deque<Entity *> &getEntities();

    void updateHeightMap(void);
    const height_map &getHeightMap(void);
private:
    std::array<uint16_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> _blocks;
    std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> _skyLights;
    std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> _blockLights;
    std::array<uint8_t, BIOME_3D_SIZE*NB_OF_CHUNKS> _biomes;
    std::vector<block_entity *> _blockEntities;
    int64_t _tickData;
    // std::deque<Entity *> _entities;
    height_map _heightMap;
};
}

#endif // CHUNKCOLUMN_HPP
