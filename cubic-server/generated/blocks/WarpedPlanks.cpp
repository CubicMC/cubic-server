#include "WarpedPlanks.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WarpedPlanks {
        BlockId toProtocol() {
            return 16255;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
