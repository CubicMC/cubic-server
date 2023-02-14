#include "GrayConcrete.hpp"
#include <stdexcept>

namespace Blocks {
    namespace GrayConcrete {
        BlockId toProtocol() {
            return 10326;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
