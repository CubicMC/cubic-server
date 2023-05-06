#include "StrippedOakWood.hpp"
namespace Blocks {
namespace StrippedOakWood {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 193;
    case Properties::Axis::Y:
        return 194;
    case Properties::Axis::Z:
        return 195;
    default:
        return 0;
    }
    return 0;
}
}

}
