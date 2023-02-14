#include "SporeBlossom.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SporeBlossom {
        BlockId toProtocol() {
            return 19713;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
