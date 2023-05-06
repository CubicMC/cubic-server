#include "SkeletonWallSkull.hpp"
namespace Blocks {
namespace SkeletonWallSkull {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 8587;
    case Properties::Facing::SOUTH:
        return 8588;
    case Properties::Facing::WEST:
        return 8589;
    case Properties::Facing::EAST:
        return 8590;
    default:
        return 0;
    }
    return 0;
}
}

}
