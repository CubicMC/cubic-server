#include "LivingEntity.hpp"
#include "Player.hpp"

/*
 * @brief Attack the entity
 *
 * @param damage The damage to deal
 * @param source The source of the damage
 */
void LivingEntity::attack(float damage, Vector3<double> source)
{
    std::vector<Player *> players =  _dim->getPlayerList();

    // compute knockback
    double knockback = 1000;
    Vector3<double> direction = (source - _pos) * knockback;

    direction.normalize();
    _health -= damage;

    // send entity velocity too connected players (should be optimized)
    for (auto &player : players) {
        player->sendEntityVelocity({
            _id,
            static_cast<int16_t>(direction.x),
            static_cast<int16_t>(direction.y),
            static_cast<int16_t>(direction.z)
        });
    }
}

void LivingEntity::setHealth(float health) {
    _health = health;
}

float &LivingEntity::getHealth() {
    return _health;
}

const float &LivingEntity::getHealth() const {
    return _health;
}