#include "PowderSnowCauldron.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PowderSnowCauldron {
        BlockId toProtocol(Properties::Level level) {
            switch (level) {
            case Properties::Level::ONE:
                return 5733;
            case Properties::Level::TWO:
                return 5734;
            case Properties::Level::THREE:
                return 5735;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Level level;
            for (auto prop : properties) {
                if (prop.first == "level") {
                    if (prop.second == "1") {
                        level = Properties::Level::ONE;
                    } else if (prop.second == "2") {
                        level = Properties::Level::TWO;
                    } else if (prop.second == "3") {
                        level = Properties::Level::THREE;
                    } else {
                        throw std::runtime_error("Invalid property \"level\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(level);
        }
    }

}
