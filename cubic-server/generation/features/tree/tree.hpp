#ifndef CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP
#define CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP

#include <cstdint>

#include "types.hpp"

class Tree {
public:
    Tree(Seed seed, Position pos, uint8_t height, uint8_t radius);
    virtual ~Tree() = default;

    virtual void generate(void) = 0;

protected:
    Seed _seed;
    Position _pos;
    uint8_t _height;
    uint8_t _radius;
};

#endif // CUBICSERVER_GENERATION_FEATURES_TREE_TREE_HPP
