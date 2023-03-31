#ifndef GENERATION_GENERATOR_HPP
#define GENERATION_GENERATOR_HPP

#include <PerlinNoise.hpp>
#include <cstdint>
#include <unordered_map>

#include "types.hpp"

namespace generation {
class Generator {
public:
    typedef Position::value_type position_type;

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

    virtual BlockId getBlock(position_type x, position_type y, position_type z) = 0;
    virtual BlockId getBlock(const Position &pos) = 0;
    virtual BiomeId getBiome(position_type x, position_type y, position_type z) = 0;
    virtual BiomeId getBiome(const Position &pos) = 0;

    virtual GenerationNoise getNoise(position_type x, position_type y, position_type z, double frequency = 0.02, uint8_t octaves = 3);

protected:
    bool isCached(position_type x, position_type y, position_type z);
    bool isCached2D(position_type x, position_type z);

protected:
    siv::PerlinNoise _noiseMaker;
    std::unordered_map<
        position_type, // x
        std::unordered_map<
            position_type, // z
            std::pair<
                GenerationNoise2D, std::unordered_map<position_type, GenerationNoise3D> // y
                >>>
        _noiseCache;
};
}

#endif // GENERATION_GENERATOR_HPP
