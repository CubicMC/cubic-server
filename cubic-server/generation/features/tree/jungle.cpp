#include "jungle.hpp"

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "blocks.hpp"
#include "generation/generator.hpp"
#include "logging/logging.hpp"
#include "Server.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Section.hpp"

#define COUNTER 1

using namespace generation::trees;

std::deque<Position> &JungleTree::getPosForTreeGeneration(void)
{
    using namespace world_storage;
    for (int z = 0; z < SECTION_WIDTH; z++) {
        for (int x = 0; x < SECTION_WIDTH; x++) {
            for (int y = CHUNK_HEIGHT_MAX - 5; CHUNK_HEIGHT_MIN <= y; y--) {
                auto block = _chunk.getBlock({ x, y, z });
                if (block == Blocks::Air::toProtocol())
                    continue;
                else {
                    if (block == Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE)
                        || block == Blocks::Dirt::toProtocol()) {
                        if (_generator
                                    .getNoise(
                                        x + _chunk.getChunkPos().x * SECTION_WIDTH, y,
                                        z + _chunk.getChunkPos().z * SECTION_WIDTH
                                    )
                                    .noise3D.density
                                > 0
                            && _generator
                                    .getNoise(
                                        x + _chunk.getChunkPos().x * SECTION_WIDTH, y,
                                        z + _chunk.getChunkPos().z * SECTION_WIDTH
                                    )
                                    .noise2D.trees
                                > 0.4
                            && _generator.getBiome(
                                x + _chunk.getChunkPos().x * SECTION_WIDTH, y,
                                z + _chunk.getChunkPos().z * SECTION_WIDTH
                            )) {
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

std::deque<Position> &JungleTree::filterTreeGrowSpace()
{
    std::erase_if(_positions, [this](const Position &pos) {
        for (int y = 0; y <= _generator.getTreeSize(pos, _treeSize); y++) {
            auto block = _chunk.getBlock({ pos.x, pos.y + y, pos.z });
            if (block != Blocks::Air::toProtocol())
                return true;
            for (int x = -MAX_SIZE_LEAVES_LAYER; x <= MAX_SIZE_LEAVES_LAYER; x++) {
                for (int z = -MAX_SIZE_LEAVES_LAYER; z <= MAX_SIZE_LEAVES_LAYER; z++) {
                    if (x == 0 && z == 0)
                        continue;
                    if (pos.x + x < 0 || pos.x + x >= world_storage::SECTION_WIDTH || pos.z + z < 0
                        || pos.z + z >= world_storage::SECTION_WIDTH)
                        return true; // has to continue if we enable the generation of leaves outside the current chunk
                    auto block = _chunk.getBlock({ pos.x + x, pos.y + y, pos.z + z });
                    if (block == Blocks::JungleLog::toProtocol(Blocks::JungleLog::Properties::Axis::Y))
                        return true;
                }
            }
        }
        return false;
    });
    return _positions;
}

void JungleTree::generateTree(UNUSED std::vector<world_storage::ChunkColumn *> neighbours)
{
    const auto &treeEmplacement = _positions.front();
    _generator.setRandomizer(treeEmplacement);
    auto tree = getTree(
        treeEmplacement.x + this->_chunk.getChunkPos().x * world_storage::SECTION_WIDTH, treeEmplacement.y,
        treeEmplacement.z + this->_chunk.getChunkPos().z * world_storage::SECTION_WIDTH
    );
    for (const auto &block : tree) {
        if (treeEmplacement.x + block.pos.x < 0 || treeEmplacement.x + block.pos.x >= world_storage::SECTION_WIDTH
            || treeEmplacement.z + block.pos.z < 0 || treeEmplacement.z + block.pos.z >= world_storage::SECTION_WIDTH)
            continue;
        if (_chunk.getBlock({ treeEmplacement.x + block.pos.x, treeEmplacement.y + block.pos.y,
                              treeEmplacement.z + block.pos.z })
            == Blocks::JungleLog::toProtocol(Blocks::JungleLog::Properties::Axis::Y))
            continue;
        _chunk.modifyBlock(
            { treeEmplacement.x + block.pos.x, treeEmplacement.y + block.pos.y, treeEmplacement.z + block.pos.z },
            block.block
        );
    }
    _positions.pop_front();
}

const std::vector<generation::Generator::FeatureBlock> JungleTree::getTree(const Position &pos) const
{
    std::vector<generation::Generator::FeatureBlock> tree;
    const auto treeSize = _generator.getTreeSize(pos, _treeSize);
    Tree::buildTree(
        treeSize, tree,
        Blocks::JungleLeaves::toProtocol(
            Blocks::JungleLeaves::Properties::Distance::ONE, Blocks::JungleLeaves::Properties::Persistent::FALSE,
            Blocks::JungleLeaves::Properties::Waterlogged::FALSE
        ),
        Blocks::JungleLog::toProtocol(Blocks::JungleLog::Properties::Axis::Y)
    );
    return tree;
}

const std::vector<generation::Generator::FeatureBlock> JungleTree::getTree(
    Generator::positionType x, Generator::positionType y, Generator::positionType z
) const
{
    return getTree({ x, y, z });
}
