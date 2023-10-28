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
                    _generator.setRandomizer({x, maxY, z});
                    if (y < midVal) {
                        spawnTryAtY = (spawnTries / (midVal - minY)) * y + spawnTries;
                        for (; spawnTryAtY > 0; spawnTryAtY--) {
                            if (_generator.getRandomizer() == int(spawnTryAtY) % 5) {
                                _positions.emplace_back(x, y + 1, z);
                                x = x + spawnSize;
                                z = z + spawnSize;
                                y = y - spawnSize;
                                break;
                            }
                        }
                    } else {
                        spawnTryAtY = -(spawnTries / (maxY - midVal)) * y + spawnTries;
                        for (; spawnTryAtY < 0; spawnTryAtY++) {
                            if (_generator.getRandomizer() == int(abs(spawnTryAtY)) % 5) {
                                _positions.emplace_back(x, y + 1, z);
                                x = x + spawnSize;
                                z = z + spawnSize;
                                y = y - spawnSize;
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
                        if (_generator.getRandomizer() == spawnTry % 5) {
                            _positions.emplace_back(x, y + 1, z);
                            x = x + spawnSize;
                            z = z + spawnSize;
                            y = y - spawnSize;
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

const std::vector<generation::Generator::FeatureBlock> OreVein::createBlob(const BlockId &blockID, const int spawnSize, const Position &pos) const
{
    auto nbOfBlocksInBlob = utility::PseudoRandomGenerator::getInstance()->generateNumber(0, MAX_NB_OF_BLOCKS[spawnSize]);
    std::vector<generation::Generator::FeatureBlock> blob;
    int m = pos.x + spawnSize; /**< Longitudinal spread of the blob */
    int n = pos.z + spawnSize; /**< Latitudinal spread of the blob */
    int p = pos.y - spawnSize; /**< Altitudinal spread of the blob */
    int r = spawnSize / 2; /**< Radius of the blob */
    int blobLimits = ((pos.x - (m / 2)) ^ 2 + (pos.y - (p / 2)) ^ 2 + (pos.z - (n / 2)) ^ 2) - r ^ 2;
    int customSkipRate;

    for (int y = p, x = pos.x, z = pos.z; y < pos.y && x < m && z < n; y++, x++, z++) {
        for (int block = 0; block <= nbOfBlocksInBlob; block++) {
            customSkipRate = (x - (m / 2)) + (y - (p / 2)) + (z - (n / 2));
            if ((x < blobLimits && y < blobLimits && z < blobLimits) && utility::PseudoRandomGenerator::getInstance()->generateNumber(0, blobLimits) > customSkipRate) {
                blob.emplace_back(generation::Generator::FeatureBlock {{x, y, z}, blockID});
            }
        }
    }
    return blob;
}
