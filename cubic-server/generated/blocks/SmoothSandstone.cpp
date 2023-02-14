#include "SmoothSandstone.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SmoothSandstone {
        BlockId toProtocol() {
            return 9168;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
