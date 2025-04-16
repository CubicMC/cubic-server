#include "NetherPortal.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "logging/logging.hpp"
#include "types.hpp"
#include <utility>

void NetherPortal::setIgnitedBlock() {
    std::vector<std::pair<Position, BlockId>> blocksArray;

    // blockArray[0] & blockArray[1] - {-1;0;0}, {1;0;0} - LEFT or RIGHT
    for (int x = -1; x <= 1; x++) {
        if (x != 0)
            continue;
        auto lateralBlock = {_pos.x + x, _pos.y, _pos.z};
        blocksArray.push_back({lateralBlock, _dim->getBlock(lateralBlock)});
    }
    // blockArray[2] & blockArray[3] - {0;-1;0}, {0;1;0} - TOP or BOTTOM
    for (int y = -1; y <= 1; y++) {
        if (y != 0)
            continue;
        auto lateralBlock = {_pos.x, _pos.y + y, _pos.z};
        blocksArray.push_back({lateralBlock, _dim->getBlock(lateralBlock)});
    }
    // blockArray[4] & blockArray[5] - {0;0;-1}, {0;0;1} - LEFT or RIGHT
    for (int z = -1; z <= 1; z++) {
        if (z != 0)
            continue;
        auto lateralBlock = {_pos.x, _pos.y, _pos.z + z};
        blocksArray.push_back({lateralBlock, _dim->getBlock(lateralBlock)});
    }

    if (blocksArray[4].second == Blocks::Obsidian::toProtocol() && blocksArray[5].second != Blocks::Obsidian::toProtocol()) {
        if ((blocksArray[0].second == Blocks::Obsidian::toProtocol() && blocksArray[1].second != Blocks::Obsidian::toProtocol()) || (blocksArray[2].second == Blocks::Obsidian::toProtocol() && blocksArray[3].second != Blocks::Obsidian::toProtocol())) {
            _ignitedBlock = PortalIgnition::PORTAL_TOP_LEFT_CORNER;
            return;
        } else if ((blocksArray[1].second == Blocks::Obsidian::toProtocol() && blocksArray[0].second != Blocks::Obsidian::toProtocol()) || (blocksArray[3].second == Blocks::Obsidian::toProtocol() && blocksArray[2].second != Blocks::Obsidian::toProtocol())) {
            _ignitedBlock = PortalIgnition::PORTAL_TOP_RIGHT_CORNER;
            return;
        } else {
            _ignitedBlock = PortalIgnition::PORTAL_TOP_CENTER;
            return;
        }
    } else if (blocksArray[4].second != Blocks::Obsidian::toProtocol() && blocksArray[5].second == Blocks::Obsidian::toProtocol()) {
        if ((blocksArray[0].second == Blocks::Obsidian::toProtocol() && blocksArray[1].second != Blocks::Obsidian::toProtocol()) || (blocksArray[2].second == Blocks::Obsidian::toProtocol() && blocksArray[3].second != Blocks::Obsidian::toProtocol())) {
            _ignitedBlock = PortalIgnition::PORTAL_BOTTOM_LEFT_CORNER;
            return;
        } else if ((blocksArray[1].second == Blocks::Obsidian::toProtocol() && blocksArray[0].second != Blocks::Obsidian::toProtocol()) || (blocksArray[3].second == Blocks::Obsidian::toProtocol() && blocksArray[2].second != Blocks::Obsidian::toProtocol())) {
            _ignitedBlock = PortalIgnition::PORTAL_BOTTOM_RIGHT_CORNER;
            return;
        } else {
            _ignitedBlock = PortalIgnition::PORTAL_BOTTOM_CENTER;
            return;
        }
    } else {
        if ((blocksArray[0].second == Blocks::Obsidian::toProtocol() && blocksArray[1].second != Blocks::Obsidian::toProtocol()) || (blocksArray[2].second == Blocks::Obsidian::toProtocol() && blocksArray[3].second != Blocks::Obsidian::toProtocol())) {
            _ignitedBlock = PortalIgnition::PORTAL_LEFT_CENTER;
            return;
        } else if ((blocksArray[1].second == Blocks::Obsidian::toProtocol() && blocksArray[0].second != Blocks::Obsidian::toProtocol()) || (blocksArray[3].second == Blocks::Obsidian::toProtocol() && blocksArray[2].second != Blocks::Obsidian::toProtocol())) {
            _ignitedBlock = PortalIgnition::PORTAL_RIGHT_CENTER;
            return;
        } else {
            _ignitedBlock = PortalIgnition::PORTAL_NONE;
            return;
        }
    }

    _ignitedBlock = PortalIgnition::PORTAL_NONE;
}

