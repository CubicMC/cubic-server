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
                if (block == Blocks::Air::toProtocol())
                    continue;
                else {
                    if (block == Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE) || block == Blocks::Dirt::toProtocol()) {
                        if (_generator.getNoise(x + _chunk.getChunkPos().x * SECTION_WIDTH, y, z + _chunk.getChunkPos().z * SECTION_WIDTH).noise3D.density > 0 &&
                            _generator.getNoise(x + _chunk.getChunkPos().x * SECTION_WIDTH, y, z + _chunk.getChunkPos().z * SECTION_WIDTH).noise2D.rocks > 0.5 &&
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
            for (int x = -MAX_SIZE_ROCK; x <= MAX_SIZE_ROCK; x++) {
                for (int z = -MAX_SIZE_ROCK; z <= MAX_SIZE_ROCK; z++) {
                    if (x == 0 && z == 0)
                        continue;
                    if (pos.x + x < 0 || pos.x + x >= world_storage::SECTION_WIDTH || pos.z + z < 0 || pos.z + z >= world_storage::SECTION_WIDTH)
                        return true; // has to continue if we enable the generation of leaves outside the current chunk
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
    auto rock = getRock(
        rockEmplacement.x + this->_chunk.getChunkPos().x * world_storage::SECTION_WIDTH, rockEmplacement.y,
        rockEmplacement.z + this->_chunk.getChunkPos().z * world_storage::SECTION_WIDTH
    );
    for (const auto &block : rock) {
        if (rockEmplacement.x + block.pos.x < 0 || rockEmplacement.x + block.pos.x >= world_storage::SECTION_WIDTH || rockEmplacement.z + block.pos.z < 0 ||
            rockEmplacement.z + block.pos.z >= world_storage::SECTION_WIDTH)
            continue;
        // the following if may change/disappear
        if (_chunk.getBlock({rockEmplacement.x + block.pos.x, rockEmplacement.y + block.pos.y, rockEmplacement.z + block.pos.z}) == Blocks::MossyCobblestone::toProtocol())
            continue;
        _chunk.updateBlock({rockEmplacement.x + block.pos.x, rockEmplacement.y + block.pos.y, rockEmplacement.z + block.pos.z}, block.block);
    }
    _positions.pop_front();
}

void ForestRock::starLayer(std::vector<generation::Generator::FeatureBlock> &rock, int y, const BlockId &mossy) const
{
    for (int x = -1; x <= 1; x++) {
        for (int z = -1; z <= 1; z++) {
            // no rock in the corners
            if (x != 0 && z != 0)
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

const std::vector<generation::Generator::FeatureBlock> ForestRock::getRock(const Position &pos) const
{
    std::vector<generation::Generator::FeatureBlock> rock;
    const auto rockSize = MAX_SIZE_ROCK - 1;
    for (int y = 0; y <= rockSize + 1; y++) {
        starLayer(rock, y, Blocks::MossyCobblestone::toProtocol());
        fullLayer(rock, y, Blocks::MossyCobblestone::toProtocol());
        starLayer(rock, y, Blocks::MossyCobblestone::toProtocol());
    }
    return rock;
}

const std::vector<generation::Generator::FeatureBlock> ForestRock::getRock(Generator::positionType x, Generator::positionType y, Generator::positionType z) const
{
    return getRock({x, y, z});
}