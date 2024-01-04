#ifndef CUBICSERVER_ITEMS_USABLE_ITEMS_HOE
#define CUBICSERVER_ITEMS_USABLE_ITEMS_HOE

#include "items/UsableItem.hpp"
#include "types.hpp"
#include <array>
#include <string>

namespace Items {

/**
 * @brief The 'Hoe' is an item used to transform dirt blocs into other types, such as farmland
 *
 */
struct Hoe : public UsableItem {
    Hoe(const std::string_view stringId, const int32_t numeralId, const ItemMaxDurabilityByType maxDurability, bool isUnbreakable, const UsabilityType usabilityType):
        UsableItem(stringId, numeralId, maxDurability, isUnbreakable, usabilityType)
    {
    }

    Hoe(const UsableItem &other):
        UsableItem(other)
    {
    }

    /**
     * @note See Item::UsableItem::onUse() for more info
     *
     */
    void onUseOn(std::shared_ptr<Dimension> dim, Position &pos, UsabilityType usage, int32_t face, Entity &user) override;

    /**
     * @note See Item::UsableItem::setNbtTag() for more info
     *
     */
    nbt_tag_t *setNbtTag() override;

    bool canUpdateDamage = false;
};

const std::array<std::string, 16> breakableWithHoe {
    "minecraft:sculk_catalyst",
    "minecraft:sculk_shrieker",
    "minecraft:sculk_sensor",
    "minecraft:calibrated_sculk_sensor",
    "minecraft:nether_wart_block",
    "minecraft:warped_wart_block",
    "minecraft:shroomlight",
    "minecraft:hay_bale",
    "minecraft:target",
    "minecraft:dried_kelp_block",
    "minecraft:sponge",
    "minecraft:wet_sponge",
    "minecraft:leaves",
    "minecraft:sculk",
    "minecraft:sculk_vein",
    "minecraft:moss_block"};

} // namespace Items

#endif // CUBICSERVER_ITEMS_USABLE_ITEMS_HOE
