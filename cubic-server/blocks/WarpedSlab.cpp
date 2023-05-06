#include "WarpedSlab.hpp"
namespace Blocks {
namespace WarpedSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 18046;
        case Properties::Waterlogged::FALSE:
            return 18047;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 18048;
        case Properties::Waterlogged::FALSE:
            return 18049;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 18050;
        case Properties::Waterlogged::FALSE:
            return 18051;
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
