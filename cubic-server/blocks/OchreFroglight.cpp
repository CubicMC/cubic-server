#include "OchreFroglight.hpp"
#include <stdexcept>

namespace Blocks {
    namespace OchreFroglight {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 23221;
            case Properties::Axis::Y:
                return 23222;
            case Properties::Axis::Z:
                return 23223;
            }
            return 0;
        }
    }

}
