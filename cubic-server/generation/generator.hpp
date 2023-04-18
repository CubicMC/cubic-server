#ifndef CUBICSERVER_GENERATION_GENERATOR_HPP
#define CUBICSERVER_GENERATION_GENERATOR_HPP

#include <cstdint>
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

public:
    Generator(Seed seed);
    virtual ~Generator() = default;

    virtual BlockId getBlock(positionType x, positionType y, positionType z) = 0;
    virtual BlockId getBlock(const Position &pos) = 0;
    virtual BiomeId getBiome(positionType x, positionType y, positionType z) = 0;
    virtual BiomeId getBiome(const Position &pos) = 0;

    virtual GenerationNoise getNoise(positionType x, positionType y, positionType z, double frequency = 0.02, uint8_t octaves = 3);

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
};
}

#endif // CUBICSERVER_GENERATION_GENERATOR_HPP
