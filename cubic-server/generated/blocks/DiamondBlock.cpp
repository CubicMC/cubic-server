#include "DiamondBlock.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DiamondBlock {
        BlockId toProtocol() {
            return 3610;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
