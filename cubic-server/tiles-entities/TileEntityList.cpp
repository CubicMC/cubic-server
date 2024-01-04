#include "TileEntityList.hpp"
#include "Server.hpp"

#include "Furnace.hpp"

std::shared_ptr<tile_entity::TileEntity> tile_entity::createTileEntity(BlockId blockId, Position position)
{
    TileEntityType tileEntityType = convertBlockNameToBlockEntityType(GLOBAL_PALETTE.fromProtocolIdToBlock(blockId).name);
    switch (tileEntityType) {
    case TileEntityType::Furnace:
        return std::make_shared<Furnace>(blockId, position);
    default:
        LINFO("Unknown tile entity type: {}", tileEntityType);
        return nullptr;
    }
}
