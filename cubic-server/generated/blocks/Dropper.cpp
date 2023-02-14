#include "Dropper.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Dropper {
        BlockId toProtocol(Properties::Facing facing, Properties::Triggered triggered) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 7464;
                case Properties::Triggered::FALSE:
                    return 7465;
                }
            case Properties::Facing::EAST:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 7466;
                case Properties::Triggered::FALSE:
                    return 7467;
                }
            case Properties::Facing::SOUTH:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 7468;
                case Properties::Triggered::FALSE:
                    return 7469;
                }
            case Properties::Facing::WEST:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 7470;
                case Properties::Triggered::FALSE:
                    return 7471;
                }
            case Properties::Facing::UP:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 7472;
                case Properties::Triggered::FALSE:
                    return 7473;
                }
            case Properties::Facing::DOWN:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 7474;
                case Properties::Triggered::FALSE:
                    return 7475;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Facing facing;
            Properties::Triggered triggered;
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
                } else if (prop.first == "triggered") {
                    if (prop.second == "true") {
                        triggered = Properties::Triggered::TRUE;
                    } else if (prop.second == "false") {
                        triggered = Properties::Triggered::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"triggered\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(facing, triggered);
        }
    }

}
