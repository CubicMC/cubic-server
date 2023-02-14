#include "OrangeConcrete.hpp"
#include <stdexcept>

namespace Blocks {
    namespace OrangeConcrete {
        BlockId toProtocol() {
            return 10320;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
