#include "SpruceWood.hpp"
namespace Blocks {
namespace SpruceWood {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 175;
    case Properties::Axis::Y:
        return 176;
    case Properties::Axis::Z:
        return 177;
    default:
        return 0;
    }
    return 0;
}
}

}
