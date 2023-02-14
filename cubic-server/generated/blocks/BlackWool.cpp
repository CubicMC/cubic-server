#include "BlackWool.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BlackWool {
        BlockId toProtocol() {
            return 1653;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
