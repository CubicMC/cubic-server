#include "LivingEntity.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "events/Events.hpp"
#include "events/CancelEvents.hpp"
#include "PluginManager.hpp"

/*
 * @brief Detect whether the entity is not immune to fall damage
 *
 * @param TBD
 */
bool LivingEntity::takesFalldmg()
{
    // method class dimension: return block from relative position %chunk_sz
    // round(this->_pos());
    return !(// TODO for Player:: only
            // !isGamemode("creative") &&
            // TODO check if entity landed in water
            // !isInWater() &&
            // TODO waiting for potion effect
            // !this->hasEffect(PotionEffect::SlowFalling) &&
            // TODO detect block under, make list of soft blocks
            // !isSoft(blockUnder) &&
            !this->_flyingWithElytra);
}

/*
 * @brief Deal fall damage to the entity
 *
 * @param height The height level from which the entity fell
 */
void LivingEntity::falldamage(const double &height)
{
    int fallBlkDistance = ceil(height - this->_pos.y); // nb of blocks fallen

    if (fallBlkDistance >= this->_health + 3.5) { // making sure death is infliged
        this->damage(999);
        return;
    }
    this->damage(fallBlkDistance);
}

/*
 * @brief Attack the entity
 *
 * @param damage The damage to deal
 * @param source The source of the damage
 */
void LivingEntity::attack(const Vector3<double> &source)
{
    //  TODO : think about how to deal with damage calculation later
    onEvent(Server::getInstance()->getPluginManager(), onEntityDamage, this, 1.0f);
    this->damage(1);
    this->knockback(source);
}

/*
 * @brief Inflict damage to the entity
 *
 * @param damage The damage to deal
 */
void LivingEntity::damage(float damage)
{
    bool canceled = false;

    onEventCancelable(Server::getInstance()->getPluginManager(), onEntityDamage, canceled, this, damage);

    if (canceled)
        return;
    _health -= damage;
}

/*
 * @brief Inflict knockback to the entity
 *
 * @param source The source of the knockback
 * @param force The force of the knockback
 */
void LivingEntity::knockback(const Vector3<double> &source, float force)
{
    // compute knockback
    // TODO(huntears): Change how the knockback is calculated to be more "vanilla like"
    Vector2<double> pos2d = _pos;
    Vector2<double> source2d = source;
    Vector2<double> direction = source2d - pos2d;
    direction.normalize();

    Vector3<double> kb(direction.x, 1.0f, direction.z);

    kb *= force;

    // send entity velocity too connected players (should be optimized)
    for (auto player : _dim->getPlayers()) {
        player->sendEntityVelocity({_id, static_cast<int16_t>(kb.x), static_cast<int16_t>(kb.y), static_cast<int16_t>(kb.z)});
        player->sendEntityAnimation(protocol::EntityAnimation::ID::TakeDamage, _id);
    }
}

void LivingEntity::setHealth(float health) { _health = health; }

float &LivingEntity::getHealth() { return _health; }

const float &LivingEntity::getHealth() const { return _health; }
