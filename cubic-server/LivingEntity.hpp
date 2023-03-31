#ifndef CUBICSERVER_LIVINGENTITY_HPP
#define CUBICSERVER_LIVINGENTITY_HPP

#include "Entity.hpp"
#include "Dimension.hpp"

class LivingEntity : public Entity {
public :
    LivingEntity(std::shared_ptr<Dimension> dim, float health = 20, float maxHealth = 20) : Entity(dim), _health(health), _maxHealth(maxHealth) {}
    ~LivingEntity() override = default;

    virtual void attack(Vector3<double> source, float damage = 1);
    virtual void damage(float damage);
    virtual void knockback(Vector3<double> source = Vector3<double>(0, 0, 0), float force = 1000);

    virtual void setHealth(float health);

    [[nodiscard]] virtual float &getHealth();
    [[nodiscard]] virtual const float &getHealth() const;

protected:
    float _health;
    float _maxHealth;
};

#endif //CUBICSERVER_LIVINGENTITY_HPP
