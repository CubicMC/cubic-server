#include <PerlinNoise.hpp>

#include "generator.hpp"

generation::Generator::Generator(Seed seed)
    : _noiseMaker(seed)
{
}

bool generation::Generator::isCached(position_type x, position_type y, position_type z)
{
    return isCached2D(x, z) &&
        _noiseCache[x][z].second.find(y) != _noiseCache[x][z].second.end();
}

bool generation::Generator::isCached2D(position_type x, position_type z)
{
    return _noiseCache.find(x) != _noiseCache.end() &&
        _noiseCache[x].find(z) != _noiseCache[x].end();
}

generation::Generator::GenerationNoise generation::Generator::getNoise(position_type x, position_type y, position_type z, double frequency, uint8_t octaves)
{
    // if (isCached(x, y, z))
    //     return { _noiseCache[x][z].first, _noiseCache[x][z].second[y] };

    GenerationNoise noise;

    double _x = static_cast<double>(x) * frequency;
    double _y = static_cast<double>(y) * frequency;
    double _z = static_cast<double>(z) * frequency;

    // 3D noise
    noise.noise3D.temperature = _noiseMaker.octave3D_11(_x, _z, _y, octaves);
    noise.noise3D.humidity = _noiseMaker.octave3D_11(_x, _z, _y, octaves);
    noise.noise3D.density = _noiseMaker.octave3D_11(_x, _z, _y, octaves);

    _noiseCache[x][z].second = {{ y, noise.noise3D }};

    // 2D noise
    // if (isCached2D(x, z)) {
    //     noise.noise2D = _noiseCache[x][z].first;
    //     return noise;
    // }

    noise.noise2D.continentalness = _noiseMaker.octave2D_11(_x, _z, octaves);
    noise.noise2D.erosion = _noiseMaker.octave2D_11(_x, _z, octaves);
    noise.noise2D.peaksAndValley = _noiseMaker.octave2D_11(_x, _z, octaves);
    noise.noise2D.weirdness = _noiseMaker.octave2D_11(_x, _z, octaves);

    _noiseCache[x][z].first = noise.noise2D;

    return noise;
}
