#ifndef CUBICSERVER_ENTITIES_LIVINGENTITY_HPP
#define CUBICSERVER_ENTITIES_LIVINGENTITY_HPP

#include "Dimension.hpp"
#include "Entity.hpp"
#include "EntityType.hpp"
#include "TickClock.hpp"
#include "logging/logging.hpp"
#include "options.hpp"
#include <cstdint>
#include <optional>

constexpr float KNOCKBACK_DEFAULT_FORCE = 2500.0f;

class LivingEntity : public Entity {
public:
    LivingEntity(std::shared_ptr<Dimension> dim, EntityType type, u128 uuid, float health = 20, float maxHealth = 20):
        Entity(dim, type, uuid),
        _health(health),
        _maxHealth(maxHealth),
        _handState(false, HandState::ActiveHand::MainHand, false),
        _potionEffectColor(0),
        _isPotionEffectAmbient(false),
        _numArrowsInEntity(0),
        _numBeeStingerInEntity(0),
        _isSleeping(false),
        _posBedSleeping(0, 0, 0),
        _deathClock(20, [this]() {
            this->_readyToRemove = true;
        }),
        _readyToRemove(false)
    {
    }
    virtual ~LivingEntity() override = default;

    virtual void tick() override;
    /*
     * @brief Attack the entity
     *
     * @param damage The damage to deal
     * @param source The source of the damage
     */
    virtual void attack(float damage, const Vector3<double> &source, const int32_t &sourceId = 0);

    /*
     * @brief Inflict damage to the entity
     *
     * @param damage The damage to deal
     * @param sourceId The ID of the source entity dealing damage
     */
    virtual void damage(float damage, const int32_t &sourceId = 0);

    /*
     * @brief Inflict knockback to the entity
     *
     * @param source The source of the knockback
     * @param force The force of the knockback
     */
    virtual void knockback(const Vector3<double> &source = Vector3<double>(0, 0, 0), float force = KNOCKBACK_DEFAULT_FORCE);

    /**
     * @brief Kill the entity
     */
    virtual void kill(const int32_t &killerId = 0);

    virtual void setHealth(float health);

    NODISCARD virtual float &getHealth();
    NODISCARD virtual const float &getHealth() const;

    /**
     * @brief Returns boolean indicating if the entity can be removed (dead and end of animation)
     */
    NODISCARD virtual const bool &isReadyToRemove() const { return _readyToRemove; };

    /**
     * @brief Adds serialized metadata to an output buffer
     *
     * @param data The output buffer
     */
    virtual void appendMetadataPacket(std::vector<uint8_t> &data) const override;

protected:
    float _health;
    float _maxHealth;

    struct HandState {
        bool isHandActive;
        enum class ActiveHand {
            MainHand = 0x00,
            OffHand = 0x02,
        } activeHand;
        bool isInRiptideSpinAttack;
    } _handState;

    int32_t _potionEffectColor;
    bool _isPotionEffectAmbient;
    int32_t _numArrowsInEntity;
    int32_t _numBeeStingerInEntity;

    bool _isSleeping;
    Position _posBedSleeping;

    TickClock _deathClock;
    bool _readyToRemove;
};

#endif // CUBICSERVER_ENTITIES_LIVINGENTITY_HPP
