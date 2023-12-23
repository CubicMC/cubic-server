#ifndef CUBICSERVER_ENTITIES_CHICKEN_HPP
#define CUBICSERVER_ENTITIES_CHICKEN_HPP

#include "Mob.hpp"
#include "TickClock.hpp"
#include "ai/wandering.hpp"

/**
 * @brief Da Chickin
 */
class Chicken : public Mob {
public:
    Chicken(std::shared_ptr<Dimension> dim, u128 uuid = u128::random(), float health = 4, float maxHealth = 4, bool leftHanded = false, bool aggressive = false);
    /**
     * @brief Called every tick to update the entity
     */
    void tick() override;

private:
    TickClock _layEgg;
    /**
     * @brief Called to make the chicken lay an egg
     */
    void layEgg();
};

#endif // CUBICSERVER_ENTITIES_CHICKEN_HPP
