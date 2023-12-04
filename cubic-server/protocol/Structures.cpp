#include "Structures.hpp"
#include "items/UsableItem.hpp"
#include "logging/logging.hpp"

void protocol::Slot::updateDamage()
{
    if (this->nbt == nullptr || this->nbt->type != NBT_TYPE_COMPOUND) {
        LERROR("Error with NBT - No corresponding NBT found");
        return;
    } else if (nbt_tag_compound_get(this->nbt, "Damage") == nullptr) {
        LINFO("Unbreakable item");
        return;
    }
    int32_t damageTaken = 0;
    GET_VALUE_INT(damageTaken, "Damage", this->nbt);

    if (this->itemUse->isUnbreakable == false) {
        damageTaken += 1;
        SET_VALUE_INT(damageTaken, "Damage", this->nbt);
        LINFO("Damage taken: {}", damageTaken);
    }
    if (damageTaken == (int32_t) this->itemUse->maxDurability) {
        this->reset();
        LINFO("Item just broke");
    }
}

Items::UsabilityType protocol::Slot::getUsabilityType()
{
    itemUse = std::find_if(Items::usableItems.begin(), Items::usableItems.end(), [this](const Items::UsableItem &item) {
        return item.numeralId == this->itemID;
    });
    LINFO("Item: {}", this->itemUse->stringId);
    LINFO("Type: {}", this->itemUse->usabilityType);
    return this->itemUse->usabilityType;
}