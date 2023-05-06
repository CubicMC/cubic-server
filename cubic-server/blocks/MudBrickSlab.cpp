#include "MudBrickSlab.hpp"
namespace Blocks {
namespace MudBrickSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10787;
        case Properties::Waterlogged::FALSE:
            return 10788;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10789;
        case Properties::Waterlogged::FALSE:
            return 10790;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10791;
        case Properties::Waterlogged::FALSE:
            return 10792;
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
