#include "CobbledDeepslate.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CobbledDeepslate {
        BlockId toProtocol() {
            return 19781;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
