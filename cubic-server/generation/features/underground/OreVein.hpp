#ifndef CUBICSERVER_GENERATION_FEATURES_UNDERGROUND_ORE_VEIN_HPP
#define CUBICSERVER_GENERATION_FEATURES_UNDERGROUND_ORE_VEIN_HPP

#include "generation/generator.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

#include <array>
#include <deque>

using namespace generation;

/**
 * @file An ORE BLOB is an ellipsoidal cluster of blocks. In the overworld,
 * underground deposits of dirt and gravel are generated in this form, followed
 * by the more precious ores. They can form only in stone, deepslate, andesite,
 * diorite, granite and tuff. Two or more ores can form next to each other and
 * appear as an ore made of more than one material.
 *
 * Each ore blob has a SPAWN SIZE.
 * The spawn size correspond to a maximum number of generated blocks that
 * can be contained in a blob.
 *
 */

// clang-format off
/* Ore blob spawn size for soft decoration blocks */
constexpr int BLOB_SPAWN_SIZE_SOFT_BLOCK = 33; /**< Soft block : can be broken by hand or with a shovel */
constexpr int BLOB_SPAWN_SIZE_DIRT = 33;
constexpr int BLOB_SPAWN_SIZE_CLAY = 33;
constexpr int BLOB_SPAWN_SIZE_GRAVEL = 33;

/* Ore blob spawn size for hard decoration blocks */
constexpr int BLOB_SPAWN_SIZE_HARD_BLOCK = 64; /**< Hard block : can only be broken with a pickaxe */
constexpr int BLOB_SPAWN_SIZE_ANDESITE = 64;
constexpr int BLOB_SPAWN_SIZE_DIORITE = 64;
constexpr int BLOB_SPAWN_SIZE_GRANITE = 64;
constexpr int BLOB_SPAWN_SIZE_TUFF = 64;

/* Ore blob spawn size for ore blocks */
constexpr int BLOB_SPAWN_SIZE_COAL = 17;
constexpr int BLOB_SPAWN_SIZE_IRON_UNIFORM = 4;
constexpr int BLOB_SPAWN_SIZE_IRON_TRIANGLE = 9;
constexpr int BLOB_SPAWN_SIZE_COPPER = 10;
constexpr int BLOB_SPAWN_SIZE_COPPER_DRIPSTONE = 20; /**< Only in Dripstone Caves biome */
constexpr int BLOB_SPAWN_SIZE_REDSTONE = 8;
constexpr int BLOB_SPAWN_SIZE_LAPIS = 7;
constexpr int BLOB_SPAWN_SIZE_GOLD = 9;
constexpr int BLOB_SPAWN_SIZE_DIAMOND_HALF_EXPOSED = 4; /**< If it is exposed to air then it has 1/2 chance of being skipped */
constexpr int BLOB_SPAWN_SIZE_DIAMOND_HIDDEN = 8; /**< If it is exposed to air then it is skipped */
constexpr int BLOB_SPAWN_SIZE_DIAMOND_BARELY_EXPOSED = 12; /**< If it is exposed to air then it has 70% chance of being skipped */
constexpr int BLOB_SPAWN_SIZE_EMERALD = 3;

constexpr int BLOB_SPAWN_SIZE_INFESTED_STONE = 9;

constexpr int UNIFORM_SPAWN_RATE = 100;

/** Spawn tries per chunk for each different ore blob that can be generated.
* This is the maximum number of one type of blob that can be generated in one chunk
*/
constexpr double BLOB_SPAWN_TRIES_COAL_TRIANGLE = 20;
constexpr double BLOB_SPAWN_TRIES_COAL_UNIFORM = 30;
constexpr double BLOB_SPAWN_TRIES_IRON = 10;
constexpr double BLOB_SPAWN_TRIES_COPPER = 16;
constexpr double BLOB_SPAWN_TRIES_REDSTONE_TRIANGLE = 8;
constexpr double BLOB_SPAWN_TRIES_REDSTONE_UNIFORM = 4;
constexpr double BLOB_SPAWN_TRIES_LAPIS_TRIANGLE = 2;
constexpr double BLOB_SPAWN_TRIES_LAPIS_UNIFORM = 4;
constexpr double BLOB_SPAWN_TRIES_GOLD_TRIANGLE = 4;
constexpr double BLOB_SPAWN_TRIES_GOLD_UNIFORM = 0.5;
constexpr double BLOB_SPAWN_TRIES_DIAMOND_HALF_EXPOSED = 7; /**< If it is exposed to air then it has 1/2 chance of being skipped */
constexpr double BLOB_SPAWN_TRIES_DIAMOND_HIDDEN = 4; /**< If it is exposed to air then it is skipped */
constexpr double BLOB_SPAWN_TRIES_DIAMOND_BARELY_EXPOSED = 1/9; /**< If it is exposed to air then it has 70% chance of being skipped */
constexpr double BLOB_SPAWN_TRIES_EMERALD = 100;

