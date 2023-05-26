#ifndef CUBICSERVER_DEFAULT_OVERWORLD_HPP
#define CUBICSERVER_DEFAULT_OVERWORLD_HPP

#include <future>

#include "../Dimension.hpp"

class Overworld : public Dimension {
public:
    Overworld(std::shared_ptr<World> world):
        Dimension(world)
    {
    }
    ~Overworld() override = default;

    void tick() override;
    void initialize() override;
    void stop() override;
    void generateChunk(int x, int z) override;

private:
    std::future<void> _worldGenFuture;
};

#endif // CUBICSERVER_DEFAULT_OVERWORLD_HPP
