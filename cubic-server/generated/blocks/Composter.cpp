#include "Composter.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Composter {
        BlockId toProtocol(Properties::Level level) {
            switch (level) {
            case Properties::Level::ZERO:
                return 16960;
            case Properties::Level::ONE:
                return 16961;
            case Properties::Level::TWO:
                return 16962;
            case Properties::Level::THREE:
                return 16963;
            case Properties::Level::FOUR:
                return 16964;
            case Properties::Level::FIVE:
                return 16965;
            case Properties::Level::SIX:
                return 16966;
            case Properties::Level::SEVEN:
                return 16967;
            case Properties::Level::EIGHT:
                return 16968;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Level level;
            for (auto prop : properties) {
                if (prop.first == "level") {
                    if (prop.second == "0") {
                        level = Properties::Level::ZERO;
                    } else if (prop.second == "1") {
                        level = Properties::Level::ONE;
                    } else if (prop.second == "2") {
                        level = Properties::Level::TWO;
                    } else if (prop.second == "3") {
                        level = Properties::Level::THREE;
                    } else if (prop.second == "4") {
                        level = Properties::Level::FOUR;
                    } else if (prop.second == "5") {
                        level = Properties::Level::FIVE;
                    } else if (prop.second == "6") {
                        level = Properties::Level::SIX;
                    } else if (prop.second == "7") {
                        level = Properties::Level::SEVEN;
                    } else if (prop.second == "8") {
                        level = Properties::Level::EIGHT;
                    } else {
                        throw std::runtime_error("Invalid property \"level\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(level);
        }
    }

}
