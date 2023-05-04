#ifndef CUBICSERVER_DEFAULT_THEEND_HPP
#define CUBICSERVER_DEFAULT_THEEND_HPP

#include "../Dimension.hpp"

class TheEnd : public Dimension {
public:
    TheEnd(std::shared_ptr<World> world):
        Dimension(world, world_storage::DimensionType::END)
    {
    }
    void tick() override;
    void initialize() override;
};

#endif // CUBICSERVER_DEFAULT_THEEND_HPP
