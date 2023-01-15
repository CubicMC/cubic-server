#include <cstdint>
#include <array>
#include <vector>

// #include "Entity.hpp"
#include "protocol/Structures.hpp"

#ifndef CHUNKCOLUMN_HPP
#define CHUNKCOLUMN_HPP


namespace world_storage {

constexpr int CHUNK_2D_SIZE = 16*16;
constexpr int CHUNK_3D_SIZE = CHUNK_2D_SIZE*16;
constexpr int BIOME_3D_SIZE = 4*4*4;
constexpr int NB_OF_CHUNKS = 20;

struct Block { // TODO: PTDR
    long long id;
};

struct BlockEntity {
};

struct HeightMap {
        std::array<uint16_t, CHUNK_2D_SIZE> motionBlocking;
        std::array<uint16_t, CHUNK_2D_SIZE> worldSurface;
};

enum class WorldType {
    OVERWORLD,
    NETHER,
    END,
    FLAT
};

class ChunkColumn
{
public:
    ChunkColumn() = default;
    ~ChunkColumn();

    void updateBlock(protocol::Position pos, Block);
    Block getBlock(protocol::Position pos);
    const std::array<Block, CHUNK_3D_SIZE*NB_OF_CHUNKS> &getBlocks() const;

    void updateSkyLight(protocol::Position pos, uint8_t light);
    uint8_t getSkyLight(protocol::Position pos);
    const std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> &getSkyLights() const;

    void updateBlockLight(protocol::Position pos, uint8_t light);
    uint8_t getBlockLight(protocol::Position pos);
    const std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> &getBlockLights() const;

    void updateBiome(protocol::Position pos, uint8_t biome);
    uint8_t getBiome(protocol::Position pos);
    const std::array<uint8_t, BIOME_3D_SIZE*NB_OF_CHUNKS> &getBiomes() const;

    void updateBlockEntity(protocol::Position pos, BlockEntity *BlockEntity);
    void addBlockEntity(protocol::Position pos, BlockEntity *BlockEntity);
    void removeBlockEntity(protocol::Position pos);
    BlockEntity *getBlockEntity(protocol::Position pos);
    const std::vector<BlockEntity *> &getBlockEntities() const;

    int64_t getTick();
    void setTick(int64_t tick);

    // void updateEntity(std::size_t id, Entity *e);
    // void updateEntity(u128 uuid, Entity *e);
    // void addEntity(Entity *e);
    // void removeEntity(std::size_t id);
    // void removeEntity(u128 uuid);
    // Entity *getEntity(std::size_t id);
    // Entity *getEntity(u128 uuid);
    // const std::deque<Entity *> &getEntities();

    void updateHeightMap(void);
    const HeightMap &getHeightMap(void);

    void generate(WorldType worldType);
private:
    std::array<Block, CHUNK_3D_SIZE*NB_OF_CHUNKS> _blocks;
    std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> _skyLights;
    std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> _blockLights;
    std::array<uint8_t, BIOME_3D_SIZE*NB_OF_CHUNKS> _biomes;
    std::vector<BlockEntity *> _blockEntities;
    int64_t _tickData;
    // std::deque<Entity *> _entities;
    HeightMap _heightMap;

    void _generateOverworld();
    void _generateNether();
    void _generateEnd();
    void _generateFlat();
};

}

#endif // CHUNKCOLUMN_HPP
