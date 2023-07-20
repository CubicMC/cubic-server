#include "Chicken.hpp"
#include "Dimension.hpp"
#include "entities/Item.hpp"
#include "entities/Mob.hpp"
#include <cstdint>
#include <random>
#include "Server.hpp"
#include "logging/logging.hpp"

Chicken::Chicken(std::shared_ptr<Dimension> dim, u128 uuid, float health, float maxHealth, bool leftHanded, bool aggressive):
    Mob(dim, EntityType::Chicken, uuid, health, maxHealth, leftHanded, aggressive)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint16_t> dist(6000, 12000);
    auto time = dist(gen);
    LINFO("Chicken will drop egg in {} ticks", time);
    _layEgg.setTickRate(time);
    _layEgg.setCallback(std::bind(&Chicken::layEgg, this));
    _layEgg.start();
    // attachAI<ai::Wandering>();
    this->setPosition({8.5, 100, 8.5}, false);
}

void Chicken::layEgg()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint16_t> dist(6000, 12000);
    _layEgg.setTickRate(dist(gen));
    auto piegg = ITEM_CONVERTER.fromItemToProtocolId("minecraft:egg");
    LINFO("protocol id = {}, and this protocol id is equal to : {}", piegg, ITEM_CONVERTER.fromProtocolIdToItem(piegg));
    this->getDimension()->makeEntity<Item>(protocol::Slot {true, 721, 1})->dropItem({_pos.x, _pos.y, _pos.z});
    return;
}

void Chicken::tick()
{
    _layEgg.tick();
    Mob::tick();
}
