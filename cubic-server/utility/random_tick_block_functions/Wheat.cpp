#include "Dimension.hpp"
#include "Server.hpp"
#include "blocks.hpp"
#include "types.hpp"
#include "utility/PseudoRandomGenerator.hpp"
#include "utility/RandomTickBlockFunctions.hpp"
#include "world_storage/ChunkColumn.hpp"
#include <memory>

void utility::wheat(BlockId blockId, world_storage::ChunkColumn &chunkColumn, const Position &absolutePosition)
{
    auto *rgen = utility::PseudoRandomGenerator::getInstance();

    if (rgen->generateNumber(0, 2) > 0)
        return;
    if (blockId == Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::ZERO)) {
        LTRACE("Wheat type 0");
        chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(absolutePosition), Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::ONE));
    }
    if (blockId == Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::ONE)) {
        LTRACE("Wheat type 1");
        chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(absolutePosition), Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::TWO));
    }
    if (blockId == Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::TWO)) {
        LTRACE("Wheat type 2");
        chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(absolutePosition), Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::THREE));
    }
    if (blockId == Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::THREE)) {
        LTRACE("Wheat type 3");
        chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(absolutePosition), Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::FOUR));
    }
    if (blockId == Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::FOUR)) {
        LTRACE("Wheat type 4");
        chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(absolutePosition), Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::FIVE));
    }
    if (blockId == Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::FIVE)) {
        LTRACE("Wheat type 5");
        chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(absolutePosition), Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::SIX));
    }
    if (blockId == Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::SIX)) {
        LTRACE("Wheat type 6");
        chunkColumn.updateBlock(world_storage::convertPositionToChunkPosition(absolutePosition), Blocks::Wheat::toProtocol(Blocks::Wheat::Properties::Age::SEVEN));
    }
}
