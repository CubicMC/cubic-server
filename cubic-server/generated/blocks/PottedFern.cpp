#include "PottedFern.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PottedFern {
        BlockId toProtocol() {
            return 6905;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
