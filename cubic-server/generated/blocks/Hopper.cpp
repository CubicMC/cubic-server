#include "Hopper.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Hopper {
        BlockId toProtocol(Properties::Enabled enabled, Properties::Facing facing) {
            switch (enabled) {
            case Properties::Enabled::TRUE:
                switch (facing) {
                case Properties::Facing::DOWN:
                    return 7345;
                case Properties::Facing::NORTH:
                    return 7346;
                case Properties::Facing::SOUTH:
                    return 7347;
                case Properties::Facing::WEST:
                    return 7348;
                case Properties::Facing::EAST:
                    return 7349;
                }
            case Properties::Enabled::FALSE:
                switch (facing) {
                case Properties::Facing::DOWN:
                    return 7350;
                case Properties::Facing::NORTH:
                    return 7351;
                case Properties::Facing::SOUTH:
                    return 7352;
                case Properties::Facing::WEST:
                    return 7353;
                case Properties::Facing::EAST:
                    return 7354;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Enabled enabled;
            Properties::Facing facing;
            for (auto prop : properties) {
                if (prop.first == "enabled") {
                    if (prop.second == "true") {
                        enabled = Properties::Enabled::TRUE;
                    } else if (prop.second == "false") {
                        enabled = Properties::Enabled::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"enabled\" value");
                    }
                } else if (prop.first == "facing") {
                    if (prop.second == "down") {
                        facing = Properties::Facing::DOWN;
                    } else if (prop.second == "north") {
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
            return toProtocol(enabled, facing);
        }
    }

}
