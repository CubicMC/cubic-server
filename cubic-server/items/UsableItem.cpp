#include "UsableItem.hpp"
#include "logging/logging.hpp"

void Items::UsableItem::updateDamage()
{
    if (this->slot.nbt == nullptr || this->slot.nbt->type != NBT_TYPE_COMPOUND) {
        LERROR("Error with NBT - No corresponding NBT found");
        return;
    } else if (nbt_tag_compound_get(this->slot.nbt, "Damage") == nullptr) {
        LINFO("Unbreakable item");
        return;
    }
    int32_t damageTaken = 0;
    GET_VALUE_INT(damageTaken, "Damage", this->slot.nbt);

    if (this->isUnbreakable == false) {
        damageTaken += 1;
        SET_VALUE_INT(damageTaken, "Damage", this->slot.nbt);
        LINFO("Damage taken: {}", damageTaken);
    }
    if (damageTaken == (int32_t) this->maxDurability) {
        this->slot.reset();
        LINFO("Item just broke");
    }
}

void Items::UsableItem::onUse(const std::string_view stringId, Position &pos)
{

}