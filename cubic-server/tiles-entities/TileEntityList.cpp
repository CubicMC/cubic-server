#include "TileEntityList.hpp"
#include "Server.hpp"

#include "Furnace.hpp"

std::unique_ptr<TileEntity> createTileEntity(BlockId blockId, Position position)
{
    TileEntityType tileEntityType = convertBlockNameToBlockEntityType(GLOBAL_PALETTE.fromProtocolIdToBlock(blockId).name);
    switch (tileEntityType) {
    case TileEntityType::Furnace:
        return std::make_unique<Furnace>(blockId, position);
    default:
        LINFO("Unknown tile entity type: {}", tileEntityType);
        return nullptr;
    }
}
