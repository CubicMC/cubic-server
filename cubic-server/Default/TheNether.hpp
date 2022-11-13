#ifndef CUBICSERVER_THENETHER_HPP
#define CUBICSERVER_THENETHER_HPP

#include "../Dimension.hpp"

class TheNether : public Dimension
{
public:
    void tick() override;
    void initialize() override;
};


#endif //CUBICSERVER_THENETHER_HPP
