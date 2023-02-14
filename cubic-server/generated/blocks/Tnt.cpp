#include "Tnt.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Tnt {
        BlockId toProtocol(Properties::Unstable unstable) {
            switch (unstable) {
            case Properties::Unstable::TRUE:
                return 1684;
            case Properties::Unstable::FALSE:
                return 1685;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Unstable unstable;
            for (auto prop : properties) {
                if (prop.first == "unstable") {
                    if (prop.second == "true") {
                        unstable = Properties::Unstable::TRUE;
                    } else if (prop.second == "false") {
                        unstable = Properties::Unstable::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"unstable\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(unstable);
        }
    }

}
