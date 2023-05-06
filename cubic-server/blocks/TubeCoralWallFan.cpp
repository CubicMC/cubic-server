#include "TubeCoralWallFan.hpp"
namespace Blocks {
namespace TubeCoralWallFan {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12265;
        case Properties::Waterlogged::FALSE:
            return 12266;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12267;
        case Properties::Waterlogged::FALSE:
            return 12268;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12269;
        case Properties::Waterlogged::FALSE:
            return 12270;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12271;
        case Properties::Waterlogged::FALSE:
            return 12272;
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
