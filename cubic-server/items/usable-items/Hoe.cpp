#include "Hoe.hpp"
#include "Dimension.hpp"
#include "Server.hpp"
#include "blocks.hpp"
#include "entities/Item.hpp"
#include "items/UsableItem.hpp"
#include "options.hpp"
#include <exception>

nbt_tag_t *Items::Hoe::setNbtTag()
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

void Items::Hoe::onUseOn(std::shared_ptr<Dimension> dim, Position &pos, UsabilityType usage, int32_t face, UNUSED Entity &user)
{
    auto blockPos = pos;

    switch (face) {
    case 0: /**< protocol::UseItemOn::Face::Bottom */
        blockPos.y++;
        break;
    case 1: /**< protocol::UseItemOn::Face::Top */
        blockPos.y--;
        break;
    case 2: /**< protocol::UseItemOn::Face::North */
        blockPos.z++;
        break;
    case 3: /**< protocol::UseItemOn::Face::South */
        blockPos.z--;
        break;
    case 4: /**< protocol::UseItemOn::Face::East */
        blockPos.x++;
        break;
    case 5: /**< protocol::UseItemOn::Face::West */
        blockPos.x--;
        break;
    }

    try {
        auto Topblock = dim->getBlock(pos);
        auto block = dim->getBlock(blockPos);
        if (usage == UsabilityType::RightMouseClickUsable) {
            if (Topblock == Blocks::Air::toProtocol() &&
                (block == Blocks::Dirt::toProtocol() || block == Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE) ||
                 block == Blocks::DirtPath::toProtocol())) {
                dim->updateBlock(blockPos, Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::ZERO));
                canUpdateDamage = true;
                return;
            } else if (Topblock == Blocks::Air::toProtocol() && block == Blocks::CoarseDirt::toProtocol()) {
                dim->updateBlock(blockPos, Blocks::Dirt::toProtocol());
                canUpdateDamage = true;
                return;
            } else if (Topblock == Blocks::Air::toProtocol() && block == Blocks::RootedDirt::toProtocol()) {
                dim->updateBlock(blockPos, Blocks::Dirt::toProtocol());
                dim->makeEntity<Item>(protocol::Slot {true, 214, 1})
                    ->dropItem({static_cast<double>(pos.x) + 0.5, static_cast<double>(pos.y), static_cast<double>(pos.z) + 0.5}); // hanging roots
                canUpdateDamage = true;
                return;
            }
        } else if (usage == UsabilityType::LeftMouseClickUsable) {
            if (BLOCK_DATA_CONVERTER.fromBlockIdToBlockData(dim->getBlock(pos)).hardness != 0) {
                canUpdateDamage = true;
                return;
            }
            for (int i = 0; i <= (int) breakableWithHoe.size(); i++) {
                if (GLOBAL_PALETTE.fromBlockToProtocolId(breakableWithHoe[i])) {
                    // TODO: handle breaking blocks speed
                }
            }
        }
    } catch (std::exception &e) {
        LERROR("Error in getting block");
    }
    canUpdateDamage = false;
}
