#include "PolishedBasalt.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PolishedBasalt {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 5690;
            case Properties::Axis::Y:
                return 5691;
            case Properties::Axis::Z:
                return 5692;
            }
            return 0;
        }
    }

}
