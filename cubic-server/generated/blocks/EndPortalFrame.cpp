#include "EndPortalFrame.hpp"
#include <stdexcept>

namespace Blocks {
    namespace EndPortalFrame {
        BlockId toProtocol(Properties::Eye eye, Properties::Facing facing) {
            switch (eye) {
            case Properties::Eye::TRUE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 5737;
                case Properties::Facing::SOUTH:
                    return 5738;
                case Properties::Facing::WEST:
                    return 5739;
                case Properties::Facing::EAST:
                    return 5740;
                }
            case Properties::Eye::FALSE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 5741;
                case Properties::Facing::SOUTH:
                    return 5742;
                case Properties::Facing::WEST:
                    return 5743;
                case Properties::Facing::EAST:
                    return 5744;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Eye eye;
            Properties::Facing facing;
            for (auto prop : properties) {
                if (prop.first == "eye") {
                    if (prop.second == "true") {
                        eye = Properties::Eye::TRUE;
                    } else if (prop.second == "false") {
                        eye = Properties::Eye::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"eye\" value");
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
            return toProtocol(eye, facing);
        }
    }

}
