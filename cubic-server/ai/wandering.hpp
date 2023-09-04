#ifndef CUBICSERVER_AI_WANDERING_HPP
#define CUBICSERVER_AI_WANDERING_HPP

#include "ai.hpp"

namespace ai {

/**
 * @brief The AI that make the entity wander around
 */
class Wandering : public AI {
public:
    Wandering(Entity &);
    ~Wandering();

    /**
     * @brief Always return true
     *
     * @return true
     * @return false
     */
    bool see() override;

    /**
     * @brief Create a path to a random position
     *
     */
    void think() override;

    /**
     * @brief Move the entity to the next position
     *
     */
    void act() override;
};
} // namespace ai
#endif // CUBICSERVER_AI_WANDERING_HPP
