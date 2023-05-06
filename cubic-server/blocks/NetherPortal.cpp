#include "NetherPortal.hpp"
namespace Blocks {
namespace NetherPortal {
BlockId toProtocol(Properties::Axis axis) {
    switch (axis) {
    case Properties::Axis::X:
        return 5699;
    case Properties::Axis::Z:
        return 5700;
    default:
        return 0;
    }
    return 0;
}
}

}
