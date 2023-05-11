#include "SmoothQuartzSlab.hpp"
namespace Blocks {
namespace SmoothQuartzSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13496;
        case Properties::Waterlogged::FALSE:
            return 13497;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13498;
        case Properties::Waterlogged::FALSE:
            return 13499;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13500;
        case Properties::Waterlogged::FALSE:
            return 13501;
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
