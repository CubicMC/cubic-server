#include "forestRock.hpp"

#include <algorithm>
#include <vector>

#include "Server.hpp"
#include "blocks.hpp"
#include "generation/generator.hpp"
#include "logging/logging.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Section.hpp"

std::deque<Position> &ForestRock::getPosForRockGeneration(void)
{
    using namespace world_storage;
    for (int z = 0; z < SECTION_WIDTH; z++) {
        for (int x = 0; x < SECTION_WIDTH; x++) {
            for (int y = CHUNK_HEIGHT_MAX - 5; CHUNK_HEIGHT_MIN <= y; y--) {
                auto block = _chunk.getBlock({x, y, z});
                if (block == Blocks::Air::toProtocol() || block == Blocks::SpruceLog::toProtocol(Blocks::SpruceLog::Properties::Axis::Y))
                    continue;
                else {
                    if (block == Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE) || block == Blocks::Dirt::toProtocol()) {
                        if (_generator.getNoise(x + _chunk.getChunkPos().x * SECTION_WIDTH, y, z + _chunk.getChunkPos().z * SECTION_WIDTH).noise3D.density > 0 &&
                            _generator.getNoise(x + _chunk.getChunkPos().x * SECTION_WIDTH, y, z + _chunk.getChunkPos().z * SECTION_WIDTH).noise2D.rocks > 0.55 &&
                            _generator.getBiome(x + _chunk.getChunkPos().x * SECTION_WIDTH, y, z + _chunk.getChunkPos().z * SECTION_WIDTH)) {
                            _positions.emplace_back(x, y + 1, z);
                        }
                    }
                    break;
                }
            }
        }
    }
    return _positions;
}

std::deque<Position> &ForestRock::filterRockOverlap()
{
    std::erase_if(_positions, [this](const Position &pos) {
        for (int y = 0; y <= MAX_SIZE_ROCK; y++) {
            auto block = _chunk.getBlock({pos.x, pos.y + y, pos.z});
            if (block != Blocks::Air::toProtocol())
                return true;
            for (int x = -MAX_SIZE_ROCK; x <= MAX_SIZE_ROCK; x++) {
                for (int z = -MAX_SIZE_ROCK; z <= MAX_SIZE_ROCK; z++) {
                    if (x == 0 && z == 0)
                        continue;
                    if (pos.x + x < 0 || pos.x + x >= world_storage::SECTION_WIDTH || pos.z + z < 0 || pos.z + z >= world_storage::SECTION_WIDTH)
                        return true; // has to continue if we enable the generation of rocks accross chunks
                    auto block = _chunk.getBlock({pos.x + x, pos.y + y, pos.z + z});
                    if (block == Blocks::MossyCobblestone::toProtocol())
                        return true;
                }
            }
        }
        return false;
    });
    return _positions;
}

void ForestRock::generateRock(std::vector<world_storage::ChunkColumn *>)
{
    const auto &rockEmplacement = _positions.front();
    _generator.setRandomizer(rockEmplacement);
    auto rock = getRock(rockEmplacement);
    for (const auto &block : rock) {
        if (rockEmplacement.x + block.pos.x < 0 || rockEmplacement.x + block.pos.x >= world_storage::SECTION_WIDTH || rockEmplacement.z + block.pos.z < 0 ||
            rockEmplacement.z + block.pos.z >= world_storage::SECTION_WIDTH)
            continue;
        // the following if may change/disappear
        if (_chunk.getBlock({rockEmplacement.x + block.pos.x, rockEmplacement.y + block.pos.y, rockEmplacement.z + block.pos.z}) == Blocks::MossyCobblestone::toProtocol())
            continue;
        _chunk.modifyBlock({rockEmplacement.x + block.pos.x, rockEmplacement.y + block.pos.y, rockEmplacement.z + block.pos.z}, block.block);
    }
    _positions.pop_front();
}

