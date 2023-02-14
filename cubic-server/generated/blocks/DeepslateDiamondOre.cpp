#include "DeepslateDiamondOre.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DeepslateDiamondOre {
        BlockId toProtocol() {
            return 3609;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
