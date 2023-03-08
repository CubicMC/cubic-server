#include "YellowShulkerBox.hpp"
#include <stdexcept>

namespace Blocks {
    namespace YellowShulkerBox {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 10183;
            case Properties::Facing::EAST:
                return 10184;
            case Properties::Facing::SOUTH:
                return 10185;
            case Properties::Facing::WEST:
                return 10186;
            case Properties::Facing::UP:
                return 10187;
            case Properties::Facing::DOWN:
                return 10188;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Facing facing;
            for (auto prop : properties) {
                if (prop.first == "facing") {
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
            return toProtocol(facing);
        }
    }

}