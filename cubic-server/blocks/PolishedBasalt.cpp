#include "PolishedBasalt.hpp"
namespace Blocks {
namespace PolishedBasalt {
BlockId toProtocol(Properties::Axis axis) {
    switch (axis) {
    case Properties::Axis::X:
        return 5690;
    case Properties::Axis::Y:
        return 5691;
    case Properties::Axis::Z:
        return 5692;
    default:
        return 0;
    }
    return 0;
}
}

}
