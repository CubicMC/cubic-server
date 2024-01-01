#include "nether.hpp"

#include "blocks.hpp"
#include "options.hpp"
#include "types.hpp"

generation::Nether::Nether(Seed seed):
    Generator(seed)
{
}

BlockId generation::Nether::getBlock(positionType x, positionType y, positionType z)
{
    auto noise = getNoise(x, y, z);
    int heightOffset = 70;
    int surfaceLevel = heightOffset + noise.noise2D.continentalness * 10;
    BlockId blockId = Blocks::Air::toProtocol();

    if (y < surfaceLevel)
        blockId = Blocks::Netherrack::toProtocol();

    auto density = noise.noise3D.density * 0.5;
    if (blockId == Blocks::Netherrack::toProtocol() && density >= -.15 && density <= .05)
        blockId = Blocks::Air::toProtocol();

    return blockId;
}

BlockId generation::Nether::getBlock(const Position &pos) { return getBlock(pos.x, pos.y, pos.z); }

BiomeId generation::Nether::getBiome(positionType x, positionType y, positionType z) { return getNoise(x, y, z).noise2D.weirdness > 0.0 ? 0 : 1; }

BiomeId generation::Nether::getBiome(const Position &pos) { return getBiome(pos.x, pos.y, pos.z); }

int generation::Nether::getTreeSize(UNUSED positionType x, UNUSED positionType y, UNUSED positionType z, UNUSED const TreeSize &treeSize) { return 0; }

int generation::Nether::getTreeSize(UNUSED const Position &pos, UNUSED const TreeSize &treeSize) { return 0; }
