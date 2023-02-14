#include "Mud.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Mud {
        BlockId toProtocol() {
            return 19777;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 0)
            throw std::runtime_error("Invalid number of properties");
            return toProtocol();
        }
    }

}
