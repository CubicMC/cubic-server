#include "PurpurPillar.hpp"
namespace Blocks {
namespace PurpurPillar {
BlockId toProtocol(Properties::Axis axis) {
    switch (axis) {
    case Properties::Axis::X:
        return 11800;
    case Properties::Axis::Y:
        return 11801;
    case Properties::Axis::Z:
        return 11802;
    default:
        return 0;
    }
    return 0;
}
}

}
