#include "PurpleTerracotta.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PurpleTerracotta {
        BlockId toProtocol() {
            return 7486;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
