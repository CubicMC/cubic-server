#ifndef CUBICSERVER_WORLDSTORAGE_CHUNKCOLUMN_HPP
#define CUBICSERVER_WORLDSTORAGE_CHUNKCOLUMN_HPP

#include <array>
#include <cmath>
#include <cstdint>
#include <vector>

#include "Palette.hpp"
#include "protocol/Structures.hpp"
#include "types.hpp"

namespace world_storage {

// Chunk
constexpr int CHUNK_HEIGHT_MIN = -64;
constexpr int CHUNK_HEIGHT_MAX = 320;
constexpr int CHUNK_HEIGHT = CHUNK_HEIGHT_MAX - CHUNK_HEIGHT_MIN;

// Section
constexpr int SECTION_HEIGHT = 16;
constexpr int SECTION_WIDTH = 16;
constexpr int SECTION_2D_SIZE = SECTION_WIDTH * SECTION_WIDTH;
constexpr int SECTION_3D_SIZE = SECTION_2D_SIZE * SECTION_HEIGHT;
constexpr int NB_OF_SECTIONS = CHUNK_HEIGHT / SECTION_HEIGHT;

// Blocks
constexpr int BLOCKS_PER_CHUNK = NB_OF_SECTIONS * SECTION_3D_SIZE;

// Biome
constexpr int BIOME_SECTION_WIDTH = 4;
constexpr int BIOME_HEIGHT_MIN = CHUNK_HEIGHT_MIN / 4;
constexpr int BIOME_HEIGHT_MAX = CHUNK_HEIGHT_MAX / 4;
constexpr int BIOME_HEIGHT = BIOME_HEIGHT_MAX - BIOME_HEIGHT_MIN;
constexpr int BIOME_SECTION_2D_SIZE = BIOME_SECTION_WIDTH * BIOME_SECTION_WIDTH;
constexpr int BIOME_SECTION_3D_SIZE = BIOME_SECTION_2D_SIZE * BIOME_SECTION_WIDTH;
constexpr int BIOME_PER_CHUNK = BIOME_SECTION_3D_SIZE * NB_OF_SECTIONS;

// Heightmap
constexpr int HEIGHTMAP_BITS = bitsNeeded(CHUNK_HEIGHT + 1);
constexpr int HEIGHTMAP_ARRAY_SIZE = SECTION_2D_SIZE * HEIGHTMAP_BITS / 64;

// TODO: Accept negative position for y
constexpr uint64_t calculateBlockIdx(const Position &pos)
{
    auto y = pos.y - CHUNK_HEIGHT_MIN;
    if (pos.x < 0 || pos.x >= SECTION_WIDTH || y < 0 || y >= CHUNK_HEIGHT || pos.z < 0 || pos.z >= SECTION_WIDTH)
        throw std::runtime_error("Invalid position: (" + std::to_string(pos.x) + ", " + std::to_string(y) + ", " + std::to_string(pos.z) + ")");
    return pos.x + (pos.z * SECTION_WIDTH) + (y * SECTION_2D_SIZE);
}

// TODO: Accept negative position for y
constexpr uint64_t calculateBiomeIdx(const Position &pos)
{
    auto y = pos.y - BIOME_HEIGHT_MIN;
    if (pos.x < 0 || pos.x >= BIOME_SECTION_WIDTH || y < 0 || y >= BIOME_HEIGHT || pos.z < 0 || pos.z >= BIOME_SECTION_WIDTH)
        throw std::runtime_error("Invalid biome position: (" + std::to_string(pos.x) + ", " + std::to_string(y) + ", " + std::to_string(pos.z) + ")");
    return pos.x + (pos.z * BIOME_SECTION_WIDTH) + (y * BIOME_SECTION_2D_SIZE);
}

struct HeightMap {
    // https://wiki.vg/index.php?title=Protocol&oldid=17753#Chunk_Data_and_Update_Light
    std::array<nbt::Long, HEIGHTMAP_ARRAY_SIZE> motionBlocking;
    std::array<nbt::Long, HEIGHTMAP_ARRAY_SIZE> worldSurface;
};

enum class WorldType {
    NORMAL,
    NETHER,
    END,
    FLAT
};

class ChunkColumn {
public:
    ChunkColumn(const Position2D &chunkPos);
    ~ChunkColumn();

    void updateBlock(Position pos, BlockId id);
    BlockId getBlock(Position pos) const;
    const std::array<BlockId, SECTION_3D_SIZE * NB_OF_SECTIONS> &getBlocks() const;

    void updateSkyLight(Position pos, uint8_t light);
    uint8_t getSkyLight(Position pos) const;
    const std::array<uint8_t, SECTION_3D_SIZE * NB_OF_SECTIONS> &getSkyLights() const;

    void updateBlockLight(Position pos, uint8_t light);
    uint8_t getBlockLight(Position pos) const;
    const std::array<uint8_t, SECTION_3D_SIZE * NB_OF_SECTIONS> &getBlockLights() const;

    void updateBiome(Position pos, BiomeId biome);
    BiomeId getBiome(Position pos) const;
    const std::array<BiomeId, BIOME_SECTION_3D_SIZE * NB_OF_SECTIONS> &getBiomes() const;

    void updateBlockEntity(Position pos, protocol::BlockEntity *BlockEntity);
    void addBlockEntity(Position pos, protocol::BlockEntity *BlockEntity);
    void removeBlockEntity(Position pos);
    protocol::BlockEntity *getBlockEntity(Position pos);
    const std::vector<protocol::BlockEntity *> &getBlockEntities() const;

    int64_t getTick();
    void setTick(int64_t tick);
    Position2D getChunkPos() const;
    bool isReady() const;

    // void updateEntity(std::size_t id, Entity *e);
    // void updateEntity(u128 uuid, Entity *e);
    // void addEntity(Entity *e);
    // void removeEntity(std::size_t id);
    // void removeEntity(u128 uuid);
    // Entity *getEntity(std::size_t id);
    // Entity *getEntity(u128 uuid);
    // const std::deque<Entity *> &getEntities();

    void updateHeightMap(void);
    const HeightMap &getHeightMap() const;

    void generate(WorldType worldType, Seed seed);

private:
    std::array<BlockId, BLOCKS_PER_CHUNK> _blocks;
    std::array<uint8_t, BLOCKS_PER_CHUNK> _skyLights;
    std::array<uint8_t, BLOCKS_PER_CHUNK> _blockLights;
    std::array<uint8_t, BIOME_PER_CHUNK> _biomes;
    std::vector<protocol::BlockEntity *> _blockEntities;
    int64_t _tickData;
    Position2D _chunkPos;
    HeightMap _heightMap;
    bool _ready;

    void _generateOverworld(Seed seed);
    void _generateNether(Seed seed);
    void _generateEnd(Seed seed);
    void _generateFlat(Seed seed);
};

} // namespace world_storage

#endif // CUBICSERVER_WORLDSTORAGE_CHUNKCOLUMN_HPP
