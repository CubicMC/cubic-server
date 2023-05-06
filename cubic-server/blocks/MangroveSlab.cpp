#include "MangroveSlab.hpp"
namespace Blocks {
namespace MangroveSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10721;
        case Properties::Waterlogged::FALSE:
            return 10722;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10723;
        case Properties::Waterlogged::FALSE:
            return 10724;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10725;
        case Properties::Waterlogged::FALSE:
            return 10726;
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
