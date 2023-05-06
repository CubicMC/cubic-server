#include "OakWood.hpp"
namespace Blocks {
namespace OakWood {
BlockId toProtocol(Properties::Axis axis) {
    switch (axis) {
    case Properties::Axis::X:
        return 172;
    case Properties::Axis::Y:
        return 173;
    case Properties::Axis::Z:
        return 174;
    default:
        return 0;
    }
    return 0;
}
}

}
