#include "LightGrayBanner.hpp"
#include <stdexcept>

namespace Blocks {
    namespace LightGrayBanner {
        BlockId toProtocol(Properties::Rotation rotation) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                return 8766;
            case Properties::Rotation::ONE:
                return 8767;
            case Properties::Rotation::TWO:
                return 8768;
            case Properties::Rotation::THREE:
                return 8769;
            case Properties::Rotation::FOUR:
                return 8770;
            case Properties::Rotation::FIVE:
                return 8771;
            case Properties::Rotation::SIX:
                return 8772;
            case Properties::Rotation::SEVEN:
                return 8773;
            case Properties::Rotation::EIGHT:
                return 8774;
            case Properties::Rotation::NINE:
                return 8775;
            case Properties::Rotation::TEN:
                return 8776;
            case Properties::Rotation::ELEVEN:
                return 8777;
            case Properties::Rotation::TWELVE:
                return 8778;
            case Properties::Rotation::THIRTEEN:
                return 8779;
            case Properties::Rotation::FOURTEEN:
                return 8780;
            case Properties::Rotation::FIFTEEN:
                return 8781;
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
