#include "HayBlock.hpp"
#include <stdexcept>

namespace Blocks {
    namespace HayBlock {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 10248;
            case Properties::Axis::Y:
                return 10249;
            case Properties::Axis::Z:
                return 10250;
            }
            return 0;
        }
    }

}
