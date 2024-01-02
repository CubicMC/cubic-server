#ifndef CUBICSERVER_DEFAULT_THENETHER_HPP
#define CUBICSERVER_DEFAULT_THENETHER_HPP

#include <future>

#include "Dimension.hpp"
#include "default/DefaultWorld.hpp"
#include "world_storage/Persistence.hpp"

class TheNether : public Dimension {
public:
    TheNether(std::shared_ptr<DefaultWorld> world):
        Dimension(world, world_storage::DimensionType::NETHER)
    {
    }
    ~TheNether() override = default;

    void tick() override;
    void initialize() override;
    void stop() override;
    void generateChunk(int x, int z, world_storage::GenerationState goalState = world_storage::GenerationState::READY) override;
    void spawnPlayer(Player &player) override;
    void removePlayer(int32_t entity_id) override;

private:
    std::future<void> _worldGenFuture;
};

#endif // CUBICSERVER_DEFAULT_THENETHER_HPP