void NetherPortal::setBottomLeftCorner() {
    auto block = _dim->getBlock(_pos);

    if (_ignitedBlock == PortalIgnition::PORTAL_BOTTOM_LEFT_CORNER) {
        _bottomLeftCorner = {_pos.x, pos.y - 1, pos.z};
        return;
    } else if (_ignitedBlock == PortalIgnition::PORTAL_TOP_LEFT_CORNER || _ignitedBlock == PortalIgnition::PORTAL_LEFT_CENTER) {
        for (int count = 0; count < PortalBoundary::PORTAL_MAX_HEIGHT - PortalBoundary::PORTAL_MIN_HEIGHT; count++) {
            if (_dim->getBlock({_pos.x, pos.y - count, pos.z}) != Blocks::Obsidian::toProtocol())
                continue;
            _bottomLeftCorner = {_pos.x, pos.y - count, pos.z};
            return;
        }
    }
}

void NetherPortal::setDirection() {
    int countRightX = 1;
    int countLeftX = 1;
    int totalCountX = -1;
    int countRightZ = 1;
    int countLeftZ = 1;
    int totalCountZ = -1;

    // Count how many aligned obsidian blocks on the X axis
    while (_dim->getBlock({_pos.x + countRightX, _pos.y, _pos.z}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x + (countRightX-1), _pos.y, _pos.z}) == Blocks::Obsidian::toProtocol())
        countRightX++;
    while (_dim->getBlock({_pos.x - countLeftX, _pos.y, _pos.z}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x - (countLeftX-1), _pos.y, _pos.z}) == Blocks::Obsidian::toProtocol())
        countLeftX++;
    totalCountX += countRightX + countLeftX;

    // Count how many aligned obsidian blocks on the Z axis
    while (_dim->getBlock({_pos.x, _pos.y, _pos.z + countRightZ}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x, _pos.y, _pos.z + (countRightZ-1)}) == Blocks::Obsidian::toProtocol())
        countRightZ++;
    while (_dim->getBlock({_pos.x, _pos.y, _pos.z - countLeftZ}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x, _pos.y, _pos.z - (countLeftZ-1)}) == Blocks::Obsidian::toProtocol())
        countLeftZ++;
    totalCountZ += countRightZ + countLeftZ;

    if (totalCountX > totalCountZ) {
        if (countLeftX > countRightX) {
            _direction = PortalDirection::PORTAL_NEG_X;
            return;
        } else {
            _direction = PortalDirection::PORTAL_POS_X;
            return;
        }
    } else {
        if (countLeftZ > countRightZ) {
            _direction = PortalDirection::PORTAL_NEG_Z;
            return;
        } else {
            _direction = PortalDirection::PORTAL_POS_Z;
            return;
        }
    }

    _direction = PortalDirection::PORTAL_WRONG_DIRECTION;
}

