#include "HeavyWeightedPressurePlate.hpp"
#include <stdexcept>

namespace Blocks {
    namespace HeavyWeightedPressurePlate {
        BlockId toProtocol(Properties::Power power) {
            switch (power) {
            case Properties::Power::ZERO:
                return 7279;
            case Properties::Power::ONE:
                return 7280;
            case Properties::Power::TWO:
                return 7281;
            case Properties::Power::THREE:
                return 7282;
            case Properties::Power::FOUR:
                return 7283;
            case Properties::Power::FIVE:
                return 7284;
            case Properties::Power::SIX:
                return 7285;
            case Properties::Power::SEVEN:
                return 7286;
            case Properties::Power::EIGHT:
                return 7287;
            case Properties::Power::NINE:
                return 7288;
            case Properties::Power::TEN:
                return 7289;
            case Properties::Power::ELEVEN:
                return 7290;
            case Properties::Power::TWELVE:
                return 7291;
            case Properties::Power::THIRTEEN:
                return 7292;
            case Properties::Power::FOURTEEN:
                return 7293;
            case Properties::Power::FIFTEEN:
                return 7294;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Power power;
            for (auto prop : properties) {
                if (prop.first == "power") {
                    if (prop.second == "0") {
                        power = Properties::Power::ZERO;
                    } else if (prop.second == "1") {
                        power = Properties::Power::ONE;
                    } else if (prop.second == "2") {
                        power = Properties::Power::TWO;
                    } else if (prop.second == "3") {
                        power = Properties::Power::THREE;
                    } else if (prop.second == "4") {
                        power = Properties::Power::FOUR;
                    } else if (prop.second == "5") {
                        power = Properties::Power::FIVE;
                    } else if (prop.second == "6") {
                        power = Properties::Power::SIX;
                    } else if (prop.second == "7") {
                        power = Properties::Power::SEVEN;
                    } else if (prop.second == "8") {
                        power = Properties::Power::EIGHT;
                    } else if (prop.second == "9") {
                        power = Properties::Power::NINE;
                    } else if (prop.second == "10") {
                        power = Properties::Power::TEN;
                    } else if (prop.second == "11") {
                        power = Properties::Power::ELEVEN;
                    } else if (prop.second == "12") {
                        power = Properties::Power::TWELVE;
                    } else if (prop.second == "13") {
                        power = Properties::Power::THIRTEEN;
                    } else if (prop.second == "14") {
                        power = Properties::Power::FOURTEEN;
                    } else if (prop.second == "15") {
                        power = Properties::Power::FIFTEEN;
                    } else {
                        throw std::runtime_error("Invalid property \"power\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(power);
        }
    }

}
