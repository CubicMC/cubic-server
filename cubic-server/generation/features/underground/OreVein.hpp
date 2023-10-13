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

/* When meeting certain condition, this define the skipping rate.
 * If the blob is exposed to air, then it has this chance of being skipped instead.
 */
constexpr std::array<double, 4> SkipRate = {0, 0.5, 0.7, 1};

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
    std::deque<Position> &computeTriangleDistribution(const int spawnSize, const double spawnTries, const int minY, const int maxY, const double skipRate);

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
    std::deque<Position> &
    defineAllBlobPositions(const GenerationType generationType, const int spawnSize, const int minY, const int maxY, const double skipRate, const double spawnTries);

    /**
     * @brief Generate an ore blob.
     *
     * @param blockID The ID of the block to compose the blob
     * @param generationType UNIFORM or TRIANGLE
     * @param spawnSize Blob spawn size (according to the value defined above)
     * @param pos The position of the blob
     *
     */
    void createBlob(const BlockId &blockID, const GenerationType generationType, const int spawnSize, const Position &pos) const;

    /**
     * @brief Generates a blob at each defined position
     *
     * @param ChuckColumn description
     *
     */
    void generateBlobs(std::vector<world_storage::ChunkColumn *>);

private:
    /* The chunks where to generate the feature */
    world_storage::ChunkColumn &_chunk;

    /* A reference towards the generator, mostly to access the randomizer */
    generation::Generator &_generator;

    /* The deque containing all the possible positions for a blob to generate */
    std::deque<Position> _positions;
};

#endif // CUBICSERVER_GENERATION_FEATURES_UNDERGROUND_ORE_VEIN_HPP
