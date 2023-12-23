#include "tree.hpp"

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "Dimension.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "blocks.hpp"
#include "generation/generator.hpp"
#include "logging/logging.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Section.hpp"

#define LEAF_DISTANCE_TO_ID(blockId, distance) blockId + (4 * (distance - 1))

using namespace generation::trees;

void Tree::lowerLayers(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf) const
{
    for (int x = -2, counter = 2; x <= 2; x++) {
        for (int z = -2; z <= 2; z++) {
            // between 0 & 4 leaves in the corners
            if ((x == 0 && z == 0) || ((_generator.getRandomizer() != abs(y - counter) || _generator.getRandomizer() == counter) && abs(x * z) == 4)) {
                counter++;
                continue;
            }
            // tree.emplace_back(generation::Generator::FeatureBlock {{x, y, z}, leaf});
            Tree::placeLeaf(tree, generation::Generator::FeatureBlock {{x, y, z}, leaf});
        }
    }
}

void Tree::secondLayer(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf) const
{
    for (int x = -1, counter = 0; x <= 1; x++) {
        for (int z = -1; z <= 1; z++) {
            // between 1 & 3 leaves in the corners
            if (x != 0 && z != 0 && counter <= MAX_CORNER_LEAVES_LAYER_TWO) {
                if (_generator.getRandomizer() == abs(counter + x)) {
                    counter++;
                    continue;
                }
                counter++;
            }
            if (x != 0 && z != 0 && counter > MAX_CORNER_LEAVES_LAYER_TWO)
                continue;
            if (x == 0 && z == 0)
                continue;
            // tree.emplace_back(generation::Generator::FeatureBlock {{x, y, z}, leaf});
            Tree::placeLeaf(tree, generation::Generator::FeatureBlock {{x, y, z}, leaf});
        }
    }
}

void Tree::topLayer(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf) const
{
    for (int x = -1; x <= 1; x++) {
        for (int z = -1; z <= 1; z++) {
            // no leaves in the corners
            if (x * x == z * z && x != 0 && z != 0)
                continue;
            // tree.emplace_back(generation::Generator::FeatureBlock {{x, y, z}, leaf});
            Tree::placeLeaf(tree, generation::Generator::FeatureBlock {{x, y, z}, leaf});
        }
    }
}

void Tree::buildTree(const int treeSize, std::vector<generation::Generator::FeatureBlock> &tree, const BlockId &leaf, const BlockId &log) const
{
    for (int y = 0; y <= treeSize + 1; y++) {
        // trunck generation
        if (y <= treeSize)
            tree.emplace_back(generation::Generator::FeatureBlock {{0, y, 0}, log});

        // // deciding of the leaves layout - layer 3 & 4
        if (y == treeSize - 1 || y == treeSize - 2) {
            lowerLayers(tree, y, leaf);
        }

        // deciding of the leaves layout - layer 2
        if (y == treeSize) {
            secondLayer(tree, y, leaf);
        }

        // // deciding of the leaves layout - top layer
        if (y == treeSize + 1) {
            topLayer(tree, y, leaf);
        }
    }
}

void Tree::placeLeaf(std::vector<generation::Generator::FeatureBlock> &tree, generation::Generator::FeatureBlock leaf) const
{
    long tinyDistance = 8;
    for (const auto &block : tree) {
        // I'm sorry for this, but I don't have the time to do it properly
        // clang-format off
        if ((block.block >= Blocks::OakLog::toProtocol(Blocks::OakLog::Properties::Axis::X) && block.block <= Blocks::OakLog::toProtocol(Blocks::OakLog::Properties::Axis::Z)) ||
            (block.block >= Blocks::AcaciaLog::toProtocol(Blocks::AcaciaLog::Properties::Axis::X) && block.block <= Blocks::AcaciaLog::toProtocol(Blocks::AcaciaLog::Properties::Axis::Z)) ||
            (block.block >= Blocks::DarkOakLog::toProtocol(Blocks::DarkOakLog::Properties::Axis::X) && block.block <= Blocks::DarkOakLog::toProtocol(Blocks::DarkOakLog::Properties::Axis::Z)) ||
            (block.block >= Blocks::BirchLog::toProtocol(Blocks::BirchLog::Properties::Axis::X) && block.block <= Blocks::BirchLog::toProtocol(Blocks::BirchLog::Properties::Axis::Z)) ||
            (block.block >= Blocks::JungleLog::toProtocol(Blocks::JungleLog::Properties::Axis::X) && block.block <= Blocks::JungleLog::toProtocol(Blocks::JungleLog::Properties::Axis::Z)) ||
            (block.block >= Blocks::SpruceLog::toProtocol(Blocks::SpruceLog::Properties::Axis::X) && block.block <= Blocks::SpruceLog::toProtocol(Blocks::SpruceLog::Properties::Axis::Z)) ||
            (block.block >= Blocks::MangroveLog::toProtocol(Blocks::MangroveLog::Properties::Axis::X) && block.block <= Blocks::MangroveLog::toProtocol(Blocks::MangroveLog::Properties::Axis::Z)))
            tinyDistance = std::min(tinyDistance, leaf.pos.manhattanDistance(block.pos));
        // clang-format on
    }
    if (tinyDistance == 8)
        return;
    leaf.block = LEAF_DISTANCE_TO_ID(leaf.block, tinyDistance);
    tree.emplace_back(leaf);
}
