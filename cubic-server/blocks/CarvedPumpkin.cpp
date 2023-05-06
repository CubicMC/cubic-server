#include "CarvedPumpkin.hpp"
namespace Blocks {
namespace CarvedPumpkin {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 5701;
    case Properties::Facing::SOUTH:
        return 5702;
    case Properties::Facing::WEST:
        return 5703;
    case Properties::Facing::EAST:
        return 5704;
    default:
        return 0;
    }
    return 0;
}
}

}