void NetherPortal::setSize() {
    int countRight = 1; /**< for the right blocks from block horizontally (set to 1 to take block into account) */
    int countLeft = 1; /**< for the left blocks from block horizontally (set to 1 to take block into account) */
    int totalCountHorizontal = -1; /**< for the total blocks horizontally (set to -1 to address the offset when adding the right & left parts) */
    int totalCountVertical = 1;

    if (_direction == PortalDirection::PORTAL_POS_X || _direction == PortalDirection::PORTAL_NEG_X) {
        while (_dim->getBlock({_pos.x + countRight, _pos.y, _pos.z}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x + (countRight-1), _pos.y, _pos.z}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x + countRight, _pos.y + 1, _pos.z}) == Blocks::Air::toProtocol())
            countRight++;
        while (_dim->getBlock({_pos.x - countLeft, _pos.y, _pos.z}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x - (countLeft-1), _pos.y, _pos.z}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x - countLeft, _pos.y + 1, _pos.z}) == Blocks::Air::toProtocol())
            countLeft++;
        while ((_dim->getBlock({_pos.x-(countLeft-1), _pos.y + totalCountVertical, _pos.z}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x-(countLeft-1), _pos.y + (totalCountVertical-1), _pos.z}) == Blocks::Obsidian::toProtocol())
        || (_dim->getBlock({_pos.x+(countRight+1), _pos.y + totalCountVertical, _pos.z}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x+countRight+1, _pos.y + (totalCountVertical-1), _pos.z}) == Blocks::Obsidian::toProtocol()))
            totalCountVertical++;
    } else if (_direction == PortalDirection::PORTAL_POS_Z || _direction == PortalDirection::PORTAL_NEG_Z) {
        while (_dim->getBlock({_pos.x, _pos.y, _pos.z + countRight}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x, _pos.y, _pos.z + (countRight-1)}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x, _pos.y + 1, _pos.z + countRight}) == Blocks::Air::toProtocol())
            countRight++;
        while (_dim->getBlock({_pos.x, _pos.y, _pos.z - countLeft}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x, _pos.y, _pos.z - (countLeft-1)}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x, _pos.y + 1, _pos.z - countLeft}) == Blocks::Air::toProtocol())
            countLeft++;
        while ((_dim->getBlock({_pos.x, _pos.y + totalCountVertical, _pos.z+(countRight+1)}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x, _pos.y + (totalCountVertical-1), _pos.z+(countRight+1)}) == Blocks::Obsidian::toProtocol())
        || (_dim->getBlock({_pos.x, _pos.y + totalCountVertical, _pos.z-(countLeft-1)}) == Blocks::Obsidian::toProtocol() && _dim->getBlock({_pos.x, _pos.y + (totalCountVertical-1), _pos.z-(countLeft-1)}) == Blocks::Obsidian::toProtocol()))
            totalCountVertical++;
    } else
        _size = {PortalError::PORTAL_BAD_PORTAL, PortalError::PORTAL_WRONG_DIRECTION};

    totalCountHorizontal += countRight + countLeft + PortalBoundary::PORTAL_MIN_WIDTH;
    if (totalCountHorizontal > PortalBoundary::PORTAL_MAX_WIDTH) {
        _size = {PortalError::PORTAL_BAD_PORTAL, PortalError::PORTAL_SIZE_OVERFLOW};
        return;
    }

    totalCountVertical += PortalBoundary::PORTAL_MIN_HEIGHT;
    if (totalCountVertical > PortalBoundary::PORTAL_MAX_HEIGHT) {
        _size = {PortalError::PORTAL_BAD_PORTAL, PortalError::PORTAL_SIZE_OVERFLOW};
        return;
    }

    _size = {totalCountHorizontal, totalCountVertical};
}

void NetherPortal::openPortal() {
    std::vector<std::pair<Position, BlockId>> blocksArray;
    auto block = _dim->getBlock(_pos);

    for (int y = 0; y < _size.z - 1; y++) {
        for (int x = 0; x < _size.x - 1; x++) {
            switch (_direction) {
                case PortalDirection::PORTAL_POS_X:
                    block = _dim->getBlock({_pos.x - 1 + x, _pos.y + y, _pos.z});
                    if (block == Blocks::Air::toProtocol() || block == Blocks::Fire::toProtocol(Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE, Blocks::Fire::Properties::South::FALSE, Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE))
                        blocksArray.push_back({{_pos.x - 1 + x, _pos.y + y, _pos.z}, Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::X)});
                    break;
                case PortalDirection::PORTAL_NEG_X:
                    block = _dim->getBlock({_pos.x - 2 + x, _pos.y + y, _pos.z});
                    if (block == Blocks::Air::toProtocol() || block == Blocks::Fire::toProtocol(Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE, Blocks::Fire::Properties::South::FALSE, Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE))
                        blocksArray.push_back({{_pos.x - 2 + x, _pos.y + y, _pos.z}, Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::X)});
                    break;
                case PortalDirection::PORTAL_POS_Z:
                    block = _dim->getBlock({_pos.x, _pos.y + y, _pos.z - 1 + x});
                    if (block == Blocks::Air::toProtocol() || block == Blocks::Fire::toProtocol(Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE, Blocks::Fire::Properties::South::FALSE, Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE))
                        blocksArray.push_back({{_pos.x, _pos.y + y, _pos.z - 1 + x}, Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::Z)});
                    break;
                case PortalDirection::PORTAL_NEG_Z:
                block = _dim->getBlock({_pos.x, _pos.y + y, _pos.z - 2 + x});
                    if (block == Blocks::Air::toProtocol() || block == Blocks::Fire::toProtocol(Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE, Blocks::Fire::Properties::South::FALSE, Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE))
                        blocksArray.push_back({{_pos.x, _pos.y + y, _pos.z - 2 + x}, Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::Z)});
                    break;
                default:
                    LDEBUG("Portal error code: PORTAL_NONE ({})", PortalError::PORTAL_NONE);
                    break;
            }
        }
    }
    for (auto [position, id] : blocksArray) {
        _dim->updateBlock(position, id);
        for (auto player : _dim->getPlayers()) {
            player->sendBlockUpdate({_pos, _dim->getBlock(_pos)});
            player->sendBlockUpdate({position, id});
            // player->sendUpdateSectionBlock({position,chunk, true, blocksArray});
        }
    }
}
