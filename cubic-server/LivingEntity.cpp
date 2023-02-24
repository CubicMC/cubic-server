#include "LivingEntity.hpp"
#include "Player.hpp"

void LivingEntity::attack(float damage, Vector3<double> source)
{
    std::vector<Player *> players =  _dim->getPlayerList();
    Vector3<double> direction = source - _pos;

    direction.normalize();
    _health -= damage;
    for (auto &player : players) {
        player->sendEntityVelocity({
            _id,
            static_cast<int16_t>(direction.x * 1000),
            static_cast<int16_t>(direction.y * 1000),
            static_cast<int16_t>(direction.z * 1000)
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