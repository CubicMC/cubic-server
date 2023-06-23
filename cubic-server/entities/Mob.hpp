#ifndef CUBICSERVER_ENTITIES_MOB_HPP
#define CUBICSERVER_ENTITIES_MOB_HPP

#include <memory>
#include <vector>

#include "LivingEntity.hpp"
#include "ai/ai.hpp"

class Mob : public LivingEntity {
public:
    Mob(std::shared_ptr<Dimension> dim, EntityType type, u128 uuid, float health = 20, float maxHealth = 20, bool leftHanded = false, bool aggressive = false, std::vector<std::unique_ptr<ai::AI>> ais = {}):
        LivingEntity(dim, type, uuid, health, maxHealth),
        _leftHanded(leftHanded),
        _aggressive(aggressive),
        _ais(std::move(ais))
    {
    }
protected:
    bool _leftHanded;
    bool _aggressive;
    std::vector<std::unique_ptr<ai::AI>> _ais;
};

#endif // CUBICSERVER_ENTITIES_MOB_HPP
