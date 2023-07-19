#include "tree.hpp"

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "Dimension.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "generation/generator.hpp"
#include "logging/logging.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Section.hpp"

using namespace generation::trees;

const void Tree::setRandomizer(const Position &pos)
{
    if (pos.x % 2 == 0 && pos.z % 2 == 1)
        _randomizer = (_chunk.getDimension()->getWorld()->getSeed() % pos.x) % 2;
    else if (pos.x % 2 == 0 && pos.z % 2 == 0)
        _randomizer = (_chunk.getDimension()->getWorld()->getSeed() % pos.z) % 2;
    else
        _randomizer = (_chunk.getDimension()->getWorld()->getSeed() % pos.y) % 2;
}

const void Tree::lowerLayers(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf) const
{
    for (int x = -2; x <= 2; x++) {
        for (int z = -2; z <= 2; z++) {
            if (x == 0 && z == 0 || (_randomizer == 0 && (x == -2 && z == -2 || x == 2 && z == 2 || x == -2 && z == 2 || x == 2 && z == -2)))
                continue;
            tree.emplace_back(generation::Generator::TreeBlock {{x, y, z}, leaf});
        }
    }
}

const void Tree::secondLayer(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf) const
{
    for (int x = -1, counter = 1; x <= 1; x++) {
        for (int z = -1; z <= 1; z++) {
            if (x == 0 && z == 0 || counter > MAX_CORNER_LEAVES_LAYER_TWO)
                continue;
            if (_randomizer == 0 && (x == -1 && z == -1 || x == 1 && z == 1 || x == -1 && z == 1 || x == 1 && z == -1))
                counter += 1;
            tree.emplace_back(generation::Generator::TreeBlock {{x, y, z}, leaf});
        }
    }
}

const void Tree::topLayer(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf) const
{
    for (int x = -1; x <= 1; x++) {
        for (int z = -1; z <= 1; z++) {
            if (x * x == z * z && x != 0 && z != 0)
                continue;
            tree.emplace_back(generation::Generator::TreeBlock {{x, y, z}, leaf});
        }
    }
}

const void Tree::buildTree(const int treeSize, std::vector<generation::Generator::TreeBlock> &tree, const BlockId &leaf, const BlockId &log) const
{
    for (int y = 0; y <= treeSize + 1; y++) {
        // trunck generation
        if (y <= treeSize)
            tree.emplace_back(generation::Generator::TreeBlock {{0, y, 0}, log});

        // deciding of the leaves layout - layer 3 & 4
        if (y == treeSize - 1 || y == treeSize - 2) {
            lowerLayers(tree, y, leaf);
        }

        // deciding of the leaves layout - layer 2
        if (y == treeSize) {
            secondLayer(tree, y, leaf);
        }

        // deciding of the leaves layout - top layer
        if (y == treeSize + 1) {
            topLayer(tree, y, leaf);
        }
    }
}