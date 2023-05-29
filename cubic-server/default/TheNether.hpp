#ifndef CUBICSERVER_DEFAULT_THENETHER_HPP
#define CUBICSERVER_DEFAULT_THENETHER_HPP

#include "Dimension.hpp"
#include "default/DefaultWorld.hpp"

class TheNether : public Dimension {
public:
    TheNether(std::shared_ptr<DefaultWorld> world):
        Dimension(world)
    {
    }
    ~TheNether() override = default;

    void tick() override;
    void initialize() override;
};

#endif // CUBICSERVER_DEFAULT_THENETHER_HPP
