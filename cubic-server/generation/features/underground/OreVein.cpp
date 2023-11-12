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

bool OreVein::isSkippedWhenAirExposed(Position pos, const int spawnSize, const double skipRate)
{
    for (int x = pos.x; x < pos.x + spawnSize; x++) {
        for (int y = pos.y; y < pos.y + spawnSize; y++) {
            for (int z = pos.z; z < pos.z + spawnSize; z++) {
                auto block = _chunk.getBlock({x, y, z});
                if (block == Blocks::Air::toProtocol() && skipRate == 1) {
                    return true;
                } else if (block == Blocks::Air::toProtocol() && skipRate > 0 && (utility::PseudoRandomGenerator::getInstance()->generateNumber(0, 10) < skipRate * 10)) {
                    return true;
                }
            }
        }
    }
    return false;
}

std::deque<Position> OreVein::addPositions(const double spawnTries, const int minY, const int maxY, const int spawnSize, const double skipRate, const int spawnRate)
{
    using namespace world_storage;
    std::deque<Position> positions;

    for (int spawnTry = spawnTries; spawnTry > 0;) {
        for (int z = utility::PseudoRandomGenerator::getInstance()->generateNumber(0, SECTION_WIDTH / 2); z < SECTION_WIDTH; z++) {
            for (int x = utility::PseudoRandomGenerator::getInstance()->generateNumber(0, SECTION_WIDTH / 2); x < SECTION_WIDTH; x++) {
                int y = utility::PseudoRandomGenerator::getInstance()->generateNumber(minY, maxY);
                auto block = _chunk.getBlock({x, y, z});
                if (block == Blocks::Stone::toProtocol() && !isSkippedWhenAirExposed({x, y, z}, spawnSize, skipRate) && y > CHUNK_HEIGHT_MIN &&
                    (utility::PseudoRandomGenerator::getInstance()->generateNumber(0, 100) < spawnRate)) {
                    positions.emplace_back(x, y, z);
                    spawnTry--;
                    x < z ? x = x + MAX_NB_OF_BLOCKS[spawnSize] % SECTION_WIDTH : z = z + MAX_NB_OF_BLOCKS[spawnSize] % SECTION_WIDTH;
                }
            }
        }
    }
    return positions;
}

std::deque<Position> OreVein::computeTriangleDistribution(const int spawnSize, const double spawnTries, const int minY, const int maxY, const double skipRate)
{
    using namespace world_storage;
    std::deque<Position> positions;
    int positiveMinY = minY + abs(minY);
    int positiveMaxY = maxY + abs(minY);
    int midVal = (positiveMaxY - positiveMinY) / 2;
    double spawnRate = 0;

    for (int spawnTry = spawnTries; spawnTry > 0;) {
        for (int z = utility::PseudoRandomGenerator::getInstance()->generateNumber(0, SECTION_WIDTH / 2); z < SECTION_WIDTH; z++) {
            for (int x = utility::PseudoRandomGenerator::getInstance()->generateNumber(0, SECTION_WIDTH / 2); x < SECTION_WIDTH; x++) {
                int y = utility::PseudoRandomGenerator::getInstance()->generateNumber(positiveMinY, positiveMaxY);
                if ((y - abs(minY)) > CHUNK_HEIGHT_MIN && (y - abs(minY)) < CHUNK_HEIGHT_MAX) {
                    auto block = _chunk.getBlock({x, (y - abs(minY)), z});
                    if (y < midVal) {
                        spawnRate = -((spawnTries * y) / midVal) + spawnTries;
                    } else {
                        spawnRate = ((spawnTries * y) / midVal) - spawnTries;
                    }
                    if (block == Blocks::Stone::toProtocol() && !isSkippedWhenAirExposed({x, (y - abs(minY)), z}, spawnSize, skipRate) &&
                        (utility::PseudoRandomGenerator::getInstance()->generateNumber(0.0, spawnTries) < spawnRate)) {
                        positions.emplace_back(x, y - abs(minY), z);
                        spawnTry--;
                        x < z ? x = x + MAX_NB_OF_BLOCKS[spawnSize] : z = z + MAX_NB_OF_BLOCKS[spawnSize];
                    }
                }
            }
        }
    }
    return positions;
}

std::deque<Position>
OreVein::defineAllBlobPositions(const GenerationType generationType, const int spawnSize, const int minY, const int maxY, const double skipRate, const double spawnTries)
{
    using namespace world_storage;
    std::deque<Position> positions;

    if (generationType == GenerationType::UNIFORM) {
        positions = addPositions(spawnTries, minY, maxY, spawnSize, skipRate, UNIFORM_SPAWN_RATE);
    } else if (generationType == GenerationType::TRIANGLE) {
        positions = computeTriangleDistribution(spawnSize, spawnTries, minY, maxY, skipRate);
    }
    return positions;
}

