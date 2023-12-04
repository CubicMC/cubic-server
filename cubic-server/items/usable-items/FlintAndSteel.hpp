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
    FlintAndSteel()
    {
        this->_stringId = "minecraft:flint_and_steel";
        this->_numeralId = 733;
        this->_maxDurability = ItemMaxDurabilityByType::FlintAndSteel;
        this->_isUnbreakable = false;
        this->_usabilityType = UsabilityType::RightMouseClickUsable;
        auto root = setNbtTag();
        this->_slot = protocol::Slot(true, this->_numeralId, 1, root);
    }
};

} // namespace Items

#endif // CUBICSERVER_ITEMS_USABLE_ITEMS_FLINT_AND_STEEL
