#ifndef CUBICSERVER_THENETHER_HPP
#define CUBICSERVER_THENETHER_HPP

#include "../Dimension.hpp"

class TheNether : public Dimension {
public:
    TheNether(std::shared_ptr<World> world):
        Dimension(world)
    {
    }
    void tick() override;
    void initialize() override;
};

#endif // CUBICSERVER_THENETHER_HPP
