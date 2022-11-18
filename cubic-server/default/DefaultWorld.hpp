#ifndef CUBICSERVER_DEFAULTWORLD_HPP
#define CUBICSERVER_DEFAULTWORLD_HPP

#include "../World.hpp"
#include "Overworld.hpp"
#include "TheNether.hpp"
#include "TheEnd.hpp"

class DefaultWorld : public World
{
public:
    DefaultWorld(WorldGroup *worldGroup);
    void tick() override;
    void initialize() override;
};


#endif //CUBICSERVER_DEFAULTWORLD_HPP
