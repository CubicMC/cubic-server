#include "SmoothStone.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SmoothStone {
        BlockId toProtocol() {
            return 9167;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
