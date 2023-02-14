#include "LimeWool.hpp"
#include <stdexcept>

namespace Blocks {
    namespace LimeWool {
        BlockId toProtocol() {
            return 1643;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
