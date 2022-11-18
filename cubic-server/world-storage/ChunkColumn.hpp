#include <cstdint>
#include <array>
#include <vector>
#include <deque>

#include "Entity.hpp"

#ifndef CHUNKCOLUMN_HPP
#define CHUNKCOLUMN_HPP

#define CHUNK_2D_SIZE 16*16
#define CHUNK_3D_SIZE CHUNK_2D_SIZE*16
#define BIOME_3D_SIZE 4*4*4
#define NB_OF_CHUNKS 20

struct _3d_pos {
    int x;
    int y;
    int z;
};

struct block_entity {
};

// typedef struct entity {
    // tag short air
    // tag string customName
    // tag byte customNameVisible
    // tag float fallDistance
    // tag short fire
    // tag byte glowing
    // tag byte hasVisualFire
    // tag string id
    // tag byte invulnerable
    // tag list motion
    // tag byte noGravity
    // tag byte onGround
    // tag list passengers
    // tag int portalCooldown
    // tag list pos
    // tag list rotation
    // tag byte silent
    // tag list tags
    // tag int ticksFrozen
    // tag int array uuid
// } entity;

struct height_map {
        std::array<uint16_t, CHUNK_2D_SIZE> motionBlocking;
        std::array<uint16_t, CHUNK_2D_SIZE> worldSurface;
};


class ChunkColumn
{
public:
    ChunkColumn();
    ~ChunkColumn();

    void updateBlock(_3d_pos pos, uint16_t id);
    uint16_t getBlock(_3d_pos pos);
    const std::array<uint16_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> &getBlocks();

    void updateSkyLight(_3d_pos pos, uint8_t light);
    uint8_t getSkyLight(_3d_pos pos);
    const std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> &getSkyLights();

    void updateBlockLight(_3d_pos pos, uint8_t light);
    uint8_t getBlockLight(_3d_pos pos);
    const std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> &getBlockLights();

    void updateBiome(_3d_pos pos, uint8_t biome);
    uint8_t getBiome(_3d_pos pos);
    const std::array<uint8_t, BIOME_3D_SIZE*NB_OF_CHUNKS> &getBiomes();

    void updateBlockEntity(_3d_pos pos, block_entity *block_entity);
    void addBlockEntity(_3d_pos pos, block_entity *block_entity);
    void removeBlockEntity(_3d_pos pos);
    block_entity *getBlockEntity(_3d_pos pos);
    const std::vector<block_entity *> &getBlockEntities();

    int64_t getTick();
    void setTick(int64_t tick);

    void updateEntity(std::size_t id, Entity *e);
    void updateEntity(__int128 uuid, Entity *e);
    void addEntity(Entity *e);
    void removeEntity(std::size_t id);
    void removeEntity(__int128 uuid);
    Entity *getEntity(std::size_t id);
    Entity *getEntity(__int128 uuid);
    const std::deque<Entity *> &getEntities();

    void updateHeightMap(void);
    const height_map &getHeightMap(void);
private:
    std::array<uint16_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> _blocks;
    std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> _skyLights;
    std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> _blockLights;
    std::array<uint8_t, BIOME_3D_SIZE*NB_OF_CHUNKS> _biomes;
    std::vector<block_entity *> _blockEntities;
    int64_t _tickData;
    std::deque<Entity *> _entities;
    height_map _heightMap;
};

#endif // CHUNKCOLUMN_HPP