#include "BeeNest.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BeeNest {
        BlockId toProtocol(Properties::Facing facing, Properties::Honey_level honey_level) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (honey_level) {
                case Properties::Honey_level::ZERO:
                    return 16985;
                case Properties::Honey_level::ONE:
                    return 16986;
                case Properties::Honey_level::TWO:
                    return 16987;
                case Properties::Honey_level::THREE:
                    return 16988;
                case Properties::Honey_level::FOUR:
                    return 16989;
                case Properties::Honey_level::FIVE:
                    return 16990;
                }
            case Properties::Facing::SOUTH:
                switch (honey_level) {
                case Properties::Honey_level::ZERO:
                    return 16991;
                case Properties::Honey_level::ONE:
                    return 16992;
                case Properties::Honey_level::TWO:
                    return 16993;
                case Properties::Honey_level::THREE:
                    return 16994;
                case Properties::Honey_level::FOUR:
                    return 16995;
                case Properties::Honey_level::FIVE:
                    return 16996;
                }
            case Properties::Facing::WEST:
                switch (honey_level) {
                case Properties::Honey_level::ZERO:
                    return 16997;
                case Properties::Honey_level::ONE:
                    return 16998;
                case Properties::Honey_level::TWO:
                    return 16999;
                case Properties::Honey_level::THREE:
                    return 17000;
                case Properties::Honey_level::FOUR:
                    return 17001;
                case Properties::Honey_level::FIVE:
                    return 17002;
                }
            case Properties::Facing::EAST:
                switch (honey_level) {
                case Properties::Honey_level::ZERO:
                    return 17003;
                case Properties::Honey_level::ONE:
                    return 17004;
                case Properties::Honey_level::TWO:
                    return 17005;
                case Properties::Honey_level::THREE:
                    return 17006;
                case Properties::Honey_level::FOUR:
                    return 17007;
                case Properties::Honey_level::FIVE:
                    return 17008;
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
