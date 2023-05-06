#include "WarpedStem.hpp"
namespace Blocks {
namespace WarpedStem {
BlockId toProtocol(Properties::Axis axis) {
    switch (axis) {
    case Properties::Axis::X:
        return 17951;
    case Properties::Axis::Y:
        return 17952;
    case Properties::Axis::Z:
        return 17953;
    default:
        return 0;
    }
    return 0;
}
}

}
