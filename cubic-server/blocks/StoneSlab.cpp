#include "StoneSlab.hpp"
namespace Blocks {
namespace StoneSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10739;
        case Properties::Waterlogged::FALSE:
            return 10740;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10741;
        case Properties::Waterlogged::FALSE:
            return 10742;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10743;
        case Properties::Waterlogged::FALSE:
            return 10744;
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
