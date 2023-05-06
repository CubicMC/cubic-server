#include "WeatheredCutCopperSlab.hpp"
namespace Blocks {
namespace WeatheredCutCopperSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 21028;
        case Properties::Waterlogged::FALSE:
            return 21029;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 21030;
        case Properties::Waterlogged::FALSE:
            return 21031;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 21032;
        case Properties::Waterlogged::FALSE:
            return 21033;
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
