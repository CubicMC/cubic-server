#include "HayBlock.hpp"
namespace Blocks {
namespace HayBlock {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 10248;
    case Properties::Axis::Y:
        return 10249;
    case Properties::Axis::Z:
        return 10250;
    default:
        return 0;
    }
    return 0;
}
}

}
