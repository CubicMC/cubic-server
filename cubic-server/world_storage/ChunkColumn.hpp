#ifndef WORLD_STORAGE_CHUNKCOLUMN_HPP
#define WORLD_STORAGE_CHUNKCOLUMN_HPP

#include <cstdint>
#include <array>
#include <vector>
#include <unordered_map>
#include <cmath>

// #include "Entity.hpp"
#include "protocol/Structures.hpp"
#include "Block.hpp"

namespace world_storage {

typedef uint32_t GlobalBlockId;

constexpr int CHUNK_HEIGHT_MIN = -64;
constexpr int CHUNK_HEIGHT_MAX = 256;
constexpr int CHUNK_HEIGHT = CHUNK_HEIGHT_MAX - CHUNK_HEIGHT_MIN;
constexpr int SECTION_HEIGHT = 16;
constexpr int SECTION_WIDTH = 16;
constexpr int SECTION_2D_SIZE = SECTION_WIDTH * SECTION_WIDTH;
constexpr int SECTION_3D_SIZE = SECTION_2D_SIZE * SECTION_HEIGHT;
constexpr int BIOME_SECTION_3D_SIZE = 4*4*4;
constexpr int NB_OF_CHUNKS = CHUNK_HEIGHT / SECTION_HEIGHT;

// TODO: Accept negative position for y
constexpr uint64_t calculateBlockIdx(const protocol::Position &pos)
{
    if (pos.x < 0 || pos.x >= SECTION_WIDTH || pos.y < 0 || pos.y >= CHUNK_HEIGHT || pos.z < 0 || pos.z >= SECTION_WIDTH)
        throw std::runtime_error("Invalid position: (" + std::to_string(pos.x) + ", " + std::to_string(pos.y) + ", " + std::to_string(pos.z) + ")");
    return pos.x + (pos.z * SECTION_WIDTH) + (pos.y * (SECTION_WIDTH * SECTION_WIDTH));
}

struct BlockEntity {
};

struct HeightMap {
    // https://wiki.vg/index.php?title=Protocol&oldid=17753#Chunk_Data_and_Update_Light
    std::array<nbt::Long, SECTION_2D_SIZE> motionBlocking;
    std::array<nbt::Long, SECTION_2D_SIZE> worldSurface;
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

    void updateBlock(protocol::Position pos, Block block);
    void updateBlock(protocol::Position pos, GlobalBlockId id);
    Block getBlock(protocol::Position pos) const;
    const std::array<GlobalBlockId, SECTION_3D_SIZE * NB_OF_CHUNKS> &getBlocks() const;

    void updateSkyLight(protocol::Position pos, uint8_t light);
    uint8_t getSkyLight(protocol::Position pos) const;
    const std::array<uint8_t, SECTION_3D_SIZE * NB_OF_CHUNKS> &getSkyLights() const;

    void updateBlockLight(protocol::Position pos, uint8_t light);
    uint8_t getBlockLight(protocol::Position pos) const;
    const std::array<uint8_t, SECTION_3D_SIZE * NB_OF_CHUNKS> &getBlockLights() const;

    void updateBiome(protocol::Position pos, uint8_t biome);
    uint8_t getBiome(protocol::Position pos) const;
    const std::array<uint8_t, BIOME_SECTION_3D_SIZE * NB_OF_CHUNKS> &getBiomes() const;

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
    std::array<GlobalBlockId, SECTION_3D_SIZE * NB_OF_CHUNKS> _blocks;
    std::array<uint8_t, SECTION_3D_SIZE * NB_OF_CHUNKS> _skyLights;
    std::array<uint8_t, SECTION_3D_SIZE * NB_OF_CHUNKS> _blockLights;
    std::array<uint8_t, BIOME_SECTION_3D_SIZE * NB_OF_CHUNKS> _biomes;
    std::vector<BlockEntity *> _blockEntities;
    int64_t _tickData;
    // std::deque<Entity *> _entities;
    HeightMap _heightMap;

    void _generateOverworld();
    void _generateNether();
    void _generateEnd();
    void _generateFlat();
};

} // namespace world_storage

#endif // WORLD_STORAGE_CHUNKCOLUMN_HPP
