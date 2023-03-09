#ifndef GENERATION_OVERWORLD_HPP
#define GENERATION_OVERWORLD_HPP

#include <cstdint>

#include "types.hpp"
#include "generator.hpp"

namespace generation
{
    class Overworld : public Generator
    {
    public:
        Overworld(Seed seed);
        BlockId getBlock(position_type x, position_type y, position_type z) override;
        BlockId getBlock(const Position &pos) override;

        BiomeId getBiome(position_type x, position_type y, position_type z) override;
        BiomeId getBiome(const Position &pos) override;
    };
}

#endif // GENERATION_OVERWORLD_HPP
