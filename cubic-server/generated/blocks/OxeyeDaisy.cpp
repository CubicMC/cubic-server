#include "OxeyeDaisy.hpp"
#include <stdexcept>

namespace Blocks {
    namespace OxeyeDaisy {
        BlockId toProtocol() {
            return 1675;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
