#include "StoneButton.hpp"
#include <stdexcept>

namespace Blocks {
    namespace StoneButton {
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
            switch (face) {
            case Properties::Face::FLOOR:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4206;
                    case Properties::Powered::FALSE:
                        return 4207;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4208;
                    case Properties::Powered::FALSE:
                        return 4209;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4210;
                    case Properties::Powered::FALSE:
                        return 4211;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4212;
                    case Properties::Powered::FALSE:
                        return 4213;
                    }
                }
            case Properties::Face::WALL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4214;
                    case Properties::Powered::FALSE:
                        return 4215;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4216;
                    case Properties::Powered::FALSE:
                        return 4217;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4218;
                    case Properties::Powered::FALSE:
                        return 4219;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4220;
                    case Properties::Powered::FALSE:
                        return 4221;
                    }
                }
            case Properties::Face::CEILING:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4222;
                    case Properties::Powered::FALSE:
                        return 4223;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4224;
                    case Properties::Powered::FALSE:
                        return 4225;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4226;
                    case Properties::Powered::FALSE:
                        return 4227;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4228;
                    case Properties::Powered::FALSE:
                        return 4229;
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
