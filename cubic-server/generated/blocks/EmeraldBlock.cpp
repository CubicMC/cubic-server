#include "EmeraldBlock.hpp"
#include <stdexcept>

namespace Blocks {
    namespace EmeraldBlock {
        BlockId toProtocol() {
            return 5995;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
