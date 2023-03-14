#include "JungleLog.hpp"
#include <stdexcept>

namespace Blocks {
    namespace JungleLog {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 128;
            case Properties::Axis::Y:
                return 129;
            case Properties::Axis::Z:
                return 130;
            }
            return 0;
        }
    }

}
