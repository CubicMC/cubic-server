#include "MagentaConcretePowder.hpp"
#include <stdexcept>

namespace Blocks {
    namespace MagentaConcretePowder {
        BlockId toProtocol() {
            return 10337;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
