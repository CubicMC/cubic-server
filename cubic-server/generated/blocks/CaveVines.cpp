#include "CaveVines.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CaveVines {
        BlockId toProtocol(Properties::Age age, Properties::Berries berries) {
            switch (age) {
            case Properties::Age::ZERO:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19659;
                case Properties::Berries::FALSE:
                    return 19660;
                }
            case Properties::Age::ONE:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19661;
                case Properties::Berries::FALSE:
                    return 19662;
                }
            case Properties::Age::TWO:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19663;
                case Properties::Berries::FALSE:
                    return 19664;
                }
            case Properties::Age::THREE:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19665;
                case Properties::Berries::FALSE:
                    return 19666;
                }
            case Properties::Age::FOUR:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19667;
                case Properties::Berries::FALSE:
                    return 19668;
                }
            case Properties::Age::FIVE:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19669;
                case Properties::Berries::FALSE:
                    return 19670;
                }
            case Properties::Age::SIX:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19671;
                case Properties::Berries::FALSE:
                    return 19672;
                }
            case Properties::Age::SEVEN:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19673;
                case Properties::Berries::FALSE:
                    return 19674;
                }
            case Properties::Age::EIGHT:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19675;
                case Properties::Berries::FALSE:
                    return 19676;
                }
            case Properties::Age::NINE:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19677;
                case Properties::Berries::FALSE:
                    return 19678;
                }
            case Properties::Age::TEN:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19679;
                case Properties::Berries::FALSE:
                    return 19680;
                }
            case Properties::Age::ELEVEN:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19681;
                case Properties::Berries::FALSE:
                    return 19682;
                }
            case Properties::Age::TWELVE:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19683;
                case Properties::Berries::FALSE:
                    return 19684;
                }
            case Properties::Age::THIRTEEN:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19685;
                case Properties::Berries::FALSE:
                    return 19686;
                }
            case Properties::Age::FOURTEEN:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19687;
                case Properties::Berries::FALSE:
                    return 19688;
                }
            case Properties::Age::FIFTEEN:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19689;
                case Properties::Berries::FALSE:
                    return 19690;
                }
            case Properties::Age::SIXTEEN:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19691;
                case Properties::Berries::FALSE:
                    return 19692;
                }
            case Properties::Age::SEVENTEEN:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19693;
                case Properties::Berries::FALSE:
                    return 19694;
                }
            case Properties::Age::EIGHTEEN:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19695;
                case Properties::Berries::FALSE:
                    return 19696;
                }
            case Properties::Age::NINETEEN:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19697;
                case Properties::Berries::FALSE:
                    return 19698;
                }
            case Properties::Age::TWENTY:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19699;
                case Properties::Berries::FALSE:
                    return 19700;
                }
            case Properties::Age::TWENTY_ONE:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19701;
                case Properties::Berries::FALSE:
                    return 19702;
                }
            case Properties::Age::TWENTY_TWO:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19703;
                case Properties::Berries::FALSE:
                    return 19704;
                }
            case Properties::Age::TWENTY_THREE:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19705;
                case Properties::Berries::FALSE:
                    return 19706;
                }
            case Properties::Age::TWENTY_FOUR:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19707;
                case Properties::Berries::FALSE:
                    return 19708;
                }
            case Properties::Age::TWENTY_FIVE:
                switch (berries) {
                case Properties::Berries::TRUE:
                    return 19709;
                case Properties::Berries::FALSE:
                    return 19710;
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 2)
            throw std::runtime_error("Invalid number of properties");
            Properties::Age age;
            Properties::Berries berries;
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
                } else if (prop.first == "berries") {
                    if (prop.second == "true") {
                        berries = Properties::Berries::TRUE;
                    } else if (prop.second == "false") {
                        berries = Properties::Berries::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"berries\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(age, berries);
        }
    }

}
