#include "MagentaStainedGlass.hpp"
#include <stdexcept>

namespace Blocks {
    namespace MagentaStainedGlass {
        BlockId toProtocol() {
            return 4406;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
