#include "ActivatorRail.hpp"
#include <stdexcept>

namespace Blocks {
    namespace ActivatorRail {
        BlockId toProtocol(Properties::Powered powered, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (powered) {
            case Properties::Powered::TRUE:
                switch (shape) {
                case Properties::Shape::NORTH_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7440;
                    case Properties::Waterlogged::FALSE:
                        return 7441;
                    }
                case Properties::Shape::EAST_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7442;
                    case Properties::Waterlogged::FALSE:
                        return 7443;
                    }
                case Properties::Shape::ASCENDING_EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7444;
                    case Properties::Waterlogged::FALSE:
                        return 7445;
                    }
                case Properties::Shape::ASCENDING_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7446;
                    case Properties::Waterlogged::FALSE:
                        return 7447;
                    }
                case Properties::Shape::ASCENDING_NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7448;
                    case Properties::Waterlogged::FALSE:
                        return 7449;
                    }
                case Properties::Shape::ASCENDING_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7450;
                    case Properties::Waterlogged::FALSE:
                        return 7451;
                    }
                }
            case Properties::Powered::FALSE:
                switch (shape) {
                case Properties::Shape::NORTH_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7452;
                    case Properties::Waterlogged::FALSE:
                        return 7453;
                    }
                case Properties::Shape::EAST_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7454;
                    case Properties::Waterlogged::FALSE:
                        return 7455;
                    }
                case Properties::Shape::ASCENDING_EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7456;
                    case Properties::Waterlogged::FALSE:
                        return 7457;
                    }
                case Properties::Shape::ASCENDING_WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7458;
                    case Properties::Waterlogged::FALSE:
                        return 7459;
                    }
                case Properties::Shape::ASCENDING_NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7460;
                    case Properties::Waterlogged::FALSE:
                        return 7461;
                    }
                case Properties::Shape::ASCENDING_SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7462;
                    case Properties::Waterlogged::FALSE:
                        return 7463;
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
