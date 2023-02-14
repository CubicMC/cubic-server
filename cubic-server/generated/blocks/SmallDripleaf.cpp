#include "SmallDripleaf.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SmallDripleaf {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::UPPER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19758;
                    case Properties::Waterlogged::FALSE:
                        return 19759;
                    }
                case Properties::Half::LOWER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19760;
                    case Properties::Waterlogged::FALSE:
                        return 19761;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (half) {
                case Properties::Half::UPPER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19762;
                    case Properties::Waterlogged::FALSE:
                        return 19763;
                    }
                case Properties::Half::LOWER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19764;
                    case Properties::Waterlogged::FALSE:
                        return 19765;
                    }
                }
            case Properties::Facing::WEST:
                switch (half) {
                case Properties::Half::UPPER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19766;
                    case Properties::Waterlogged::FALSE:
                        return 19767;
                    }
                case Properties::Half::LOWER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19768;
                    case Properties::Waterlogged::FALSE:
                        return 19769;
                    }
                }
            case Properties::Facing::EAST:
                switch (half) {
                case Properties::Half::UPPER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19770;
                    case Properties::Waterlogged::FALSE:
                        return 19771;
                    }
                case Properties::Half::LOWER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19772;
                    case Properties::Waterlogged::FALSE:
                        return 19773;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Facing facing;
            Properties::Half half;
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
                } else if (prop.first == "half") {
                    if (prop.second == "upper") {
                        half = Properties::Half::UPPER;
                    } else if (prop.second == "lower") {
                        half = Properties::Half::LOWER;
                    } else {
                        throw std::runtime_error("Invalid property \"half\" value");
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
            return toProtocol(facing, half, waterlogged);
        }
    }

}
