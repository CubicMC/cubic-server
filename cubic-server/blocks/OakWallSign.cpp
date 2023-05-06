#include "OakWallSign.hpp"
namespace Blocks {
namespace OakWallSign {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4678;
        case Properties::Waterlogged::FALSE:
            return 4679;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4680;
        case Properties::Waterlogged::FALSE:
            return 4681;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4682;
        case Properties::Waterlogged::FALSE:
            return 4683;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4684;
        case Properties::Waterlogged::FALSE:
            return 4685;
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
