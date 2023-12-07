#ifndef CUBICSERVER_ITEMS_TOOLSDAMAGE_HPP
#define CUBICSERVER_ITEMS_TOOLSDAMAGE_HPP

#include "../types.hpp"
#include <array>
#include <vector>

namespace Items {
struct ToolDescription {
    ItemId id;
    float damage;
    float attackSpeed;
};
const std::vector<ToolDescription> toolsDamage = {
    {752, 4, 1.6}, // Wooden Sword
    {757, 5, 1.6}, // Stone Sword
    {767, 6, 1.6}, // Iron Sword
    {762, 4, 1.6}, // Golden Sword
    {772, 7, 1.6}, // Diamond Sword
    {777, 8, 1.6}, // Netherite Sword

    {1108, 9, 1.1}, // Trident

    {753, 2.5, 1}, // Wooden Shovel
    {758, 3.5, 1}, // Stone Shovel
    {768, 4.5, 1}, // Iron Shovel
    {763, 2.5, 1}, // Golden Shovel
    {773, 5.5, 1}, // Diamond Shovel
    {778, 6.5, 1}, // Netherite Shovel

    {754, 2, 1.2}, // Wooden Pickaxe
    {759, 3, 1.2}, // Stone Pickaxe
    {769, 4, 1.2}, // Iron Pickaxe
    {764, 2, 1.2}, // Golden Pickaxe
    {774, 5, 1.2}, // Diamond Pickaxe
    {779, 6, 1.2}, // Netherite Pickaxe

    {755, 7, 0.8}, // Wooden Axe
    {760, 9, 0.8}, // Stone Axe
    {770, 9, 0.9}, // Iron Axe
    {765, 7, 1}, // Golden Axe
    {775, 9, 1}, // Diamond Axe
    {780, 10, 1}, // Netherite Axe

    {756, 1, 1}, // Wooden Hoe
    {761, 1, 2}, // Stone Hoe
    {771, 1, 3}, // Iron Hoe
    {766, 1, 1}, // Golden Hoe
    {776, 1, 4}, // Diamond Hoe
    {781, 1, 4}, // Netherite Hoe
};

}

#endif // CUBICSERVER_ITEMS_TOOLSDAMAGE_HPP
