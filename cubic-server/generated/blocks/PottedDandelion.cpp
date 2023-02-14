#include "PottedDandelion.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PottedDandelion {
        BlockId toProtocol() {
            return 6906;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
