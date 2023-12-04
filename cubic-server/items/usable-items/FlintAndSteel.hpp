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
    FlintAndSteel(const std::string_view stringId = "minecraft:flint_and_steel", const int32_t numeralId = 733, const ItemMaxDurabilityByType maxDurability = ItemMaxDurabilityByType::FlintAndSteel, bool isUnbreakable = false, const UsabilityType usabilityType = UsabilityType::RightMouseClickUsable):
    _stringId(stringId),
    _numeralId(numeralId),
    _maxDurability(maxDurability),
    _isUnbreakable(isUnbreakable),
    _usabilityType(usabilityType)
    {
        auto root = setNbtTag();
        this->_slot = protocol::Slot(true, this->_numeralId, 1, root);
    }
};

} // namespace Items

#endif // CUBICSERVER_ITEMS_USABLE_ITEMS_FLINT_AND_STEEL
