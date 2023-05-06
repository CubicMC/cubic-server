#include "CobbledDeepslateSlab.hpp"
namespace Blocks {
namespace CobbledDeepslateSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 21646;
        case Properties::Waterlogged::FALSE:
            return 21647;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 21648;
        case Properties::Waterlogged::FALSE:
            return 21649;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 21650;
        case Properties::Waterlogged::FALSE:
            return 21651;
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
