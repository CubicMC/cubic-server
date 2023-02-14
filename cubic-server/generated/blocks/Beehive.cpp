#include "Beehive.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Beehive {
        BlockId toProtocol(Properties::Facing facing, Properties::Honey_level honey_level) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (honey_level) {
                case Properties::Honey_level::ZERO:
                    return 17009;
                case Properties::Honey_level::ONE:
                    return 17010;
                case Properties::Honey_level::TWO:
                    return 17011;
                case Properties::Honey_level::THREE:
                    return 17012;
                case Properties::Honey_level::FOUR:
                    return 17013;
                case Properties::Honey_level::FIVE:
                    return 17014;
                }
            case Properties::Facing::SOUTH:
                switch (honey_level) {
                case Properties::Honey_level::ZERO:
                    return 17015;
                case Properties::Honey_level::ONE:
                    return 17016;
                case Properties::Honey_level::TWO:
                    return 17017;
                case Properties::Honey_level::THREE:
                    return 17018;
                case Properties::Honey_level::FOUR:
                    return 17019;
                case Properties::Honey_level::FIVE:
                    return 17020;
                }
            case Properties::Facing::WEST:
                switch (honey_level) {
                case Properties::Honey_level::ZERO:
                    return 17021;
                case Properties::Honey_level::ONE:
                    return 17022;
                case Properties::Honey_level::TWO:
                    return 17023;
                case Properties::Honey_level::THREE:
                    return 17024;
                case Properties::Honey_level::FOUR:
                    return 17025;
                case Properties::Honey_level::FIVE:
                    return 17026;
                }
            case Properties::Facing::EAST:
                switch (honey_level) {
                case Properties::Honey_level::ZERO:
                    return 17027;
                case Properties::Honey_level::ONE:
                    return 17028;
                case Properties::Honey_level::TWO:
                    return 17029;
                case Properties::Honey_level::THREE:
                    return 17030;
                case Properties::Honey_level::FOUR:
                    return 17031;
                case Properties::Honey_level::FIVE:
                    return 17032;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Facing facing;
            Properties::Honey_level honey_level;
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
                } else if (prop.first == "honey_level") {
                    if (prop.second == "0") {
                        honey_level = Properties::Honey_level::ZERO;
                    } else if (prop.second == "1") {
                        honey_level = Properties::Honey_level::ONE;
                    } else if (prop.second == "2") {
                        honey_level = Properties::Honey_level::TWO;
                    } else if (prop.second == "3") {
                        honey_level = Properties::Honey_level::THREE;
                    } else if (prop.second == "4") {
                        honey_level = Properties::Honey_level::FOUR;
                    } else if (prop.second == "5") {
                        honey_level = Properties::Honey_level::FIVE;
                    } else {
                        throw std::runtime_error("Invalid property \"honey_level\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(facing, honey_level);
        }
    }

}
