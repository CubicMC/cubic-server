#include "PottedCactus.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PottedCactus {
        BlockId toProtocol() {
            return 6922;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
