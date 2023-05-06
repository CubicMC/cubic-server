#include "BirchWallHangingSign.hpp"
namespace Blocks {
namespace BirchWallHangingSign {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5398;
        case Properties::Waterlogged::FALSE:
            return 5399;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5400;
        case Properties::Waterlogged::FALSE:
            return 5401;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5402;
        case Properties::Waterlogged::FALSE:
            return 5403;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5404;
        case Properties::Waterlogged::FALSE:
            return 5405;
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
