#ifndef CUBICSERVER_ITEMS_USABLE_ITEMS_FLINT_AND_STEEL
#define CUBICSERVER_ITEMS_USABLE_ITEMS_FLINT_AND_STEEL

#include "items/UsableItem.hpp"

#include <cstdint>
#include <string_view>

namespace Items {

struct FlintAndSteel : public UsableItem {
    FlintAndSteel(
        const std::string_view stringId = "minecraft:flint_and_steel", const int32_t numeralId = 733,
        const ItemMaxDurabilityByType maxDurability = ItemMaxDurabilityByType::FlintAndSteel, const bool isUnbreakable = false,
        const UsabilityType usabilityType = UsabilityType::RightMouseClickUsable
    ):
        UsableItem(stringId, numeralId, maxDurability, isUnbreakable, usabilityType)
    {
    }
    void onUse(std::shared_ptr<Dimension> dim, Position &pos) const override;
    nbt_tag_t *setNbtTag() override;
};

} // namespace Items

#endif // CUBICSERVER_ITEMS_USABLE_ITEMS_FLINT_AND_STEEL
