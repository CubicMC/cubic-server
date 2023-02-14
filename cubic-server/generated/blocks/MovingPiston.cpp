#include "MovingPiston.hpp"
#include <stdexcept>

namespace Blocks {
    namespace MovingPiston {
        BlockId toProtocol(Properties::Type type, Properties::Facing facing) {
            switch (type) {
            case Properties::Type::NORMAL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 1654;
                case Properties::Facing::EAST:
                    return 1656;
                case Properties::Facing::SOUTH:
                    return 1658;
                case Properties::Facing::WEST:
                    return 1660;
                case Properties::Facing::UP:
                    return 1662;
                case Properties::Facing::DOWN:
                    return 1664;
                }
            case Properties::Type::STICKY:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 1655;
                case Properties::Facing::EAST:
                    return 1657;
                case Properties::Facing::SOUTH:
                    return 1659;
                case Properties::Facing::WEST:
                    return 1661;
                case Properties::Facing::UP:
                    return 1663;
                case Properties::Facing::DOWN:
                    return 1665;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Type type;
            Properties::Facing facing;
            for (auto prop : properties) {
                if (prop.first == "type") {
                    if (prop.second == "normal") {
                        type = Properties::Type::NORMAL;
                    } else if (prop.second == "sticky") {
                        type = Properties::Type::STICKY;
                    } else {
                        throw std::runtime_error("Invalid property \"type\" value");
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
            return toProtocol(type, facing);
        }
    }

}
