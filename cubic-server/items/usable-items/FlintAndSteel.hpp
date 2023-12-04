#ifndef CUBICSERVER_ITEMS_USABLE_ITEMS_FLINT_AND_STEEL
#define CUBICSERVER_ITEMS_USABLE_ITEMS_FLINT_AND_STEEL

#include "items/UsableItem.hpp"
#include "nbt.h"
#include "protocol/Structures.hpp"
#include "types.hpp"

#include <cstdint>
#include <string_view>

namespace Items {

struct FlintAndSteel : public UsableItem {
    FlintAndSteel("minecraft:flint_and_steel", 733, ItemMaxDurabilityByType::FlintAndSteel, false, UsabilityType::RightMouseClickUsable)
    {
        int32_t DAMAGE = 0;
        int32_t UNBREAKABLE = this->_isUnbreakable;
        std::string_view DAMAGE_TAG = "Damage";
        std::string_view UNBREAKABLE_TAG = "Breakable";
        auto root = nbt_new_tag_compound();
        auto damage = nbt_new_tag_int(DAMAGE);
        auto breakable = nbt_new_tag_int(UNBREAKABLE);
        nbt_set_tag_name(damage, DAMAGE_TAG.data(), DAMAGE_TAG.size());
        nbt_set_tag_name(breakable, UNBREAKABLE_TAG.data(), UNBREAKABLE_TAG.size());
        nbt_tag_compound_append(root, damage);
        nbt_tag_compound_append(root, breakable);

        this->_slot = protocol::Slot(true, this->_numeralId, 1, root);
    }
};

} // namespace Items

#endif // CUBICSERVER_ITEMS_USABLE_ITEMS_FLINT_AND_STEEL
