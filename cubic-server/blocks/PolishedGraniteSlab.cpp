#include "PolishedGraniteSlab.hpp"
namespace Blocks {
namespace PolishedGraniteSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13454;
        case Properties::Waterlogged::FALSE:
            return 13455;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13456;
        case Properties::Waterlogged::FALSE:
            return 13457;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13458;
        case Properties::Waterlogged::FALSE:
            return 13459;
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
