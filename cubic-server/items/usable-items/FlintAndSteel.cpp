#include "FlintAndSteel.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "logging/logging.hpp"
#include "world_storage/Section.hpp"

nbt_tag_t *Items::FlintAndSteel::setNbtTag()
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

void Items::FlintAndSteel::onUse(std::shared_ptr<Dimension> dim, Position &pos, UNUSED UsabilityType usage, UNUSED int32_t face)
{
    auto portal = NetherPortal(dim);
    if (portal.isFrame({pos.x, pos.y - 1, pos.z})) {
        portal.buildPortal({pos.x, pos.y - 1, pos.z});
        return;
    } else {
        dim->updateBlock(
            pos,
            Blocks::Fire::toProtocol(
                Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE, Blocks::Fire::Properties::South::FALSE,
                Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE
            )
        );
    }
}