/** Minimum height where an ore blob can be generated.
 * In the case of triangle distribution, this value is sometimes lower than the minimum of that of the world.
 * This is purely for calculations purpose, as both the minimum and maximum height are of importance to determine
 * the right amount of ores to be generated according to the triangle distribution, and does not mean in any way
 * that ores might generate outside of the bonds of the world.
 */
constexpr int BLOB_MIN_Y_SPAWN_COAL_TRIANGLE = 0;
constexpr int BLOB_MIN_Y_SPAWN_COAL_UNIFORM = 136;
constexpr int BLOB_MIN_Y_SPAWN_IRON_TRIANGLE = -24;
constexpr int BLOB_MIN_Y_SPAWN_IRON_UNIFORM = -64;
constexpr int BLOB_MIN_Y_SPAWN_COPPER = -16;
constexpr int BLOB_MIN_Y_SPAWN_REDSTONE_TRIANGLE = -96;
constexpr int BLOB_MIN_Y_SPAWN_REDSTONE_UNIFORM = -64;
constexpr int BLOB_MIN_Y_SPAWN_LAPIS_TRIANGLE = -32;
constexpr int BLOB_MIN_Y_SPAWN_LAPIS_UNIFORM = -64;
constexpr int BLOB_MIN_Y_SPAWN_GOLD = -64;
constexpr int BLOB_MIN_Y_SPAWN_GOLD_BALDLANDS = 32;
constexpr int BLOB_MIN_Y_SPAWN_DIAMOND = -144;
constexpr int BLOB_MIN_Y_SPAWN_EMERALD = -16;

/** Maximum height where an ore blob can be generated.
 * In the case of triangle distribution, this value is sometimes higher than the maximum of that of the world.
 * This is purely for calculations purpose, as both the minimum and maximum height are of importance to determine
 * the right amount of ores to be generated according to the triangle distribution, and does not mean in any way
 * that ores might generate outside of the bonds of the world.
 */
constexpr int BLOB_MAX_Y_SPAWN_COAL_TRIANGLE = 192;
constexpr int BLOB_MAX_Y_SPAWN_COAL_UNIFORM = 320;
constexpr int BLOB_MAX_Y_SPAWN_IRON_TRIANGLE = 56;
constexpr int BLOB_MAX_Y_SPAWN_IRON_UNIFORM = 72;
constexpr int BLOB_MAX_Y_SPAWN_COPPER = 112;
constexpr int BLOB_MAX_Y_SPAWN_REDSTONE_TRIANGLE = -32;
constexpr int BLOB_MAX_Y_SPAWN_REDSTONE_UNIFORM = 15;
constexpr int BLOB_MAX_Y_SPAWN_LAPIS_TRIANGLE = 32;
constexpr int BLOB_MAX_Y_SPAWN_LAPIS_UNIFORM = 64;
constexpr int BLOB_MAX_Y_SPAWN_GOLD_TRIANGLE = 32;
constexpr int BLOB_MAX_Y_SPAWN_GOLD_UNIFORM = -48;
constexpr int BLOB_MAX_Y_SPAWN_GOLD_BALDLANDS = 256;
constexpr int BLOB_MAX_Y_SPAWN_DIAMOND = 16;
constexpr int BLOB_MAX_Y_SPAWN_EMERALD = 480;

/** When meeting certain condition, this define the skipping rate.
 * If the blob is exposed to air, then it has this chance of being skipped instead.
 */
constexpr std::array<double, 4> SkipRate = {0, 0.5, 0.7, 1};
constexpr double BLOB_SKIP_RATE_COAL_TRIANGLE = SkipRate[1];
constexpr double BLOB_SKIP_RATE_COAL_UNIFORM = SkipRate[0];
constexpr double BLOB_SKIP_RATE_IRON = SkipRate[0];
constexpr double BLOB_SKIP_RATE_COPPER = SkipRate[0];
constexpr double BLOB_SKIP_RATE_REDSTONE = SkipRate[0];
constexpr double BLOB_SKIP_RATE_LAPIS_TRIANGLE = SkipRate[0];
constexpr double BLOB_SKIP_RATE_LAPIS_UNIFORM = SkipRate[3];
constexpr double BLOB_SKIP_RATE_GOLD = SkipRate[1];
constexpr double BLOB_SKIP_RATE_GOLD_BALDLANDS = SkipRate[0];
constexpr double BLOB_SKIP_RATE_DIAMOND_HALF_EXPOSED = SkipRate[1];
constexpr double BLOB_SKIP_RATE_DIAMOND_HIDDEN = SkipRate[3];
constexpr double BLOB_SKIP_RATE_DIAMOND_BARELY_EXPOSED = SkipRate[2];
constexpr double BLOB_SKIP_RATE_EMERALD = SkipRate[0];

