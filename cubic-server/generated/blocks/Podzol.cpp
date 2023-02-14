#include "Podzol.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Podzol {
        BlockId toProtocol(Properties::Snowy snowy) {
            switch (snowy) {
            case Properties::Snowy::TRUE:
                return 12;
            case Properties::Snowy::FALSE:
                return 13;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Snowy snowy;
            for (auto prop : properties) {
                if (prop.first == "snowy") {
                    if (prop.second == "true") {
                        snowy = Properties::Snowy::TRUE;
                    } else if (prop.second == "false") {
                        snowy = Properties::Snowy::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"snowy\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(snowy);
        }
    }

}
