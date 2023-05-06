#include "SpruceSlab.hpp"
namespace Blocks {
namespace SpruceSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10691;
        case Properties::Waterlogged::FALSE:
            return 10692;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10693;
        case Properties::Waterlogged::FALSE:
            return 10694;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10695;
        case Properties::Waterlogged::FALSE:
            return 10696;
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
