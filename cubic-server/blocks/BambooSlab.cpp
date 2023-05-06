#include "BambooSlab.hpp"
namespace Blocks {
namespace BambooSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10727;
        case Properties::Waterlogged::FALSE:
            return 10728;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10729;
        case Properties::Waterlogged::FALSE:
            return 10730;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10731;
        case Properties::Waterlogged::FALSE:
            return 10732;
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
