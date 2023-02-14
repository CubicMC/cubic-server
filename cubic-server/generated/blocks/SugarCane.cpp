#include "SugarCane.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SugarCane {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 4257;
            case Properties::Age::ONE:
                return 4258;
            case Properties::Age::TWO:
                return 4259;
            case Properties::Age::THREE:
                return 4260;
            case Properties::Age::FOUR:
                return 4261;
            case Properties::Age::FIVE:
                return 4262;
            case Properties::Age::SIX:
                return 4263;
            case Properties::Age::SEVEN:
                return 4264;
            case Properties::Age::EIGHT:
                return 4265;
            case Properties::Age::NINE:
                return 4266;
            case Properties::Age::TEN:
                return 4267;
            case Properties::Age::ELEVEN:
                return 4268;
            case Properties::Age::TWELVE:
                return 4269;
            case Properties::Age::THIRTEEN:
                return 4270;
            case Properties::Age::FOURTEEN:
                return 4271;
            case Properties::Age::FIFTEEN:
                return 4272;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Age age;
            for (auto prop : properties) {
                if (prop.first == "age") {
                    if (prop.second == "0") {
                        age = Properties::Age::ZERO;
                    } else if (prop.second == "1") {
                        age = Properties::Age::ONE;
                    } else if (prop.second == "2") {
                        age = Properties::Age::TWO;
                    } else if (prop.second == "3") {
                        age = Properties::Age::THREE;
                    } else if (prop.second == "4") {
                        age = Properties::Age::FOUR;
                    } else if (prop.second == "5") {
                        age = Properties::Age::FIVE;
                    } else if (prop.second == "6") {
                        age = Properties::Age::SIX;
                    } else if (prop.second == "7") {
                        age = Properties::Age::SEVEN;
                    } else if (prop.second == "8") {
                        age = Properties::Age::EIGHT;
                    } else if (prop.second == "9") {
                        age = Properties::Age::NINE;
                    } else if (prop.second == "10") {
                        age = Properties::Age::TEN;
                    } else if (prop.second == "11") {
                        age = Properties::Age::ELEVEN;
                    } else if (prop.second == "12") {
                        age = Properties::Age::TWELVE;
                    } else if (prop.second == "13") {
                        age = Properties::Age::THIRTEEN;
                    } else if (prop.second == "14") {
                        age = Properties::Age::FOURTEEN;
                    } else if (prop.second == "15") {
                        age = Properties::Age::FIFTEEN;
                    } else {
                        throw std::runtime_error("Invalid property \"age\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(age);
        }
    }

}
