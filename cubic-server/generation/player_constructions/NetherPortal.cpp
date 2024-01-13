#include "NetherPortal.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "logging/logging.hpp"
#include "types.hpp"
#include <utility>

bool NetherPortal::checkLayers(Position pos, int axis)
{
    world_storage::ChunkColumn &_chunk = _dim->getLevel().getChunkColumnFromBlockPos(pos.x, pos.z);
    auto block = _chunk.getBlock(pos);
    for (int y = 0; y < FRAME_HEIGHT; y++) {
        for (int x = 0; x < FRAME_WIDTH; x++) {
            if (axis == AXIS_X) {
                block = _chunk.getBlock(world_storage::convertPositionToChunkPosition({pos.x + x, pos.y + y, pos.z}));
            } else if (axis == AXIS_Z) {
                block = _chunk.getBlock(world_storage::convertPositionToChunkPosition({pos.x, pos.y + y, pos.z + x}));
            } else {
                return false;
            }
            if ((y == 0 || y == FRAME_HEIGHT - 1) && (x == 0 || x == FRAME_WIDTH - 1)) {
                if (block != Blocks::Obsidian::toProtocol()) {
                    LERROR("Wrong obsidian layer: x:{} y:{}, block:{}", pos.x + x, pos.y + y, block);
                    return false;
                }
            } else if (x != 0 && x < FRAME_WIDTH - 1 && y == 1) {
                if (block == Blocks::Air::toProtocol() ||
                    block ==
                        Blocks::Fire::toProtocol(
                            Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE,
                            Blocks::Fire::Properties::South::FALSE, Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE
                        )) {
                    continue;
                } else {
                    LERROR("Wrong middle layer(s) : obsidian, x:{} y:{}, block:{}", pos.x + x, pos.y + y, block);
                    return false;
                }
            } else if (x > 1 && x < FRAME_WIDTH - 1 && y != 0 && y < FRAME_HEIGHT - 1) {
                if (block != Blocks::Air::toProtocol()) {
                    LERROR("Wrong middle layer(s) : air, x:{} y:{}, block:{}", pos.x + x, pos.y + y, block);
                    return false;
                }
            }
        }
    }
    LINFO("Frame here");
    return true;
}

Frame NetherPortal::getFrame(Position pos)
{
    world_storage::ChunkColumn &_chunk = _dim->getLevel().getChunkColumnFromBlockPos(pos.x, pos.z);
    auto nextBlockX = _chunk.getBlock(world_storage::convertPositionToChunkPosition({(pos.x + 1), pos.y, pos.z}));
    auto nextBlockZ = _chunk.getBlock(world_storage::convertPositionToChunkPosition({pos.x, pos.y, (pos.z + 1)}));
    auto topNextBlockX = _chunk.getBlock(world_storage::convertPositionToChunkPosition({(pos.x + 1), pos.y + 1, pos.z}));
    auto topNextBlockZ = _chunk.getBlock(world_storage::convertPositionToChunkPosition({pos.x, pos.y + 1, (pos.z + 1)}));

    // LWARN("Chunk: {}.{}", _chunk.getChunkPos().x, _chunk.getChunkPos().z);
    // LINFO("nextBlockX: {}, {}.{}.{}", nextBlockX, (pos.x + 1), pos.y, pos.z);
    // LINFO("nextBlockZ: {}, {}.{}.{}", nextBlockZ, pos.x, pos.y, (pos.z + 1));
    // LINFO("topNextBlockX: {}, {}.{}.{}", topNextBlockX, (pos.x + 1), pos.y + 1, pos.z);
    // LINFO("topNextBlockZ: {}, {}.{}.{}", topNextBlockZ, pos.x, pos.y + 1, (pos.z + 1));

    if (nextBlockX == Blocks::Obsidian::toProtocol() && topNextBlockX == Blocks::Air::toProtocol() && nextBlockZ != Blocks::Obsidian::toProtocol()) {
        LDEBUG("Axis X");
        if (checkLayers({pos.x - 1, pos.y, pos.z}, AXIS_X))
            return {AXIS_X, POSITIVE_POS};
    } else if (nextBlockX == Blocks::Obsidian::toProtocol() && topNextBlockX == Blocks::Obsidian::toProtocol() && topNextBlockZ != Blocks::Obsidian::toProtocol()) {
        LDEBUG("Axis X");
        if (checkLayers({pos.x - 2, pos.y, pos.z}, AXIS_X))
            return {AXIS_X, NEGATIVE_POS};
    }
    if (nextBlockZ == Blocks::Obsidian::toProtocol() && topNextBlockZ == Blocks::Air::toProtocol() && nextBlockX != Blocks::Obsidian::toProtocol()) {
        LDEBUG("Axis Z");
        if (checkLayers({pos.x, pos.y, pos.z - 1}, AXIS_Z))
            return {AXIS_Z, POSITIVE_POS};
    } else if (nextBlockZ == Blocks::Obsidian::toProtocol() && topNextBlockZ == Blocks::Obsidian::toProtocol() && topNextBlockX != Blocks::Obsidian::toProtocol()) {
        LDEBUG("Axis Z");
        if (checkLayers({pos.x, pos.y, pos.z - 2}, AXIS_Z))
            return {AXIS_Z, NEGATIVE_POS};
    }
    LWARN("No frame");
    return {AXIS_UNDEFINED, UNDEFINED_POS};
}

