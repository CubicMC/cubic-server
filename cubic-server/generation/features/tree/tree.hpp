#ifndef CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP
#define CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP

#include <deque>
#include <memory>

#include "generation/generator.hpp"
#include "types.hpp"

namespace world_storage {
class ChunkColumn;
}
namespace generation::trees {
struct Tree {
    Tree(std::shared_ptr<world_storage::ChunkColumn> chunk, generation::Generator &generator):
        _chunk(chunk),
        _generator(generator)
    {
    }
    virtual std::deque<Position> &getPosForTreeGeneration() = 0;
    virtual std::deque<Position> &filterTreeGrowSpace() = 0;
    virtual void generateTree() = 0;

    std::shared_ptr<world_storage::ChunkColumn> _chunk;
    generation::Generator &_generator;
    std::deque<Position> _positions;
};
} // namespace generation::trees

#endif // CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP
