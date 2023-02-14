#include "DaylightDetector.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DaylightDetector {
        BlockId toProtocol(Properties::Inverted inverted, Properties::Power power) {
            switch (inverted) {
            case Properties::Inverted::TRUE:
                switch (power) {
                case Properties::Power::ZERO:
                    return 7311;
                case Properties::Power::ONE:
                    return 7312;
                case Properties::Power::TWO:
                    return 7313;
                case Properties::Power::THREE:
                    return 7314;
                case Properties::Power::FOUR:
                    return 7315;
                case Properties::Power::FIVE:
                    return 7316;
                case Properties::Power::SIX:
                    return 7317;
                case Properties::Power::SEVEN:
                    return 7318;
                case Properties::Power::EIGHT:
                    return 7319;
                case Properties::Power::NINE:
                    return 7320;
                case Properties::Power::TEN:
                    return 7321;
                case Properties::Power::ELEVEN:
                    return 7322;
                case Properties::Power::TWELVE:
                    return 7323;
                case Properties::Power::THIRTEEN:
                    return 7324;
                case Properties::Power::FOURTEEN:
                    return 7325;
                case Properties::Power::FIFTEEN:
                    return 7326;
                }
            case Properties::Inverted::FALSE:
                switch (power) {
                case Properties::Power::ZERO:
                    return 7327;
                case Properties::Power::ONE:
                    return 7328;
                case Properties::Power::TWO:
                    return 7329;
                case Properties::Power::THREE:
                    return 7330;
                case Properties::Power::FOUR:
                    return 7331;
                case Properties::Power::FIVE:
                    return 7332;
                case Properties::Power::SIX:
                    return 7333;
                case Properties::Power::SEVEN:
                    return 7334;
                case Properties::Power::EIGHT:
                    return 7335;
                case Properties::Power::NINE:
                    return 7336;
                case Properties::Power::TEN:
                    return 7337;
                case Properties::Power::ELEVEN:
                    return 7338;
                case Properties::Power::TWELVE:
                    return 7339;
                case Properties::Power::THIRTEEN:
                    return 7340;
                case Properties::Power::FOURTEEN:
                    return 7341;
                case Properties::Power::FIFTEEN:
                    return 7342;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Inverted inverted;
            Properties::Power power;
            for (auto prop : properties) {
                if (prop.first == "inverted") {
                    if (prop.second == "true") {
                        inverted = Properties::Inverted::TRUE;
                    } else if (prop.second == "false") {
                        inverted = Properties::Inverted::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"inverted\" value");
                    }
                } else if (prop.first == "power") {
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
            return toProtocol(inverted, power);
        }
    }

}
