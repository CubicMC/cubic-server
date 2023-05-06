#include "BubbleCoralWallFan.hpp"
namespace Blocks {
namespace BubbleCoralWallFan {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12281;
        case Properties::Waterlogged::FALSE:
            return 12282;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12283;
        case Properties::Waterlogged::FALSE:
            return 12284;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12285;
        case Properties::Waterlogged::FALSE:
            return 12286;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12287;
        case Properties::Waterlogged::FALSE:
            return 12288;
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
