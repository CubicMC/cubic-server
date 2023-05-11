#include "DeadBrainCoralWallFan.hpp"
namespace Blocks {
namespace DeadBrainCoralWallFan {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12233;
        case Properties::Waterlogged::FALSE:
            return 12234;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12235;
        case Properties::Waterlogged::FALSE:
            return 12236;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12237;
        case Properties::Waterlogged::FALSE:
            return 12238;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12239;
        case Properties::Waterlogged::FALSE:
            return 12240;
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
