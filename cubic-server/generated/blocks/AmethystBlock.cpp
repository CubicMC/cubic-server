#include "AmethystBlock.hpp"
#include <stdexcept>

namespace Blocks {
    namespace AmethystBlock {
        BlockId toProtocol() {
            return 18619;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
