#ifndef CUBICSERVER_GENERATION_FEATURES_SURFACE_FOREST_ROCK_HPP
#define CUBICSERVER_GENERATION_FEATURES_SURFACE_FOREST_ROCK_HPP

#include <deque>
#include <memory>
#include <vector>

#include "generation/generator.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

using namespace generation;

constexpr int MAX_SIZE_ROCK = 3;
constexpr int OFFSET_BIG_ROCK = -2;

class ForestRock {
public:
    ForestRock(world_storage::ChunkColumn &chunk, Generator &generator):
        _chunk(chunk),
        _generator(generator)
    {
    }

    /**
     * Filters all the positions where rocks can generate
     *
     */
    std::deque<Position> &getPosForRockGeneration();

    /**
     * Filters the previous kept positions to avoid rocks to
     * overlap between themselves too much
     */
    std::deque<Position> &filterRockOverlap();

    /**
     * Generates a rock by calling the building functions
     * where a rock can generate
     */
    void generateRock(std::vector<world_storage::ChunkColumn *>);

private:
    /**
     * Randomize the maximum size a rock can take and build
     * the rock before returning it
     * @param pos The position of the feature (here, a rock)
     */
    const std::vector<Generator::FeatureBlock> getRock(const Position &pos) const;

    /**
     * Randomize the format of the rocks that are generated
     * @param rock The rock to be generated
     * @param rockSize The maximum size the rock can take
     * @param pos The position of the feature (here, a rock)
     */
    void buildDiversifiedRocks(std::vector<generation::Generator::FeatureBlock> &rock, const int rockSize, const Position &pos) const;
    void starLayer(std::vector<generation::Generator::FeatureBlock> &rock, int y, const BlockId &mossy) const;
    void fullLayer(std::vector<generation::Generator::FeatureBlock> &rock, int y, const BlockId &mossy) const;
    void placeBits(std::vector<generation::Generator::FeatureBlock> &rock, const BlockId &mossy, const int rockSize, const Position &pos) const;
    void placeTinyBits(std::vector<generation::Generator::FeatureBlock> &rock, const BlockId &mossy, const Position &pos) const;

    /**
     * The chunks where to generate rocks
     */
    world_storage::ChunkColumn &_chunk;

    /**
     * The generator, which provides the noise maps
     */
    generation::Generator &_generator;

    /**
     * The positions where a rock can generate, initialized first
     * in getPosForRockGeneration(), then in filterRockOverlap()
     */
    std::deque<Position> _positions;
};

#endif // CUBICSERVER_GENERATION_FEATURES_SURFACE_FOREST_ROCK_HPP
