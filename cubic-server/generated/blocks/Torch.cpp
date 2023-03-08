#include "Torch.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Torch {
        BlockId toProtocol() {
            return 1689;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}