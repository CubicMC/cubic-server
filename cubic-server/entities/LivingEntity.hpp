#ifndef CUBICSERVER_ENTITIES_LIVINGENTITY_HPP
#define CUBICSERVER_ENTITIES_LIVINGENTITY_HPP

#include "Entity.hpp"
#include "EntityType.hpp"
#include "options.hpp"
#include <optional>

constexpr float KNOCKBACK_DEFAULT_FORCE = 2500.0f;

class LivingEntity : public Entity {
public:
    LivingEntity(std::shared_ptr<Dimension> dim, EntityType type, u128 uuid, float health = 20, float maxHealth = 20):
        Entity(dim, type, uuid),
        _health(health),
        _maxHealth(maxHealth),
        _armorDefense(0),
        _armorToughness(0),
        _handState(false, HandState::ActiveHand::MainHand, false),
        _potionEffectColor(0),
        _isPotionEffectAmbient(false),
        _numArrowsInEntity(0),
        _numBeeStingerInEntity(0),
        _isSleeping(false),
        _posBedSleeping(0, 0, 0)
    {
    }
    virtual ~LivingEntity() override = default;

    /*
     * @brief Attack the entity
     *
     * @param damage The damage to deal
     * @param source The source of the damage
     */
    virtual void attack(float damage, const Vector3<double> &source);

    /*
     * @brief Inflict damage to the entity
     *
     * @param damage The damage to deal
     */
    virtual void damage(float damage);

    /*
     * @brief Inflict knockback to the entity
     *
     * @param source The source of the knockback
     * @param force The force of the knockback
     */
    virtual void knockback(const Vector3<double> &source = Vector3<double>(0, 0, 0), float force = KNOCKBACK_DEFAULT_FORCE);

    virtual void setHealth(float health);

    NODISCARD virtual float &getHealth();
    NODISCARD virtual const float &getHealth() const;

    virtual void setDefense(float value);
    virtual void addDefense(float value);
    virtual void removeDefense(float value);
    NODISCARD virtual float getDefense() const noexcept;

    virtual void setToughness(float value);
    virtual void addToughness(float value);
    virtual void removeToughness(float value);
    NODISCARD virtual float getToughness() const noexcept;

    /**
     * @brief Adds serialized metadata to an output buffer
     *
     * @param data The output buffer
     */
    virtual void appendMetadataPacket(std::vector<uint8_t> &data) const override;

protected:
    float _health;
    float _maxHealth;

    float _armorDefense;
    float _armorToughness;

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
};

#endif // CUBICSERVER_ENTITIES_LIVINGENTITY_HPP
