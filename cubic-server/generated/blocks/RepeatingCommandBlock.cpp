#include "RepeatingCommandBlock.hpp"
#include <stdexcept>

namespace Blocks {
    namespace RepeatingCommandBlock {
        BlockId toProtocol(Properties::Conditional conditional, Properties::Facing facing) {
            switch (conditional) {
            case Properties::Conditional::TRUE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 10106;
                case Properties::Facing::EAST:
                    return 10107;
                case Properties::Facing::SOUTH:
                    return 10108;
                case Properties::Facing::WEST:
                    return 10109;
                case Properties::Facing::UP:
                    return 10110;
                case Properties::Facing::DOWN:
                    return 10111;
                }
            case Properties::Conditional::FALSE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 10112;
                case Properties::Facing::EAST:
                    return 10113;
                case Properties::Facing::SOUTH:
                    return 10114;
                case Properties::Facing::WEST:
                    return 10115;
                case Properties::Facing::UP:
                    return 10116;
                case Properties::Facing::DOWN:
                    return 10117;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Conditional conditional;
            Properties::Facing facing;
            for (auto prop : properties) {
                if (prop.first == "conditional") {
                    if (prop.second == "true") {
                        conditional = Properties::Conditional::TRUE;
                    } else if (prop.second == "false") {
                        conditional = Properties::Conditional::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"conditional\" value");
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
            return toProtocol(conditional, facing);
        }
    }

}
