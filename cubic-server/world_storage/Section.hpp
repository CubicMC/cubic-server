#ifndef WORLD_STORAGE_SECTION_HPP
#define WORLD_STORAGE_SECTION_HPP

#include <array>
#include <cstdint>

#include "Palette.hpp"
#include "types.hpp"
#include "world_storage/DynamicStorage.hpp"

namespace world_storage {

// Chunk
constexpr int CHUNK_HEIGHT_MIN = -64;
constexpr int CHUNK_HEIGHT_MAX = 320;
constexpr int CHUNK_HEIGHT = CHUNK_HEIGHT_MAX - CHUNK_HEIGHT_MIN;

// Section
constexpr int SECTION_WIDTH = 16;
constexpr int SECTION_2D_SIZE = SECTION_WIDTH * SECTION_WIDTH;
constexpr int SECTION_3D_SIZE = SECTION_2D_SIZE * SECTION_WIDTH;
constexpr int NB_OF_PLAYABLE_SECTIONS = CHUNK_HEIGHT / SECTION_WIDTH + (CHUNK_HEIGHT % SECTION_WIDTH ? 1 : 0);
constexpr int NB_OF_SECTIONS = NB_OF_PLAYABLE_SECTIONS + 2;

// Biome
constexpr int BIOME_SECTION_WIDTH = 4;
constexpr int BIOME_HEIGHT_MIN = CHUNK_HEIGHT_MIN / 4;
constexpr int BIOME_HEIGHT_MAX = CHUNK_HEIGHT_MAX / 4;
constexpr int BIOME_HEIGHT = BIOME_HEIGHT_MAX - BIOME_HEIGHT_MIN;
constexpr int BIOME_SECTION_2D_SIZE = BIOME_SECTION_WIDTH * BIOME_SECTION_WIDTH;
constexpr int BIOME_SECTION_3D_SIZE = BIOME_SECTION_2D_SIZE * BIOME_SECTION_WIDTH;
constexpr int BIOME_PER_CHUNK = BIOME_SECTION_3D_SIZE * NB_OF_PLAYABLE_SECTIONS;

constexpr uint64_t calculateSectionBlockIdx(const Position &pos) { return pos.x + (pos.z * SECTION_WIDTH) + (pos.y * SECTION_2D_SIZE); }
constexpr uint64_t calculateSectionBiomeIdx(const Position &pos) { return pos.x + (pos.z * BIOME_SECTION_WIDTH) + (pos.y * BIOME_SECTION_2D_SIZE); }

class Section {
public:
    typedef DynamicStorage<uint64_t, SECTION_3D_SIZE> BlockStorage;
    typedef DynamicStorage<uint64_t, BIOME_SECTION_3D_SIZE> BiomeStorage;
    typedef DynamicStorage<uint8_t, SECTION_3D_SIZE> LightStorage;

public:
    Section() noexcept;
    Section(Section &&section) noexcept;

    void updateBlock(const Position &pos, int32_t block);
    void setBlock(const Position &pos, int32_t block);

    void updateBiome(const Position &pos, int32_t biome);
    void setBiome(const Position &pos, int32_t biome);

    void updateSkyLight(const Position &pos, uint8_t light);
    void setSkyLight(const Position &pos, uint8_t light);
    void recalculateSkyLightCount();

    void updateBlockLight(const Position &pos, uint8_t light);
    void setBlockLight(const Position &pos, uint8_t);
    void recalculateBlockLightCount();

    [[nodiscard]] int32_t getBlock(const Position &pos) const;
    [[nodiscard]] int32_t getBiome(const Position &pos) const;

    [[nodiscard]] int32_t getBlock(uint64_t idx) const;
    [[nodiscard]] int32_t getBiome(uint64_t idx) const;

    [[nodiscard]] uint8_t getBlockLight(const Position &pos) const;
    [[nodiscard]] uint8_t getSkyLight(const Position &pos) const;

    [[nodiscard]] uint8_t getBlockLight(uint64_t idx) const;
    [[nodiscard]] uint8_t getSkyLight(uint64_t idx) const;

    [[nodiscard]] inline constexpr bool hasBlocks() const { return _blockPalette.getBits() != 0; }
    [[nodiscard]] inline constexpr bool hasBiomes() const { return _biomePalette.getBits() != 0; }

    [[nodiscard]] inline BlockStorage &getBlocks() { return _blocks; }
    [[nodiscard]] inline BiomeStorage &getBiomes() { return _biomes; }

    [[nodiscard]] inline const BlockStorage &getBlocks() const { return _blocks; }
    [[nodiscard]] inline const BiomeStorage &getBiomes() const { return _biomes; }

    [[nodiscard]] inline BlockPalette &getBlockPalette() { return _blockPalette; }
    [[nodiscard]] inline BiomePalette &getBiomePalette() { return _biomePalette; }

    [[nodiscard]] inline const BlockPalette &getBlockPalette() const { return _blockPalette; }
    [[nodiscard]] inline const BiomePalette &getBiomePalette() const { return _biomePalette; }

    [[nodiscard]] inline bool hasSkyLight() const { return _skyLightCount > 0; }
    [[nodiscard]] inline bool hasBlockLight() const { return _blockLightCount > 0; }

    [[nodiscard]] inline LightStorage &getBlockLights() { return _blockLight; }
    [[nodiscard]] inline LightStorage &getSkyLights() { return _skyLight; }

    [[nodiscard]] inline const LightStorage &getBlockLights() const { return _blockLight; }
    [[nodiscard]] inline const LightStorage &getSkyLights() const { return _skyLight; }

    void recalculateSkyLight();
    void recalculateBlockLight();

private:
    void _reCalculatePalette();

private:
    BlockStorage _blocks;
    BiomeStorage _biomes;
    BlockPalette _blockPalette;
    BiomePalette _biomePalette;

    LightStorage _skyLight;
    LightStorage _blockLight;
    uint64_t _skyLightCount;
    uint64_t _blockLightCount;
};

} // namespace world_storage

#endif // WORLD_STORAGE_SECTION_HPP
