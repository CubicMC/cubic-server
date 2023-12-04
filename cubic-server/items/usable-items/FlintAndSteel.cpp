#include "FlintAndSteel.hpp"
#include "logging/logging.hpp"
#include "Dimension.hpp"

void FlintAndSteel::updateDamage()
{
    if (this->_slot.nbt == nullptr || this->_slot.nbt->type != NBT_TYPE_COMPOUND) {
        LERROR("Error with NBT - No corresponding NBT found");
        return;
    } else if (nbt_tag_compound_get(this->_slot.nbt, "Damage") == nullptr) {
        LINFO("Unbreakable item");
        return;
    }
    int32_t damageTaken = 0;
    GET_VALUE_INT(damageTaken, "Damage", this->_slot.nbt);

    if (this->_isUnbreakable == false) {
        damageTaken += 1;
        SET_VALUE_INT(damageTaken, "Damage", this->_slot.nbt);
        LINFO("Damage taken: {}", damageTaken);
    }
    if (damageTaken == (int32_t) this->_maxDurability) {
        this->_slot.reset();
        LINFO("Item just broke");
    }
}

void FlintAndSteel::onUse(std::shared_ptr<Dimension> dim, Position &pos)
{
    dim->updateBlock(pos, Blocks::Fire::toProtocol(Blocks::Fire::Properties::Age::ZERO,
    Blocks::Fire::Properties::East::FALSE,
    Blocks::Fire::Properties::North::FALSE,
    Blocks::Fire::Properties::South::FALSE,
    Blocks::Fire::Properties::Up::FALSE,
    Blocks::Fire::Properties::West::FALSE));
    this.updateDamage();
}
