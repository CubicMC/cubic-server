#ifndef CUBICSERVER_ENTITIES_CHICKEN_HPP
#define CUBICSERVER_ENTITIES_CHICKEN_HPP

#include "Mob.hpp"
#include "ai/wandering.hpp"

class Chicken : public Mob {
public:
    Chicken(std::shared_ptr<Dimension> dim, u128 uuid, float health = 4, float maxHealth = 4, bool leftHanded = false, bool aggressive = false);
};

#endif // CUBICSERVER_ENTITIES_CHICKEN_HPP
