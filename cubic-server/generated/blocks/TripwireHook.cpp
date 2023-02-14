#include "TripwireHook.hpp"
#include <stdexcept>

namespace Blocks {
    namespace TripwireHook {
        BlockId toProtocol(Properties::Attached attached, Properties::Facing facing, Properties::Powered powered) {
            switch (attached) {
            case Properties::Attached::TRUE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 5851;
                    case Properties::Powered::FALSE:
                        return 5852;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 5853;
                    case Properties::Powered::FALSE:
                        return 5854;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 5855;
                    case Properties::Powered::FALSE:
                        return 5856;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 5857;
                    case Properties::Powered::FALSE:
                        return 5858;
                    }
                }
            case Properties::Attached::FALSE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 5859;
                    case Properties::Powered::FALSE:
                        return 5860;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 5861;
                    case Properties::Powered::FALSE:
                        return 5862;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 5863;
                    case Properties::Powered::FALSE:
                        return 5864;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 5865;
                    case Properties::Powered::FALSE:
                        return 5866;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Attached attached;
            Properties::Facing facing;
            Properties::Powered powered;
            for (auto prop : properties) {
                if (prop.first == "attached") {
                    if (prop.second == "true") {
                        attached = Properties::Attached::TRUE;
                    } else if (prop.second == "false") {
                        attached = Properties::Attached::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"attached\" value");
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
            return toProtocol(attached, facing, powered);
        }
    }

}
