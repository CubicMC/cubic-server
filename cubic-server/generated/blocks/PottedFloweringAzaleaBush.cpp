#include "PottedFloweringAzaleaBush.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PottedFloweringAzaleaBush {
        BlockId toProtocol() {
            return 21436;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