void ForestRock::starLayer(std::vector<generation::Generator::FeatureBlock> &rock, int y, const BlockId &mossy) const
{
    bool bigRock = false;

    for (int x = -1; x <= 1; x++) {
        for (int z = -1; z <= 1; z++) {
            // no rock in the corners
            if ((!bigRock && abs(x) == 1 && abs(z) == 1))
                continue;
            rock.emplace_back(generation::Generator::FeatureBlock {{x, y, z}, mossy});
        }
    }
}

void ForestRock::fullLayer(std::vector<generation::Generator::FeatureBlock> &rock, int y, const BlockId &mossy) const
{
    for (int x = -1; x <= 1; x++) {
        for (int z = -1; z <= 1; z++) {
            rock.emplace_back(generation::Generator::FeatureBlock {{x, y, z}, mossy});
        }
    }
}

void ForestRock::placeBits(std::vector<generation::Generator::FeatureBlock> &rock, const BlockId &mossy, const int rockSize, const Position &pos) const
{
    int x = -1;
    int z = -1;

    if (rockSize == MAX_SIZE_ROCK) {
        if (pos.y % 2 == 0)
            x = OFFSET_BIG_ROCK;
        else
            z = OFFSET_BIG_ROCK;
    }

    for (int countY = OFFSET_BIG_ROCK; countY <= OFFSET_BIG_ROCK + 1; countY++) {
        for (int countX = x; countX <= 1; countX++) {
            for (int countZ = z; countZ <= 1; countZ++) {
                if ((pos.x % 2 == 0 && countZ == _generator.getRandomizer() % 2 && abs(countY) == pos.y % 2) ||
                    (_generator.getRandomizer() % 2 != abs(countZ) && abs(countY) != pos.y % 2 && abs(countX) % 2 == _generator.getRandomizer() % 2) ||
                    ((countX == 0 || countX == -2) && countY == -1 && pos.z % 2 == _generator.getRandomizer() % 2) ||
                    (countX == _generator.getRandomizer() % 2 && abs(countY - countX) % 2 && abs(countZ) % 2 != 0))
                    rock.emplace_back(generation::Generator::FeatureBlock {{countX, countY, countZ}, mossy});
            }
        }
    }
}

void ForestRock::placeTinyBits(std::vector<generation::Generator::FeatureBlock> &rock, const BlockId &mossy, const Position &pos) const
{
    for (int countX = -1; countX <= 1; countX++) {
        for (int countZ = -1; countZ <= 1; countZ++) {
            if (pos.x % 2 == abs(countX) && countZ == _generator.getRandomizer() % 2)
                rock.emplace_back(generation::Generator::FeatureBlock {{countX, 0, countZ}, mossy});
        }
    }
}

void ForestRock::buildDiversifiedRocks(std::vector<generation::Generator::FeatureBlock> &rock, const int rockSize, const Position &pos) const
{
    if (_generator.getRandomizer() == 0) {
        for (int y = OFFSET_BIG_ROCK; y <= rockSize + OFFSET_BIG_ROCK; y++) {
            if (y == OFFSET_BIG_ROCK || y == rockSize + OFFSET_BIG_ROCK)
                starLayer(rock, y, Blocks::MossyCobblestone::toProtocol());
            else
                fullLayer(rock, y, Blocks::MossyCobblestone::toProtocol());
        }
    } else if (_generator.getRandomizer() >= 3) {
        placeBits(rock, Blocks::MossyCobblestone::toProtocol(), rockSize, pos);
    } else {
        placeTinyBits(rock, Blocks::MossyCobblestone::toProtocol(), pos);
    }
}

const std::vector<generation::Generator::FeatureBlock> ForestRock::getRock(const Position &pos) const
{
    std::vector<generation::Generator::FeatureBlock> rock;
    auto rockSize = 0;
    if (_generator.getRandomizer() == 4) {
        rockSize = MAX_SIZE_ROCK;
    } else {
        rockSize = MAX_SIZE_ROCK - 1;
    }
    buildDiversifiedRocks(rock, rockSize, pos);
    return rock;
}
