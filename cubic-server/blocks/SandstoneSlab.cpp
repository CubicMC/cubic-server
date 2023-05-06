#include "SandstoneSlab.hpp"
namespace Blocks {
namespace SandstoneSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10751;
        case Properties::Waterlogged::FALSE:
            return 10752;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10753;
        case Properties::Waterlogged::FALSE:
            return 10754;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10755;
        case Properties::Waterlogged::FALSE:
            return 10756;
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
