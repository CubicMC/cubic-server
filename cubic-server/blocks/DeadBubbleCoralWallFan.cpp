#include "DeadBubbleCoralWallFan.hpp"
namespace Blocks {
namespace DeadBubbleCoralWallFan {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12241;
        case Properties::Waterlogged::FALSE:
            return 12242;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12243;
        case Properties::Waterlogged::FALSE:
            return 12244;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12245;
        case Properties::Waterlogged::FALSE:
            return 12246;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12247;
        case Properties::Waterlogged::FALSE:
            return 12248;
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
