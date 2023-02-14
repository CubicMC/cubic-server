#include "DeepslateBricks.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DeepslateBricks {
        BlockId toProtocol() {
            return 21014;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
