#include "LimeWallBanner.hpp"
namespace Blocks {
namespace LimeWallBanner {
BlockId toProtocol(Properties::Facing facing) {
    switch (facing) {
    case Properties::Facing::NORTH:
        return 10558;
    case Properties::Facing::SOUTH:
        return 10559;
    case Properties::Facing::WEST:
        return 10560;
    case Properties::Facing::EAST:
        return 10561;
    default:
        return 0;
    }
    return 0;
}
}

}