void NetherPortal::buildPortal(Position pos)
{
    world_storage::ChunkColumn &_chunk = _dim->getLevel().getChunkColumnFromBlockPos(pos.x, pos.z);
    auto frame = getFrame(pos);
    std::vector<std::pair<Position, BlockId>> blocksArray;
    auto block = _chunk.getBlock(pos);
    for (int y = 0; y < FRAME_HEIGHT - 1; y++) {
        for (int x = 0; x < FRAME_WIDTH - 1; x++) {
            if (frame.direction == POSITIVE_POS && frame.axis == AXIS_X) {
                block = _chunk.getBlock(world_storage::convertPositionToChunkPosition({pos.x - 1 + x, pos.y + y, pos.z}));
                if (block == Blocks::Air::toProtocol() ||
                    block ==
                        Blocks::Fire::toProtocol(
                            Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE,
                            Blocks::Fire::Properties::South::FALSE, Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE
                        )) {
                    blocksArray.push_back({{pos.x - 1 + x, pos.y + y, pos.z}, Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::X)});
                }
            } else if (frame.direction == POSITIVE_POS && frame.axis == AXIS_Z) {
                block = _chunk.getBlock(world_storage::convertPositionToChunkPosition({pos.x, pos.y + y, pos.z - 1 + x}));
                if (block == Blocks::Air::toProtocol() ||
                    block ==
                        Blocks::Fire::toProtocol(
                            Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE,
                            Blocks::Fire::Properties::South::FALSE, Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE
                        )) {
                    blocksArray.push_back({{pos.x, pos.y + y, pos.z - 1 + x}, Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::Z)});
                }
            } else if (frame.direction == NEGATIVE_POS && frame.axis == AXIS_X) {
                block = _chunk.getBlock(world_storage::convertPositionToChunkPosition({pos.x - 2 + x, pos.y + y, pos.z}));
                if (block == Blocks::Air::toProtocol() ||
                    block ==
                        Blocks::Fire::toProtocol(
                            Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE,
                            Blocks::Fire::Properties::South::FALSE, Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE
                        )) {
                    blocksArray.push_back({{pos.x - 2 + x, pos.y + y, pos.z}, Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::X)});
                }
            } else if (frame.direction == NEGATIVE_POS && frame.axis == AXIS_Z) {
                block = _chunk.getBlock(world_storage::convertPositionToChunkPosition({pos.x, pos.y + y, pos.z - 2 + x}));
                if (block == Blocks::Air::toProtocol() ||
                    block ==
                        Blocks::Fire::toProtocol(
                            Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE,
                            Blocks::Fire::Properties::South::FALSE, Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE
                        )) {
                    blocksArray.push_back({{pos.x, pos.y + y, pos.z - 2 + x}, Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::Z)});
                }
            }
        }
    }
    for (auto [position, id] : blocksArray) {
        auto &chunk = _dim->getLevel().getChunkColumnFromBlockPos(position.x, position.z);
        auto chunkPosition = world_storage::convertPositionToChunkPosition(position);
        chunk.updateBlock(chunkPosition, id);
        LINFO("Supposedly built");
        for (auto player : _dim->getPlayers()) {
            player->sendBlockUpdate({pos, chunk.getBlock(pos)});
            player->sendBlockUpdate({position, id});
            // player->sendUpdateSectionBlock({position,chunk, true, blocksArray});
        }
    }
}
