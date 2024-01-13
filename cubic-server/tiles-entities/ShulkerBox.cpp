#include "ShulkerBox.hpp"
#include "Server.hpp"
#include "nbt.h"
#include <cstddef>

namespace tile_entity {
ShulkerBox::ShulkerBox(BlockId blockId, const Position &position, nbt_tag_t *nbt):
    TileEntity("minecraft:shulker_box", position, nullptr)
{
    for (auto [name, value] : GLOBAL_PALETTE.fromProtocolIdToBlock(blockId).properties) {
        if (name == "facing") {
            if (value == "north")
                _facing = Blocks::ShulkerBox::Properties::Facing::NORTH;
            if (value == "south")
                _facing = Blocks::ShulkerBox::Properties::Facing::SOUTH;
            if (value == "west")
                _facing = Blocks::ShulkerBox::Properties::Facing::WEST;
            if (value == "east")
                _facing = Blocks::ShulkerBox::Properties::Facing::EAST;
        }
    }
    if (nbt != nullptr) {
        auto *items = nbt_tag_compound_get(nbt, "Items");
        if (items != nullptr) {
            for (size_t i = 0; i < items->tag_list.size; ++i) {
                auto *slot = nbt_tag_list_get(items, i);
                if (slot != nullptr) {
                    bool present = nbt_tag_compound_get(slot, "Present")->tag_byte.value;
                    if (present) {
                        auto id = nbt_tag_compound_get(slot, "id")->tag_int.value;
                        auto count = nbt_tag_compound_get(slot, "Count")->tag_byte.value;
                    }
                }
            }
        }
    }
    LINFO("Created ShulkerBox with facing: {}", _facing);
}
}
