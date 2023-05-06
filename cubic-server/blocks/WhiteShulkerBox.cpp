#include "WhiteShulkerBox.hpp"
namespace Blocks {
namespace WhiteShulkerBox {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 11943;
    case Properties::Facing::EAST:
        return 11944;
    case Properties::Facing::SOUTH:
        return 11945;
    case Properties::Facing::WEST:
        return 11946;
    case Properties::Facing::UP:
        return 11947;
    case Properties::Facing::DOWN:
        return 11948;
    default:
        return 0;
    }
    return 0;
}
}

}
