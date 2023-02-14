#include "Cornflower.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Cornflower {
        BlockId toProtocol() {
            return 1676;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
