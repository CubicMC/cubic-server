#include "StrippedOakLog.hpp"
namespace Blocks {
namespace StrippedOakLog {
BlockId toProtocol(Properties::Axis axis) {
    switch (axis) {
    case Properties::Axis::X:
        return 163;
    case Properties::Axis::Y:
        return 164;
    case Properties::Axis::Z:
        return 165;
    default:
        return 0;
    }
    return 0;
}
}

}
