#include "ChiseledQuartzBlock.hpp"
#include <stdexcept>

namespace Blocks {
    namespace ChiseledQuartzBlock {
        BlockId toProtocol() {
            return 7356;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
