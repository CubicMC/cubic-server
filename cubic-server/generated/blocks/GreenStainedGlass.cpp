#include "GreenStainedGlass.hpp"
#include <stdexcept>

namespace Blocks {
    namespace GreenStainedGlass {
        BlockId toProtocol() {
            return 4417;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
