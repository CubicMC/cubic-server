#include "Smoker.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Smoker {
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 16008;
                case Properties::Lit::FALSE:
                    return 16009;
                }
            case Properties::Facing::SOUTH:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 16010;
                case Properties::Lit::FALSE:
                    return 16011;
                }
            case Properties::Facing::WEST:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 16012;
                case Properties::Lit::FALSE:
                    return 16013;
                }
            case Properties::Facing::EAST:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 16014;
                case Properties::Lit::FALSE:
                    return 16015;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Facing facing;
            Properties::Lit lit;
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
                } else if (prop.first == "lit") {
                    if (prop.second == "true") {
                        lit = Properties::Lit::TRUE;
                    } else if (prop.second == "false") {
                        lit = Properties::Lit::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"lit\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(facing, lit);
        }
    }

}
