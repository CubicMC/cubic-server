#include "MuddyMangroveRoots.hpp"
namespace Blocks {
namespace MuddyMangroveRoots {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 142;
    case Properties::Axis::Y:
        return 143;
    case Properties::Axis::Z:
        return 144;
    default:
        return 0;
    }
    return 0;
}
}

}
