#ifndef CUBICSERVER_DEFAULT_DEFAULTWORLD_HPP
#define CUBICSERVER_DEFAULT_DEFAULTWORLD_HPP

#include "../World.hpp"
#include "WorldGroup.hpp"
#include "world_storage/Persistence.hpp"
#include <memory>

class DefaultWorld : public World {
public:
    DefaultWorld(std::shared_ptr<WorldGroup> worldGroup, std::string folder);
    ~DefaultWorld() override = default;
    void tick() override;
    void initialize() override;
    void stop() override;

    world_storage::Persistence persistence;
};

#endif // CUBICSERVER_DEFAULT_DEFAULTWORLD_HPP
