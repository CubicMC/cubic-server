#include "NetherPortal.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "logging/logging.hpp"
#include "types.hpp"
#include <utility>

void NetherPortal::setIgnitedBlock()
{
    std::vector<BlockId> blocksArray;

    // blockArray[0] & blockArray[1] - {-1;0;0}, {1;0;0} - LEFT or RIGHT
    for (int x = -1; x <= 1; x++) {
        if (x != 0)
            continue;
        auto lateralBlock = {_pos.x + x, _pos.y, _pos.z};
        blocksArray.push_back(_dim->getBlock(lateralBlock));
    }
    // blockArray[2] & blockArray[3] - {0;-1;0}, {0;1;0} - TOP or BOTTOM
    for (int y = -1; y <= 1; y++) {
        if (y != 0)
            continue;
        auto lateralBlock = {_pos.x, _pos.y + y, _pos.z};
        blocksArray.push_back(_dim->getBlock(lateralBlock));
    }
    // blockArray[4] & blockArray[5] - {0;0;-1}, {0;0;1} - LEFT or RIGHT
    for (int z = -1; z <= 1; z++) {
        if (z != 0)
            continue;
        auto lateralBlock = {_pos.x, _pos.y, _pos.z + z};
        blocksArray.push_back(_dim->getBlock(lateralBlock));
    }

    if (blocksArray[4] == Blocks::Obsidian::toProtocol() && blocksArray[5] != Blocks::Obsidian::toProtocol()) {
        if ((blocksArray[0] == Blocks::Obsidian::toProtocol() && blocksArray[1] != Blocks::Obsidian::toProtocol()) ||
            (blocksArray[2] == Blocks::Obsidian::toProtocol() && blocksArray[3] != Blocks::Obsidian::toProtocol())) {
            _ignitedBlock = PortalIgnition::PORTAL_TOP_LEFT_CORNER;
            return;
        } else if ((blocksArray[1] == Blocks::Obsidian::toProtocol() && blocksArray[0] != Blocks::Obsidian::toProtocol()) || (blocksArray[3] == Blocks::Obsidian::toProtocol() &&
                    blocksArray[2] != Blocks::Obsidian::toProtocol())) {
            _ignitedBlock = PortalIgnition::PORTAL_TOP_RIGHT_CORNER;
            return;
        } else {
            _ignitedBlock = PortalIgnition::PORTAL_TOP_CENTER;
            return;
        }
    } else if (blocksArray[4] != Blocks::Obsidian::toProtocol() && blocksArray[5] == Blocks::Obsidian::toProtocol()) {
        if ((blocksArray[0] == Blocks::Obsidian::toProtocol() && blocksArray[1] != Blocks::Obsidian::toProtocol()) ||
            (blocksArray[2] == Blocks::Obsidian::toProtocol() && blocksArray[3] != Blocks::Obsidian::toProtocol())) {
            _ignitedBlock = PortalIgnition::PORTAL_BOTTOM_LEFT_CORNER;
            return;
        } else if ((blocksArray[1] == Blocks::Obsidian::toProtocol() && blocksArray[0] != Blocks::Obsidian::toProtocol()) || (blocksArray[3] == Blocks::Obsidian::toProtocol() &&
                    blocksArray[2] != Blocks::Obsidian::toProtocol())) {
            _ignitedBlock = PortalIgnition::PORTAL_BOTTOM_RIGHT_CORNER;
            return;
        } else {
            _ignitedBlock = PortalIgnition::PORTAL_BOTTOM_CENTER;
            return;
        }
    } else {
        if ((blocksArray[0] == Blocks::Obsidian::toProtocol() && blocksArray[1] != Blocks::Obsidian::toProtocol()) ||
            (blocksArray[2] == Blocks::Obsidian::toProtocol() && blocksArray[3] != Blocks::Obsidian::toProtocol())) {
            _ignitedBlock = PortalIgnition::PORTAL_LEFT_CENTER;
            return;
        } else if ((blocksArray[1] == Blocks::Obsidian::toProtocol() && blocksArray[0] != Blocks::Obsidian::toProtocol()) || (blocksArray[3] == Blocks::Obsidian::toProtocol() &&
                    blocksArray[2] != Blocks::Obsidian::toProtocol())) {
            _ignitedBlock = PortalIgnition::PORTAL_RIGHT_CENTER;
            return;
        } else {
            _ignitedBlock = PortalIgnition::PORTAL_NONE;
            return;
        }
    }

    _ignitedBlock = PortalIgnition::PORTAL_NONE;
}

