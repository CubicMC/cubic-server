#include "PottedLilyOfTheValley.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PottedLilyOfTheValley {
        BlockId toProtocol() {
            return 6917;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
