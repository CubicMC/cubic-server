#include "Barrel.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Barrel {
        BlockId toProtocol(Properties::Facing facing, Properties::Open open) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (open) {
                case Properties::Open::TRUE:
                    return 15996;
                case Properties::Open::FALSE:
                    return 15997;
                }
            case Properties::Facing::EAST:
                switch (open) {
                case Properties::Open::TRUE:
                    return 15998;
                case Properties::Open::FALSE:
                    return 15999;
                }
            case Properties::Facing::SOUTH:
                switch (open) {
                case Properties::Open::TRUE:
                    return 16000;
                case Properties::Open::FALSE:
                    return 16001;
                }
            case Properties::Facing::WEST:
                switch (open) {
                case Properties::Open::TRUE:
                    return 16002;
                case Properties::Open::FALSE:
                    return 16003;
                }
            case Properties::Facing::UP:
                switch (open) {
                case Properties::Open::TRUE:
                    return 16004;
                case Properties::Open::FALSE:
                    return 16005;
                }
            case Properties::Facing::DOWN:
                switch (open) {
                case Properties::Open::TRUE:
                    return 16006;
                case Properties::Open::FALSE:
                    return 16007;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Facing facing;
            Properties::Open open;
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
                } else if (prop.first == "open") {
                    if (prop.second == "true") {
                        open = Properties::Open::TRUE;
                    } else if (prop.second == "false") {
                        open = Properties::Open::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"open\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(facing, open);
        }
    }

}
