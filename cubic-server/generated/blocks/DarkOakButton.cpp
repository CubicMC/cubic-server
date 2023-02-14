#include "DarkOakButton.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DarkOakButton {
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
            switch (face) {
            case Properties::Face::FLOOR:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7059;
                    case Properties::Powered::FALSE:
                        return 7060;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7061;
                    case Properties::Powered::FALSE:
                        return 7062;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7063;
                    case Properties::Powered::FALSE:
                        return 7064;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7065;
                    case Properties::Powered::FALSE:
                        return 7066;
                    }
                }
            case Properties::Face::WALL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7067;
                    case Properties::Powered::FALSE:
                        return 7068;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7069;
                    case Properties::Powered::FALSE:
                        return 7070;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7071;
                    case Properties::Powered::FALSE:
                        return 7072;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7073;
                    case Properties::Powered::FALSE:
                        return 7074;
                    }
                }
            case Properties::Face::CEILING:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7075;
                    case Properties::Powered::FALSE:
                        return 7076;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7077;
                    case Properties::Powered::FALSE:
                        return 7078;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7079;
                    case Properties::Powered::FALSE:
                        return 7080;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7081;
                    case Properties::Powered::FALSE:
                        return 7082;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Face face;
            Properties::Facing facing;
            Properties::Powered powered;
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
                } else if (prop.first == "powered") {
                    if (prop.second == "true") {
                        powered = Properties::Powered::TRUE;
                    } else if (prop.second == "false") {
                        powered = Properties::Powered::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"powered\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(face, facing, powered);
        }
    }

}
