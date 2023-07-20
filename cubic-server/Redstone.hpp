#ifndef CUBICSERVER_LIVINGENTITY_HPP
#define CUBICSERVER_LIVINGENTITY_HPP

#include "Entity.hpp"
#include "options.hpp"

constexpr float KNOCKBACK_DEFAULT_FORCE = 2500.0f;

namespace Redsone {
    class Button {
    public:
        Button(std::string material);
        virtual void press(void);
    private:
        bool _duration;
        bool _pressed;
    };
}

class LivingEntity : public Entity {
public:
    LivingEntity(std::shared_ptr<Dimension> dim, protocol::SpawnEntity::EntityType type, float health = 20, float maxHealth = 20):
        Entity(dim, type),
        _health(health),
        _maxHealth(maxHealth)
    {
    }
    ~LivingEntity() override = default;

    virtual void attack(const Vector3<double> &source);
    virtual void damage(float damage);
    virtual void knockback(const Vector3<double> &source = Vector3<double>(0, 0, 0), float force = KNOCKBACK_DEFAULT_FORCE);

    virtual void setHealth(float health);

    NODISCARD virtual float &getHealth();
    NODISCARD virtual const float &getHealth() const;

protected:
    float _health;
    float _maxHealth;
};

#endif // CUBICSERVER_LIVINGENTITY_HPP
