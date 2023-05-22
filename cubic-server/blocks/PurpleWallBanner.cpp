#include "PurpleWallBanner.hpp"
namespace Blocks {
namespace PurpleWallBanner {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 10578;
    case Properties::Facing::SOUTH:
        return 10579;
    case Properties::Facing::WEST:
        return 10580;
    case Properties::Facing::EAST:
        return 10581;
    default:
        return 0;
    }
    return 0;
}
}

}
