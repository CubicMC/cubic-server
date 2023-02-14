#include "PoweredRail.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PoweredRail {
        BlockId toProtocol(Properties::Powered powered, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (powered) {
            case Properties::Powered::TRUE:
                switch (shape) {
                case Properties::Shape::NORTH_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1535;
                    case Properties::Waterlogged::FALSE:
                        return 1536;
                    }
                case Properties::Shape::EAST_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1537;
                    case Properties::Waterlogged::FALSE:
                        return 1538;
                    }
                case Properties::Shape::ASCENDING_EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1539;
                    case Properties::Waterlogged::FALSE:
                        return 1540;
                    }
                case Properties::Shape::ASCENDING_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1541;
                    case Properties::Waterlogged::FALSE:
                        return 1542;
                    }
                case Properties::Shape::ASCENDING_NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1543;
                    case Properties::Waterlogged::FALSE:
                        return 1544;
                    }
                case Properties::Shape::ASCENDING_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1545;
                    case Properties::Waterlogged::FALSE:
                        return 1546;
                    }
                }
            case Properties::Powered::FALSE:
                switch (shape) {
                case Properties::Shape::NORTH_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1547;
                    case Properties::Waterlogged::FALSE:
                        return 1548;
                    }
                case Properties::Shape::EAST_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1549;
                    case Properties::Waterlogged::FALSE:
                        return 1550;
                    }
                case Properties::Shape::ASCENDING_EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1551;
                    case Properties::Waterlogged::FALSE:
                        return 1552;
                    }
                case Properties::Shape::ASCENDING_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1553;
                    case Properties::Waterlogged::FALSE:
                        return 1554;
                    }
                case Properties::Shape::ASCENDING_NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1555;
                    case Properties::Waterlogged::FALSE:
                        return 1556;
                    }
                case Properties::Shape::ASCENDING_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1557;
                    case Properties::Waterlogged::FALSE:
                        return 1558;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Powered powered;
            Properties::Shape shape;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "powered") {
                    if (prop.second == "true") {
                        powered = Properties::Powered::TRUE;
                    } else if (prop.second == "false") {
                        powered = Properties::Powered::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"powered\" value");
                    }
                } else if (prop.first == "shape") {
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
            return toProtocol(powered, shape, waterlogged);
        }
    }

}
