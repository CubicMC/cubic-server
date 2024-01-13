#include "Structures.hpp"
#include "items/UsableItem.hpp"
#include "items/usable-items/FlintAndSteel.hpp"
#include "items/usable-items/Hoe.hpp"
#include "logging/logging.hpp"

const protocol::ItemType protocol::Slot::getUsableItemFromSlot()
{
    auto item = std::find_if(Items::usableItems.begin(), Items::usableItems.end(), [this](const Items::UsableItem &uItem) {
        return uItem._numeralId == this->itemID;
    });
    if (item == Items::usableItems.end()) {
        return Items::usableItems[40];
    }
    if (item->_stringId == "minecraft:flint_and_steel")
        return Items::FlintAndSteel();
    if (item->_stringId == "minecraft:bow")
        return Items::Bow(*item);
    if (item->_stringId.find("_hoe") != item->_stringId.npos)
        return Items::Hoe(*item);
    return *item;
}

void protocol::Slot::updateDamage()
{
    auto item = std::find_if(Items::usableItems.begin(), Items::usableItems.end(), [this](const Items::UsableItem &uItem) {
        return uItem._numeralId == this->itemID;
    });
    if (item == Items::usableItems.end()) {
        return;
    }
    if (this->nbt == nullptr || this->nbt->type != NBT_TYPE_COMPOUND) {
        LERROR("Error with NBT - No corresponding NBT found");
        return;
    } else if (nbt_tag_compound_get(this->nbt, "Damage") == nullptr) {
        LDEBUG("Unbreakable item - No durability set");
        return;
    }
    int32_t damageTaken = 0;
    GET_VALUE_INT(damageTaken, "Damage", this->nbt);
    damageTaken += 1;
    SET_VALUE_INT(damageTaken, "Damage", this->nbt);
    LDEBUG("Damage taken: {}/{}", damageTaken, item->_maxDurability);
    if (damageTaken >= (int32_t) item->_maxDurability) {
        this->reset();
        LDEBUG("Item just broke");
    }
}
