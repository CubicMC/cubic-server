#include "BlueStainedGlass.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BlueStainedGlass {
        BlockId toProtocol() {
            return 4415;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
