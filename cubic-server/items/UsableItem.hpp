#ifndef CUBICSERVER_ITEMS_USABLEITEM_HPP
#define CUBICSERVER_ITEMS_USABLEITEM_HPP

#include "blocks.hpp"
#include "protocol/Structures.hpp"
#include "types.hpp"

#include <array>
#include <cstdint>
#include <string_view>

namespace Items {

/**
 * @brief Max durability for each type of item. As an unbreakable item does not have any, if an item is unbreakable, its value will be -1 to facilitate the use of this enum.
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
    Unbreakable = -1,
};

/**
 * @brief Used to determine with which mouse click an item can be used (and can lose durability)
 *
 */
enum class UsabilityType : int32_t {
    LeftMouseClickUsable = 0,
    RightMouseClickUsable = 1,
    BothMouseClicksUsable = 2,
    NoneClickUsable = -1, // only for custom unbreakable items
};

struct UsableItem {
    UsableItem(const std::string_view stringId, const int32_t numeralId, const ItemMaxDurabilityByType maxDurability, bool isUnbreakable, const UsabilityType usabilityType):
    _stringId(stringId),
    _numeralId(numeralId),
    _maxDurability(maxDurability),
    _isUnbreakable(isUnbreakable),
    _usabilityType(usabilityType)
    {
        auto root = setNbtTag();
        _slot = protocol::Slot(true, _numeralId, 1, root);
    };

    public:
        /** damageTaken = damageTaken + 1, breaks item if (damageTaken > maxDurability) */
        virtual void updateDamage();
        virtual void onUse(Position &pos);
        nbt_tag_t *setNbtTag(){return nullptr;};

        const std::string_view _stringId;
        const int32_t _numeralId; // this ID can become obsolete between versions. Only guaranteed to work for 1.19.3, avoid to use it.
        const ItemMaxDurabilityByType _maxDurability;
        bool _isUnbreakable;
        const UsabilityType _usabilityType;
        protocol::Slot _slot;
};

const std::array<UsableItem, 41> usableItems {
    UsableItem ("minecraft:fishing_rod", 864, ItemMaxDurabilityByType::FishingRod, false, UsabilityType::RightMouseClickUsable),
    UsableItem ("minecraft:flint_and_steel", 733, ItemMaxDurabilityByType::FlintAndSteel, false, UsabilityType::RightMouseClickUsable),
    UsableItem ("minecraft:carrot_on_a_stick", 710, ItemMaxDurabilityByType::CarrotOnaStick, false, UsabilityType::RightMouseClickUsable),
    UsableItem ("minecraft:shears", 915, ItemMaxDurabilityByType::Shears, false, UsabilityType::BothMouseClicksUsable),
    UsableItem ("minecraft:shield", 1086, ItemMaxDurabilityByType::Shield, false, UsabilityType::RightMouseClickUsable),
    UsableItem ("minecraft:bow", 735, ItemMaxDurabilityByType::Bow, false, UsabilityType::RightMouseClickUsable),
    UsableItem ("minecraft:trident", 1108, ItemMaxDurabilityByType::Trident, false, UsabilityType::RightMouseClickUsable),
    UsableItem ("minecraft:elytra", 712, ItemMaxDurabilityByType::Elytra, false, UsabilityType::RightMouseClickUsable),
    UsableItem ("minecraft:crossbow", 1112, ItemMaxDurabilityByType::Crossbow, false, UsabilityType::RightMouseClickUsable),
    UsableItem ("minecraft:warped_fungus_on_a_stick", 711, ItemMaxDurabilityByType::WarpedFungusOnaStick, false, UsabilityType::RightMouseClickUsable),
    UsableItem ("minecraft:golden_sword", 762, ItemMaxDurabilityByType::GoldenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:golden_shovel", 763, ItemMaxDurabilityByType::GoldenItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem ("minecraft:golden_pickaxe", 764, ItemMaxDurabilityByType::GoldenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:golden_axe", 765, ItemMaxDurabilityByType::GoldenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:golden_hoe", 766, ItemMaxDurabilityByType::GoldenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:wooden_sword", 752, ItemMaxDurabilityByType::WoodenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:wooden_shovel", 753, ItemMaxDurabilityByType::WoodenItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem ("minecraft:wooden_pickaxe", 754, ItemMaxDurabilityByType::WoodenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:wooden_axe", 755, ItemMaxDurabilityByType::WoodenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:wooden_hoe", 756, ItemMaxDurabilityByType::WoodenItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:stone_sword", 757, ItemMaxDurabilityByType::StoneItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:stone_shovel", 758, ItemMaxDurabilityByType::StoneItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem ("minecraft:stone_pickaxe", 759, ItemMaxDurabilityByType::StoneItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:stone_axe", 760, ItemMaxDurabilityByType::StoneItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:stone_hoe", 761, ItemMaxDurabilityByType::StoneItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:iron_sword", 767, ItemMaxDurabilityByType::IronItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:iron_shovel", 768, ItemMaxDurabilityByType::IronItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem ("minecraft:iron_pickaxe", 769, ItemMaxDurabilityByType::IronItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:iron_axe", 770, ItemMaxDurabilityByType::IronItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:iron_hoe", 771, ItemMaxDurabilityByType::IronItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:diamond_sword", 772, ItemMaxDurabilityByType::DiamondItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:diamond_shovel", 773, ItemMaxDurabilityByType::DiamondItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem ("minecraft:diamond_pickaxe", 774, ItemMaxDurabilityByType::DiamondItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:diamond_axe", 775, ItemMaxDurabilityByType::DiamondItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:diamond_hoe", 776, ItemMaxDurabilityByType::DiamondItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:netherite_sword", 777, ItemMaxDurabilityByType::NetheriteItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:netherite_shovel", 778, ItemMaxDurabilityByType::NetheriteItem, false, UsabilityType::BothMouseClicksUsable),
    UsableItem ("minecraft:netherite_pickaxe", 779, ItemMaxDurabilityByType::NetheriteItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:netherite_axe", 780, ItemMaxDurabilityByType::NetheriteItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("minecraft:netherite_hoe", 781, ItemMaxDurabilityByType::NetheriteItem, false, UsabilityType::LeftMouseClickUsable),
    UsableItem ("cubic:unusable", 0, ItemMaxDurabilityByType::Unbreakable, true, UsabilityType::NoneClickUsable) /**< used for all items that are not usable */
};

} // namespace Items

#endif // CUBICSERVER_ITEMS_USABLEITEM_HPP
