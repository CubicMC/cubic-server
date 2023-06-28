#include "Chicken.hpp"

Chicken::Chicken(std::shared_ptr<Dimension> dim, u128 uuid, float health, float maxHealth, bool leftHanded, bool aggressive):
    Mob(dim, EntityType::Chicken, uuid, health, maxHealth, leftHanded, aggressive)
{
    attachAI<ai::Wandering>();
}
