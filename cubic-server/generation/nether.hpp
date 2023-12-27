#ifndef CUBICSERVER_GENERATION_NETHER_HPP
#define CUBICSERVER_GENERATION_NETHER_HPP

#include "generator.hpp"
#include "types.hpp"
#include <vector>

namespace generation {
class Nether : public Generator {
public:
    Nether(Seed seed);
    ~Nether() = default;

    BlockId getBlock(positionType x, positionType y, positionType z) override;
    BlockId getBlock(const Position &pos) override;

    BiomeId getBiome(positionType x, positionType y, positionType z) override;
    BiomeId getBiome(const Position &pos) override;

    int getTreeSize(positionType x, positionType y, positionType z, const TreeSize &treeSize) override;
    int getTreeSize(const Position &pos, const TreeSize &treeSize) override;
};
}

#endif // CUBICSERVER_GENERATION_NETHER_HPP
