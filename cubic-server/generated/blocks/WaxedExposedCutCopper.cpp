#include "WaxedExposedCutCopper.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WaxedExposedCutCopper {
        BlockId toProtocol() {
            return 19268;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
