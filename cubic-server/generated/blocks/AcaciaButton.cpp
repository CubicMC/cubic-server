#include "AcaciaButton.hpp"
#include <stdexcept>

namespace Blocks {
    namespace AcaciaButton {
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
            switch (face) {
            case Properties::Face::FLOOR:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7035;
                    case Properties::Powered::FALSE:
                        return 7036;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7037;
                    case Properties::Powered::FALSE:
                        return 7038;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7039;
                    case Properties::Powered::FALSE:
                        return 7040;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7041;
                    case Properties::Powered::FALSE:
                        return 7042;
                    }
                }
            case Properties::Face::WALL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7043;
                    case Properties::Powered::FALSE:
                        return 7044;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7045;
                    case Properties::Powered::FALSE:
                        return 7046;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7047;
                    case Properties::Powered::FALSE:
                        return 7048;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7049;
                    case Properties::Powered::FALSE:
                        return 7050;
                    }
                }
            case Properties::Face::CEILING:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7051;
                    case Properties::Powered::FALSE:
                        return 7052;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7053;
                    case Properties::Powered::FALSE:
                        return 7054;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7055;
                    case Properties::Powered::FALSE:
                        return 7056;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7057;
                    case Properties::Powered::FALSE:
                        return 7058;
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
