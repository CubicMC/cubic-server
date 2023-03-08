#include "QuartzPillar.hpp"
#include <stdexcept>

namespace Blocks {
    namespace QuartzPillar {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 8841;
            case Properties::Axis::Y:
                return 8842;
            case Properties::Axis::Z:
                return 8843;
            }
            return 0;
        }
    }

}
