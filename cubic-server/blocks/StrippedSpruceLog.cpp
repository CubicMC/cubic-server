#include "StrippedSpruceLog.hpp"
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
    default:
        return 0;
    }
    return 0;
}
}

}
