#ifndef CUBICSERVER_GENERATION_GENERATOR_HPP
#define CUBICSERVER_GENERATION_GENERATOR_HPP

#include <cstdint>
#include <mutex>
#include <unordered_map>

#include <PerlinNoise.hpp>

#include "types.hpp"

namespace generation {
class Generator {
public:
    typedef Position::valueType positionType;

    typedef struct {
        double continentalness;
        double erosion;
        double peaksAndValley;
        double weirdness;
        double trees;
        double rocks;
        double flowers;
        double grass;
    } GenerationNoise2D;

    typedef struct {
        double temperature;
        double humidity;
        /**
         * @brief Used to determine the terrain density
         */
        double density;
    } GenerationNoise3D;

    typedef struct {
        GenerationNoise2D noise2D;
        GenerationNoise3D noise3D;
    } GenerationNoise;

    typedef struct {
        Position pos;
        BlockId block;
    } FeatureBlock;

    typedef struct {
        int sizeMin;
        int sizeMax;
    } TreeSize;

public:
    Generator(Seed seed):
        _noiseMaker(seed),
        _seed(seed) {};
    virtual ~Generator() = default;

    /**
     * Set a randomizer number to a value between 0 & 4, based on the seed & the position of a block
     * @param pos The position of a block
     */
    void setRandomizer(const Position &pos);
    int getRandomizer() { return _randomizer; };

    virtual BlockId getBlock(positionType x, positionType y, positionType z) = 0;
    virtual BlockId getBlock(const Position &pos) = 0;
    virtual BiomeId getBiome(positionType x, positionType y, positionType z) = 0;
    virtual BiomeId getBiome(const Position &pos) = 0;

    /**
     * Generates noise and diverse noise maps for the generation
     */
    virtual GenerationNoise getNoise(positionType x, positionType y, positionType z, double frequency = 0.02, uint8_t octaves = 3);
    virtual int getTreeSize(positionType x, positionType y, positionType z, const TreeSize &treeSize) = 0;
    virtual int getTreeSize(const Position &pos, const TreeSize &treeSize) = 0;

protected:
    bool isCached(positionType x, positionType y, positionType z);
    bool isCached2D(positionType x, positionType z);

protected:
    siv::PerlinNoise _noiseMaker;
    std::unordered_map<
        positionType, // x
        std::unordered_map<
            positionType, // z
            std::pair<
                GenerationNoise2D, std::unordered_map<positionType, GenerationNoise3D> // y
                >>>
        _noiseCache;
    /**
     * A randomizer, based on the seed & the position of a block,
     * set in 'setRandomizer(const Position &pos)'
     */
    int _randomizer;

    /**
     * The world's seed
     */
    const Seed _seed;
};
}

#endif // CUBICSERVER_GENERATION_GENERATOR_HPP
