#include "GrayTerracotta.hpp"
#include <stdexcept>

namespace Blocks {
    namespace GrayTerracotta {
        BlockId toProtocol() {
            return 7483;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
