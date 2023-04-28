#ifndef WORLD_STORAGE_SECTION_HPP
#define WORLD_STORAGE_SECTION_HPP

#include <array>
#include <cstdint>

#include "Palette.hpp"
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

// Biome
constexpr int BIOME_SECTION_WIDTH = 4;
constexpr int BIOME_HEIGHT_MIN = CHUNK_HEIGHT_MIN / 4;
constexpr int BIOME_HEIGHT_MAX = CHUNK_HEIGHT_MAX / 4;
constexpr int BIOME_HEIGHT = BIOME_HEIGHT_MAX - BIOME_HEIGHT_MIN;
constexpr int BIOME_SECTION_2D_SIZE = BIOME_SECTION_WIDTH * BIOME_SECTION_WIDTH;
constexpr int BIOME_SECTION_3D_SIZE = BIOME_SECTION_2D_SIZE * BIOME_SECTION_WIDTH;
constexpr int BIOME_PER_CHUNK = BIOME_SECTION_3D_SIZE * NB_OF_SECTIONS;

class Section {
public:
    Section() = default;

    void updateBlock(const Position &pos, int32_t block);
    void setBlock(const Position &pos, int32_t block);

    void updateBiome(const Position &pos, int32_t biome);
    void setBiome(const Position &pos, int32_t biome);

    int32_t getBlock(const Position &pos) const;
    int32_t getBiome(const Position &pos) const;

private:
    std::array<int32_t, SECTION_3D_SIZE> _blocks;
    std::array<int32_t, BIOME_SECTION_3D_SIZE> _biomes;
    BlockPalette _blockPalette;
    BiomePalette _biomePalette;
};

} // namespace world_storage

#endif // WORLD_STORAGE_SECTION_HPP
