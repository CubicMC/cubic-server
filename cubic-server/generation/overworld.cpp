#include <PerlinNoise.hpp>

#include "generator.hpp"
#include "logging/Logger.hpp"
#include "overworld.hpp"
#include "protocol/Structures.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

generation::Overworld::Overworld(Seed seed):
    Generator(seed)
{
}

BlockId generation::Overworld::getBlock(positionType x, positionType y, positionType z)
{
    //! OLD
    // double test = y - world_storage::CHUNK_HEIGHT_MIN;
    // test = test / 384.0;
    // auto heightOffset = 100.0;
    // auto noise = getNoise(x, y, z);
    // double densityMultiplier = y < heightOffset
    //     ? ((y - world_storage::CHUNK_HEIGHT_MIN) / (heightOffset - (double) world_storage::CHUNK_HEIGHT_MIN)) / 100.0
    //     : ((y - world_storage::CHUNK_HEIGHT_MIN) / ((double) world_storage::CHUNK_HEIGHT_MAX - heightOffset)) / 100.0;

    // // LINFO(std::to_string(densityMultiplier));

    // // double densityMultiplier = std::tanh(y / 384) + heightOffset;

    // // if (noise.noise3D.density * -(densityMultiplier*2) >= 0.0)
    // if (noise.noise3D.density * densityMultiplier>= 0.0)
    //     return 0;
    // return 1;

    //! NEW
    // double u = getNoise(x, y, z).noise3D.density;
    // double heightOffset = 100.0;

    // double a = (u + 1) / 2;
    // double n = 2 * std::abs(
    //     (y - world_storage::CHUNK_HEIGHT_MIN) / (world_storage::CHUNK_HEIGHT_MAX - world_storage::CHUNK_HEIGHT_MIN)
    //     -
    //     (heightOffset - world_storage::CHUNK_HEIGHT_MIN) / (world_storage::CHUNK_HEIGHT_MAX - world_storage::CHUNK_HEIGHT_MIN)
    // );
    // // h correspond a la force de l'effet avec la hauteur
    // double h = 2;

    // a = y < heightOffset
    //     ? -std::pow(a, h * n + 1) + 1
    //     : std::pow(a, h * n + 1);
    // if (2 * a - 1 >= 0.0)
    //     return 1;
    // return 0;

    //! NEW NEW
    auto noise = getNoise(x, y, z);
    int heightOffset = 100;
    int surfaceLevel = heightOffset + noise.noise2D.continentalness * 20;
    BlockId blockId = 0;

    if (y < surfaceLevel)
        blockId = 1;

    // Trying to make caves
    // auto density = noise.noise3D.density / (1.0 / (double (y + world_storage::CHUNK_HEIGHT_MIN) + 0.001)) * 10;
    // auto density = (noise.noise3D.density + 1) / (1.0 / (double (y))) + 1;
    auto density = noise.noise3D.density;
    if (y >= 70)
        density *= 1.5;
    if (y >= 80)
        density *= 1.5;
    if (y >= 90)
        density *= 1.5;
    if (y >= 100)
        density *= 100.0;
    if (blockId == 1 && density >= -.15 && density <= .05)
        blockId = 0;
    // Trying to repair caves surface
    if (blockId == 0 && noise.noise3D.density >= -.4 && noise.noise3D.density <= .4 && y < surfaceLevel && y > heightOffset - 10)
        blockId = 1;

    return blockId;
}

BlockId generation::Overworld::getBlock(const Position &pos) { return getBlock(pos.x, pos.y, pos.z); }

BiomeId generation::Overworld::getBiome(positionType x, positionType y, positionType z)
{
    // TODO: Implement lol
    return getNoise(x, y, z).noise2D.weirdness > 0.0 ? 0 : 1;
}

BiomeId generation::Overworld::getBiome(const Position &pos) { return getBiome(pos.x, pos.y, pos.z); }
