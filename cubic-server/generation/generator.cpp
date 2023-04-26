#include "generator.hpp"

generation::Generator::Generator(Seed seed):
    _noiseMaker(seed)
{
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
    noise.noise3D.humidity = _noiseMaker.octave3D_11(_x, _z, _y, octaves);
    noise.noise3D.density = _noiseMaker.octave3D_11(_x, _z, _y, octaves);

    // Cache, calling it here because the next line create it if it doesn't exist
    bool cached2D = isCached2D(x, z);

    _noiseCache[x][z].second[y] = noise.noise3D;

    // 2D noise
    if (cached2D) {
        noise.noise2D = _noiseCache[x][z].first;
        return noise;
    }

    noise.noise2D.continentalness = _noiseMaker.octave2D_11(_x, _z, octaves);
    // noise.noise2D.erosion = _noiseMaker.octave2D_11(_x, _z, octaves);
    // noise.noise2D.peaksAndValley = _noiseMaker.octave2D_11(_x, _z, octaves);
    // noise.noise2D.weirdness = _noiseMaker.octave2D_11(_x, _z, octaves);

    _noiseCache[x][z].first = noise.noise2D;

    return noise;
}
