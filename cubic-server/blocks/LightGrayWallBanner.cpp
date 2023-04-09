#include "LightGrayWallBanner.hpp"
#include <stdexcept>

namespace Blocks {
namespace LightGrayWallBanner {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 10570;
    case Properties::Facing::SOUTH:
        return 10571;
    case Properties::Facing::WEST:
        return 10572;
    case Properties::Facing::EAST:
        return 10573;
    }
    return 0;
}
}

}
