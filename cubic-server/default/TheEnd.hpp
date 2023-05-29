#ifndef CUBICSERVER_DEFAULT_THEEND_HPP
#define CUBICSERVER_DEFAULT_THEEND_HPP

#include "Dimension.hpp"
#include "default/DefaultWorld.hpp"

class TheEnd : public Dimension {
public:
    TheEnd(std::shared_ptr<DefaultWorld> world):
        Dimension(world)
    {
    }
    ~TheEnd() override = default;

    void tick() override;
    void initialize() override;
};

#endif // CUBICSERVER_DEFAULT_THEEND_HPP
