#ifndef CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP
#define CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP

#include <vector>

#include "types.hpp"

struct Tree {
    Tree(Position2D chunkPos):
        _chunkPos(chunkPos)
    {
    }
    virtual std::vector<Position> getPosForTreeGeneration();
    virtual std::vector<Position> &filterTreeGrowSpace(std::vector<Position> &);
    virtual void generateTrees(std::vector<Position> &);

    Position2D _chunkPos;
};

#endif // CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP
