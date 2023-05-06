#include "DarkOakWallSign.hpp"
namespace Blocks {
namespace DarkOakWallSign {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4718;
        case Properties::Waterlogged::FALSE:
            return 4719;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4720;
        case Properties::Waterlogged::FALSE:
            return 4721;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4722;
        case Properties::Waterlogged::FALSE:
            return 4723;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4724;
        case Properties::Waterlogged::FALSE:
            return 4725;
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
