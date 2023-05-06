#include "EnderChest.hpp"
namespace Blocks {
namespace EnderChest {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 7283;
        case Properties::Waterlogged::FALSE:
            return 7284;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 7285;
        case Properties::Waterlogged::FALSE:
            return 7286;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 7287;
        case Properties::Waterlogged::FALSE:
            return 7288;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 7289;
        case Properties::Waterlogged::FALSE:
            return 7290;
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