// clang-format on

/**
 * @brief Indicates the maximum number of generated blocks that can be contained
 * in a blob. The index, from 0 to 64, correspond to the SPAWN SIZE of the blob, whereas
 * the value correspond to the maximum number of block associated to its
 * index.
 *
 */
constexpr std::array<int, 65> MAX_NB_OF_BLOCKS = {0,   0,   0,   4,   5,   8,   9,   10,  10,  13,  16,  17,  23,  24,  24,  29,  32,  37,  46,  52,  52,  60,
                                                  68,  68,  74,  82,  94,  104, 106, 120, 128, 135, 149, 160, 180, 190, 204, 212, 228, 246, 262, 276, 292, 308,
                                                  324, 344, 360, 381, 403, 429, 452, 480, 500, 530, 558, 584, 616, 634, 664, 694, 730, 760, 790, 826, 864};

/* Ore distribution type */
enum class GenerationType {
    UNIFORM, /**< Uniform distribution have all ores spread in same frequency at any height */
    TRIANGLE /**< Triangle generate ores more frequently in center height */
};

class OreVein {
public:
    OreVein(world_storage::ChunkColumn &chunk, Generator &generator):
        _chunk(chunk),
        _generator(generator)
    {
    }

    /**
     * @brief Define all the positions where a blob can generate for the triangle distribution
     *
     * @param spawnSize Blob spawn size (according to the value defined above)
     * @param spawnTries A number of times the blob is allowed to try to generate
     * @param minY Minimum height for the blob to generate
     * @param maxY Maximum height for the blob to generate
     * @param skipRate The skip rate of the blob
     * @return a deque holding all the positions where a blob can generate for the triangle distribution
     *
     */
    std::deque<Position> computeTriangleDistribution(const int spawnSize, const double spawnTries, const int minY, const int maxY, const double skipRate);

    /**
     * @brief Define all the positions where a blob can generate
     *
     * @param generationType UNIFORM or TRIANGLE
     * @param spawnSize Blob spawn size (according to the value defined above)
     * @param minY Minimum height for the blob to generate
     * @param maxY Maximum height for the blob to generate
     * @param skipRate The skip rate of the blob
     * @param spawnTries A number of times the blob is allowed to try to generate
     * @return a deque holding all the positions where a blob can generate
     *
     */
    std::deque<Position>
    defineAllBlobPositions(const GenerationType generationType, const int spawnSize, const int minY, const int maxY, const double skipRate, const double spawnTries);

    /**
     * @brief Define all the positions where a blob can generate for the uniform distribution
     *
     * @param spawnSize Blob spawn size (according to the value defined above)
     * @param minY Minimum height for the blob to generate
     * @param maxY Maximum height for the blob to generate
     * @param skipRate The skip rate of the blob
     * @param spawnTries A number of times the blob is allowed to try to generate
     * @return a deque holding all the positions where a blob can generate for the uniform distribution
     *
     */
    std::deque<Position> computeUniformDistribution(const double spawnTries, const int minY, const int maxY, const int spawnSize, const double skipRate, const int spawnRate);

    /**
     * @brief Skip the position if the ore is exposed to air
     *
     * @param pos The position of the blob
     * @param spawnSize Blob spawn size (according to the value defined above)
     * @param skipRate The skip rate of the blob
     */
    bool isSkippedWhenAirExposed(Position pos, const int spawnSize, const double skipRate);

    /**
     * @brief Generate an ore blob.
     *
     * @param blockID The ID of the block to compose the blob
     * @param spawnSize Blob spawn size (according to the value defined above)
     * @param pos The position of the blob
     *
     */
    void createBlob(const BlockId &blockID, const int spawnSize, const Position &pos) const;

    /**
     * @brief Generates all the blobs of the world
     *
     */
    void generateBlobs();

protected:
private:
    void generateIronBlobs();
    void generateRedstoneBlobs();
    void generateDiamondBlobs();
    void generateCoalBlobs();
    void generateEmeraldBlobs();
    void generateCopperBlobs();
    void generateLapisBlobs();
    void generateGoldBlobs();

    /* The chunks where to generate the feature */
    world_storage::ChunkColumn &_chunk;

    /* A reference towards the generator, mostly to access the randomizer */
    generation::Generator &_generator;

    /* The deque containing all the possible positions for a blob to generate */
    std::deque<Position> _positions;
};

#endif // CUBICSERVER_GENERATION_FEATURES_UNDERGROUND_ORE_VEIN_HPP
