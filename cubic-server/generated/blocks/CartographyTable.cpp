#include "CartographyTable.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CartographyTable {
        BlockId toProtocol() {
            return 16024;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}