#include "StrippedDarkOakLog.hpp"
namespace Blocks {
namespace StrippedDarkOakLog {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 160;
    case Properties::Axis::Y:
        return 161;
    case Properties::Axis::Z:
        return 162;
    default:
        return 0;
    }
    return 0;
}
}

}
