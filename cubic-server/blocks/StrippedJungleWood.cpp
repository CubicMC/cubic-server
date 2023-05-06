#include "StrippedJungleWood.hpp"
namespace Blocks {
namespace StrippedJungleWood {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 202;
    case Properties::Axis::Y:
        return 203;
    case Properties::Axis::Z:
        return 204;
    default:
        return 0;
    }
    return 0;
}
}

}
