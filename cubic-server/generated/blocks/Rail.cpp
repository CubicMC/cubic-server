#include "Rail.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Rail {
        BlockId toProtocol(Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (shape) {
            case Properties::Shape::NORTH_SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 3932;
                case Properties::Waterlogged::FALSE:
                    return 3933;
                }
            case Properties::Shape::EAST_WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 3934;
                case Properties::Waterlogged::FALSE:
                    return 3935;
                }
            case Properties::Shape::ASCENDING_EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 3936;
                case Properties::Waterlogged::FALSE:
                    return 3937;
                }
            case Properties::Shape::ASCENDING_WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 3938;
                case Properties::Waterlogged::FALSE:
                    return 3939;
                }
            case Properties::Shape::ASCENDING_NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 3940;
                case Properties::Waterlogged::FALSE:
                    return 3941;
                }
            case Properties::Shape::ASCENDING_SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 3942;
                case Properties::Waterlogged::FALSE:
                    return 3943;
                }
            case Properties::Shape::SOUTH_EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 3944;
                case Properties::Waterlogged::FALSE:
                    return 3945;
                }
            case Properties::Shape::SOUTH_WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 3946;
                case Properties::Waterlogged::FALSE:
                    return 3947;
                }
            case Properties::Shape::NORTH_WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 3948;
                case Properties::Waterlogged::FALSE:
                    return 3949;
                }
            case Properties::Shape::NORTH_EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 3950;
                case Properties::Waterlogged::FALSE:
                    return 3951;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Shape shape;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "shape") {
                    if (prop.second == "north_south") {
                        shape = Properties::Shape::NORTH_SOUTH;
                    } else if (prop.second == "east_west") {
                        shape = Properties::Shape::EAST_WEST;
                    } else if (prop.second == "ascending_east") {
                        shape = Properties::Shape::ASCENDING_EAST;
                    } else if (prop.second == "ascending_west") {
                        shape = Properties::Shape::ASCENDING_WEST;
                    } else if (prop.second == "ascending_north") {
                        shape = Properties::Shape::ASCENDING_NORTH;
                    } else if (prop.second == "ascending_south") {
                        shape = Properties::Shape::ASCENDING_SOUTH;
                    } else if (prop.second == "south_east") {
                        shape = Properties::Shape::SOUTH_EAST;
                    } else if (prop.second == "south_west") {
                        shape = Properties::Shape::SOUTH_WEST;
                    } else if (prop.second == "north_west") {
                        shape = Properties::Shape::NORTH_WEST;
                    } else if (prop.second == "north_east") {
                        shape = Properties::Shape::NORTH_EAST;
                    } else {
                        throw std::runtime_error("Invalid property \"shape\" value");
                    }
                } else if (prop.first == "waterlogged") {
                    if (prop.second == "true") {
                        waterlogged = Properties::Waterlogged::TRUE;
                    } else if (prop.second == "false") {
                        waterlogged = Properties::Waterlogged::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"waterlogged\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(shape, waterlogged);
        }
    }

}
