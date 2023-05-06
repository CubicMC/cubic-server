#include "RedShulkerBox.hpp"
namespace Blocks {
namespace RedShulkerBox {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 12027;
    case Properties::Facing::EAST:
        return 12028;
    case Properties::Facing::SOUTH:
        return 12029;
    case Properties::Facing::WEST:
        return 12030;
    case Properties::Facing::UP:
        return 12031;
    case Properties::Facing::DOWN:
        return 12032;
    default:
        return 0;
    }
    return 0;
}
}

}
