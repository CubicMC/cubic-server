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
                            _generator.getNoise(x + _chunk.getChunkPos().x * SECTION_WIDTH, y, z + _chunk.getChunkPos().z * SECTION_WIDTH).noise2D.trees > 0.4 &&
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
        for (int y = 0; y <= _generator.getTreeSize(pos, {4, 6}); y++) {
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
