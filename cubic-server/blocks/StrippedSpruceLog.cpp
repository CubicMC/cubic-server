#include "StrippedSpruceLog.hpp"
#include <stdexcept>

namespace Blocks {
    namespace StrippedSpruceLog {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 148;
            case Properties::Axis::Y:
                return 149;
            case Properties::Axis::Z:
                return 150;
            }
            return 0;
        }
    }

}
