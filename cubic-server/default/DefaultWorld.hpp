#ifndef CUBICSERVER_DEFAULT_DEFAULTWORLD_HPP
#define CUBICSERVER_DEFAULT_DEFAULTWORLD_HPP

#include "../World.hpp"

class DefaultWorld : public World {
public:
    DefaultWorld(WorldGroup *worldGroup);
    void tick() override;
    void initialize() override;
    void stop() override;
};

#endif // CUBICSERVER_DEFAULT_DEFAULTWORLD_HPP
