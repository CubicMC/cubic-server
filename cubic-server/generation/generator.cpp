#include "generator.hpp"
#include "generation/overworld.hpp"

void Tree::setRandomizer(const Position &pos)
{
    if (pos.x % 2 == 0 && pos.z % 2 != 0)
        _randomizer = abs((_chunk.getDimension()->getWorld()->getSeed() % pos.y) % 5);
    else if (pos.x % 2 != 0 && pos.z % 2 == 0)
        _randomizer = abs((_chunk.getDimension()->getWorld()->getSeed() % pos.z) % 5);
    else
        _randomizer = abs((_chunk.getDimension()->getWorld()->getSeed() % pos.x) % 5);
    // LINFO("RANDOMIZER : {}", _randomizer);
}

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
    noise.noise2D.weirdness = _noiseMaker.octave2D_11(_x, _z, octaves);
    noise.noise2D.trees = _noiseMaker.octave2D_11(x * 0.5, z * 0.5, 1);

    _noiseCache[x][z].first = noise.noise2D;
    noise.noise3D = _noiseCache[x][z].second[y];

    return noise;
}
