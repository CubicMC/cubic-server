#ifndef CUBICSERVER_DEFAULT_DEFAULTWORLD_HPP
#define CUBICSERVER_DEFAULT_DEFAULTWORLD_HPP

#include "../World.hpp"
#include "WorldGroup.hpp"

class DefaultWorld : public World {
public:
    DefaultWorld(std::shared_ptr<WorldGroup> worldGroup);
    void tick() override;
    void initialize() override;
    void stop() override;
};

#endif // CUBICSERVER_DEFAULT_DEFAULTWORLD_HPP
