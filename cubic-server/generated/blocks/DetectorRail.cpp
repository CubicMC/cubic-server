#include "DetectorRail.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DetectorRail {
        BlockId toProtocol(Properties::Powered powered, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (powered) {
            case Properties::Powered::TRUE:
                switch (shape) {
                case Properties::Shape::NORTH_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1559;
                    case Properties::Waterlogged::FALSE:
                        return 1560;
                    }
                case Properties::Shape::EAST_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1561;
                    case Properties::Waterlogged::FALSE:
                        return 1562;
                    }
                case Properties::Shape::ASCENDING_EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1563;
                    case Properties::Waterlogged::FALSE:
                        return 1564;
                    }
                case Properties::Shape::ASCENDING_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1565;
                    case Properties::Waterlogged::FALSE:
                        return 1566;
                    }
                case Properties::Shape::ASCENDING_NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1567;
                    case Properties::Waterlogged::FALSE:
                        return 1568;
                    }
                case Properties::Shape::ASCENDING_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1569;
                    case Properties::Waterlogged::FALSE:
                        return 1570;
                    }
                }
            case Properties::Powered::FALSE:
                switch (shape) {
                case Properties::Shape::NORTH_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1571;
                    case Properties::Waterlogged::FALSE:
                        return 1572;
                    }
                case Properties::Shape::EAST_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1573;
                    case Properties::Waterlogged::FALSE:
                        return 1574;
                    }
                case Properties::Shape::ASCENDING_EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1575;
                    case Properties::Waterlogged::FALSE:
                        return 1576;
                    }
                case Properties::Shape::ASCENDING_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1577;
                    case Properties::Waterlogged::FALSE:
                        return 1578;
                    }
                case Properties::Shape::ASCENDING_NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1579;
                    case Properties::Waterlogged::FALSE:
                        return 1580;
                    }
                case Properties::Shape::ASCENDING_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 1581;
                    case Properties::Waterlogged::FALSE:
                        return 1582;
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
