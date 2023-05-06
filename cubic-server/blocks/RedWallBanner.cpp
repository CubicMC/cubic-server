#include "RedWallBanner.hpp"
namespace Blocks {
namespace RedWallBanner {
BlockId toProtocol(Properties::Facing facing) {
    switch (facing) {
    case Properties::Facing::NORTH:
        return 10594;
    case Properties::Facing::SOUTH:
        return 10595;
    case Properties::Facing::WEST:
        return 10596;
    case Properties::Facing::EAST:
        return 10597;
    default:
        return 0;
    }
    return 0;
}
}

}
