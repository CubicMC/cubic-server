#ifndef CUBICSERVER_ITEMS_USABLEITEM_HPP
#define CUBICSERVER_ITEMS_USABLEITEM_HPP

#include <array>
#include <cstdint>
#include <memory>
#include <string_view>

#include "nbt.h"
#include "options.hpp"
#include "types.hpp"

class Dimension;
class Entity;

namespace Items {

/**
 * @brief Max durability for each type of item. As an unbreakable item does not have any, its value will be -1 to facilitate the use of this enum.
 *
 */
enum class ItemMaxDurabilityByType : int32_t {
    FishingRod = 64,
    FlintAndSteel = 64,
    CarrotOnaStick = 25,
    Shears = 238,
    Shield = 336,
    Bow = 384,
    Trident = 250,
    Elytra = 423,
    Crossbow = 465,
    WarpedFungusOnaStick = 100,
    GoldenItem = 32,
    WoodenItem = 59,
    StoneItem = 131,
    IronItem = 250,
    DiamondItem = 1561,
    NetheriteItem = 2031,
    ResetDefault = -1, // only for custom unbreakable items (when an item is broken, it is set to this custom value)
};

/**
 * @brief Used to determine with which mouse click an item can be used (and can lose durability)
 *
 */
enum class UsabilityType : int32_t {
    LeftMouseClickUsable = 0,
    RightMouseClickUsable = 1,
    BothMouseClicksUsable = 2,
    NoneClickUsable = -1, // only for custom unbreakable items (when an item is broken, it is set to this custom value)
};

struct UsableItem {
    UsableItem(const std::string_view stringId, const int32_t numeralId, const ItemMaxDurabilityByType maxDurability, bool isUnbreakable, const UsabilityType usabilityType):
        _stringId(stringId),
        _numeralId(numeralId),
        _maxDurability(maxDurability),
        _isUnbreakable(isUnbreakable),
        _usabilityType(usabilityType) {};

    UsableItem(const UsableItem &other):
        _stringId(other._stringId),
        _numeralId(other._numeralId),
        _maxDurability(other._maxDurability),
        _isUnbreakable(other._isUnbreakable),
        _usabilityType(other._usabilityType)
    {
    }

public:
    /**
     * @brief Define the course of action when the player uses the item
     *
     * @param dim The current dimension the player is in (facultative)
     * @param pos The position on which the item was used (facultative)
     * @param usage Determining with which mouse click the item is used (for items that are used with both clicks)
     */
    virtual void onUseOn(UNUSED std::shared_ptr<Dimension> dim, UNUSED Position &pos, UNUSED UsabilityType usage, UNUSED int32_t face, UNUSED Entity &user) {};

    virtual void onUse(UNUSED std::shared_ptr<Dimension> dim, UNUSED Entity &user, UNUSED UsabilityType usage) {};

    /**
     * @brief Set the NBT Tag of the item
     *
     * @return The NBT Tag for the item
     */
    virtual nbt_tag_t *setNbtTag() { return nullptr; };

