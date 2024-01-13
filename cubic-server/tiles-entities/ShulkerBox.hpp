#ifndef CUBICSERVER_TILEENTITY_SHULKERBOX_HPP
#define CUBICSERVER_TILEENTITY_SHULKERBOX_HPP

#include "TileEntity.hpp"
#include "blocks.hpp"

class Player;

namespace tile_entity {
class ShulkerBox : public TileEntity {
public:
    ShulkerBox(BlockId blockId, const Position &position, nbt_tag_t *nbt);

    ShulkerBox(const ShulkerBox &) = default;

    BlockId getBlockId() const override { return Blocks::ShulkerBox::toProtocol(_facing); }

    void tick() override {};

private:
    Blocks::ShulkerBox::Properties::Facing _facing;
};
}

#endif // CUBICSERVER_TILEENTITY_SHULKERBOX_HPP
