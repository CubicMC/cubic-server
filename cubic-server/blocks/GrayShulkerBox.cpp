#include "GrayShulkerBox.hpp"
namespace Blocks {
namespace GrayShulkerBox {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 11985;
    case Properties::Facing::EAST:
        return 11986;
    case Properties::Facing::SOUTH:
        return 11987;
    case Properties::Facing::WEST:
        return 11988;
    case Properties::Facing::UP:
        return 11989;
    case Properties::Facing::DOWN:
        return 11990;
    default:
        return 0;
    }
    return 0;
}
}

}
