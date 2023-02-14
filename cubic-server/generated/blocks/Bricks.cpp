#include "Bricks.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Bricks {
        BlockId toProtocol() {
            return 1683;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
