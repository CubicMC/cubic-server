#include "SmoothRedSandstone.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SmoothRedSandstone {
        BlockId toProtocol() {
            return 9170;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
