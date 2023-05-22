#include "BrainCoralWallFan.hpp"
namespace Blocks {
namespace BrainCoralWallFan {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12273;
        case Properties::Waterlogged::FALSE:
            return 12274;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12275;
        case Properties::Waterlogged::FALSE:
            return 12276;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12277;
        case Properties::Waterlogged::FALSE:
            return 12278;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12279;
        case Properties::Waterlogged::FALSE:
            return 12280;
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
