#include "StrippedWarpedHyphae.hpp"
namespace Blocks {
namespace StrippedWarpedHyphae {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 17960;
    case Properties::Axis::Y:
        return 17961;
    case Properties::Axis::Z:
        return 17962;
    default:
        return 0;
    }
    return 0;
}
}

}
