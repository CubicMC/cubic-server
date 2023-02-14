#include "StickyPiston.hpp"
#include <stdexcept>

namespace Blocks {
    namespace StickyPiston {
        BlockId toProtocol(Properties::Extended extended, Properties::Facing facing) {
            switch (extended) {
            case Properties::Extended::TRUE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 1583;
                case Properties::Facing::EAST:
                    return 1584;
                case Properties::Facing::SOUTH:
                    return 1585;
                case Properties::Facing::WEST:
                    return 1586;
                case Properties::Facing::UP:
                    return 1587;
                case Properties::Facing::DOWN:
                    return 1588;
                }
            case Properties::Extended::FALSE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 1589;
                case Properties::Facing::EAST:
                    return 1590;
                case Properties::Facing::SOUTH:
                    return 1591;
                case Properties::Facing::WEST:
                    return 1592;
                case Properties::Facing::UP:
                    return 1593;
                case Properties::Facing::DOWN:
                    return 1594;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Extended extended;
            Properties::Facing facing;
            for (auto prop : properties) {
                if (prop.first == "extended") {
                    if (prop.second == "true") {
                        extended = Properties::Extended::TRUE;
                    } else if (prop.second == "false") {
                        extended = Properties::Extended::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"extended\" value");
                    }
                } else if (prop.first == "facing") {
                    if (prop.second == "north") {
                        facing = Properties::Facing::NORTH;
                    } else if (prop.second == "east") {
                        facing = Properties::Facing::EAST;
                    } else if (prop.second == "south") {
                        facing = Properties::Facing::SOUTH;
                    } else if (prop.second == "west") {
                        facing = Properties::Facing::WEST;
                    } else if (prop.second == "up") {
                        facing = Properties::Facing::UP;
                    } else if (prop.second == "down") {
                        facing = Properties::Facing::DOWN;
                    } else {
                        throw std::runtime_error("Invalid property \"facing\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(extended, facing);
        }
    }

}
