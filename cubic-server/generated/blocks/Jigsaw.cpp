#include "Jigsaw.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Jigsaw {
        BlockId toProtocol(Properties::Orientation orientation) {
            switch (orientation) {
            case Properties::Orientation::DOWN_EAST:
                return 16948;
            case Properties::Orientation::DOWN_NORTH:
                return 16949;
            case Properties::Orientation::DOWN_SOUTH:
                return 16950;
            case Properties::Orientation::DOWN_WEST:
                return 16951;
            case Properties::Orientation::UP_EAST:
                return 16952;
            case Properties::Orientation::UP_NORTH:
                return 16953;
            case Properties::Orientation::UP_SOUTH:
                return 16954;
            case Properties::Orientation::UP_WEST:
                return 16955;
            case Properties::Orientation::WEST_UP:
                return 16956;
            case Properties::Orientation::EAST_UP:
                return 16957;
            case Properties::Orientation::NORTH_UP:
                return 16958;
            case Properties::Orientation::SOUTH_UP:
                return 16959;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Orientation orientation;
            for (auto prop : properties) {
                if (prop.first == "orientation") {
                    if (prop.second == "down_east") {
                        orientation = Properties::Orientation::DOWN_EAST;
                    } else if (prop.second == "down_north") {
                        orientation = Properties::Orientation::DOWN_NORTH;
                    } else if (prop.second == "down_south") {
                        orientation = Properties::Orientation::DOWN_SOUTH;
                    } else if (prop.second == "down_west") {
                        orientation = Properties::Orientation::DOWN_WEST;
                    } else if (prop.second == "up_east") {
                        orientation = Properties::Orientation::UP_EAST;
                    } else if (prop.second == "up_north") {
                        orientation = Properties::Orientation::UP_NORTH;
                    } else if (prop.second == "up_south") {
                        orientation = Properties::Orientation::UP_SOUTH;
                    } else if (prop.second == "up_west") {
                        orientation = Properties::Orientation::UP_WEST;
                    } else if (prop.second == "west_up") {
                        orientation = Properties::Orientation::WEST_UP;
                    } else if (prop.second == "east_up") {
                        orientation = Properties::Orientation::EAST_UP;
                    } else if (prop.second == "north_up") {
                        orientation = Properties::Orientation::NORTH_UP;
                    } else if (prop.second == "south_up") {
                        orientation = Properties::Orientation::SOUTH_UP;
                    } else {
                        throw std::runtime_error("Invalid property \"orientation\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(orientation);
        }
    }

}
