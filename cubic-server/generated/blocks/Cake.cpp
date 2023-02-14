#include "Cake.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Cake {
        BlockId toProtocol(Properties::Bites bites) {
            switch (bites) {
            case Properties::Bites::ZERO:
                return 4333;
            case Properties::Bites::ONE:
                return 4334;
            case Properties::Bites::TWO:
                return 4335;
            case Properties::Bites::THREE:
                return 4336;
            case Properties::Bites::FOUR:
                return 4337;
            case Properties::Bites::FIVE:
                return 4338;
            case Properties::Bites::SIX:
                return 4339;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Bites bites;
            for (auto prop : properties) {
                if (prop.first == "bites") {
                    if (prop.second == "0") {
                        bites = Properties::Bites::ZERO;
                    } else if (prop.second == "1") {
                        bites = Properties::Bites::ONE;
                    } else if (prop.second == "2") {
                        bites = Properties::Bites::TWO;
                    } else if (prop.second == "3") {
                        bites = Properties::Bites::THREE;
                    } else if (prop.second == "4") {
                        bites = Properties::Bites::FOUR;
                    } else if (prop.second == "5") {
                        bites = Properties::Bites::FIVE;
                    } else if (prop.second == "6") {
                        bites = Properties::Bites::SIX;
                    } else {
                        throw std::runtime_error("Invalid property \"bites\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(bites);
        }
    }

}
