#include "generator.hpp"
#include "generation/nether.hpp"
#include "generation/overworld.hpp"

bool generation::Generator::isCached(positionType x, positionType y, positionType z) { return isCached2D(x, z) && _noiseCache[x][z].second.contains(y); }

bool generation::Generator::isCached2D(positionType x, positionType z) { return _noiseCache.contains(x) && _noiseCache[x].contains(z); }

generation::Generator::GenerationNoise generation::Generator::getNoise(positionType x, positionType y, positionType z, double frequency, uint8_t octaves)
{
    if (isCached(x, y, z))
        return {_noiseCache[x][z].first, _noiseCache[x][z].second[y]};

    GenerationNoise noise;

    double _x = static_cast<double>(x) * frequency;
    double _y = static_cast<double>(y) * frequency;
    double _z = static_cast<double>(z) * frequency;

    // 3D noise
    noise.noise3D.temperature = _noiseMaker.octave3D_11(_x, _z, _y, octaves);
    // noise.noise3D.humidity = _noiseMaker.octave3D_11(_x, _z, _y, octaves);
    noise.noise3D.density = _noiseMaker.octave3D_11(_x, _z, _y, octaves);

    bool is2DCached = isCached2D(x, z);
    _noiseCache[x][z].second[y] = noise.noise3D;

    // 2D noise
    if (is2DCached) {
        noise.noise2D = _noiseCache[x][z].first;
        return noise;
    }

    noise.noise2D.continentalness = _noiseMaker.octave2D_11(_x, _z, octaves);
    // noise.noise2D.erosion = _noiseMaker.octave2D_11(_x, _z, octaves);
    // noise.noise2D.peaksAndValley = _noiseMaker.octave2D_11(_x, _z, octaves);
    noise.noise2D.weirdness = _noiseMaker.octave2D_11(_x * 0.5, _z * 0.8, 6);
    noise.noise2D.trees = _noiseMaker.octave2D_11(x * 0.5, z * 0.4, 1);
    noise.noise2D.rocks = _noiseMaker.octave2D_11(x * 0.7, z * 0.4, 1);
    noise.noise2D.flowers = _noiseMaker.octave2D_11(x * 0.4, z * 0.2, 2);
    noise.noise2D.grass = _noiseMaker.octave2D_11(x * 0.3, z * 0.3, 2);

    _noiseCache[x][z].first = noise.noise2D;
    noise.noise3D = _noiseCache[x][z].second[y];

    return noise;
}

void generation::Generator::setRandomizer(const Position &pos)
{
    if (pos.y == 0 && pos.x != 0)
        _randomizer = std::abs((_seed % pos.x) % 5);
    else if (pos.x == 0 && pos.z != 0)
        _randomizer = std::abs((_seed % pos.z) % 5);
    else if (pos.z == 0 && pos.y != 0)
        _randomizer = std::abs((_seed % pos.y) % 5);

    if (pos.x != 0 && pos.y != 0 && pos.z != 0) {
        if (pos.x % 2 == 0 && pos.z % 2 != 0)
            _randomizer = std::abs((_seed % pos.y) % 5);
        else if (pos.x % 2 != 0 && pos.z % 2 == 0)
            _randomizer = std::abs((_seed % pos.z) % 5);
        else
            _randomizer = std::abs((_seed % pos.x) % 5);
    }
    // LINFO("RANDOMIZER : {}", _randomizer);
}
