#include "WhiteTulip.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WhiteTulip {
        BlockId toProtocol() {
            return 1673;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
