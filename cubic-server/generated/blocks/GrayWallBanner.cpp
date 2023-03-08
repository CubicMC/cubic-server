#include "GrayWallBanner.hpp"
#include <stdexcept>

namespace Blocks {
    namespace GrayWallBanner {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 8922;
            case Properties::Facing::SOUTH:
                return 8923;
            case Properties::Facing::WEST:
                return 8924;
            case Properties::Facing::EAST:
                return 8925;
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
                    } else if (prop.second == "south") {
                        facing = Properties::Facing::SOUTH;
                    } else if (prop.second == "west") {
                        facing = Properties::Facing::WEST;
                    } else if (prop.second == "east") {
                        facing = Properties::Facing::EAST;
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