#include "CreeperWallHead.hpp"
#include <stdexcept>

namespace Blocks {
namespace CreeperWallHead {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 8667;
    case Properties::Facing::SOUTH:
        return 8668;
    case Properties::Facing::WEST:
        return 8669;
    case Properties::Facing::EAST:
        return 8670;
    }
    return 0;
}
}

}
