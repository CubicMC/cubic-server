#include "NetherPortal.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "logging/logging.hpp"
#include "types.hpp"
#include <utility>
#include <unistd.h>

PortalDirection NetherPortal::computeDirection(Position pos) {
    int countRightX = 1;
    int countLeftX = 1;
    int totalCountX = -1;
    int countRightZ = 1;
    int countLeftZ = 1;
    int totalCountZ = -1;

    // Count how many aligned obsidian blocks on the X axis
    while (_dim->getBlock({pos.x + countRightX, pos.y, pos.z}) == PortalBlocks::PORTAL_OBSIDIAN && _dim->getBlock({pos.x + (countRightX-1), pos.y, pos.z}) == PortalBlocks::PORTAL_OBSIDIAN)
        countRightX++;
    while (_dim->getBlock({pos.x - countLeftX, pos.y, pos.z}) == PortalBlocks::PORTAL_OBSIDIAN && _dim->getBlock({pos.x - (countLeftX-1), pos.y, pos.z}) == PortalBlocks::PORTAL_OBSIDIAN)
        countLeftX++;
    totalCountX += countRightX + countLeftX;

    // Count how many aligned obsidian blocks on the Z axis
    while (_dim->getBlock({pos.x, pos.y, pos.z + countRightZ}) == PortalBlocks::PORTAL_OBSIDIAN && _dim->getBlock({pos.x, pos.y, pos.z + (countRightZ-1)}) == PortalBlocks::PORTAL_OBSIDIAN)
        countRightZ++;
    while (_dim->getBlock({pos.x, pos.y, pos.z - countLeftZ}) == PortalBlocks::PORTAL_OBSIDIAN && _dim->getBlock({pos.x, pos.y, pos.z - (countLeftZ-1)}) == PortalBlocks::PORTAL_OBSIDIAN)
        countLeftZ++;
    totalCountZ += countRightZ + countLeftZ;

    if (totalCountX > totalCountZ) {
        if (countLeftX > countRightX)
            return PortalDirection::PORTAL_NEG_X;
        else
            return PortalDirection::PORTAL_POS_X;
    } else {
        if (countLeftZ > countRightZ)
            return PortalDirection::PORTAL_NEG_Z;
        else
            return PortalDirection::PORTAL_POS_Z;
    }

    return static_cast<std::underlying_type_t<PortalDirection>>(PortalError::PORTAL_BAD_PORTAL);
}

Vector2<int> NetherPortal::computeSize(Position pos, PortalDirection direction) {
    int countRight = 1; /**< for the right blocks from block horizontally (set to 1 to take block into account) */
    int countLeft = 1; /**< for the left blocks from block horizontally (set to 1 to take block into account) */
    int totalCountHorizontal = -1; /**< for the total blocks horizontally (set to -1 to address the offset when adding the right & left parts) */
    int totalCountVertical = 1;
    Vector2<int> size = {0, 0};

    if (direction == PortalDirection::PORTAL_POS_X || direction == PortalDirection::PORTAL_NEG_X) {
        while (_dim->getBlock({pos.x + countRight, pos.y, pos.z}) == PortalBlocks::PORTAL_OBSIDIAN && _dim->getBlock({pos.x + (countRight-1), pos.y, pos.z}) == PortalBlocks::PORTAL_OBSIDIAN)
            countRight++;
        while (_dim->getBlock({pos.x - countLeft, pos.y, pos.z}) == PortalBlocks::PORTAL_OBSIDIAN && _dim->getBlock({pos.x - (countLeft-1), pos.y, pos.z}) == PortalBlocks::PORTAL_OBSIDIAN)
            countLeft++;
        while ((_dim->getBlock({pos.x-(countLeft-1), pos.y + totalCountVertical, pos.z}) == PortalBlocks::PORTAL_OBSIDIAN && _dim->getBlock({pos.x-(countLeft-1), pos.y + (totalCountVertical-1), pos.z}) == PortalBlocks::PORTAL_OBSIDIAN)
        || (_dim->getBlock({pos.x+(countRight+1), pos.y + totalCountVertical, pos.z}) == PortalBlocks::PORTAL_OBSIDIAN && _dim->getBlock({pos.x+countRight+1, pos.y + (totalCountVertical-1), pos.z}) == PortalBlocks::PORTAL_OBSIDIAN))
            totalCountVertical++;
    } else if (direction == PortalDirection::PORTAL_POS_Z || direction == PortalDirection::PORTAL_NEG_Z) {
        while (_dim->getBlock({pos.x, pos.y, pos.z + countRight}) == PortalBlocks::PORTAL_OBSIDIAN && _dim->getBlock({pos.x, pos.y, pos.z + (countRight-1)}) == PortalBlocks::PORTAL_OBSIDIAN)
            countRight++;
        while (_dim->getBlock({pos.x, pos.y, pos.z - countLeft}) == PortalBlocks::PORTAL_OBSIDIAN && _dim->getBlock({pos.x, pos.y, pos.z - (countLeft-1)}) == PortalBlocks::PORTAL_OBSIDIAN)
            countLeft++;
        while ((_dim->getBlock({pos.x, pos.y + totalCountVertical, pos.z+(countRight+1)}) == PortalBlocks::PORTAL_OBSIDIAN && _dim->getBlock({pos.x, pos.y + (totalCountVertical-1), pos.z+(countRight+1)}) == PortalBlocks::PORTAL_OBSIDIAN)
        || (_dim->getBlock({pos.x, pos.y + totalCountVertical, pos.z-(countLeft-1)}) == PortalBlocks::PORTAL_OBSIDIAN && _dim->getBlock({pos.x, pos.y + (totalCountVertical-1), pos.z-(countLeft-1)}) == PortalBlocks::PORTAL_OBSIDIAN))
            totalCountVertical++;
    } else
        return {PortalError::PORTAL_BAD_PORTAL, PortalError::PORTAL_WRONG_DIRECTION};

    totalCountHorizontal += countRight + countLeft + PortalBoundary::PORTAL_MIN_WIDTH;
    if (totalCountHorizontal > PortalBoundary::PORTAL_MAX_WIDTH)
        return {PortalError::PORTAL_BAD_PORTAL, PortalError::PORTAL_SIZE_OVERFLOW};

    totalCountVertical += PortalBoundary::PORTAL_MIN_HEIGHT;
    if (totalCountVertical + PortalBoundary::PORTAL_MIN_HEIGHT > PortalBoundary::PORTAL_MAX_HEIGHT)
        return {PortalError::PORTAL_BAD_PORTAL, PortalError::PORTAL_SIZE_OVERFLOW};

    size = {totalCountHorizontal, totalCountVertical}

    return size;
}
