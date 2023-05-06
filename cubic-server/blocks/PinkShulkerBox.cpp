#include "PinkShulkerBox.hpp"
namespace Blocks {
namespace PinkShulkerBox {
BlockId toProtocol(Properties::Facing facing) {
    switch (facing) {
    case Properties::Facing::NORTH:
        return 11979;
    case Properties::Facing::EAST:
        return 11980;
    case Properties::Facing::SOUTH:
        return 11981;
    case Properties::Facing::WEST:
        return 11982;
    case Properties::Facing::UP:
        return 11983;
    case Properties::Facing::DOWN:
        return 11984;
    default:
        return 0;
    }
    return 0;
}
}

}
