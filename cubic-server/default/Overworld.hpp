#ifndef CUBICSERVER_OVERWORLD_HPP
#define CUBICSERVER_OVERWORLD_HPP

#include "../Dimension.hpp"

class Overworld : public Dimension
{
public:
    Overworld(World *world): Dimension(world) {}
    void tick() override;
    void initialize() override;
    void generateChunk(int x, int z) override;
};


#endif //CUBICSERVER_OVERWORLD_HPP
