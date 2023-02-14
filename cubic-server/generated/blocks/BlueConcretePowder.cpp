#include "BlueConcretePowder.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BlueConcretePowder {
        BlockId toProtocol() {
            return 10346;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
