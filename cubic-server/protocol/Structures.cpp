#include "Structures.hpp"
#include "logging/logging.hpp"

bool protocol::Slot::isBroken()
{
    if (this->nbt == nullptr && this->nbt->type != NBT_TYPE_COMPOUND) {
        LERROR("Error with NBT");
        return true;
    }
    int32_t damageTaken = 0;
    GET_VALUE_INT(damageTaken, "Damage", this->nbt);
    if (damageTaken == (int32_t)Items::getMaxDurabilityById(this->itemID)) {
        return true;
    }
    return false;
}

void protocol::Slot::updateDamage()
{
    if (this->nbt == nullptr && this->nbt->type != NBT_TYPE_COMPOUND) {
        LERROR("Error with NBT");
        return;
    }
    int32_t damageTaken = 0;
    GET_VALUE_INT(damageTaken, "Damage", this->nbt);
    damageTaken += 1;
    SET_VALUE_INT(damageTaken, "Damage", this->nbt);
    LINFO("Damage taken: {}", damageTaken);
    if (isBroken()) {
        this->present = false;
        this->itemCount = 0;
        this->itemID = 0;
        nbt_free_tag(this->nbt);
        this->nbt = nullptr;
        LINFO("Item broke");
    }
}