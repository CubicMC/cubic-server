#ifndef CUBICSERVER_WORLDSTORAGE_CHUNKCOLUMN_HPP
#define CUBICSERVER_WORLDSTORAGE_CHUNKCOLUMN_HPP

#include <array>
#include <cmath>
#include <cstdint>
#include <memory>
#include <mutex>
#include <vector>

#include "Palette.hpp"
#include "Section.hpp"
#include "generation/generator.hpp"
#include "nbt.hpp"
#include "protocol/Structures.hpp"
#include "protocol/common.hpp"
#include "types.hpp"
#include "world_storage/DynamicStorage.hpp"

class Dimension;

namespace world_storage {

// Heightmap
constexpr int HEIGHTMAP_BITS = bitsNeeded(CHUNK_HEIGHT + 1);
constexpr int HEIGHTMAP_ARRAY_SIZE = (SECTION_2D_SIZE * HEIGHTMAP_BITS / 64) + ((SECTION_2D_SIZE * HEIGHTMAP_BITS % 64) != 0);
constexpr const char *const HEIGHTMAP_ENTRY[] = {"MOTION_BLOCKING", "WORLD_SURFACE", nullptr};

constexpr uint8_t getSectionIndex(const Position &pos) { return (pos.y - CHUNK_HEIGHT_MIN + SECTION_WIDTH) / SECTION_WIDTH; }
constexpr uint8_t getBiomeSectionIndex(const Position &pos) { return (pos.y - BIOME_HEIGHT_MIN + BIOME_SECTION_WIDTH) / BIOME_SECTION_WIDTH; }

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

enum class WorldType {
    DEFAULT = 0,
    SUPERFLAT,
    LARGEBIOME,
    AMPLIFIED,
    SINGLEBIOME,
    DEBUG,
    SUPERFLAT_CUBIC_SERVER
};

enum class DimensionType {
    OVERWORLD = 0,
    NETHER,
    END
};

enum class GenerationState {
    INITIALIZED = 0,
    RAW_GENERATION,
    LAKES,
    LOCAL_MODIFICATIONS,
    UNDERGROUND_STRUCTURES,
    SURFACE_STRUCTURES,
    STRONGHOLDS,
    UNDERGROUND_ORES,
    UNDERGROUND_DECORATION,
    FLUID_SPRINGS,
    VEGETAL_DECORATION,
    TOP_LAYER_MODIFICATION,
    READY,
};

class ChunkColumn {
public:
    ChunkColumn(const Position2D &chunkPos, std::shared_ptr<Dimension> dimension);
    ChunkColumn(ChunkColumn &&chunk);
    ~ChunkColumn();

    void updateBlock(const Position &pos, BlockId id);
    BlockId getBlock(const Position &pos) const;

    void updateSkyLight(const Position &pos, uint8_t light);
    uint8_t getSkyLight(const Position &pos) const;
    void recalculateSkyLight();

    void updateBlockLight(const Position &pos, uint8_t light);
    uint8_t getBlockLight(const Position &pos) const;
    void recalculateBlockLight();

    void updateBiome(const Position &pos, BiomeId biome);
    BiomeId getBiome(const Position &pos) const;

    constexpr Section &getSection(uint8_t index) { return _sections.at(index); }
    constexpr const Section &getSection(uint8_t index) const { return _sections.at(index); }

    constexpr std::array<Section, NB_OF_SECTIONS> &getSections() { return _sections; }
    constexpr const std::array<Section, NB_OF_SECTIONS> &getSections() const { return _sections; }

    const std::shared_ptr<const Dimension> getDimension() const { return _dimension; }

    int64_t getTick();
    void setTick(int64_t tick);
    Position2D getChunkPos() const;
    bool isReady() const;
    GenerationState getState() const;

    // void updateEntity(std::size_t id, Entity *e);
    // void updateEntity(u128 uuid, Entity *e);
    // void addEntity(Entity *e);
    // void removeEntity(std::size_t id);
    // void removeEntity(u128 uuid);
    // Entity *getEntity(std::size_t id);
    // Entity *getEntity(u128 uuid);
    // const std::deque<Entity *> &getEntities();

    void updateHeightMap();
    NODISCARD constexpr inline const nbt::Compound &getHeightMap() const { return _heightMap; }

    void generate(GenerationState goalState = GenerationState::READY);

    /**
     * @brief Process a random tick on the chunk
     *
     * @param rts The value of randomtickspeed
     */
    void processRandomTick(uint32_t rts);

    friend class Persistence;

private:
    void _generateOverworld(GenerationState goalState);
    void _generateNether(GenerationState goalState);
    void _generateEnd(GenerationState goalState);

    void _generateFlat(GenerationState goalState);
    void _generateDebug(GenerationState goalState);
    void _generateFlatCubicServer(GenerationState goalState);

    void _generateRawGeneration(generation::Generator &generator);
    void _generateLakes(generation::Generator &generator);
    void _generateLocalModifications(generation::Generator &generator);
    void _generateUndergroundStructures(generation::Generator &generator);
    void _generateSurfaceStructures(generation::Generator &generator);
    void _generateStrongholds(generation::Generator &generator);
    void _generateUndergroundOres(generation::Generator &generator);
    void _generateUndergroundDecoration(generation::Generator &generator);
    void _generateFluidSprings(generation::Generator &generator);
    void _generateVegetalDecoration(generation::Generator &generator);
    void _generateTopLayerModification(generation::Generator &generator);

private:
private:
    std::array<Section, NB_OF_SECTIONS> _sections;
    // std::array<uint8_t, (NB_OF_PLAYABLE_SECTIONS + 2) * SECTION_3D_SIZE> _skyLights;
    // std::array<uint8_t, (NB_OF_PLAYABLE_SECTIONS + 2) * SECTION_3D_SIZE> _blockLights;
    // LightStorage _skyLights;
    // LightStorage _blockLights;
    int64_t _tickData;
    Position2D _chunkPos;
    nbt::Compound _heightMap;
    GenerationState _currentState;
    std::mutex _generationLock;
    std::shared_ptr<Dimension> _dimension;
};

} // namespace world_storage

#endif // CUBICSERVER_WORLDSTORAGE_CHUNKCOLUMN_HPP
