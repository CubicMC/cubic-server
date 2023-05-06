#include "OchreFroglight.hpp"
namespace Blocks {
namespace OchreFroglight {
BlockId toProtocol(Properties::Axis axis) {
    switch (axis) {
    case Properties::Axis::X:
        return 23221;
    case Properties::Axis::Y:
        return 23222;
    case Properties::Axis::Z:
        return 23223;
    default:
        return 0;
    }
    return 0;
}
}

}
