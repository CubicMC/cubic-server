#include "DioriteSlab.hpp"
namespace Blocks {
namespace DioriteSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13526;
        case Properties::Waterlogged::FALSE:
            return 13527;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13528;
        case Properties::Waterlogged::FALSE:
            return 13529;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13530;
        case Properties::Waterlogged::FALSE:
            return 13531;
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
