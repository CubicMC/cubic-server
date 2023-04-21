#ifndef CUBICSERVER_GENERATION_FEATURES_TREE_OAK_HPP
#define CUBICSERVER_GENERATION_FEATURES_TREE_OAK_HPP

#include "tree.hpp"

class OakTree : public Tree {
public:
    OakTree(Seed seed, Position pos, uint8_t height, uint8_t radius);
    ~OakTree() = default;

    void generate(void) override;
};

#endif // CUBICSERVER_GENERATION_FEATURES_TREE_OAK_HPP
