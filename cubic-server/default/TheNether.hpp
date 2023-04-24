#ifndef CUBICSERVER_DEFAULT_THENETHER_HPP
#define CUBICSERVER_DEFAULT_THENETHER_HPP

#include "../Dimension.hpp"

class TheNether : public Dimension {
public:
    TheNether(World *world):
        Dimension(world, world_storage::DimensionType::NETHER)
    {
    }
    void tick() override;
    void initialize() override;
};

#endif // CUBICSERVER_DEFAULT_THENETHER_HPP
