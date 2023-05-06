#include "OrangeShulkerBox.hpp"
namespace Blocks {
namespace OrangeShulkerBox {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 11949;
    case Properties::Facing::EAST:
        return 11950;
    case Properties::Facing::SOUTH:
        return 11951;
    case Properties::Facing::WEST:
        return 11952;
    case Properties::Facing::UP:
        return 11953;
    case Properties::Facing::DOWN:
        return 11954;
    default:
        return 0;
    }
    return 0;
}
}

}
