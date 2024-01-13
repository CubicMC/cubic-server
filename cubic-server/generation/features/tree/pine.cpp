#include "pine.hpp"

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

std::deque<Position> &PineTree::getPosForTreeGeneration(void)
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

std::deque<Position> &PineTree::filterTreeGrowSpace()
{
    std::erase_if(_positions, [this](const Position &pos) {
        for (int y = 0; y <= _generator.getTreeSize(pos, _treeSize); y++) {
            auto block = _chunk.getBlock({pos.x, pos.y + y, pos.z});
            if (block != Blocks::Air::toProtocol())
                return true;
            for (int x = -MAX_SIZE_LEAVES_LAYER_PINE; x <= MAX_SIZE_LEAVES_LAYER_PINE; x++) {
                for (int z = -MAX_SIZE_LEAVES_LAYER_PINE; z <= MAX_SIZE_LEAVES_LAYER_PINE; z++) {
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

void PineTree::layerWithoutCorner(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log, int layerSize) const
{
    for (int x = -layerSize; x <= layerSize; x++) {
        for (int z = -layerSize; z <= layerSize; z++) {
            // no leaves in the corners
            if (abs(x) == layerSize && abs(z) == layerSize)
                continue;
            tree.emplace_back(generation::Generator::FeatureBlock {{0, y, 0}, log});
            // tree.emplace_back(generation::Generator::FeatureBlock {{x, y, z}, leaf});
            Tree::placeLeaf(tree, generation::Generator::FeatureBlock {{x, y, z}, leaf});
        }
    }
}

void PineTree::topLayers(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf) const
{
    // tree.emplace_back(generation::Generator::FeatureBlock {{0, y + 1, 0}, leaf});
    Tree::placeLeaf(tree, generation::Generator::FeatureBlock {{0, y + 1, 0}, leaf});
    layerWithoutCorner(tree, y, leaf, leaf, 1);
}

void PineTree::makeLongPine(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const
{
    layerWithoutCorner(tree, y, leaf, log, 1);
    layerWithoutCorner(tree, y - 1, leaf, log, 1);
}

void PineTree::makeMushroomPine(UNUSED const int treeSize, std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const
{
    if (_generator.getRandomizer() % 2 == 0) {
        layerWithoutCorner(tree, y, leaf, log, 2);
        layerWithoutCorner(tree, y - 1, leaf, log, 1);
    } else {
        layerWithoutCorner(tree, y, leaf, log, 2);
        layerWithoutCorner(tree, y - 1, leaf, log, 3);
        layerWithoutCorner(tree, y - 2, leaf, log, 2);
    }
}

void PineTree::buildTree(const int treeSize, std::vector<generation::Generator::FeatureBlock> &tree, const BlockId &leaf, const BlockId &log) const
{
    for (int y = 0; y <= treeSize + 1; y++) {
        // Top leaf & top star on top of the trunk
        if (y == treeSize + 1) {
            topLayers(tree, y, leaf);
        }

        // Add the other layers
        if (y == treeSize) {
            // I think this will have to change - setting the proportion of each variant
            if (_generator.getRandomizer() != abs(treeSize % 2)) {
                makeLongPine(tree, y, leaf, log);
            } else {
                makeMushroomPine(treeSize, tree, y, leaf, log);
            }
        }

        // trunk block generation
        if (y <= treeSize) {
            tree.emplace_back(generation::Generator::FeatureBlock {{0, y, 0}, log});
        }
    }
}

void PineTree::generateTree(UNUSED std::vector<world_storage::ChunkColumn *> neighbours)
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

const std::vector<generation::Generator::FeatureBlock> PineTree::getTree(const Position &pos) const
{
    std::vector<generation::Generator::FeatureBlock> tree;
    const auto treeSize = _generator.getTreeSize(pos, _treeSize);
    PineTree::buildTree(
        treeSize, tree,
        Blocks::SpruceLeaves::toProtocol(
            Blocks::SpruceLeaves::Properties::Distance::ONE, Blocks::SpruceLeaves::Properties::Persistent::FALSE, Blocks::SpruceLeaves::Properties::Waterlogged::FALSE
        ),
        Blocks::SpruceLog::toProtocol(Blocks::SpruceLog::Properties::Axis::Y)
    );
    return tree;
}

const std::vector<generation::Generator::FeatureBlock> PineTree::getTree(Generator::positionType x, Generator::positionType y, Generator::positionType z) const
{
    return getTree({x, y, z});
}
