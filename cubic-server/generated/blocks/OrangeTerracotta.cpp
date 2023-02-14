#include "OrangeTerracotta.hpp"
#include <stdexcept>

namespace Blocks {
    namespace OrangeTerracotta {
        BlockId toProtocol() {
            return 7477;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
