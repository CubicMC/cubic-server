#ifndef CUBICSERVER_GENERATION_FEATURES_TREE_OAK_HPP
#define CUBICSERVER_GENERATION_FEATURES_TREE_OAK_HPP

#include "tree.hpp"

namespace generation::trees {
struct OakTree : public Tree {
    OakTree(std::shared_ptr<world_storage::ChunkColumn> chunk, generation::Generator &generator):
        Tree(chunk, generator)
    {
    }

    std::deque<Position> &getPosForTreeGeneration() override;
    std::deque<Position> &filterTreeGrowSpace() override;
    void generateTree() override;
};
} // namespace generation::trees

#endif // CUBICSERVER_GENERATION_FEATURES_TREE_OAK_HPP
