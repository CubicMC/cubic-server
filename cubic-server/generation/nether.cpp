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
    BlockId blockId = Blocks::Netherrack::toProtocol();

    auto density = noise.noise3D.density * 1.5;
    if (y >= 100)
        density *= 0.75;
    if (y >= 200)
        density *= 1.5;
    if (y >= 270)
        density *= 5;
    if (y >= 310)
        density *= 100;
    if (blockId == Blocks::Netherrack::toProtocol() && density >= -0.5 && density <= 0.1)
        blockId = Blocks::Air::toProtocol();

    return blockId;
}

BlockId generation::Nether::getBlock(const Position &pos) { return getBlock(pos.x, pos.y, pos.z); }

BiomeId generation::Nether::getBiome(UNUSED positionType x, UNUSED positionType y, UNUSED positionType z) { return 2; }

BiomeId generation::Nether::getBiome(const Position &pos) { return getBiome(pos.x, pos.y, pos.z); }

int generation::Nether::getTreeSize(UNUSED positionType x, UNUSED positionType y, UNUSED positionType z, UNUSED const TreeSize &treeSize) { return 0; }

int generation::Nether::getTreeSize(UNUSED const Position &pos, UNUSED const TreeSize &treeSize) { return 0; }