void OreVein::createBlob(const BlockId &blockID, const int spawnSize, const Position &pos) const
{
    auto nbOfBlocksInBlob = utility::PseudoRandomGenerator::getInstance()->generateNumber(0, MAX_NB_OF_BLOCKS[spawnSize]);
    int m = pos.x + spawnSize; /**< Longitudinal spread of the blob */
    int n = pos.z + spawnSize; /**< Latitudinal spread of the blob */
    int p = pos.y + spawnSize; /**< Altitudinal spread of the blob */
    int r = spawnSize / 2; /**< Radius of the blob */
    int customSkipRate;
    int nb = 0;

    for (int y = pos.y; y < p && nb < nbOfBlocksInBlob; y++) {
        for (int x = pos.x; x < m; x++) {
            for (int z = pos.z; z < n; z++) {
                customSkipRate =
                    abs(((((m / 2) - x) % world_storage::SECTION_WIDTH) ^ 2) + ((((p / 2) - y) % world_storage::SECTION_WIDTH) ^ 2) +
                        ((((n / 2) - z) % world_storage::SECTION_WIDTH) ^ 2) % world_storage::SECTION_WIDTH);
                auto block = _chunk.getBlock({x, y, z});
                if ((x - pos.x < r && z - pos.z < r) && r / 2 > customSkipRate && nb < nbOfBlocksInBlob &&
                    (block != Blocks::Air::toProtocol() && block != Blocks::Bedrock::toProtocol()) && y > world_storage::CHUNK_HEIGHT_MIN) {
                    _chunk.updateBlock({x, y, z}, blockID);
                    nb++;
                }
            }
        }
    }
}

void OreVein::generateIronBlobs()
{
    std::deque<Position> posTriangle = defineAllBlobPositions(GenerationType::TRIANGLE, BLOB_SPAWN_SIZE_IRON_TRIANGLE, -24, 56, 0, 10);
    std::deque<Position> posUniform = defineAllBlobPositions(GenerationType::UNIFORM, BLOB_SPAWN_SIZE_IRON_UNIFORM, -64, 72, 0, 10);

    while (!posTriangle.empty()) {
        createBlob(Blocks::IronOre::toProtocol(), BLOB_SPAWN_SIZE_IRON_TRIANGLE, posTriangle.back());
        posTriangle.pop_back();
    }
    while (!posUniform.empty()) {
        createBlob(Blocks::IronOre::toProtocol(), BLOB_SPAWN_SIZE_IRON_UNIFORM, posUniform.back());
        posUniform.pop_back();
    }
}

void OreVein::generateRedstoneBlobs()
{
    std::deque<Position> posTriangle = defineAllBlobPositions(GenerationType::TRIANGLE, BLOB_SPAWN_SIZE_REDSTONE, -96, -32, 0, 8);
    std::deque<Position> posUniform = defineAllBlobPositions(GenerationType::UNIFORM, BLOB_SPAWN_SIZE_REDSTONE, -64, 15, 0, 4);

    while (!posTriangle.empty()) {
        createBlob(Blocks::RedstoneOre::toProtocol(Blocks::RedstoneOre::Properties::Lit::FALSE), BLOB_SPAWN_SIZE_REDSTONE, posTriangle.back());
        posTriangle.pop_back();
    }
    while (!posUniform.empty()) {
        createBlob(Blocks::RedstoneOre::toProtocol(Blocks::RedstoneOre::Properties::Lit::FALSE), BLOB_SPAWN_SIZE_REDSTONE, posUniform.back());
        posUniform.pop_back();
    }
}

void OreVein::generateDiamondBlobs()
{
    std::deque<Position> posTriangleOne = defineAllBlobPositions(GenerationType::TRIANGLE, BLOB_SPAWN_SIZE_DIAMOND_BARELY_EXPOSED, -144, 16, 0.7, (1 / 9));
    std::deque<Position> posTriangleTwo = defineAllBlobPositions(GenerationType::TRIANGLE, BLOB_SPAWN_SIZE_DIAMOND_HALF_EXPOSED, -144, 16, 0.5, 7);
    std::deque<Position> posTriangleThree = defineAllBlobPositions(GenerationType::TRIANGLE, BLOB_SPAWN_SIZE_DIAMOND_HIDDEN, -144, 16, 1, 4);

    while (!posTriangleOne.empty()) {
        createBlob(Blocks::DiamondOre::toProtocol(), BLOB_SPAWN_SIZE_DIAMOND_BARELY_EXPOSED, posTriangleOne.back());
        posTriangleOne.pop_back();
    }
    while (!posTriangleTwo.empty()) {
        createBlob(Blocks::DiamondOre::toProtocol(), BLOB_SPAWN_SIZE_DIAMOND_HALF_EXPOSED, posTriangleTwo.back());
        posTriangleTwo.pop_back();
    }
    while (!posTriangleThree.empty()) {
        createBlob(Blocks::DiamondOre::toProtocol(), BLOB_SPAWN_SIZE_DIAMOND_HIDDEN, posTriangleThree.back());
        posTriangleThree.pop_back();
    }
}

