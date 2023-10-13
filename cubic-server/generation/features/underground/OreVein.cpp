#include "OreVein.hpp"

#include <algorithm>
#include <vector>

#include "Server.hpp"
#include "blocks.hpp"
#include "generation/generator.hpp"
#include "logging/logging.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Section.hpp"

std::deque<Position> &OreVein::computeTriangleDistribution(const int spawnSize, const int minY, const int maxY, const int x, const int y, const int z)
{
    // computations to get the distribution in function of y
    return _positions;
}

std::deque<Position> &
OreVein::defineAllBlobPositions(const GenerationType generationType, const int spawnSize, const int minY, const int maxY, const double skipRate, const double spawnTries)
{
    using namespace world_storage;
    for (int z = 0; z < SECTION_WIDTH; z++) {
        for (int x = 0; x < SECTION_WIDTH; x++) {
            for (int y = maxY - 5; minY <= y; y--) {
                for (int spawnTry = spawnTries; spawnTry > 0; spawnTry--) {
                    _generator.setRandomizer({x, maxY, z});
                    auto block = _chunk.getBlock({x, y, z});
                    if (block == Blocks::Air::toProtocol() && skipRate == 1)
                        continue;
                    else {
                        if (_generator.getRandomizer() == spawnTry) {
                            if (generationType == GenerationType::UNIFORM) {
                                _positions.emplace_back(x, y + 1, z);
                            } else if (generationType == GenerationType::TRIANGLE) {
                                computeTriangleDistribution(spawnSize, minY, maxY, x, y, z);
                            }
                            x = x + spawnSize;
                            z = z + spawnSize;
                        }
                    }
                }
            }
        }
    }
    return _positions;
}
