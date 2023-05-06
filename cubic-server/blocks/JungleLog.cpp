#include "JungleLog.hpp"
namespace Blocks {
namespace JungleLog {
BlockId toProtocol(Properties::Axis axis) {
    switch (axis) {
    case Properties::Axis::X:
        return 128;
    case Properties::Axis::Y:
        return 129;
    case Properties::Axis::Z:
        return 130;
    default:
        return 0;
    }
    return 0;
}
}

}
