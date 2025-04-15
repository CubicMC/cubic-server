#include "NetherPortal.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "logging/logging.hpp"
#include "types.hpp"
#include <utility>

// int getDirection(Position pos) {

// }

Vector2<int> NetherPortal::computeSize(Position pos, PortalDirection direction) {
    auto block = _dim->getBlock(pos); // (block{n;0;0} or block{0;0;n})
    int countRight = 1; /**< for the right blocks from block horizontally (set to 1 to take block into account) */
    int countLeft = 1; /**< for the left blocks from block horizontally (set to 1 to take block into account) */
    int totalCountHorizontal = -1; /**< for the total blocks horizontally (set to -1 to address the offset when adding the right & left parts) */
    int totalCountVertical = 1;
    Vector2<int> size = {0, 0};

    if (direction == PortalDirection::PORTAL_POS_X || direction == PortalDirection::PORTAL_NEG_X) {
        while (_dim->getBlock({pos.x + countRight, pos.y, pos.z}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({pos.x + (countRight-1), pos.y, pos.z}) == Blocks::Obsidian::toProtocol())
            countRight++;
        while (_dim->getBlock({pos.x - countLeft, pos.y, pos.z}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({pos.x - (countLeft-1), pos.y, pos.z}) == Blocks::Obsidian::toProtocol())
            countLeft++;
        while ((_dim->getBlock({pos.x-countLeft-1, pos.y + totalCountVertical, pos.z}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({pos.x-countLeft-1, pos.y + (totalCountVertical-1), pos.z}) == Blocks::Obsidian::toProtocol()) || (_dim->getBlock({pos.x+countRight+1, pos.y + totalCountVertical, pos.z}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({pos.x+countRight+1, pos.y + (totalCountVertical-1), pos.z}) == Blocks::Obsidian::toProtocol()))
            totalCountVertical++;
    } else if (direction == PortalDirection::PORTAL_POS_Z || direction == PortalDirection::PORTAL_NEG_Z) {
        while (_dim->getBlock({pos.x, pos.y, pos.z + countRight}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({pos.x, pos.y, pos.z + (countRight-1)}) == Blocks::Obsidian::toProtocol())
            countRight++;
        while (_dim->getBlock({pos.x, pos.y, pos.z - countLeft}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({pos.x, pos.y, pos.z - (countLeft-1)}) == Blocks::Obsidian::toProtocol())
            countLeft++;
        while ((_dim->getBlock({pos.x, pos.y + totalCountVertical, pos.z+countRight+1}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({pos.x, pos.y + (totalCountVertical-1), pos.z+countRight+1}) == Blocks::Obsidian::toProtocol()) || (_dim->getBlock({pos.x, pos.y + totalCountVertical, pos.z-countLeft-1}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({pos.x, pos.y + (totalCountVertical-1), pos.z-countLeft-1}) == Blocks::Obsidian::toProtocol()))
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

// int NetherPortal::checkLayers(Position pos, int axis)
// {
//     auto block = _dim->getBlock(pos);
//     for (int y = 0; y < this->_size.z; y++) {
//         for (int x = 0; x < this->_size.x; x++) {
//             if (axis == WIDTH) {
//                 block = _dim->getBlock({pos.x + x, pos.y + y, pos.z});
//             } else if (axis == HEIGHT) {
//                 block = _dim->getBlock({pos.x, pos.y + y, pos.z + x});
//             } else {
//                 return WRONG_AXIS;
//             }
//             if ((y == 0 || y == FRAME_HEIGHT - 1) && (x == 0 || x == FRAME_WIDTH - 1)) {
//                 if (block != Blocks::Obsidian::toProtocol()) {
//                     return false;
//                 }
//             } else if (x != 0 && x < FRAME_WIDTH - 1 && y == 1) {
//                 if (block == Blocks::Air::toProtocol() ||
//                     block ==
//                         Blocks::Fire::toProtocol(
//                             Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE,
//                             Blocks::Fire::Properties::South::FALSE, Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE
//                         )) {
//                     continue;
//                 } else {
//                     return false;
//                 }
//             } else if (x > 1 && x < FRAME_WIDTH - 1 && y != 0 && y < FRAME_HEIGHT - 1) {
//                 if (block != Blocks::Air::toProtocol()) {
//                     return false;
//                 }
//             }
//         }
//     }
//     return 1;
// }
