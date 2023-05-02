#ifndef CUBICSERVER_GENERATION_OVERWORLD_HPP
#define CUBICSERVER_GENERATION_OVERWORLD_HPP

#include "generator.hpp"
#include "types.hpp"

namespace generation {
class Overworld : public Generator {
public:
    Overworld(Seed seed);
    BlockId getBlock(positionType x, positionType y, positionType z) override;
    BlockId getBlock(const Position &pos) override;

    BiomeId getBiome(positionType x, positionType y, positionType z) override;
    BiomeId getBiome(const Position &pos) override;
};
}

#endif // CUBICSERVER_GENERATION_OVERWORLD_HPP
