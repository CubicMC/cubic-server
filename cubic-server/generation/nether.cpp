#include "nether.hpp"

#include "blocks.hpp"
#include "options.hpp"
#include "types.hpp"
#include "world_storage/Section.hpp"

generation::Nether::Nether(Seed seed):
    Generator(seed)
{
}

BlockId generation::Nether::getBlock(positionType x, positionType y, positionType z)
{
    BlockId blockId = Blocks::Netherrack::toProtocol();
    auto noise = getNoise(x, y, z);
    auto density = noise.noise3D.density; // increase to add more netherrack, decrease to add more air
    auto densityCoef = std::abs(y) * 0.03; // coefficient to accentuate the variations of the terrain according to y
    auto seaLevel = 32; // lava sea level
    auto offset = 42; // arbitrary value for a flatter generation at sea level
    auto continentalness = seaLevel + (noise.noise2D.continentalness * (offset * 0.5));

    // adjusting the coefficient for smallest y values (y ∈ [-6 ; 6])
    if (std::abs(densityCoef) < 0.2)
        densityCoef = (densityCoef * 12) + 0.75;
    // adjusting the coefficient for smaller y values (y ∈ [-16 ; -6[ & ]6 ; 16])
    if (std::abs(densityCoef) < 0.5)
        densityCoef *= 8;
    // adjusting the coefficient for small y values (y ∈ [-19 ; -16[ & ]16 ; 19])
    if (std::abs(densityCoef) < 1.5)
        densityCoef *= 4.5;
    // adjusting the coefficient for big y values (y > 70)
    while (std::abs(densityCoef) > 2.1)
        densityCoef *= 0.85;

    density *= densityCoef;
    if (y >= 80)
        density *= (densityCoef * 1.25);
    if (y >= 100 || y <= -40)
        density *= (densityCoef * 2);
    if (y >= 110 || y <= -50)
        density *= 3;

    if (y < seaLevel)
        continentalness = seaLevel + (noise.noise2D.continentalness * offset);

    // carve some of the netherrack
    if ((blockId == Blocks::Netherrack::toProtocol() && density >= -0.5 && density <= 0.1) || (y >= world_storage::NETHER_ROOF))
        blockId = Blocks::Air::toProtocol();
    // add some flatter surfaces of netherrack at sea level
    if (y < continentalness && y > seaLevel - (offset * 0.4))
        blockId = Blocks::Netherrack::toProtocol();
    // Adjust the netherrack under lava level
    if (std::abs(density) <= 0.1 && y < seaLevel)
        blockId = Blocks::Air::toProtocol();

    return blockId;
}

BlockId generation::Nether::getBlock(const Position &pos) { return getBlock(pos.x, pos.y, pos.z); }

BiomeId generation::Nether::getBiome(UNUSED positionType x, UNUSED positionType y, UNUSED positionType z) { return 2; }

BiomeId generation::Nether::getBiome(const Position &pos) { return getBiome(pos.x, pos.y, pos.z); }

int generation::Nether::getTreeSize(UNUSED positionType x, UNUSED positionType y, UNUSED positionType z, UNUSED const TreeSize &treeSize) { return 0; }

int generation::Nether::getTreeSize(UNUSED const Position &pos, UNUSED const TreeSize &treeSize) { return 0; }
