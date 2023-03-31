#include "DragonWallHead.hpp"
#include <stdexcept>

namespace Blocks {
namespace DragonWallHead {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 8687;
    case Properties::Facing::SOUTH:
        return 8688;
    case Properties::Facing::WEST:
        return 8689;
    case Properties::Facing::EAST:
        return 8690;
    }
    return 0;
}
}

}