void NetherPortal::setBottomLeftCorner()
{
    if (_ignitedBlock == PortalIgnition::PORTAL_BOTTOM_LEFT_CORNER) {
        _bottomLeftCorner = {_pos.x, _pos.y - 1, _pos.z};
        return;
    } else if (_ignitedBlock == PortalIgnition::PORTAL_NONE) {
        return;
    } else if (_ignitedBlock == PortalIgnition::PORTAL_TOP_LEFT_CORNER || _ignitedBlock == PortalIgnition::PORTAL_LEFT_CENTER) {
        for (int count = 1; count < PortalBoundary::PORTAL_MAX_HEIGHT - PortalBoundary::PORTAL_MIN_HEIGHT - PortalBoundary::PORTAL_NO_CORNERS; count++) {
            if (_dim->getBlock({_pos.x, _pos.y - count, _pos.z}) == Blocks::Obsidian::toProtocol()) {
                _bottomLeftCorner = {_pos.x, _pos.y - count, _pos.z};
                return;
            }
        }
    } else if (_ignitedBlock == PortalIgnition::PORTAL_BOTTOM_RIGHT_CORNER || _ignitedBlock == PortalIgnition::PORTAL_BOTTOM_CENTER) {
        for (int count = 1; count < PortalBoundary::PORTAL_MAX_WIDTH - PortalBoundary::PORTAL_MIN_WIDTH - PortalBoundary::PORTAL_NO_CORNERS; count++) {
            if (_dim->getBlock({_pos.x - count, _pos.y, _pos.z}) == Blocks::Obsidian::toProtocol() && count > 1) {
                _bottomLeftCorner = {_pos.x - count, _pos.y - 1, _pos.z};
                _direction = PortalDirection::PORTAL_X_AXIS;
                return;
            } else if (_dim->getBlock({_pos.x, _pos.y, _pos.z - count}) == Blocks::Obsidian::toProtocol() && count > 1) {
                _bottomLeftCorner = {_pos.x, _pos.y - 1, _pos.z - count};
                _direction = PortalDirection::PORTAL_Z_AXIS;
                return;
            }
        }
    } else {
        for (int countY = 1; countY < PortalBoundary::PORTAL_MAX_HEIGHT - PortalBoundary::PORTAL_MIN_HEIGHT - PortalBoundary::PORTAL_NO_CORNERS; countY++) {
            for (int count = 1; count < PortalBoundary::PORTAL_MAX_WIDTH - PortalBoundary::PORTAL_MIN_WIDTH - PortalBoundary::PORTAL_NO_CORNERS; count++) {
                if (_dim->getBlock({_pos.x, _pos.y - countY, _pos.z}) == Blocks::Obsidian::toProtocol() &&
                    _dim->getBlock({_pos.x - count, _pos.y, _pos.z}) == Blocks::Obsidian::toProtocol() && count > 1) {
                    _bottomLeftCorner = {_pos.x - count, _pos.y - countY, _pos.z};
                    _direction = PortalDirection::PORTAL_X_AXIS;
                    return;
                } else if (_dim->getBlock({_pos.x, _pos.y - countY, _pos.z}) == Blocks::Obsidian::toProtocol() &&
                           _dim->getBlock({_pos.x, _pos.y, _pos.z - count}) == Blocks::Obsidian::toProtocol() && count > 1) {
                    _bottomLeftCorner = {_pos.x, _pos.y - countY, _pos.z - count};
                    _direction = PortalDirection::PORTAL_Z_AXIS;
                    return;
                }
            }
        }
    }
    _bottomLeftCorner = _pos;
    _direction = PortalDirection::PORTAL_WRONG_DIRECTION;
}

