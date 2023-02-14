#include "CommandBlock.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CommandBlock {
        BlockId toProtocol(Properties::Conditional conditional, Properties::Facing facing) {
            switch (conditional) {
            case Properties::Conditional::TRUE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 6236;
                case Properties::Facing::EAST:
                    return 6237;
                case Properties::Facing::SOUTH:
                    return 6238;
                case Properties::Facing::WEST:
                    return 6239;
                case Properties::Facing::UP:
                    return 6240;
                case Properties::Facing::DOWN:
                    return 6241;
                }
            case Properties::Conditional::FALSE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 6242;
                case Properties::Facing::EAST:
                    return 6243;
                case Properties::Facing::SOUTH:
                    return 6244;
                case Properties::Facing::WEST:
                    return 6245;
                case Properties::Facing::UP:
                    return 6246;
                case Properties::Facing::DOWN:
                    return 6247;
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
