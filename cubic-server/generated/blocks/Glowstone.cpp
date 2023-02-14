#include "Glowstone.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Glowstone {
        BlockId toProtocol() {
            return 4322;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
