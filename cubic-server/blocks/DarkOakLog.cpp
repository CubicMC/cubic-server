#include "DarkOakLog.hpp"
namespace Blocks {
    namespace DarkOakLog {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 134;
            case Properties::Axis::Y:
                return 135;
            case Properties::Axis::Z:
                return 136;
            default:
                return 0;
            }
            return 0;
        }
    }

}
