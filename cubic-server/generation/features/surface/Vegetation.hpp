#ifndef CUBICSERVER_GENERATION_FEATURES_SURFACE_VEGETATION_HPP
#define CUBICSERVER_GENERATION_FEATURES_SURFACE_VEGETATION_HPP

#include <deque>
#include <vector>

#include "generation/generator.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

using namespace generation;

class Vegetation {
public:
    Vegetation(world_storage::ChunkColumn &chunk, Generator &generator):
        _chunk(chunk),
        _generator(generator)
    {
    }

    /**
     * @brief Filters all the positions where vegetation can generate
     *
     */
    std::deque<Position> &getPositions();

    /**
     * @brief Generates all the Vegetation items (poppies, dandelions or grass)
     *
     */
    void generateVegetation(std::vector<world_storage::ChunkColumn *>);

private:
    /**
     * @brief Randomize the type of the Vegetation that are generated (poppies, dandelions or grass)
     *
     * @param pos The position of the feature (here, a Vegetation)
     *
     */
    const std::vector<Generator::FeatureBlock> getVegetation(const Position &pos) const;

    void placeDandelions(std::vector<generation::Generator::FeatureBlock> &listOfFeatureBlocks, const Position &pos) const;
    void placePoppies(std::vector<generation::Generator::FeatureBlock> &listOfFeatureBlocks, const Position &pos) const;
    void placeOxeyeDaisies(std::vector<generation::Generator::FeatureBlock> &listOfFeatureBlocks, const Position &pos) const;
    void placeGrass(std::vector<generation::Generator::FeatureBlock> &listOfFeatureBlocks, const Position &pos) const;

    /**
     * The chunks where to generate Vegetations
     */
    world_storage::ChunkColumn &_chunk;

    /**
     * The generator, which provides the noise maps
     */
    generation::Generator &_generator;

    /**
     * The positions where a Vegetation can generate, initialized in getPositions()
     */
    std::deque<Position> _positions;
};

#endif // CUBICSERVER_GENERATION_FEATURES_SURFACE_VEGETATION_HPP
