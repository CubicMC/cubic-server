#ifndef CUBICSERVER_GENERATION_FEATURES_SURFACE_FOREST_ROCK_HPP
#define CUBICSERVER_GENERATION_FEATURES_SURFACE_FOREST_ROCK_HPP

#include <deque>
#include <memory>
#include <vector>

#include "generation/generator.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

using namespace generation;

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
    const std::vector<Generator::FeatureBlock> getRock(const Position &pos) const;
    const std::vector<Generator::FeatureBlock> getRock(Generator::positionType x, Generator::positionType y, Generator::positionType z) const;
    void setRandomizer(const Position &pos);

    world_storage::ChunkColumn &_chunk;
    generation::Generator &_generator;
    std::deque<Position> _positions;
};

#endif // CUBICSERVER_GENERATION_FEATURES_SURFACE_FOREST_ROCK_HPP
