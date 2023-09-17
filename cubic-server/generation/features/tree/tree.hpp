#ifndef CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP
#define CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP

#include <deque>
#include <memory>
#include <vector>

#include "generation/generator.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

constexpr int MAX_CORNER_LEAVES_LAYER_TWO = 3;
constexpr int MAX_SIZE_LEAVES_LAYER = 2;

namespace generation::trees {
class Tree {
public:
    Tree(world_storage::ChunkColumn &chunk, generation::Generator &generator):
        _chunk(chunk),
        _generator(generator)
    {
    }
    virtual std::deque<Position> &getPosForTreeGeneration() = 0;
    virtual std::deque<Position> &filterTreeGrowSpace() = 0;
    virtual void generateTree(std::vector<world_storage::ChunkColumn *>) = 0;

protected:
    virtual const std::vector<generation::Generator::FeatureBlock> getTree(const Position &pos) const = 0;
    virtual const std::vector<generation::Generator::FeatureBlock> getTree(Generator::positionType x, Generator::positionType y, Generator::positionType z) const = 0;

    void buildTree(const int treeSize, std::vector<generation::Generator::FeatureBlock> &tree, const BlockId &leaf, const BlockId &log) const;
    void topLayer(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf) const;
    void secondLayer(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf) const;
    void lowerLayers(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf) const;

    /**
     * @brief Place a leaf block in the tree vector with the correct distance to a log block
     *
     * @param tree The tree vector
     * @param block The leaf block to place
     */
    void placeLeaf(std::vector<generation::Generator::FeatureBlock> &tree, generation::Generator::FeatureBlock block) const;

    world_storage::ChunkColumn &_chunk;
    generation::Generator &_generator;
    std::deque<Position> _positions;
    generation::Generator::TreeSize _treeSize;
};
} // namespace generation::trees

#endif // CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP
