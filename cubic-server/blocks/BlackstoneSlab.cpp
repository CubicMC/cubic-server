#include "BlackstoneSlab.hpp"
namespace Blocks {
namespace BlackstoneSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 19237;
        case Properties::Waterlogged::FALSE:
            return 19238;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 19239;
        case Properties::Waterlogged::FALSE:
            return 19240;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 19241;
        case Properties::Waterlogged::FALSE:
            return 19242;
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
