#include "TwistingVines.hpp"
#include <stdexcept>

namespace Blocks {
    namespace TwistingVines {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 16226;
            case Properties::Age::ONE:
                return 16227;
            case Properties::Age::TWO:
                return 16228;
            case Properties::Age::THREE:
                return 16229;
            case Properties::Age::FOUR:
                return 16230;
            case Properties::Age::FIVE:
                return 16231;
            case Properties::Age::SIX:
                return 16232;
            case Properties::Age::SEVEN:
                return 16233;
            case Properties::Age::EIGHT:
                return 16234;
            case Properties::Age::NINE:
                return 16235;
            case Properties::Age::TEN:
                return 16236;
            case Properties::Age::ELEVEN:
                return 16237;
            case Properties::Age::TWELVE:
                return 16238;
            case Properties::Age::THIRTEEN:
                return 16239;
            case Properties::Age::FOURTEEN:
                return 16240;
            case Properties::Age::FIFTEEN:
                return 16241;
            case Properties::Age::SIXTEEN:
                return 16242;
            case Properties::Age::SEVENTEEN:
                return 16243;
            case Properties::Age::EIGHTEEN:
                return 16244;
            case Properties::Age::NINETEEN:
                return 16245;
            case Properties::Age::TWENTY:
                return 16246;
            case Properties::Age::TWENTY_ONE:
                return 16247;
            case Properties::Age::TWENTY_TWO:
                return 16248;
            case Properties::Age::TWENTY_THREE:
                return 16249;
            case Properties::Age::TWENTY_FOUR:
                return 16250;
            case Properties::Age::TWENTY_FIVE:
                return 16251;
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
                    } else if (prop.second == "16") {
                        age = Properties::Age::SIXTEEN;
                    } else if (prop.second == "17") {
                        age = Properties::Age::SEVENTEEN;
                    } else if (prop.second == "18") {
                        age = Properties::Age::EIGHTEEN;
                    } else if (prop.second == "19") {
                        age = Properties::Age::NINETEEN;
                    } else if (prop.second == "20") {
                        age = Properties::Age::TWENTY;
                    } else if (prop.second == "21") {
                        age = Properties::Age::TWENTY_ONE;
                    } else if (prop.second == "22") {
                        age = Properties::Age::TWENTY_TWO;
                    } else if (prop.second == "23") {
                        age = Properties::Age::TWENTY_THREE;
                    } else if (prop.second == "24") {
                        age = Properties::Age::TWENTY_FOUR;
                    } else if (prop.second == "25") {
                        age = Properties::Age::TWENTY_FIVE;
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
