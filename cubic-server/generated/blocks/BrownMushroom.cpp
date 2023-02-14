#include "BrownMushroom.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BrownMushroom {
        BlockId toProtocol() {
            return 1679;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
