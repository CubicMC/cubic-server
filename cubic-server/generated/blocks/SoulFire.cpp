#include "SoulFire.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SoulFire {
        BlockId toProtocol() {
            return 2206;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
