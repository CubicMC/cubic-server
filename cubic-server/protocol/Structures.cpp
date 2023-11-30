#include "Structures.hpp"
#include "logging/logging.hpp"

bool protocol::Slot::isBroken()
{
    if (this->nbt == nullptr || this->nbt->type != NBT_TYPE_COMPOUND) {
        LERROR("Error with NBT");
        return false;
    } else if (nbt_tag_compound_get(this->nbt, "Damage") == nullptr) {
        LDEBUG("Unbreakable item");
        return false;
    }
    int32_t damageTaken = 0;
    GET_VALUE_INT(damageTaken, "Damage", this->nbt);
    if (damageTaken == (int32_t) Items::getMaxDurabilityById(this->itemID)) {
        return true;
    }
    return false;
}

void protocol::Slot::updateDamage()
{
    if (this->nbt == nullptr || this->nbt->type != NBT_TYPE_COMPOUND) {
        LERROR("Error with NBT");
        return;
    } else if (nbt_tag_compound_get(this->nbt, "Damage") == nullptr) {
        LDEBUG("Unbreakable item");
        return;
    }
    int32_t damageTaken = 0;
    GET_VALUE_INT(damageTaken, "Damage", this->nbt);
    damageTaken += 1;
    SET_VALUE_INT(damageTaken, "Damage", this->nbt);
    LDEBUG("Damage taken: {}", damageTaken);
    if (isBroken()) {
        this->reset();
        LDEBUG("Item just broke");
    }
}
