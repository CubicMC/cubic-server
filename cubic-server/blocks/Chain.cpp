#include "Chain.hpp"
namespace Blocks {
namespace Chain {
BlockId toProtocol(Properties::Axis axis, Properties::Waterlogged waterlogged) {
    switch (axis) {
    case Properties::Axis::X:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 6544;
        case Properties::Waterlogged::FALSE:
            return 6545;
        default:
            return 0;
        }
    case Properties::Axis::Y:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 6546;
        case Properties::Waterlogged::FALSE:
            return 6547;
        default:
            return 0;
        }
    case Properties::Axis::Z:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 6548;
        case Properties::Waterlogged::FALSE:
            return 6549;
        default:
            return 0;
        }
    default:
        return 0;
    }
    return 0;
}
}

}
