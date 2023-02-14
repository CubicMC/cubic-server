#include "GrassBlock.hpp"
#include <stdexcept>

namespace Blocks {
    namespace GrassBlock {
        BlockId toProtocol(Properties::Snowy snowy) {
            switch (snowy) {
            case Properties::Snowy::TRUE:
                return 8;
            case Properties::Snowy::FALSE:
                return 9;
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
