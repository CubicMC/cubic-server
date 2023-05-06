#include "PolishedBlackstoneBrickSlab.hpp"
namespace Blocks {
namespace PolishedBlackstoneBrickSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 19247;
        case Properties::Waterlogged::FALSE:
            return 19248;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 19249;
        case Properties::Waterlogged::FALSE:
            return 19250;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 19251;
        case Properties::Waterlogged::FALSE:
            return 19252;
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
