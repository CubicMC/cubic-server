#include "DarkOakSlab.hpp"
namespace Blocks {
namespace DarkOakSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10715;
        case Properties::Waterlogged::FALSE:
            return 10716;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10717;
        case Properties::Waterlogged::FALSE:
            return 10718;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10719;
        case Properties::Waterlogged::FALSE:
            return 10720;
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
