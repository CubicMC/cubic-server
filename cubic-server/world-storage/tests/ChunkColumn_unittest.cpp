#include <gtest/gtest.h>
#include "../ChunkColumn.hpp"

ChunkColumn chunkColumn;

TEST(ChunkColumnTest, Blocks) {
    _3d_pos pos = {0, 0, 0};
    chunkColumn.updateBlock(pos, 1);
    EXPECT_EQ(chunkColumn.getBlock(pos), 1);
    std::array<uint16_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> blocks;
    blocks[0] = 1;
    EXPECT_EQ(chunkColumn.getBlocks(), blocks);
}

TEST(ChunkColumnTest, SkyLights) {
    _3d_pos pos = {0, 0, 0};
    chunkColumn.updateSkyLight(pos, 1);
    EXPECT_EQ(chunkColumn.getSkyLight(pos), 1);
    std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> skyLights;
    skyLights[0] = 1;
    EXPECT_EQ(chunkColumn.getSkyLights(), skyLights);
}

TEST(ChunkColumnTest, BlockLights) {
    _3d_pos pos = {0, 0, 0};
    chunkColumn.updateBlockLight(pos, 1);
    EXPECT_EQ(chunkColumn.getBlockLight(pos), 1);
    std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> blockLights;
    blockLights[0] = 1;
    EXPECT_EQ(chunkColumn.getBlockLights(), blockLights);
}

TEST(ChunkColumnTest, Biomes) {
    _3d_pos pos = {0, 0, 0};
    chunkColumn.updateBiome(pos, 1);
    EXPECT_EQ(chunkColumn.getBiome(pos), 1);
    std::array<uint8_t, BIOME_3D_SIZE*NB_OF_CHUNKS> biomes;
    biomes[0] = 1;
    EXPECT_EQ(chunkColumn.getBiomes(), biomes);
}

TEST(ChunkColumnTest, BlockEntities) {
    EXPECT_EQ(1, 1);
}

TEST(ChunkColumnTest, Tick) {
    chunkColumn.setTick(345);
    EXPECT_EQ(chunkColumn.getTick(), 345);
}

TEST(ChunkColumnTest, HeightMap) {
    EXPECT_EQ(1, 1);
}