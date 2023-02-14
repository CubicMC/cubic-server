#include "PottedAzureBluet.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PottedAzureBluet {
        BlockId toProtocol() {
            return 6910;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
