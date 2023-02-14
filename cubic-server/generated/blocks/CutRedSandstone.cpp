#include "CutRedSandstone.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CutRedSandstone {
        BlockId toProtocol() {
            return 8960;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
