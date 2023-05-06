#include "Basalt.hpp"
namespace Blocks {
namespace Basalt {
BlockId toProtocol(Properties::Axis axis) {
    switch (axis) {
    case Properties::Axis::X:
        return 5687;
    case Properties::Axis::Y:
        return 5688;
    case Properties::Axis::Z:
        return 5689;
    default:
        return 0;
    }
    return 0;
}
}

}
