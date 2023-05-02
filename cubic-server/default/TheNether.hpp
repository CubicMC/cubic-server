#ifndef CUBICSERVER_DEFAULT_THENETHER_HPP
#define CUBICSERVER_DEFAULT_THENETHER_HPP

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

#endif // CUBICSERVER_DEFAULT_THENETHER_HPP
