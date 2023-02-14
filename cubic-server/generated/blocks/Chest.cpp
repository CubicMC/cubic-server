#include "Chest.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Chest {
        BlockId toProtocol(Properties::Type type, Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::SINGLE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 2288;
                    case Properties::Waterlogged::FALSE:
                        return 2289;
                    }
                case Properties::Facing::SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 2294;
                    case Properties::Waterlogged::FALSE:
                        return 2295;
                    }
                case Properties::Facing::WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 2300;
                    case Properties::Waterlogged::FALSE:
                        return 2301;
                    }
                case Properties::Facing::EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 2306;
                    case Properties::Waterlogged::FALSE:
                        return 2307;
                    }
                }
            case Properties::Type::LEFT:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 2290;
                    case Properties::Waterlogged::FALSE:
                        return 2291;
                    }
                case Properties::Facing::SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 2296;
                    case Properties::Waterlogged::FALSE:
                        return 2297;
                    }
                case Properties::Facing::WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 2302;
                    case Properties::Waterlogged::FALSE:
                        return 2303;
                    }
                case Properties::Facing::EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 2308;
                    case Properties::Waterlogged::FALSE:
                        return 2309;
                    }
                }
            case Properties::Type::RIGHT:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 2292;
                    case Properties::Waterlogged::FALSE:
                        return 2293;
                    }
                case Properties::Facing::SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 2298;
                    case Properties::Waterlogged::FALSE:
                        return 2299;
                    }
                case Properties::Facing::WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 2304;
                    case Properties::Waterlogged::FALSE:
                        return 2305;
                    }
                case Properties::Facing::EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 2310;
                    case Properties::Waterlogged::FALSE:
                        return 2311;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Type type;
            Properties::Facing facing;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "type") {
                    if (prop.second == "single") {
                        type = Properties::Type::SINGLE;
                    } else if (prop.second == "left") {
                        type = Properties::Type::LEFT;
                    } else if (prop.second == "right") {
                        type = Properties::Type::RIGHT;
                    } else {
                        throw std::runtime_error("Invalid property \"type\" value");
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
            return toProtocol(type, facing, waterlogged);
        }
    }

}
