#include "StrippedAcaciaWood.hpp"
namespace Blocks {
namespace StrippedAcaciaWood {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 205;
    case Properties::Axis::Y:
        return 206;
    case Properties::Axis::Z:
        return 207;
    default:
        return 0;
    }
    return 0;
}
}

}
