#include "PottedAllium.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PottedAllium {
        BlockId toProtocol() {
            return 6909;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
