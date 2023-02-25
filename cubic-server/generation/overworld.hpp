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
        GlobalBlockId getBlock(position_type x, position_type y, position_type z) override;
        GlobalBlockId getBlock(const Position &pos) override;

        GlobalBiomeId getBiome(position_type x, position_type y, position_type z) override;
        GlobalBiomeId getBiome(const Position &pos) override;
    };
}

#endif // GENERATION_OVERWORLD_HPP
