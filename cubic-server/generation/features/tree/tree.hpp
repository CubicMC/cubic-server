#ifndef CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP
#define CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP

#include <deque>
#include <memory>
#include <vector>

#include "generation/generator.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

constexpr int MAX_CORNER_LEAVES_LAYER_TWO = 3;

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
    virtual const std::vector<generation::Generator::TreeBlock> getTree(const Position &pos) const = 0;
    virtual const std::vector<generation::Generator::TreeBlock> getTree(Generator::positionType x, Generator::positionType y, Generator::positionType z) const = 0;
    const void setRandomizer(const Position &pos);

    const void buildTree(const int treeSize, std::vector<generation::Generator::TreeBlock> &tree, const BlockId &leaf, const BlockId &log) const;
    const void topLayer(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf) const;
    const void secondLayer(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf) const;
    const void lowerLayers(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf) const;

    world_storage::ChunkColumn &_chunk;
    generation::Generator &_generator;
    std::deque<Position> _positions;
    generation::Generator::TreeSize _treeSize;
    int _randomizer;
};
} // namespace generation::trees

#endif // CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP
