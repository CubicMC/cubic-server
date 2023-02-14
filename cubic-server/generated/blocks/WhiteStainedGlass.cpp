#include "WhiteStainedGlass.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WhiteStainedGlass {
        BlockId toProtocol() {
            return 4404;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
