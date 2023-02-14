#include "CaveVinesPlant.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CaveVinesPlant {
        BlockId toProtocol(Properties::Berries berries) {
            switch (berries) {
            case Properties::Berries::TRUE:
                return 19711;
            case Properties::Berries::FALSE:
                return 19712;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Berries berries;
            for (auto prop : properties) {
                if (prop.first == "berries") {
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
            return toProtocol(berries);
        }
    }

}
