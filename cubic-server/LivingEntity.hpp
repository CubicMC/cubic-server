#ifndef CUBICSERVER_LIVINGENTITY_HPP
#define CUBICSERVER_LIVINGENTITY_HPP

#include "Dimension.hpp"
#include "Entity.hpp"

constexpr float KNOCKBACK_DEFAULT_FORCE = 2500.0f;

class LivingEntity : public Entity {
public:
    LivingEntity(std::shared_ptr<Dimension> dim, float health = 20, float maxHealth = 20):
        Entity(dim),
        _health(health),
        _maxHealth(maxHealth)
    {
    }
    ~LivingEntity() override = default;

    virtual void attack(const Vector3<double> &source);
    virtual void damage(float damage);
    virtual void knockback(const Vector3<double> &source = Vector3<double>(0, 0, 0), float force = KNOCKBACK_DEFAULT_FORCE);

    virtual void setHealth(float health);

    [[nodiscard]] virtual float &getHealth();
    [[nodiscard]] virtual const float &getHealth() const;

protected:
    float _health;
    float _maxHealth;
};

#endif // CUBICSERVER_LIVINGENTITY_HPP
