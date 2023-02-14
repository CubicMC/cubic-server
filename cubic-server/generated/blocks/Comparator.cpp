#include "Comparator.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Comparator {
        BlockId toProtocol(Properties::Facing facing, Properties::Mode mode, Properties::Powered powered) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (mode) {
                case Properties::Mode::COMPARE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7295;
                    case Properties::Powered::FALSE:
                        return 7296;
                    }
                case Properties::Mode::SUBTRACT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7297;
                    case Properties::Powered::FALSE:
                        return 7298;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (mode) {
                case Properties::Mode::COMPARE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7299;
                    case Properties::Powered::FALSE:
                        return 7300;
                    }
                case Properties::Mode::SUBTRACT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7301;
                    case Properties::Powered::FALSE:
                        return 7302;
                    }
                }
            case Properties::Facing::WEST:
                switch (mode) {
                case Properties::Mode::COMPARE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7303;
                    case Properties::Powered::FALSE:
                        return 7304;
                    }
                case Properties::Mode::SUBTRACT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7305;
                    case Properties::Powered::FALSE:
                        return 7306;
                    }
                }
            case Properties::Facing::EAST:
                switch (mode) {
                case Properties::Mode::COMPARE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7307;
                    case Properties::Powered::FALSE:
                        return 7308;
                    }
                case Properties::Mode::SUBTRACT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7309;
                    case Properties::Powered::FALSE:
                        return 7310;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Facing facing;
            Properties::Mode mode;
            Properties::Powered powered;
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
                } else if (prop.first == "mode") {
                    if (prop.second == "compare") {
                        mode = Properties::Mode::COMPARE;
                    } else if (prop.second == "subtract") {
                        mode = Properties::Mode::SUBTRACT;
                    } else {
                        throw std::runtime_error("Invalid property \"mode\" value");
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
            return toProtocol(facing, mode, powered);
        }
    }

}
