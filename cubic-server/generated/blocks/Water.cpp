#include "Water.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Water {
        BlockId toProtocol(Properties::Level level) {
            switch (level) {
            case Properties::Level::ZERO:
                return 75;
            case Properties::Level::ONE:
                return 76;
            case Properties::Level::TWO:
                return 77;
            case Properties::Level::THREE:
                return 78;
            case Properties::Level::FOUR:
                return 79;
            case Properties::Level::FIVE:
                return 80;
            case Properties::Level::SIX:
                return 81;
            case Properties::Level::SEVEN:
                return 82;
            case Properties::Level::EIGHT:
                return 83;
            case Properties::Level::NINE:
                return 84;
            case Properties::Level::TEN:
                return 85;
            case Properties::Level::ELEVEN:
                return 86;
            case Properties::Level::TWELVE:
                return 87;
            case Properties::Level::THIRTEEN:
                return 88;
            case Properties::Level::FOURTEEN:
                return 89;
            case Properties::Level::FIFTEEN:
                return 90;
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
                    } else if (prop.second == "9") {
                        level = Properties::Level::NINE;
                    } else if (prop.second == "10") {
                        level = Properties::Level::TEN;
                    } else if (prop.second == "11") {
                        level = Properties::Level::ELEVEN;
                    } else if (prop.second == "12") {
                        level = Properties::Level::TWELVE;
                    } else if (prop.second == "13") {
                        level = Properties::Level::THIRTEEN;
                    } else if (prop.second == "14") {
                        level = Properties::Level::FOURTEEN;
                    } else if (prop.second == "15") {
                        level = Properties::Level::FIFTEEN;
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
