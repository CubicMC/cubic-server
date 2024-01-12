#include "LivingEntity.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "PluginManager.hpp"
#include "Server.hpp"
#include "events/CancelEvents.hpp"
#include "events/Events.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/metadata.hpp"
#include <algorithm>
#include <optional>

void LivingEntity::attack(float damage, const Vector3<double> &source)
{
    //  TODO : think about how to deal with damage calculation later
    onEvent(Server::getInstance()->getPluginManager(), onEntityDamage, this, 1.0f);
    this->damage(damage);
    this->knockback(source);
}

void LivingEntity::damage(float damage)
{
    bool canceled = false;

    onEventCancelable(Server::getInstance()->getPluginManager(), onEntityDamage, canceled, this, damage);

    if (canceled)
        return;
    _health -= damage * (1.0f - ((std::min(20.0f, std::max(this->_armorDefense / 5.0f, this->_armorDefense - ((4.0f * damage) / (this->_armorToughness + 8.0f))))) / 25));
    broadcastMetadata();
    LDEBUG("entity type {} with id {} took damage {}, health is now {}", this->_type, this->_id, damage, _health);
}

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

void LivingEntity::setDefense(float value) { this->_armorDefense = value; }

void LivingEntity::addDefense(float value) { this->_armorDefense += value; }

void LivingEntity::removeDefense(float value) { this->_armorDefense -= value; }

float LivingEntity::getDefense() const noexcept { return (this->_armorDefense); }

void LivingEntity::setToughness(float value) { this->_armorToughness = value; }

void LivingEntity::addToughness(float value) { this->_armorToughness += value; }

void LivingEntity::removeToughness(float value) { this->_armorToughness -= value; }

float LivingEntity::getToughness() const noexcept { return (this->_armorToughness); }

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
