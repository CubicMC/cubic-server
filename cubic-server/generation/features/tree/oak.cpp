#include "oak.hpp"

#include "blocks.hpp"
#include "world_storage/ChunkColumn.hpp"

using namespace generation::trees;

std::deque<Position> &OakTree::getPosForTreeGeneration(void)
{
    using namespace world_storage;
    for (int z = 0; z < SECTION_WIDTH; z++) {
        for (int x = 0; x < SECTION_WIDTH; x++) {
            for (int y = CHUNK_HEIGHT_MAX - 5; CHUNK_HEIGHT_MIN <= y; y--) {
                auto block = _chunk->getBlock({x, y, z});
                if (block == Blocks::Air::toProtocol())
                    continue;
                else {
                    if (block == Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE) || block == Blocks::Dirt::toProtocol()) {
                        if (_generator.getNoise(x + _chunk->getChunkPos().x * SECTION_WIDTH, y, z + _chunk->getChunkPos().z * SECTION_WIDTH).noise3D.density > 0.5 &&
                            _generator.getBiome(x + _chunk->getChunkPos().x * SECTION_WIDTH, y, z + _chunk->getChunkPos().z * SECTION_WIDTH))
                            _positions.push_back({x, y + 1, z});
                    }
                    break;
                }
            }
        }
    }
    return _positions;
}

std::deque<Position> &OakTree::filterTreeGrowSpace()
{
    for (auto treeEmplacement = _positions.begin(); treeEmplacement != _positions.end(); treeEmplacement++) {
        for (int i = 0; i <= 5; i++) {
            auto block = _chunk->getBlock({treeEmplacement->x, treeEmplacement->y + i, treeEmplacement->z});
            // Test for transparent blocks (with tags ?)
            if (block != Blocks::Air::toProtocol()) {
                if (treeEmplacement == _positions.begin()) {
                    _positions.pop_front();
                    treeEmplacement = _positions.begin();
                } else {
                    auto previous = treeEmplacement -= 1;
                    _positions.erase(treeEmplacement);
                    treeEmplacement = previous;
                }
            }
        }
    }
    return _positions;
}

void OakTree::generateTree()
{
    auto treeEmplacement = _positions.begin();
    // for (auto treeEmplacement : _positions) {
        // auto tree = generator.getTree(treeEmplacement.x + this->_chunkPos.x * SECTION_WIDTH, treeEmplacement.y, treeEmplacement.z + this->_chunkPos.z * SECTION_WIDTH);
        // for (auto block : tree) {
        // updateBlock({treeEmplacement.x + block.x, treeEmplacement.y + block.y, treeEmplacement.z + block.z}, block.block);
        // }
        // this code is for testing only
        _chunk->updateBlock({treeEmplacement->x, treeEmplacement->y, treeEmplacement->z}, Blocks::OakLog::toProtocol(Blocks::OakLog::Properties::Axis::Y));
    // }
}
