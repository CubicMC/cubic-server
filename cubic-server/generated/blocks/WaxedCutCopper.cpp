#include "WaxedCutCopper.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WaxedCutCopper {
        BlockId toProtocol() {
            return 19269;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
