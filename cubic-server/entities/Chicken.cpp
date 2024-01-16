#include "Chicken.hpp"
#include "Dimension.hpp"
#include "Server.hpp"
#include "entities/Item.hpp"
#include "entities/Mob.hpp"
#include "logging/logging.hpp"
#include "utility/PseudoRandomGenerator.hpp"
#include <cstdint>
#include <random>

Chicken::Chicken(std::shared_ptr<Dimension> dim, u128 uuid, float health, float maxHealth, bool leftHanded, bool aggressive):
    Mob(dim, EntityType::Chicken, uuid, health, maxHealth, leftHanded, aggressive)
{
    auto time = utility::PseudoRandomGenerator::getInstance()->generateNumber(6000, 12000);
    LDEBUG("Chicken will drop egg in {} ticks", time);
    _layEgg.setTickRate(time);
    _layEgg.setCallback(std::bind(&Chicken::layEgg, this));
    _layEgg.start();
    attachAI<ai::Wandering>();
    this->forceSetPosition({8.5, 70, 8.5});
}

void Chicken::layEgg()
{
    auto time = utility::PseudoRandomGenerator::getInstance()->generateNumber(6000, 12000);
    LDEBUG("Chicken will drop egg in {} ticks", time);
    _layEgg.setTickRate(time);
    _dim->makeEntity<Item>(protocol::Slot {true, ITEM_CONVERTER.fromItemToProtocolId("minecraft:egg"), 1})->dropItem({_pos.x, _pos.y + 1, _pos.z}, false);
    LDEBUG("Chicken dropped egg at x: {}, y: {}, z: {}", _pos.x, _pos.y + 1, _pos.z);
}

void Chicken::tick()
{
    _layEgg.tick();
    Mob::tick();
}
