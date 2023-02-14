#include "ChiseledStoneBricks.hpp"
#include <stdexcept>

namespace Blocks {
    namespace ChiseledStoneBricks {
        BlockId toProtocol() {
            return 4871;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