void NetherPortal::setDirection()
{
    if (_ignitedBlock == PortalIgnition::PORTAL_NONE || _direction == PortalDirection::PORTAL_WRONG_DIRECTION || _direction == PortalDirection::PORTAL_X_AXIS ||
        _direction == PortalDirection::PORTAL_Z_AXIS)
        return;

    if (_dim->getBlock({_bottomLeftCorner.x - 1, _bottomLeftCorner.y + 1, _bottomLeftCorner.z}) == Blocks::Obsidian::toProtocol() &&
        _dim->getBlock({_bottomLeftCorner.x + 1, _bottomLeftCorner.y, _bottomLeftCorner.z}) == Blocks::Obsidian::toProtocol() &&
        (_dim->getBlock({_bottomLeftCorner.x + 2, _bottomLeftCorner.y, _bottomLeftCorner.z}) == Blocks::Obsidian::toProtocol() ||
         _dim->getBlock({_bottomLeftCorner.x + 2, _bottomLeftCorner.y + 1, _bottomLeftCorner.z}) == Blocks::Obsidian::toProtocol())) {
        _direction = PortalDirection::PORTAL_X_AXIS;
        return;
    } else if (_dim->getBlock({_bottomLeftCorner.x, _bottomLeftCorner.y + 1, _bottomLeftCorner.z - 1}) == Blocks::Obsidian::toProtocol() &&
               _dim->getBlock({_bottomLeftCorner.x, _bottomLeftCorner.y, _bottomLeftCorner.z + 1}) == Blocks::Obsidian::toProtocol() &&
               (_dim->getBlock({_bottomLeftCorner.x, _bottomLeftCorner.y, _bottomLeftCorner.z + 2}) == Blocks::Obsidian::toProtocol() ||
                _dim->getBlock({_bottomLeftCorner.x, _bottomLeftCorner.y + 1, _bottomLeftCorner.z + 2}) == Blocks::Obsidian::toProtocol())) {
        _direction = PortalDirection::PORTAL_Z_AXIS;
        return;
    }

    _direction = PortalDirection::PORTAL_WRONG_DIRECTION;
}

void NetherPortal::setSize()
{
    if (_ignitedBlock == PortalIgnition::PORTAL_NONE)
        return;

    if (_direction == PortalDirection::PORTAL_X_AXIS) {
        for (int countWidth = 1; countWidth < (PortalBoundary::PORTAL_MAX_WIDTH - PortalBoundary::PORTAL_NO_CORNERS); countWidth++) {
            if (_dim->getBlock({_bottomLeftCorner.x + (countWidth - 1), _bottomLeftCorner.y, _bottomLeftCorner.z}) == Blocks::Obsidian::toProtocol() &&
                _dim->getBlock({_bottomLeftCorner.x + countWidth, _bottomLeftCorner.y + 1, _bottomLeftCorner.z}) == Blocks::Obsidian::toProtocol() &&
                countWidth >= (PortalBoundary::PORTAL_MIN_WIDTH - PortalBoundary::PORTAL_NO_CORNERS)) {
                _size.x = countWidth - 1;
            }
        }
        for (int countHeight = 1; countHeight < (PortalBoundary::PORTAL_MAX_HEIGHT - PortalBoundary::PORTAL_NO_CORNERS); countHeight++) {
            if (_dim->getBlock({_bottomLeftCorner.x - 1, _bottomLeftCorner.y + (countHeight - 1), _bottomLeftCorner.z}) == Blocks::Obsidian::toProtocol() &&
                _dim->getBlock({_bottomLeftCorner.x, _bottomLeftCorner.y + countHeight, _bottomLeftCorner.z}) == Blocks::Obsidian::toProtocol() &&
                countHeight > (PortalBoundary::PORTAL_MIN_HEIGHT - PortalBoundary::PORTAL_NO_CORNERS)) {
                _size.z = countHeight - 1;
            }
        }
    } else if (_direction == PortalDirection::PORTAL_Z_AXIS) {
        for (int countWidth = 1; countWidth < (PortalBoundary::PORTAL_MAX_WIDTH - PortalBoundary::PORTAL_NO_CORNERS); countWidth++) {
            if (_dim->getBlock({_bottomLeftCorner.x, _bottomLeftCorner.y, _bottomLeftCorner.z + (countWidth - 1)}) == Blocks::Obsidian::toProtocol() &&
                _dim->getBlock({_bottomLeftCorner.x, _bottomLeftCorner.y + 1, _bottomLeftCorner.z + countWidth}) == Blocks::Obsidian::toProtocol() &&
                countWidth >= (PortalBoundary::PORTAL_MIN_WIDTH - PortalBoundary::PORTAL_NO_CORNERS)) {
                _size.x = countWidth - 1;
            }
        }
        for (int countHeight = 1; countHeight < (PortalBoundary::PORTAL_MAX_HEIGHT - PortalBoundary::PORTAL_NO_CORNERS); countHeight++) {
            if (_dim->getBlock({_bottomLeftCorner.x, _bottomLeftCorner.y + (countHeight - 1), _bottomLeftCorner.z - 1}) == Blocks::Obsidian::toProtocol() &&
                _dim->getBlock({_bottomLeftCorner.x, _bottomLeftCorner.y + countHeight, _bottomLeftCorner.z}) == Blocks::Obsidian::toProtocol() &&
                countHeight > (PortalBoundary::PORTAL_MIN_HEIGHT - PortalBoundary::PORTAL_NO_CORNERS)) {
                _size.z = countHeight - 1;
            }
        }
    } else
        _size = {PortalError::PORTAL_BAD_PORTAL, _direction};

    _size = {PortalError::PORTAL_BAD_PORTAL, PortalError::PORTAL_WRONG_SIZE};
}

