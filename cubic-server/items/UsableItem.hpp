#ifndef CUBICSERVER_ITEMS_USABLEITEM_HPP
#define CUBICSERVER_ITEMS_USABLEITEM_HPP

#include <array>
#include <string_view>

namespace Items {

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

inline ItemMaxDurabilityByType getMaxDurabilityById(int32_t itemId)
{
    switch (itemId) {
    case 864:
        return ItemMaxDurabilityByType::FishingRod;
    case 733:
        return ItemMaxDurabilityByType::FlintAndSteel;
    case 710:
        return ItemMaxDurabilityByType::CarrotOnaStick;
    case 915:
        return ItemMaxDurabilityByType::Shears;
    case 1086:
        return ItemMaxDurabilityByType::Shield;
    case 735:
        return ItemMaxDurabilityByType::Bow;
    case 1108:
        return ItemMaxDurabilityByType::Trident;
    case 712:
        return ItemMaxDurabilityByType::Elytra;
    case 1112:
        return ItemMaxDurabilityByType::Crossbow;
    case 711:
        return ItemMaxDurabilityByType::WarpedFungusOnaStick;
    case 762: /* golden sword */
    case 763: /* golden shovel*/
    case 764: /* golden pickaxe */
    case 765: /* golden axe */
    case 766: /* golden hoe */
        return ItemMaxDurabilityByType::GoldenItem;
    case 752: /* wooden sword */
    case 753: /* wooden shovel*/
    case 754: /* wooden pickaxe */
    case 755: /* wooden axe */
    case 756: /* wooden hoe */
        return ItemMaxDurabilityByType::WoodenItem;
    case 757: /* stone sword */
    case 758: /* stone shovel*/
    case 759: /* stone pickaxe */
    case 760: /* stone axe */
    case 761: /* stone hoe */
        return ItemMaxDurabilityByType::StoneItem;
    case 767: /* iron sword */
    case 768: /* iron shovel*/
    case 769: /* iron pickaxe */
    case 770: /* iron axe */
    case 771: /* iron hoe */
        return ItemMaxDurabilityByType::IronItem;
    case 772: /* diamond sword */
    case 773: /* diamond shovel*/
    case 774: /* diamond pickaxe */
    case 775: /* diamond axe */
    case 776: /* diamond hoe */
        return ItemMaxDurabilityByType::DiamondItem;
    case 777: /* netherite sword */
    case 778: /* netherite shovel*/
    case 779: /* netherite pickaxe */
    case 780: /* netherite axe */
    case 781: /* netherite hoe */
        return ItemMaxDurabilityByType::NetheriteItem;
    default:
        return ItemMaxDurabilityByType::Unbreakable;
    }
}

class UsableItem {
public:
    virtual ~UsableItem();

    virtual bool isBroken(); /* true if damage = max_durability */
    virtual void updateDamage(); /* set damage = damage + 1 */
};

} // namespace Items

#endif // CUBICSERVER_ITEMS_USABLEITEM_HPP
