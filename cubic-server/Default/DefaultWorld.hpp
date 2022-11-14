#ifndef CUBICSERVER_DEFAULTWORLD_HPP
#define CUBICSERVER_DEFAULTWORLD_HPP

#include "../World.hpp"
#include "Overworld.hpp"
#include "TheNether.hpp"
#include "TheEnd.hpp"

class DefaultWorld : public World
{
public:
    DefaultWorld();
    void tick() override;
    void initialize() override;
private:
    TheEnd *_theEnd;
    TheNether *_theNether;
    Overworld *_overworld;
};


#endif //CUBICSERVER_DEFAULTWORLD_HPP
