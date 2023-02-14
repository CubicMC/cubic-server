#include "WaxedExposedCopper.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WaxedExposedCopper {
        BlockId toProtocol() {
            return 19264;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
