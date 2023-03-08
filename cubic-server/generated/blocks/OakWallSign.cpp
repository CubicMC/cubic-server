#include "OakWallSign.hpp"
#include <stdexcept>

namespace Blocks {
    namespace OakWallSign {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4032;
                case Properties::Waterlogged::FALSE:
                    return 4033;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4034;
                case Properties::Waterlogged::FALSE:
                    return 4035;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4036;
                case Properties::Waterlogged::FALSE:
                    return 4037;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4038;
                case Properties::Waterlogged::FALSE:
                    return 4039;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Facing facing;
            Properties::Waterlogged waterlogged;
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
            return toProtocol(facing, waterlogged);
        }
    }

}