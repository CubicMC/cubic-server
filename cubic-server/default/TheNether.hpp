#ifndef CUBICSERVER_DEFAULT_THENETHER_HPP
#define CUBICSERVER_DEFAULT_THENETHER_HPP

#include "Dimension.hpp"
#include "default/DefaultWorld.hpp"

class TheNether : public Dimension {
public:
    TheNether(std::shared_ptr<DefaultWorld> world):
        Dimension(world, world_storage::DimensionType::NETHER)
    {
    }
    ~TheNether() override = default;

    void tick() override;
    void initialize() override;
    void spawnPlayer(Player &player) override;
    void removePlayer(int32_t entity_id) override;

    std::string getDimensionTypeName () const override { return "minecraft:the_nether"; }
    std::string getDimensionName () const override { return "the_nether"; }

};

#endif // CUBICSERVER_DEFAULT_THENETHER_HPP
