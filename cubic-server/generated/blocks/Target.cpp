#include "Target.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Target {
        BlockId toProtocol(Properties::Power power) {
            switch (power) {
            case Properties::Power::ZERO:
                return 16969;
            case Properties::Power::ONE:
                return 16970;
            case Properties::Power::TWO:
                return 16971;
            case Properties::Power::THREE:
                return 16972;
            case Properties::Power::FOUR:
                return 16973;
            case Properties::Power::FIVE:
                return 16974;
            case Properties::Power::SIX:
                return 16975;
            case Properties::Power::SEVEN:
                return 16976;
            case Properties::Power::EIGHT:
                return 16977;
            case Properties::Power::NINE:
                return 16978;
            case Properties::Power::TEN:
                return 16979;
            case Properties::Power::ELEVEN:
                return 16980;
            case Properties::Power::TWELVE:
                return 16981;
            case Properties::Power::THIRTEEN:
                return 16982;
            case Properties::Power::FOURTEEN:
                return 16983;
            case Properties::Power::FIFTEEN:
                return 16984;
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
