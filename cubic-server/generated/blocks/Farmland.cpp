#include "Farmland.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Farmland {
        BlockId toProtocol(Properties::Moisture moisture) {
            switch (moisture) {
            case Properties::Moisture::ZERO:
                return 3620;
            case Properties::Moisture::ONE:
                return 3621;
            case Properties::Moisture::TWO:
                return 3622;
            case Properties::Moisture::THREE:
                return 3623;
            case Properties::Moisture::FOUR:
                return 3624;
            case Properties::Moisture::FIVE:
                return 3625;
            case Properties::Moisture::SIX:
                return 3626;
            case Properties::Moisture::SEVEN:
                return 3627;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Moisture moisture;
            for (auto prop : properties) {
                if (prop.first == "moisture") {
                    if (prop.second == "0") {
                        moisture = Properties::Moisture::ZERO;
                    } else if (prop.second == "1") {
                        moisture = Properties::Moisture::ONE;
                    } else if (prop.second == "2") {
                        moisture = Properties::Moisture::TWO;
                    } else if (prop.second == "3") {
                        moisture = Properties::Moisture::THREE;
                    } else if (prop.second == "4") {
                        moisture = Properties::Moisture::FOUR;
                    } else if (prop.second == "5") {
                        moisture = Properties::Moisture::FIVE;
                    } else if (prop.second == "6") {
                        moisture = Properties::Moisture::SIX;
                    } else if (prop.second == "7") {
                        moisture = Properties::Moisture::SEVEN;
                    } else {
                        throw std::runtime_error("Invalid property \"moisture\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(moisture);
        }
    }

}
