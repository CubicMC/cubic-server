#ifndef CUBICSERVER_AI_WANDERING_HPP
#define CUBICSERVER_AI_WANDERING_HPP

#include "ai.hpp"

namespace ai {
class Wandering : public AI {
public:
    Wandering(Entity &);
    ~Wandering();

    bool see() override;
    void think() override;
    void act() override;
};
} // namespace ai
#endif // CUBICSERVER_AI_WANDERING_HPP