void NetherPortal::openPortal()
{
    std::vector<std::pair<Position, BlockId>> blocksArray;

    if (_ignitedBlock == PortalIgnition::PORTAL_NONE)
        return;

    if (_direction == PortalDirection::PORTAL_X_AXIS) {
        for (int x = 0; x <= _size.x; x++) {
            for (int y = 1; y <= _size.z; y++) {
                auto position = {_bottomLeftCorner.x + x, _bottomLeftCorner.y + y, _bottomLeftCorner.z};
                auto blockId = _dim->getBlock(position);
                blocksArray.push_back({position, blockId});
            }
        }
        for (auto [position, id] : blocksArray) {
            if (id != Blocks::Air::toProtocol() &&
                id !=
                    Blocks::Fire::toProtocol(
                        Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE, Blocks::Fire::Properties::South::FALSE,
                        Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE
                    )) {
                LDEBUG("Obstruction within the frame at position {}: PORTAL_BAD_PORTAL ({})", position, PortalError::PORTAL_BAD_PORTAL);
                return;
            } else {
                _dim->updateBlock(position, Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::X));
                for (auto player : _dim->getPlayers()) {
                    player->sendBlockUpdate({position, Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::X});
                }
            }
        }
    } else if (_direction == PortalDirection::PORTAL_Z_AXIS) {
        for (int z = 0; z <= _size.x; z++) {
            for (int y = 1; y <= _size.z; y++) {
                auto position = {_bottomLeftCorner.x, _bottomLeftCorner.y + y, _bottomLeftCorner.z + z};
                auto blockId = _dim->getBlock(position);
                blocksArray.push_back({position, blockId});
            }
        }
        for (auto [position, id] : blocksArray) {
            if (id != Blocks::Air::toProtocol() &&
                id !=
                    Blocks::Fire::toProtocol(
                        Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE, Blocks::Fire::Properties::South::FALSE,
                        Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE
                    )) {
                LDEBUG("Obstruction within the frame at position {}: PORTAL_BAD_PORTAL ({})", position, PortalError::PORTAL_BAD_PORTAL);
                return;
            } else {
                _dim->updateBlock(position, Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::Z));
                for (auto player : _dim->getPlayers()) {
                    player->sendBlockUpdate({position, Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::Z});
                }
            }
        }
    } else {
        LDEBUG("No portal at pos {}: PORTAL_NONE ({})", _pos, PortalError::PORTAL_NONE);
        return;
    }
}
