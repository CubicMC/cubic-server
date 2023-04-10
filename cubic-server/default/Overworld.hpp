#ifndef CUBICSERVER_OVERWORLD_HPP
#define CUBICSERVER_OVERWORLD_HPP

#include <future>

#include "../Dimension.hpp"
#include "world_storage/Persistence.hpp"

class Overworld : public Dimension {
public:
    Overworld(World *world):
        Dimension(world),
        persistence("world2") // TODO(huntears): Make this changeable through the config
    {
    }
    void tick() override;
    void initialize() override;
    void stop() override;
    void generateChunk(int x, int z) override;

private:
    std::future<void> _worldGenFuture;
    world_storage::Persistence persistence;
};

#endif // CUBICSERVER_OVERWORLD_HPP
