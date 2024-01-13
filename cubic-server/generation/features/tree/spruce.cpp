#include "spruce.hpp"

#include <algorithm>
#include <vector>

#include "Server.hpp"
#include "blocks.hpp"
#include "generation/features/tree/tree.hpp"
#include "generation/generator.hpp"
#include "logging/logging.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Section.hpp"

using namespace generation::trees;

std::deque<Position> &SpruceTree::getPosForTreeGeneration(void)
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

std::deque<Position> &SpruceTree::filterTreeGrowSpace()
{
    std::erase_if(_positions, [this](const Position &pos) {
        for (int y = 0; y <= _generator.getTreeSize(pos, _treeSize); y++) {
            auto block = _chunk.getBlock({pos.x, pos.y + y, pos.z});
            if (block != Blocks::Air::toProtocol())
                return true;
            for (int x = -MAX_SIZE_LEAVES_LAYER_SPRUCE; x <= MAX_SIZE_LEAVES_LAYER_SPRUCE; x++) {
                for (int z = -MAX_SIZE_LEAVES_LAYER_SPRUCE; z <= MAX_SIZE_LEAVES_LAYER_SPRUCE; z++) {
                    if (x == 0 && z == 0)
                        continue;
                    if (pos.x + x < 0 || pos.x + x >= world_storage::SECTION_WIDTH || pos.z + z < 0 || pos.z + z >= world_storage::SECTION_WIDTH)
                        return true; // has to continue if we enable the generation of leaves outside the current chunk
                    auto block = _chunk.getBlock({pos.x + x, pos.y + y, pos.z + z});
                    if (block == Blocks::SpruceLog::toProtocol(Blocks::SpruceLog::Properties::Axis::Y))
                        return true;
                }
            }
        }
        return false;
    });
    return _positions;
}

