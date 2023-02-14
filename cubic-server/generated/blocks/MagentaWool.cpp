#include "MagentaWool.hpp"
#include <stdexcept>

namespace Blocks {
    namespace MagentaWool {
        BlockId toProtocol() {
            return 1640;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
