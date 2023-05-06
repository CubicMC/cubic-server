#include "MangroveWood.hpp"
namespace Blocks {
namespace MangroveWood {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 190;
    case Properties::Axis::Y:
        return 191;
    case Properties::Axis::Z:
        return 192;
    default:
        return 0;
    }
    return 0;
}
}

}
