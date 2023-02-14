#include "RespawnAnchor.hpp"
#include <stdexcept>

namespace Blocks {
    namespace RespawnAnchor {
        BlockId toProtocol(Properties::Charges charges) {
            switch (charges) {
            case Properties::Charges::ZERO:
                return 17038;
            case Properties::Charges::ONE:
                return 17039;
            case Properties::Charges::TWO:
                return 17040;
            case Properties::Charges::THREE:
                return 17041;
            case Properties::Charges::FOUR:
                return 17042;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Charges charges;
            for (auto prop : properties) {
                if (prop.first == "charges") {
                    if (prop.second == "0") {
                        charges = Properties::Charges::ZERO;
                    } else if (prop.second == "1") {
                        charges = Properties::Charges::ONE;
                    } else if (prop.second == "2") {
                        charges = Properties::Charges::TWO;
                    } else if (prop.second == "3") {
                        charges = Properties::Charges::THREE;
                    } else if (prop.second == "4") {
                        charges = Properties::Charges::FOUR;
                    } else {
                        throw std::runtime_error("Invalid property \"charges\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(charges);
        }
    }

}