void OreVein::generateCoalBlobs()
{
    std::deque<Position> posTriangle = defineAllBlobPositions(GenerationType::TRIANGLE, BLOB_SPAWN_SIZE_COAL, 0, 192, 0.5, 20);
    std::deque<Position> posUniform = defineAllBlobPositions(GenerationType::UNIFORM, BLOB_SPAWN_SIZE_COAL, 136, 320, 0, 30);
    std::deque<Position> posUniformBis = defineAllBlobPositions(GenerationType::UNIFORM, BLOB_SPAWN_SIZE_COAL, 128, 156, 0, 0);

    while (!posTriangle.empty()) {
        createBlob(Blocks::CoalOre::toProtocol(), BLOB_SPAWN_SIZE_COAL, posTriangle.back());
        posTriangle.pop_back();
    }
    while (!posUniform.empty()) {
        createBlob(Blocks::CoalOre::toProtocol(), BLOB_SPAWN_SIZE_COAL, posUniform.back());
        posUniform.pop_back();
    }
    while (!posUniformBis.empty()) {
        createBlob(Blocks::CoalOre::toProtocol(), BLOB_SPAWN_SIZE_COAL, posUniformBis.back());
        posUniformBis.pop_back();
    }
}

void OreVein::generateEmeraldBlobs()
{
    std::deque<Position> posTriangle = defineAllBlobPositions(GenerationType::TRIANGLE, BLOB_SPAWN_SIZE_EMERALD, -16, 320, 0, 100);

    while (!posTriangle.empty()) {
        createBlob(Blocks::EmeraldOre::toProtocol(), BLOB_SPAWN_SIZE_EMERALD, posTriangle.back());
        posTriangle.pop_back();
    }
}

void OreVein::generateCopperBlobs()
{
    std::deque<Position> posTriangle = defineAllBlobPositions(GenerationType::TRIANGLE, BLOB_SPAWN_SIZE_COPPER, -16, 112, 0, 16);

    while (!posTriangle.empty()) {
        createBlob(Blocks::CopperOre::toProtocol(), BLOB_SPAWN_SIZE_COPPER, posTriangle.back());
        posTriangle.pop_back();
    }
}

void OreVein::generateLapisBlobs()
{
    std::deque<Position> posTriangle = defineAllBlobPositions(GenerationType::TRIANGLE, BLOB_SPAWN_SIZE_LAPIS, -32, 32, 0, 2);

    while (!posTriangle.empty()) {
        createBlob(Blocks::LapisOre::toProtocol(), BLOB_SPAWN_SIZE_LAPIS, posTriangle.back());
        posTriangle.pop_back();
    }
}

void OreVein::generateGoldBlobs()
{
    std::deque<Position> posTriangle = defineAllBlobPositions(GenerationType::TRIANGLE, BLOB_SPAWN_SIZE_GOLD, -64, 32, 0.5, 4);
    std::deque<Position> posUniform = defineAllBlobPositions(GenerationType::UNIFORM, BLOB_SPAWN_SIZE_GOLD, -64, -48, 0.5, 0.5);

    while (!posTriangle.empty()) {
        createBlob(Blocks::GoldOre::toProtocol(), BLOB_SPAWN_SIZE_GOLD, posTriangle.back());
        posTriangle.pop_back();
    }
    while (!posUniform.empty()) {
        createBlob(Blocks::GoldOre::toProtocol(), BLOB_SPAWN_SIZE_GOLD, posUniform.back());
        posUniform.pop_back();
    }
}

void OreVein::generateBlobs()
{
    generateIronBlobs();
    generateRedstoneBlobs();
    generateDiamondBlobs();
    // generateCoalBlobs(); TODO: Debug because buggy
    // generateEmeraldBlobs(); only in mountains biome
    generateCopperBlobs();
    generateLapisBlobs();
    generateGoldBlobs();
}
