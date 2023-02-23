#include <PerlinNoise.hpp>

#include "protocol/Structures.hpp"
#include "types.hpp"
#include "overworld.hpp"
#include "generator.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "logging/Logger.hpp"

generation::Overworld::Overworld(Seed seed)
    : Generator(seed)
{
}

GlobalBlockId generation::Overworld::getBlock(position_type x, position_type y, position_type z)
{
    //! OLD
    // double test = y - world_storage::CHUNK_HEIGHT_MIN;
    // test = test / 384.0;
    // auto heightOffset = 100.0;
    // auto noise = getNoise(x, y, z);
    // double densityMultiplier = y < heightOffset
    //     ? ((y - world_storage::CHUNK_HEIGHT_MIN) / (heightOffset - (double) world_storage::CHUNK_HEIGHT_MIN)) / 100.0
    //     : ((y - world_storage::CHUNK_HEIGHT_MIN) / ((double) world_storage::CHUNK_HEIGHT_MAX - heightOffset)) / 100.0;

    // // logging::Logger::get_instance()->info(std::to_string(densityMultiplier));

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
    GlobalBlockId blockId = 0;

    if (y < surfaceLevel)
        blockId = 1;

    // Trying to make caves
    if (blockId == 1 && noise.noise3D.density >= 0.9 &&  noise.noise3D.density <= 1.1)
        blockId = 0;

    return blockId;
}

GlobalBlockId generation::Overworld::getBlock(const Position &pos)
{
    return getBlock(pos.x, pos.y, pos.z);
}

GlobalBiomeId generation::Overworld::getBiome(position_type x, position_type y, position_type z)
{
    // TODO: Implement lol
    return getNoise(x, y, z).noise2D.weirdness > 0.0 ? 0 : 1;
}

GlobalBiomeId generation::Overworld::getBiome(const Position &pos)
{
    return getBiome(pos.x, pos.y, pos.z);
}
