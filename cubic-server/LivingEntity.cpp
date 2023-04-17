#include "LivingEntity.hpp"
#include "Dimension.hpp"
#include "Player.hpp"

/*
 * @brief Attack the entity
 *
 * @param damage The damage to deal
 * @param source The source of the damage
 */
void LivingEntity::attack(Vector3<double> source)
{
    //  TODO : think about how to deal with damage calculation later
    this->damage(1);
    this->knockback(source);
}

/*
 * @brief Inflict damage to the entity
 *
 * @param damage The damage to deal
 */
void LivingEntity::damage(float damage) { _health -= damage; }

/*
 * @brief Inflict knockback to the entity
 *
 * @param source The source of the knockback
 * @param force The force of the knockback
 */
void LivingEntity::knockback(Vector3<double> source, float force)
{
    // compute knockback
    Vector3<double> direction = (source - _pos) * force;

    direction.normalize();

    // send entity velocity too connected players (should be optimized)
    for (auto &player : _dim->getPlayerList()) {
        player->sendEntityVelocity({_id, static_cast<int16_t>(direction.x), static_cast<int16_t>(direction.y), static_cast<int16_t>(direction.z)});
    }
}

void LivingEntity::setHealth(float health) { _health = health; }

float &LivingEntity::getHealth() { return _health; }

const float &LivingEntity::getHealth() const { return _health; }
