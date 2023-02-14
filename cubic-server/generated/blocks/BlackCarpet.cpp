#include "BlackCarpet.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BlackCarpet {
        BlockId toProtocol() {
            return 8622;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
