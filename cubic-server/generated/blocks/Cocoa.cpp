#include "Cocoa.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Cocoa {
        BlockId toProtocol(Properties::Age age, Properties::Facing facing) {
            switch (age) {
            case Properties::Age::ZERO:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 5749;
                case Properties::Facing::SOUTH:
                    return 5750;
                case Properties::Facing::WEST:
                    return 5751;
                case Properties::Facing::EAST:
                    return 5752;
                }
            case Properties::Age::ONE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 5753;
                case Properties::Facing::SOUTH:
                    return 5754;
                case Properties::Facing::WEST:
                    return 5755;
                case Properties::Facing::EAST:
                    return 5756;
                }
            case Properties::Age::TWO:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 5757;
                case Properties::Facing::SOUTH:
                    return 5758;
                case Properties::Facing::WEST:
                    return 5759;
                case Properties::Facing::EAST:
                    return 5760;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Age age;
            Properties::Facing facing;
            for (auto prop : properties) {
                if (prop.first == "age") {
                    if (prop.second == "0") {
                        age = Properties::Age::ZERO;
                    } else if (prop.second == "1") {
                        age = Properties::Age::ONE;
                    } else if (prop.second == "2") {
                        age = Properties::Age::TWO;
                    } else {
                        throw std::runtime_error("Invalid property \"age\" value");
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
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(age, facing);
        }
    }

}
