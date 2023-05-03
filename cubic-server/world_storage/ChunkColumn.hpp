#ifndef CUBICSERVER_WORLDSTORAGE_CHUNKCOLUMN_HPP
#define CUBICSERVER_WORLDSTORAGE_CHUNKCOLUMN_HPP

#include <array>
#include <cmath>
#include <cstdint>
#include <vector>

#include "Palette.hpp"
#include "Section.hpp"
#include "protocol/Structures.hpp"
#include "types.hpp"

namespace world_storage {

// Blocks
constexpr int BLOCKS_PER_CHUNK = NB_OF_SECTIONS * SECTION_3D_SIZE;

// Heightmap
constexpr int HEIGHTMAP_BITS = bitsNeeded(CHUNK_HEIGHT + 1);
constexpr int HEIGHTMAP_ARRAY_SIZE = (SECTION_2D_SIZE * HEIGHTMAP_BITS / 64) + ((SECTION_2D_SIZE * HEIGHTMAP_BITS % 64) != 0);

constexpr uint8_t getSectionIndex(const Position &pos) { return (pos.y - CHUNK_HEIGHT_MIN) / SECTION_HEIGHT; }
constexpr uint8_t getBiomeSectionIndex(const Position &pos) { return (pos.y - BIOME_HEIGHT_MIN) / BIOME_SECTION_WIDTH; }

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

// TODO: This is completely wrong, redo
struct HeightMap {
    // https://wiki.vg/index.php?title=Protocol&oldid=17753#Chunk_Data_and_Update_Light
    std::array<std::shared_ptr<nbt::Long>, HEIGHTMAP_ARRAY_SIZE> motionBlocking;
    std::array<std::shared_ptr<nbt::Long>, HEIGHTMAP_ARRAY_SIZE> worldSurface;
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

    void updateSkyLight(Position pos, uint8_t light);
    uint8_t getSkyLight(Position pos) const;
    const std::array<uint8_t, SECTION_3D_SIZE * NB_OF_SECTIONS> &getSkyLights() const;

    void updateBlockLight(Position pos, uint8_t light);
    uint8_t getBlockLight(Position pos) const;
    const std::array<uint8_t, SECTION_3D_SIZE * NB_OF_SECTIONS> &getBlockLights() const;

    void updateBiome(Position pos, BiomeId biome);
    BiomeId getBiome(Position pos) const;

    constexpr Section &getSection(uint8_t index) { return _sections.at(index); }
    constexpr const Section &getSection(uint8_t index) const { return _sections.at(index); }

    constexpr std::array<Section, NB_OF_SECTIONS> &getSections() { return _sections; }
    constexpr const std::array<Section, NB_OF_SECTIONS> &getSections() const { return _sections; }

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
    void _generateOverworld(Seed seed);
    void _generateNether(Seed seed);
    void _generateEnd(Seed seed);
    void _generateFlat(Seed seed);

private:
    std::array<Section, NB_OF_SECTIONS> _sections;
    std::array<uint8_t, BLOCKS_PER_CHUNK> _skyLights;
    std::array<uint8_t, BLOCKS_PER_CHUNK> _blockLights;
    int64_t _tickData;
    Position2D _chunkPos;
    HeightMap _heightMap;
    bool _ready;
    // std::mutex _mutex;
};

} // namespace world_storage

#endif // CUBICSERVER_WORLDSTORAGE_CHUNKCOLUMN_HPP
