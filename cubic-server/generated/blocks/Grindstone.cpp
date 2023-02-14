#include "Grindstone.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Grindstone {
        BlockId toProtocol(Properties::Face face, Properties::Facing facing) {
            switch (face) {
            case Properties::Face::FLOOR:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 16026;
                case Properties::Facing::SOUTH:
                    return 16027;
                case Properties::Facing::WEST:
                    return 16028;
                case Properties::Facing::EAST:
                    return 16029;
                }
            case Properties::Face::WALL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 16030;
                case Properties::Facing::SOUTH:
                    return 16031;
                case Properties::Facing::WEST:
                    return 16032;
                case Properties::Facing::EAST:
                    return 16033;
                }
            case Properties::Face::CEILING:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 16034;
                case Properties::Facing::SOUTH:
                    return 16035;
                case Properties::Facing::WEST:
                    return 16036;
                case Properties::Facing::EAST:
                    return 16037;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Face face;
            Properties::Facing facing;
            for (auto prop : properties) {
                if (prop.first == "face") {
                    if (prop.second == "floor") {
                        face = Properties::Face::FLOOR;
                    } else if (prop.second == "wall") {
                        face = Properties::Face::WALL;
                    } else if (prop.second == "ceiling") {
                        face = Properties::Face::CEILING;
                    } else {
                        throw std::runtime_error("Invalid property \"face\" value");
                    }
                } else if (prop.first == "facing") {
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
            return toProtocol(face, facing);
        }
    }

}
