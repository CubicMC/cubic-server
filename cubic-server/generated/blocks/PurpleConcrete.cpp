#include "PurpleConcrete.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PurpleConcrete {
        BlockId toProtocol() {
            return 10329;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
