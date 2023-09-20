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
    void save(const std::string &folder) override;
};

#endif // CUBICSERVER_DEFAULT_THEEND_HPP