    const std::string_view _stringId;
    const int32_t _numeralId; /**< this ID can become obsolete between versions. Only guaranteed to work for 1.19.3, avoid to use it. */
    const ItemMaxDurabilityByType _maxDurability;
    bool _isUnbreakable;
    const UsabilityType _usabilityType;
};

const std::array<UsableItem, 41> usableItems {
    UsableItem("minecraft:fishing_rod", 864, ItemMaxDurabilityByType::FishingRod, false, UsabilityType::RightMouseClickUsable),
    UsableItem("minecraft:flint_and_steel", 733, ItemMaxDurabilityByType::FlintAndSteel, false, UsabilityType::RightMouseClickUsable),
    UsableItem("minecraft:carrot_on_a_stick", 710, ItemMaxDurabilityByType::CarrotOnaStick, false, UsabilityType::RightMouseClickUsable),
    UsableItem("minecraft:shears", 915, ItemMaxDurabilityByType::Shears, false, UsabilityType::BothMouseClicksUsable),
    UsableItem("minecraft:shield", 1086, ItemMaxDurabilityByType::Shield, false, UsabilityType::RightMouseClickUsable),
    UsableItem("minecraft:bow", 735, ItemMaxDurabilityByType::Bow, false, UsabilityType::RightMouseClickUsable),
    UsableItem("minecraft:trident", 1108, ItemMaxDurabilityByType::Trident, false, UsabilityType::RightMouseClickUsable),
    UsableItem("minecraft:elytra", 712, ItemMaxDurabilityByType::Elytra, false, UsabilityType::RightMouseClickUsable),
    UsableItem("minecraft:crossbow", 1112, ItemMaxDurabilityByType::Crossbow, false, UsabilityType::RightMouseClickUsable),
    UsableItem("minecraft:warped_fungus_on_a_stick", 711, ItemMaxDurabilityByType::WarpedFungusOnaStick, false, UsabilityType::RightMouseClickUsable),
    UsableItem("minecraft:golden_sword", 762, ItemMaxDurabilityByType::GoldenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:golden_shovel", 763, ItemMaxDurabilityByType::GoldenItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem("minecraft:golden_pickaxe", 764, ItemMaxDurabilityByType::GoldenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:golden_axe", 765, ItemMaxDurabilityByType::GoldenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:golden_hoe", 766, ItemMaxDurabilityByType::GoldenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:wooden_sword", 752, ItemMaxDurabilityByType::WoodenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:wooden_shovel", 753, ItemMaxDurabilityByType::WoodenItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem("minecraft:wooden_pickaxe", 754, ItemMaxDurabilityByType::WoodenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:wooden_axe", 755, ItemMaxDurabilityByType::WoodenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:wooden_hoe", 756, ItemMaxDurabilityByType::WoodenItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem("minecraft:stone_sword", 757, ItemMaxDurabilityByType::StoneItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:stone_shovel", 758, ItemMaxDurabilityByType::StoneItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem("minecraft:stone_pickaxe", 759, ItemMaxDurabilityByType::StoneItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:stone_axe", 760, ItemMaxDurabilityByType::StoneItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:stone_hoe", 761, ItemMaxDurabilityByType::StoneItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem("minecraft:iron_sword", 767, ItemMaxDurabilityByType::IronItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:iron_shovel", 768, ItemMaxDurabilityByType::IronItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem("minecraft:iron_pickaxe", 769, ItemMaxDurabilityByType::IronItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:iron_axe", 770, ItemMaxDurabilityByType::IronItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:iron_hoe", 771, ItemMaxDurabilityByType::IronItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem("minecraft:diamond_sword", 772, ItemMaxDurabilityByType::DiamondItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:diamond_shovel", 773, ItemMaxDurabilityByType::DiamondItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem("minecraft:diamond_pickaxe", 774, ItemMaxDurabilityByType::DiamondItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:diamond_axe", 775, ItemMaxDurabilityByType::DiamondItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:diamond_hoe", 776, ItemMaxDurabilityByType::DiamondItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem("minecraft:netherite_sword", 777, ItemMaxDurabilityByType::NetheriteItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:netherite_shovel", 778, ItemMaxDurabilityByType::NetheriteItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem("minecraft:netherite_pickaxe", 779, ItemMaxDurabilityByType::NetheriteItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:netherite_axe", 780, ItemMaxDurabilityByType::NetheriteItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem("minecraft:netherite_hoe", 781, ItemMaxDurabilityByType::NetheriteItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem("cubic:unusable", -1, ItemMaxDurabilityByType::ResetDefault, true, UsabilityType::NoneClickUsable) /**< For items that are not usable/broken */
};

} // namespace Items

#endif // CUBICSERVER_ITEMS_USABLEITEM_HPP
