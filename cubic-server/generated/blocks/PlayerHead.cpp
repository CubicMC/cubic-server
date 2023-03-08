#include "PlayerHead.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PlayerHead {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 7167;
            case Properties::Rotation::ONE:
                return 7168;
            case Properties::Rotation::TWO:
                return 7169;
            case Properties::Rotation::THREE:
                return 7170;
            case Properties::Rotation::FOUR:
                return 7171;
            case Properties::Rotation::FIVE:
                return 7172;
            case Properties::Rotation::SIX:
                return 7173;
            case Properties::Rotation::SEVEN:
                return 7174;
            case Properties::Rotation::EIGHT:
                return 7175;
            case Properties::Rotation::NINE:
                return 7176;
            case Properties::Rotation::TEN:
                return 7177;
            case Properties::Rotation::ELEVEN:
                return 7178;
            case Properties::Rotation::TWELVE:
                return 7179;
            case Properties::Rotation::THIRTEEN:
                return 7180;
            case Properties::Rotation::FOURTEEN:
                return 7181;
            case Properties::Rotation::FIFTEEN:
                return 7182;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Rotation rotation;
            for (auto prop : properties) {
                if (prop.first == "rotation") {
                    if (prop.second == "0") {
                        rotation = Properties::Rotation::ZERO;
                    } else if (prop.second == "1") {
                        rotation = Properties::Rotation::ONE;
                    } else if (prop.second == "2") {
                        rotation = Properties::Rotation::TWO;
                    } else if (prop.second == "3") {
                        rotation = Properties::Rotation::THREE;
                    } else if (prop.second == "4") {
                        rotation = Properties::Rotation::FOUR;
                    } else if (prop.second == "5") {
                        rotation = Properties::Rotation::FIVE;
                    } else if (prop.second == "6") {
                        rotation = Properties::Rotation::SIX;
                    } else if (prop.second == "7") {
                        rotation = Properties::Rotation::SEVEN;
                    } else if (prop.second == "8") {
                        rotation = Properties::Rotation::EIGHT;
                    } else if (prop.second == "9") {
                        rotation = Properties::Rotation::NINE;
                    } else if (prop.second == "10") {
                        rotation = Properties::Rotation::TEN;
                    } else if (prop.second == "11") {
                        rotation = Properties::Rotation::ELEVEN;
                    } else if (prop.second == "12") {
                        rotation = Properties::Rotation::TWELVE;
                    } else if (prop.second == "13") {
                        rotation = Properties::Rotation::THIRTEEN;
                    } else if (prop.second == "14") {
                        rotation = Properties::Rotation::FOURTEEN;
                    } else if (prop.second == "15") {
                        rotation = Properties::Rotation::FIFTEEN;
                    } else {
                        throw std::runtime_error("Invalid property \"rotation\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(rotation);
        }
    }

}