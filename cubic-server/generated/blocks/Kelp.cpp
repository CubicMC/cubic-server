#include "Kelp.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Kelp {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 10351;
            case Properties::Age::ONE:
                return 10352;
            case Properties::Age::TWO:
                return 10353;
            case Properties::Age::THREE:
                return 10354;
            case Properties::Age::FOUR:
                return 10355;
            case Properties::Age::FIVE:
                return 10356;
            case Properties::Age::SIX:
                return 10357;
            case Properties::Age::SEVEN:
                return 10358;
            case Properties::Age::EIGHT:
                return 10359;
            case Properties::Age::NINE:
                return 10360;
            case Properties::Age::TEN:
                return 10361;
            case Properties::Age::ELEVEN:
                return 10362;
            case Properties::Age::TWELVE:
                return 10363;
            case Properties::Age::THIRTEEN:
                return 10364;
            case Properties::Age::FOURTEEN:
                return 10365;
            case Properties::Age::FIFTEEN:
                return 10366;
            case Properties::Age::SIXTEEN:
                return 10367;
            case Properties::Age::SEVENTEEN:
                return 10368;
            case Properties::Age::EIGHTEEN:
                return 10369;
            case Properties::Age::NINETEEN:
                return 10370;
            case Properties::Age::TWENTY:
                return 10371;
            case Properties::Age::TWENTY_ONE:
                return 10372;
            case Properties::Age::TWENTY_TWO:
                return 10373;
            case Properties::Age::TWENTY_THREE:
                return 10374;
            case Properties::Age::TWENTY_FOUR:
                return 10375;
            case Properties::Age::TWENTY_FIVE:
                return 10376;
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
