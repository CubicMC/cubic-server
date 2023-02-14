#include "Observer.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Observer {
        BlockId toProtocol(Properties::Facing facing, Properties::Powered powered) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10141;
                case Properties::Powered::FALSE:
                    return 10142;
                }
            case Properties::Facing::EAST:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10143;
                case Properties::Powered::FALSE:
                    return 10144;
                }
            case Properties::Facing::SOUTH:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10145;
                case Properties::Powered::FALSE:
                    return 10146;
                }
            case Properties::Facing::WEST:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10147;
                case Properties::Powered::FALSE:
                    return 10148;
                }
            case Properties::Facing::UP:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10149;
                case Properties::Powered::FALSE:
                    return 10150;
                }
            case Properties::Facing::DOWN:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10151;
                case Properties::Powered::FALSE:
                    return 10152;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Facing facing;
            Properties::Powered powered;
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
            return toProtocol(facing, powered);
        }
    }

}
