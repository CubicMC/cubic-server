#include "add.hpp"

namespace protocol {
void addBlockEntities(std::vector<uint8_t> &out, const std::unordered_map<Position, std::shared_ptr<tile_entity::TileEntity>> &data)
{
    addVarInt(out, data.size());
    for (auto &[_, tileEntity] : data)
        addBlockEntity(out, tileEntity->updateNbt()->toBlockEntity());
}
}
