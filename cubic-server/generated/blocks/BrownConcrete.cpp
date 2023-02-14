#include "BrownConcrete.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BrownConcrete {
        BlockId toProtocol() {
            return 10331;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