void SpruceTree::bigLayer(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const
{
    for (int x = -2; x <= 2; x++) {
        for (int z = -2; z <= 2; z++) {
            // no leaves in the corners
            if (abs(x) == 2 && abs(z) == 2)
                continue;
            tree.emplace_back(generation::Generator::FeatureBlock {{0, y, 0}, log});
            // tree.emplace_back(generation::Generator::FeatureBlock {{x, y, z}, leaf});
            Tree::placeLeaf(tree, generation::Generator::FeatureBlock {{x, y, z}, leaf});
        }
    }
}

void SpruceTree::biggerLayer(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const
{
    for (int x = -3; x <= 3; x++) {
        for (int z = -3; z <= 3; z++) {
            // no leaves in the corners
            if (abs(x) == 3 && abs(z) == 3)
                continue;
            tree.emplace_back(generation::Generator::FeatureBlock {{0, y, 0}, log});
            // tree.emplace_back(generation::Generator::FeatureBlock {{x, y, z}, leaf});
            Tree::placeLeaf(tree, generation::Generator::FeatureBlock {{x, y, z}, leaf});
        }
    }
}

void SpruceTree::starLayer(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const
{
    for (int x = -1; x <= 1; x++) {
        for (int z = -1; z <= 1; z++) {
            // no leaves in the corners
            if (x != 0 && z != 0)
                continue;
            tree.emplace_back(generation::Generator::FeatureBlock {{0, y, 0}, log});
            // tree.emplace_back(generation::Generator::FeatureBlock {{x, y, z}, leaf});
            Tree::placeLeaf(tree, generation::Generator::FeatureBlock {{x, y, z}, leaf});
        }
    }
}

void SpruceTree::repetitivePattern(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log, UNUSED int treeSize) const
{
    for (int i = y, counter = 0; i >= (y - 3) && i > 0; i--, counter++) {
        if (counter % 2 == 0)
            starLayer(tree, i, leaf, log);
        else
            bigLayer(tree, i, leaf, log);
    }
}

void SpruceTree::bottomLeaves(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const
{
    if (_generator.getRandomizer() % 2 == 0)
        starLayer(tree, y, leaf, log);
    else
        biggerLayer(tree, y, leaf, log);
}

void SpruceTree::topStarLayers(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const
{
    for (int x = -1; x <= 1; x++) {
        for (int z = -1; z <= 1; z++) {
            if (x == 0 && z == 0) {
                // Placing the top leaf; if no leaf, air
                if (_generator.getRandomizer() != y % 2)
                    // tree.emplace_back(generation::Generator::FeatureBlock {{x, y + 2, z}, leaf});
                    Tree::placeLeaf(tree, generation::Generator::FeatureBlock {{x, y + 2, z}, leaf});
                // Placing the bottom leaf; if no leaf, a log
                if (_generator.getRandomizer() % 2 != 0)
                    // tree.emplace_back(generation::Generator::FeatureBlock {{x, y, z}, leaf});
                    Tree::placeLeaf(tree, generation::Generator::FeatureBlock {{x, y, z}, leaf});
                else
                    tree.emplace_back(generation::Generator::FeatureBlock {{x, y, z}, log});
            }
            if (x != 0 && z != 0)
                continue;
            // tree.emplace_back(generation::Generator::FeatureBlock {{x, y + 1, z}, leaf});
            Tree::placeLeaf(tree, generation::Generator::FeatureBlock {{x, y + 1, z}, leaf});
        }
    }
}

void SpruceTree::buildTree(const int treeSize, std::vector<generation::Generator::FeatureBlock> &tree, const BlockId &leaf, const BlockId &log) const
{
    for (int y = 0; y <= treeSize + 1; y++) {
        // deciding of the leaves layout - 3 top layers
        if (y == treeSize) {
            topStarLayers(tree, y, leaf, log);
        }

        // Placing the repetitive pattern below the top star - star/big/star/big
        if (y == treeSize - 1) {
            repetitivePattern(tree, y, leaf, log, treeSize);
        }

        // Placing a bottom layer if the tree is high enough - at least 1 visible trunk block above ground
        if (y == treeSize - 5 && treeSize == 6) {
            bottomLeaves(tree, y, leaf, log);
        }

        // Placing more bottom layers if the tree is higher - at least 7 log blocks
        if (y == treeSize - 5 && treeSize >= 7) {
            repetitivePattern(tree, y, leaf, log, treeSize);
        }

        // visible trunk block generation
        if (y == 0) {
            tree.emplace_back(generation::Generator::FeatureBlock {{0, y, 0}, log});
        }
    }
}

void SpruceTree::generateTree(UNUSED std::vector<world_storage::ChunkColumn *> neighbours)
{
    const auto &treeEmplacement = _positions.front();
    _generator.setRandomizer(treeEmplacement);
    auto tree = getTree(
        treeEmplacement.x + this->_chunk.getChunkPos().x * world_storage::SECTION_WIDTH, treeEmplacement.y,
        treeEmplacement.z + this->_chunk.getChunkPos().z * world_storage::SECTION_WIDTH
    );
    for (const auto &block : tree) {
        if (treeEmplacement.x + block.pos.x < 0 || treeEmplacement.x + block.pos.x >= world_storage::SECTION_WIDTH || treeEmplacement.z + block.pos.z < 0 ||
            treeEmplacement.z + block.pos.z >= world_storage::SECTION_WIDTH)
            continue;
        if (_chunk.getBlock({treeEmplacement.x + block.pos.x, treeEmplacement.y + block.pos.y, treeEmplacement.z + block.pos.z}) ==
            Blocks::SpruceLog::toProtocol(Blocks::SpruceLog::Properties::Axis::Y))
            continue;
        _chunk.modifyBlock({treeEmplacement.x + block.pos.x, treeEmplacement.y + block.pos.y, treeEmplacement.z + block.pos.z}, block.block);
    }
    _positions.pop_front();
}

const std::vector<generation::Generator::FeatureBlock> SpruceTree::getTree(const Position &pos) const
{
    std::vector<generation::Generator::FeatureBlock> tree;
    const auto treeSize = _generator.getTreeSize(pos, _treeSize);
    SpruceTree::buildTree(
        treeSize, tree,
        Blocks::SpruceLeaves::toProtocol(
            Blocks::SpruceLeaves::Properties::Distance::ONE, Blocks::SpruceLeaves::Properties::Persistent::FALSE, Blocks::SpruceLeaves::Properties::Waterlogged::FALSE
        ),
        Blocks::SpruceLog::toProtocol(Blocks::SpruceLog::Properties::Axis::Y)
    );
    return tree;
}

const std::vector<generation::Generator::FeatureBlock> SpruceTree::getTree(Generator::positionType x, Generator::positionType y, Generator::positionType z) const
{
    return getTree({x, y, z});
}
