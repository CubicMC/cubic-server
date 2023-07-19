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
    if (pos.x % 2 == 0 && pos.z % 2 != 0)
        _randomizer = abs((_chunk.getDimension()->getWorld()->getSeed() % pos.y) % 5);
    else if (pos.x % 2 != 0 && pos.z % 2 == 0)
        _randomizer = abs((_chunk.getDimension()->getWorld()->getSeed() % pos.z) % 5);
    else
        _randomizer = abs((_chunk.getDimension()->getWorld()->getSeed() % pos.x) % 5);
    // LINFO("RANDOMIZER : {}", _randomizer);
}

const void Tree::lowerLayers(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf) const
{
    for (int x = -2, counter = 2; x <= 2; x++) {
        for (int z = -2; z <= 2; z++) {
            // between 0 & 4 leaves in the corners
            if (x == 0 && z == 0 || ((_randomizer != abs(y - counter) || _randomizer == counter) && abs(x * z) == 4)) {
                counter++;
                continue;
            }
            tree.emplace_back(generation::Generator::TreeBlock {{x, y, z}, leaf});
        }
    }
}

const void Tree::secondLayer(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf) const
{
    for (int x = -1, counter = 0; x <= 1; x++) {
        for (int z = -1; z <= 1; z++) {
            // between 1 & 3 leaves in the corners
            if (x != 0 && z != 0 && counter <= MAX_CORNER_LEAVES_LAYER_TWO) {
                if (_randomizer == abs(counter + x)) {
                    counter++;
                    continue;
                }
                counter++;
            }
            if (x != 0 && z != 0 && counter > MAX_CORNER_LEAVES_LAYER_TWO)
                continue;
            if (x == 0 && z == 0)
                continue;
            tree.emplace_back(generation::Generator::TreeBlock {{x, y, z}, leaf});
        }
    }
}

const void Tree::topLayer(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf) const
{
    for (int x = -1; x <= 1; x++) {
        for (int z = -1; z <= 1; z++) {
            // no leaves in the corners
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