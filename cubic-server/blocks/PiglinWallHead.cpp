#include "PiglinWallHead.hpp"
#include <stdexcept>

namespace Blocks {
namespace PiglinWallHead {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 8707;
    case Properties::Facing::SOUTH:
        return 8708;
    case Properties::Facing::WEST:
        return 8709;
    case Properties::Facing::EAST:
        return 8710;
    }
    return 0;
}
}

}
