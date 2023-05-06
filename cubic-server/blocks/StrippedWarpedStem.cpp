#include "StrippedWarpedStem.hpp"
namespace Blocks {
namespace StrippedWarpedStem {
BlockId toProtocol(Properties::Axis axis) {
    switch (axis) {
    case Properties::Axis::X:
        return 17954;
    case Properties::Axis::Y:
        return 17955;
    case Properties::Axis::Z:
        return 17956;
    default:
        return 0;
    }
    return 0;
}
}

}
