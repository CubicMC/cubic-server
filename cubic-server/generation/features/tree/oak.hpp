#ifndef CUBICSERVER_GENERATION_FEATURES_TREE_OAK_HPP
#define CUBICSERVER_GENERATION_FEATURES_TREE_OAK_HPP

#include "tree.hpp"

struct OakTree : public Tree {
    virtual std::vector<Position> getPosForTreeGeneration() override;
    virtual std::vector<Position> &filterTreeGrowSpace(std::vector<Position> &) override;
    virtual void generateTrees(std::vector<Position> &) override;
};

#endif // CUBICSERVER_GENERATION_FEATURES_TREE_OAK_HPP
