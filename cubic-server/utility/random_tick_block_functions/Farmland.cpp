#include "Dimension.hpp"
#include "Server.hpp"
#include "blocks.hpp"
#include "types.hpp"
#include "utility/RandomTickBlockFunctions.hpp"
#include "world_storage/ChunkColumn.hpp"
#include <memory>

bool checkWater(const world_storage::ChunkColumn &chunkColumn, const Position &ablsolutePosition)
{
    auto dim = chunkColumn.getDimension();
    for (int y = 0; y < 2; y++) {
        for (int x = -4; x < 5; x++) {
            for (int z = -4; z < 5; z++) {
                if (GLOBAL_PALETTE.fromProtocolIdToBlock(dim->getBlock(ablsolutePosition + Position(x, y, z))).name.find("water") != std::string::npos) {
                    return true;
                }
            }
        }
    }
    return false;
}

void utility::farmland(BlockId blockId, world_storage::ChunkColumn &chunkColumn, const Position &ablsolutePosition)
{
    if (blockId == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::ZERO)) {
        LINFO("Farmland type 0");
        if (checkWater(chunkColumn, ablsolutePosition)) {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::SEVEN));
            LINFO("Farmland has water");
        } else {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Dirt::toProtocol());
            LINFO("Farmland has no water");
        }
    }
    if (blockId == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::ONE)) {
        if (checkWater(chunkColumn, ablsolutePosition)) {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::SEVEN));
        } else {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::ZERO));
        }
    }
    if (blockId == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::TWO)) {
        if (checkWater(chunkColumn, ablsolutePosition)) {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::SEVEN));
        } else {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::ONE));
        }
    }
    if (blockId == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::THREE)) {
        if (checkWater(chunkColumn, ablsolutePosition)) {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::SEVEN));
        } else {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::TWO));
        }
    }
    if (blockId == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::FOUR)) {
        if (checkWater(chunkColumn, ablsolutePosition)) {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::SEVEN));
        } else {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::THREE));
        }
    }
    if (blockId == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::FIVE)) {
        if (checkWater(chunkColumn, ablsolutePosition)) {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::SEVEN));
        } else {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::FOUR));
        }
    }
    if (blockId == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::SIX)) {
        if (checkWater(chunkColumn, ablsolutePosition)) {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::SEVEN));
        } else {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::FIVE));
        }
    }
    if (blockId == Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::SEVEN)) {
        if (!checkWater(chunkColumn, ablsolutePosition)) {
            chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(ablsolutePosition), Blocks::Farmland::toProtocol(Blocks::Farmland::Properties::Moisture::SIX));
        }
    }
}
