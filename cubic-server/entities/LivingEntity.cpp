#include "LivingEntity.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "PluginManager.hpp"
#include "Server.hpp"
#include "events/CancelEvents.hpp"
#include "events/Events.hpp"
#include "options.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/metadata.hpp"
#include <optional>

/*
 * @brief Attack the entity
 *
 * @param damage The damage to deal
 * @param source The source of the damage
 */
void LivingEntity::attack(const Vector3<double> &source, const int32_t &sourceId)
{
    //  TODO : think about how to deal with damage calculation later
    onEvent(Server::getInstance()->getPluginManager(), onEntityDamage, this, 1.0f);
    this->damage(1, sourceId);
    this->knockback(source);
}

/*
 * @brief Inflict damage to the entity
 *
 * @param damage The damage to deal
 */
void LivingEntity::damage(float damage, const int32_t &sourceId)
{
    bool canceled = false;

    onEventCancelable(Server::getInstance()->getPluginManager(), onEntityDamage, canceled, this, damage);

    if (canceled)
        return;
    _health -= damage;
    if (_health <= 0) {
        this->kill(sourceId);
    }
    broadcastMetadata();
    LDEBUG("entity type {} with id {} took damage {}, health is now {}", this->_type, this->_id, damage, _health);
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

void LivingEntity::kill(UNUSED const int32_t &killerId)
{
    // TODO : think about how to deal with death later
    _health = 0;
}

void LivingEntity::setHealth(float health) { _health = health; }

float &LivingEntity::getHealth() { return _health; }

const float &LivingEntity::getHealth() const { return _health; }

void LivingEntity::appendMetadataPacket(std::vector<uint8_t> &data) const
{
    Entity::appendMetadataPacket(data);

    using namespace protocol::entity_metadata;

    // Hand state flags
    uint8_t flag = 0;
    if (_handState.isHandActive)
        flag |= 0x01;
    flag |= (uint8_t) _handState.activeHand;
    if (_handState.isInRiptideSpinAttack)
        flag |= 0x04;
    addMByte(data, 8, flag);

    // Health
    addMFloat(data, 9, _health);

    // Potion effect color
    addMVarInt(data, 10, _potionEffectColor);

    // Is potion effect ambient
    addMBoolean(data, 11, _isPotionEffectAmbient);

    // Num Arrows in entity
    addMVarInt(data, 12, _numArrowsInEntity);

    // Num Bee Stingers in entity
    addMVarInt(data, 13, _numBeeStingerInEntity);

    // Location of the bed the entity is currently sleeping in
    addMOptPosition(data, 14, _isSleeping ? std::optional<Position>(_posBedSleeping) : std::nullopt);
}
