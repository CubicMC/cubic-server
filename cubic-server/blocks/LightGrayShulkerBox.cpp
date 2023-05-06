#include "LightGrayShulkerBox.hpp"
namespace Blocks {
namespace LightGrayShulkerBox {
BlockId toProtocol(Properties::Facing facing) {
    switch (facing) {
    case Properties::Facing::NORTH:
        return 11991;
    case Properties::Facing::EAST:
        return 11992;
    case Properties::Facing::SOUTH:
        return 11993;
    case Properties::Facing::WEST:
        return 11994;
    case Properties::Facing::UP:
        return 11995;
    case Properties::Facing::DOWN:
        return 11996;
    default:
        return 0;
    }
    return 0;
}
}

}
