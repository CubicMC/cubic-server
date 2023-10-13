#ifndef CUBICSERVER_DEFAULT_THEEND_HPP
#define CUBICSERVER_DEFAULT_THEEND_HPP

#include "Dimension.hpp"
#include "default/DefaultWorld.hpp"

class TheEnd : public Dimension {
public:
    TheEnd(std::shared_ptr<DefaultWorld> world):
        Dimension(world, world_storage::DimensionType::END)
    {
    }
    ~TheEnd() override = default;

    void tick() override;
    void initialize() override;
    void spawnPlayer(Player &player) override;
    void removePlayer(int32_t entity_id) override;

    const std::string getDimensionTypeName() const override { return "minecraft:the_end"; }
    const std::string getDimensionName() const override { return "the_end"; }
};

#endif // CUBICSERVER_DEFAULT_THEEND_HPP
