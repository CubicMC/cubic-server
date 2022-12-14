#ifndef CUBICSERVER_THEEND_HPP
#define CUBICSERVER_THEEND_HPP

#include "../Dimension.hpp"

class TheEnd : public Dimension
{
public:
    TheEnd(World *world): Dimension(world) {}
    void tick() override;
    void initialize() override;
};


#endif //CUBICSERVER_THEEND_HPP
