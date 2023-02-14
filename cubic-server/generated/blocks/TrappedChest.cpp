#include "TrappedChest.hpp"
#include <stdexcept>

namespace Blocks {
    namespace TrappedChest {
        BlockId toProtocol(Properties::Type type, Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::SINGLE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7239;
                    case Properties::Waterlogged::FALSE:
                        return 7240;
                    }
                case Properties::Facing::SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7245;
                    case Properties::Waterlogged::FALSE:
                        return 7246;
                    }
                case Properties::Facing::WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7251;
                    case Properties::Waterlogged::FALSE:
                        return 7252;
                    }
                case Properties::Facing::EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7257;
                    case Properties::Waterlogged::FALSE:
                        return 7258;
                    }
                }
            case Properties::Type::LEFT:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7241;
                    case Properties::Waterlogged::FALSE:
                        return 7242;
                    }
                case Properties::Facing::SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7247;
                    case Properties::Waterlogged::FALSE:
                        return 7248;
                    }
                case Properties::Facing::WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7253;
                    case Properties::Waterlogged::FALSE:
                        return 7254;
                    }
                case Properties::Facing::EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7259;
                    case Properties::Waterlogged::FALSE:
                        return 7260;
                    }
                }
            case Properties::Type::RIGHT:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7243;
                    case Properties::Waterlogged::FALSE:
                        return 7244;
                    }
                case Properties::Facing::SOUTH:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7249;
                    case Properties::Waterlogged::FALSE:
                        return 7250;
                    }
                case Properties::Facing::WEST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7255;
                    case Properties::Waterlogged::FALSE:
                        return 7256;
                    }
                case Properties::Facing::EAST:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 7261;
                    case Properties::Waterlogged::FALSE:
                        return 7262;
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
