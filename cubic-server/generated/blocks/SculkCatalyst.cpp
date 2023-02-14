#include "SculkCatalyst.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SculkCatalyst {
        BlockId toProtocol(Properties::Bloom bloom) {
            switch (bloom) {
            case Properties::Bloom::TRUE:
                return 18898;
            case Properties::Bloom::FALSE:
                return 18899;
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 1)
            throw std::runtime_error("Invalid number of properties");
            Properties::Bloom bloom;
            for (auto prop : properties) {
                if (prop.first == "bloom") {
                    if (prop.second == "true") {
                        bloom = Properties::Bloom::TRUE;
                    } else if (prop.second == "false") {
                        bloom = Properties::Bloom::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"bloom\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(bloom);
        }
    }

}
