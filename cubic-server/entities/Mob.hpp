#ifndef CUBICSERVER_ENTITIES_MOB_HPP
#define CUBICSERVER_ENTITIES_MOB_HPP

#include <memory>
#include <vector>

#include "LivingEntity.hpp"
#include "ai/ai.hpp"
#include "concept.hpp"
#include "entities/Entity.hpp"

class Mob : public LivingEntity {
public:
    Mob(std::shared_ptr<Dimension> dim, EntityType type, u128 uuid, float health = 20, float maxHealth = 20, bool leftHanded = false, bool aggressive = false):
        LivingEntity(dim, type, uuid, health, maxHealth),
        _leftHanded(leftHanded),
        _aggressive(aggressive)
    {
    }

    void tick() override
    {
        for (auto &ai : _ais) {
            if (ai->brain())
                break;
        }
        Entity::tick();
    }

    template<isBaseOf<ai::AI> AI, typename... Args>
    void attachAI(Args && ... args)
    {
        _ais.emplace_back(std::make_unique<AI>(*this, std::forward<Args>(args)...));
    }

protected:
    bool _leftHanded;
    bool _aggressive;
    std::vector<std::unique_ptr<ai::AI>> _ais;
};

#endif // CUBICSERVER_ENTITIES_MOB_HPP
