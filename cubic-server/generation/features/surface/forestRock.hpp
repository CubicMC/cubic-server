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

class ForestRock {
public:
    ForestRock(world_storage::ChunkColumn &chunk, Generator &generator):
        _chunk(chunk),
        _generator(generator)
    {
    }

    std::deque<Position> &getPosForRockGeneration();
    std::deque<Position> &filterRockOverlap();
    void generateRock(std::vector<world_storage::ChunkColumn *>);

private:
    const std::vector<Generator::FeatureBlock> getRock() const;

    void starLayer(std::vector<generation::Generator::FeatureBlock> &rock, int y, const BlockId &mossy) const;
    void fullLayer(std::vector<generation::Generator::FeatureBlock> &rock, int y, const BlockId &mossy) const;

    world_storage::ChunkColumn &_chunk;
    generation::Generator &_generator;
    std::deque<Position> _positions;
};

#endif // CUBICSERVER_GENERATION_FEATURES_SURFACE_FOREST_ROCK_HPP
