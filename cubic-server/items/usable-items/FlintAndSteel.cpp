#include "FlintAndSteel.hpp"
#include "logging/logging.hpp"
#include "Dimension.hpp"

nbt_tag_t *FlintAndSteel::setNbtTag()
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

    return root;
}

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
