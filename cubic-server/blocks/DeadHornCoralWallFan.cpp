#include "DeadHornCoralWallFan.hpp"
namespace Blocks {
namespace DeadHornCoralWallFan {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12257;
        case Properties::Waterlogged::FALSE:
            return 12258;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12259;
        case Properties::Waterlogged::FALSE:
            return 12260;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12261;
        case Properties::Waterlogged::FALSE:
            return 12262;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12263;
        case Properties::Waterlogged::FALSE:
            return 12264;
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
