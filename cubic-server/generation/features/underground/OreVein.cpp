#include "OreVein.hpp"

#include <algorithm>
#include <vector>

#include "Server.hpp"
#include "blocks.hpp"
#include "generation/generator.hpp"
#include "logging/logging.hpp"
#include "types.hpp"
#include "utility/PseudoRandomGenerator.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Section.hpp"

std::deque<Position> &OreVein::computeTriangleDistribution(const int spawnSize, const double spawnTries, const int minY, const int maxY, const double skipRate)
{
    using namespace world_storage;
    const int midVal = (maxY - minY) / 2;
    double spawnTryAtY = 0;

    for (int y = maxY - 5; minY <= y; y--) {
        for (int z = 0; z < SECTION_WIDTH; z++) {
            for (int x = 0; x < SECTION_WIDTH; x++) {
                auto block = _chunk.getBlock({x, y, z});
                if (block == Blocks::Air::toProtocol() && skipRate == 1)
                    continue;
                else if (block == Blocks::Air::toProtocol() && skipRate > 0) {
                    if (utility::PseudoRandomGenerator::getInstance()->generateNumber(0, 10) < skipRate * 10)
                        continue;
                } else {
                    if (y < midVal) {
                        spawnTryAtY = (spawnTries / (midVal - minY)) * y + spawnTries;
                        for (; spawnTryAtY > 0; spawnTryAtY--) {
                            if (_generator.getRandomizer() == spawnTryAtY) {
                                _positions.emplace_back(x, y + 1, z);
                                x = x + spawnSize;
                                z = z + spawnSize;
                                break;
                            }
                        }
                    } else {
                        spawnTryAtY = -(spawnTries / (maxY - midVal)) * y + spawnTries;
                        for (; spawnTryAtY < 0; spawnTryAtY++) {
                            if (_generator.getRandomizer() == spawnTryAtY) {
                                _positions.emplace_back(x, y + 1, z);
                                x = x + spawnSize;
                                z = z + spawnSize;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    return _positions;
}

std::deque<Position> &
OreVein::defineAllBlobPositions(const GenerationType generationType, const int spawnSize, const int minY, const int maxY, const double skipRate, const double spawnTries)
{
    using namespace world_storage;
    if (generationType == GenerationType::UNIFORM) {
        for (int y = maxY - 5; minY <= y; y--) {
            for (int z = 0; z < SECTION_WIDTH; z++) {
                for (int x = 0; x < SECTION_WIDTH; x++) {
                    auto block = _chunk.getBlock({x, y, z});
                    if (block == Blocks::Air::toProtocol() && skipRate == 1)
                        continue;
                    else if (block == Blocks::Air::toProtocol() && skipRate > 0) {
                        if (utility::PseudoRandomGenerator::getInstance()->generateNumber(0, 10) < skipRate * 10)
                            continue;
                    }
                    _generator.setRandomizer({x, maxY, z});
                    for (int spawnTry = spawnTries; spawnTry > 0; spawnTry--) {
                        if (_generator.getRandomizer() == spawnTry) {
                            _positions.emplace_back(x, y + 1, z);
                            x = x + spawnSize;
                            z = z + spawnSize;
                            break;
                        }
                    }
                }
            }
        }
    } else if (generationType == GenerationType::TRIANGLE) {
        computeTriangleDistribution(spawnSize, spawnTries, minY, maxY, skipRate);
    }
    return _positions;
}

