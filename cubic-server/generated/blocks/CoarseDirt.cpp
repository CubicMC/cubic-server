#include "CoarseDirt.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CoarseDirt {
        BlockId toProtocol() {
            return 11;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
