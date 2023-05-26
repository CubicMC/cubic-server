#ifndef CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP
#define CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP

#include <deque>
#include <memory>

#include "generation/generator.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

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
    virtual void generateTree() = 0;

protected:
    virtual const std::vector<generation::Generator::TreeBlock> getTree(const Position &pos) = 0;
    virtual const std::vector<generation::Generator::TreeBlock> getTree(Generator::positionType x, Generator::positionType y, Generator::positionType z) = 0;

    world_storage::ChunkColumn &_chunk;
    generation::Generator &_generator;
    std::deque<Position> _positions;
    generation::Generator::TreeSize _treeSize;
};
} // namespace generation::trees

#endif // CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP
